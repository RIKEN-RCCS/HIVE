
/**
 * @file KVSScreen.cpp
 */
#ifndef _KVSSCREEN_H_
#define _KVSSCREEN_H_

#include "Ref.h"
#include "Buffer.h"
#include "BufferImageData.h"
#include <kvs/Timer>

namespace kvs {
    namespace glut {
        class Screen;
    }
}

class KVSScreen : public RefCount
{
public:
    KVSScreen();
    ~KVSScreen();
    
    int Width();
    int Height();
    BufferImageData* Image();
    bool Render();
    bool Register( void * obj, void* renderer );
    bool Clear();
    bool SetScreenSize( int width, int height );

protected:
    RefPtr<BufferImageData> m_img;
    kvs::glut::Screen* m_screen;
    std::vector<std::pair<int, int> > m_regstered;
    kvs::Timer m_timer;
};

#endif //_KVSSCREEN_H_
