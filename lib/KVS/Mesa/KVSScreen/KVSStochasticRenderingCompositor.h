
/**
 * @file KVSStochasticRenderingCompositor.h
 */
#ifndef _KVSSCREENCOMPOSITOR_H_
#define _KVSSCREENCOMPOSITOR_H_

#include "Ref.h"
#include "Buffer.h"
#include "BufferImageData.h"
#include "KVSScreen.h"
#include <kvs/Timer>

namespace kvs {
    class StochasticRenderingCompositor;
    namespace glut {
        class Screen;
    }
}

class KVSStochasticRenderingCompositor : public KVSScreen
{
public:
    KVSStochasticRenderingCompositor();
    ~KVSStochasticRenderingCompositor();
    
    bool EnableLODControl( bool isEnable );
    bool SetRepetitionLevel( int level );
    bool Composite();

private:
    kvs::StochasticRenderingCompositor* m_compositor;
    int m_repetitionLevel;
    kvs::Timer m_timer;
};

#endif //_KVSSCREENCOMPOSITOR_H_
