#ifdef HIVE_ENABLE_MPI
#include <mpi.h>
#endif

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdint.h>

#include "happyhttp.h"
#include "easywsclient.hpp"

#include "Connection.h"

namespace {
    // Assume single instance for websocket.
    std::string gRecvBuffer;

    void RecvCallback(const std::string& message) {
        printf("msg: %s\n", message.c_str());
        gRecvBuffer = message;
    }
    
    // callback  for http
    void onBegin( const happyhttp::Response* r, void* userdata )
    {
    }
    // callback for http
    void onData( const happyhttp::Response* r, void* userdata, const unsigned char* data, int n )
    {
    }
    // callback for http
    void onComplete( const happyhttp::Response* r, void* userdata )
    {
    }
    int base64encode(char* dst, const char* src, unsigned int in_size)
    {
        const char b64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
        if (in_size == 0 || src == dst) return 0;
        
        int count = 0;
        for (int i = 0; i < (in_size - 1) / 3 + 1; i++) {
            const unsigned char* c = reinterpret_cast<const unsigned char*>(&src[i*3]);
            for (int j = 0; j < 4; j++)
                if (in_size >= i * 3 + j) {
                    dst[count++] = b64[(c[j-1]<<(6-j*2) | c[j]>>(j*2+2)) & 0x3f];
                }
                else dst[count++] = '=';
        }
        dst[count] = '\0';
        return count;
    }
} // anonymouse namespace

/**
 * default implementaion
 */
class Impl : public ConnectionIF
{
public:
    Impl()
    {
        m_connection = NULL;
        m_ws = NULL;
        m_timeout = 1000;
    }
    
    ~Impl()
    {
        Close();
        delete m_connection;
        m_connection = NULL;
        delete m_ws;
        m_ws = NULL;
    }

    bool Connect(const std::string& url)
    {
        if (m_connection) {
            if (!Close()) {
                return false;
            }
        }
        printf("connect : %s  \n", url.c_str());
        if (url.find("http://") != std::string::npos) {
            return connectHTTP(url);
        } else if (url.find("ws://") != std::string::npos) {
            return connectWS(url);
        }
        return false;
    }
    
    bool SendText(const std::string& text)
    {
        if (m_connection) {
            const unsigned char* body = reinterpret_cast<const unsigned char*>(text.c_str());
            const int size = static_cast<int>(text.size());
            const char* header[] = {
                "Content-type", "text/plain", 0
            };
            happyhttp::Error error = m_connection->request("POST", "/postparam", header, body, size);
            if (error) {
                fprintf(stderr, "Connection Error: %s¥n", error->c_str());
                return false;
            }
            return true;
        } else if (m_ws) {
            m_ws->send(text);
            m_ws->poll();
            return true;
        }
        return false;
    }
    
    bool SendJSON(const std::string& json)
    {
        if (m_connection) {
            const unsigned char* body = reinterpret_cast<const unsigned char*>(json.c_str());
            const int size = static_cast<int>(json.size());
            const char* header[] = {
                "Content-type", "application/json", 0
            };
            happyhttp::Error error = m_connection->request("POST", "/postparam", header, body, size);
            if (error) {
                fprintf(stderr, "Connection Error: %s\n", error->c_str());
                return false;
            }
            return true;
        } else if (m_ws) {
            m_ws->send(json);
            m_ws->poll();
            return true;
        }
        return false;
    }
    
    bool SendBinary(const Binary binary, int size)
    {
        if (m_connection) {
            const unsigned char* body = reinterpret_cast<const unsigned char*>(binary);
            const char* header[] = {
                "Content-type", "application/octet-stream", 0
            };
            happyhttp::Error error = m_connection->request("POST", "/postparam", header, body, size);
            if (error) {
                fprintf(stderr, "Connection Error: %s\n", error->c_str());
                return false;
            }
            return true;
        } else if (m_ws) {
            std::string body(reinterpret_cast<const char*>(binary), size);
            m_ws->sendBinary(body);
            m_ws->poll();
            return true;
        }
        return false;
    }
    
    bool SendImage(const std::string& filepath)
    {
        printf("send image : %s\n", filepath.c_str());
        
        // load image
        std::ifstream ifs(filepath.c_str(), std::ios::in | std::ios::binary);
        if (!ifs.good()) {
            fprintf(stderr, "File Open Error");
            return false;
        }
        ifs.seekg(0, std::ifstream::end);
        const unsigned int fsize = ifs.tellg();
        ifs.seekg(0, std::ifstream::beg);
        char* buffer = new char[fsize];
        ifs.read(buffer, fsize);
        
        // HTTP
        if (m_connection) {
            // base64 encoding
            char* base64buffer = new char[fsize * 2];
            const int base64size = base64encode(base64buffer, buffer, fsize);
            
            // send data
            const char* header[] = {
                "Content-type", "image", 0
            };
            unsigned char* body = reinterpret_cast<unsigned char*>(base64buffer);
            happyhttp::Error error = m_connection->request("POST", "/postparam", header, body, base64size);
            delete [] buffer;
            delete [] base64buffer;
            if (error) {
                fprintf(stderr, "Connection Error: %s\n", error->c_str());
                return false;
            }
            return true;
        }
        // Websocket
        else if (m_ws) {
            std::string binary(buffer, fsize);
            m_ws->sendBinary(binary);
            m_ws->poll();
            delete [] buffer;
            return true;
        }
        return false;
    }
    
    std::string Recv() {
        if (m_connection) {
            fprintf(stderr, "No connection Error");
            return "";
        } else if (m_ws) {
            if (m_ws->getReadyState() == easywsclient::WebSocket::CLOSED) {
                return "";
            }

            // Assume single thread, single instance execution.
            gRecvBuffer.clear();

            m_ws->poll(m_timeout);
            m_ws->dispatch(RecvCallback);

            return gRecvBuffer;
        }
        return "";
    }
    
