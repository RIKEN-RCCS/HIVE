/**
 * @file KVSTransferFunction.h
 */
#ifndef _KVSTRANSFERFUNCTION_H_
#define _KVSTRANSFERFUNCTION_H_

#include "Ref.h"
#include "Buffer.h"
#include <string>

namespace kvs {
    class TransferFunction;
}

class KVSTransferFunction : public RefCount
{
 public:
    KVSTransferFunction();
    ~KVSTransferFunction();
    const char* TransferFunction() const;
    bool SetFile( std::string& file );

 private:
    kvs::TransferFunction* m_tf;
};

#endif //_KVSTRANSFERFUNCTION_H_