    bool SetTimeout(int timeout) {
        if (timeout < 0) {
            return false;
        }
        m_timeout = timeout;
        return true;
    }
    
    bool Close()
    {
        if (m_connection) {
            m_connection->close();
            delete m_connection;
            m_connection = NULL;
        }
        if (m_ws) {
            m_ws->close();
        }
        return true;
    }
    
private:
    typedef std::vector<std::string> SURL;
    void separateURL(SURL& dst, int& dstPort, const std::string& url) {
        int pos = static_cast<int>(url.find("http://"));
        int startHost = pos + 7;
        if (pos != std::string::npos) {
            dst.push_back(url.substr(pos, startHost));
            std::string second = url.substr(startHost, url.size() - startHost);
            if (second.find(':') != std::string::npos) {
                // find port
                int colon = second.find(':');
                int endHost = second.find_first_of("/");
                if (endHost == std::string::npos) {
                    endHost = second.size();
                }
                std::string port = second.substr(colon+1, endHost-(colon+1));
                std::stringstream ss;
                ss << port;
                ss >> dstPort;
                // make url without port
                std::string host = second.substr(0, colon);
                std::string other;
                if (endHost < second.size()) {
                    other = second.substr(endHost+1, second.size() - (endHost+1));
                }
                dst.push_back(host + other);
            }
            else
            {
                // use default port
                dst.push_back(second);
            }
        }
    }
    
    bool connectHTTP(const std::string& url) {
        SURL surl;
        int port = 8080;
        separateURL(surl, port, url);
        m_connection = new happyhttp::Connection(surl[1].c_str(), port);
        m_connection->setcallbacks( onBegin, onData, onComplete, 0 );
        happyhttp::Error error = m_connection->connect();
        if (error) {
            fprintf(stderr, "Connection Error: %s\n", error->c_str());
            return false;
        }
        while (m_connection->outstanding()) {
            happyhttp::Error err = m_connection->pump();
            if (err) {
                fprintf(stderr, "Error: %s\n", err->c_str());
                return false;
            }
        }
        return true;
    }
    
    bool connectWS(const std::string& url) {
        m_ws = easywsclient::WebSocket::from_url(url);
        return true;
    }

    easywsclient::WebSocket::pointer m_ws;
    happyhttp::Connection* m_connection;
    std::string m_recvBuf;
    int m_timeout;
};

/**
 * MPI implementaion
 */
#ifdef HIVE_ENABLE_MPI
class MPIImpl : public ConnectionIF
{
public:
    MPIImpl() {}
    ~MPIImpl() {}
    
    bool isValid() const {
        int rank = 0;
        MPI_Comm_rank(MPI_COMM_WORLD, &rank);
        return (rank == 0);
    }
    
    bool Connect(const std::string& url)
    {
        if (!isValid()) { return false; }
        return m_imp.Connect(url);
    }
    
    bool SendText(const std::string& text)
    {
        if (!isValid()) { return false; }
        return m_imp.SendText(text);
    }
    
    bool SendJSON(const std::string& text)
    {
        if (!isValid()) { return false; }
        return m_imp.SendText(text);
    }
    
    bool SendBinary(const Binary binary, int size)
    {
        if (!isValid()) { return false; }
        return m_imp.SendBinary(binary, size);
    }
    
    bool SendImage(const std::string& filepath)
    {
        if (!isValid()) { return false; }
        return m_imp.SendImage(filepath);
    }
    
    std::string Recv() {
        int rank = 0;
        MPI_Comm_rank(MPI_COMM_WORLD, &rank);
        
        std::string buf;
        int len = 0;
        if (rank == 0) {
            buf = m_imp.Recv();
            len = buf.size();
        }
        
        MPI_Bcast(&len, 1, MPI_INT, 0, MPI_COMM_WORLD);
        if (len > 0) {
            if (rank != 0) {
                buf.resize(len);
            }
            MPI_Bcast(&buf.at(0), len, MPI_BYTE, 0, MPI_COMM_WORLD);
        }
        
        if (len > 0) {
            return std::string(buf, len);
        } else {
            return "";
        }
    }
    
    bool SetTimeout(int timeout) {
        return m_imp.SetTimeout(timeout);
    }
    
    //int RecvSize() const {
    //    return static_cast<int>(m_recvBuf.size());
    //}
    
    bool Close() {
        return m_imp.Close();
    }
    
private:
    Impl m_imp;
};
#endif // HIVE_ENABLE_MPI

/// constructor.
/// switch mpi or default impl
Connection::Connection()
{
#ifdef HIVE_ENABLE_MPI
    m_imp = new MPIImpl();
#else
    m_imp = new Impl();
#endif
}

/// destructor
Connection::~Connection()
{
    delete m_imp;
}

bool Connection::Connect(const std::string& url)
{
    return m_imp->Connect(url);
}

bool Connection::SendText(const std::string& text)
{
    return m_imp->SendText(text);
}

bool Connection::SendJSON(const std::string& text)
{
    return m_imp->SendJSON(text);
}

bool Connection::SendBinary(const Binary binary, int size)
{
    return m_imp->SendBinary(binary, size);
}

bool Connection::SendImage(const std::string& filepath)
{
    return m_imp->SendImage(filepath);
}

std::string Connection::Recv()
{
    return m_imp->Recv();
}

bool Connection::Close()
{
    return m_imp->Close();
}

bool Connection::SetTimeout(int timeout)
{
    return m_imp->SetTimeout(timeout);
}

