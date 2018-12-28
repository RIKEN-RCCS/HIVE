/**
 * @file KVSStochasticRenderingCompositor.cpp
 */
#include "KVSStochasticRenderingCompositor.h"

#include <kvs/StochasticRenderingCompositor>
#include <kvs/glut/Screen>
#include <kvs/Timer>
#include <iostream>

#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

/// constructor
KVSStochasticRenderingCompositor::KVSStochasticRenderingCompositor() 
    : KVSScreen(),
      m_compositor(NULL),
      m_repetitionLevel(50)
{
    kvs::StochasticRenderingCompositor* compositor = new kvs::StochasticRenderingCompositor( m_screen->scene() );
    if ( !compositor )
    {
        kvsMessageError( "Cannot creat a stocastic rendering compositor.");
    }
    m_compositor = compositor;
}

/// destructor
KVSStochasticRenderingCompositor::~KVSStochasticRenderingCompositor()
{
    delete m_compositor;
}

/**
 * enable lod control or not
 * @param isEnable [in]
 * @return success(true) or failed(false)
 */
bool KVSStochasticRenderingCompositor::EnableLODControl( bool isEnable )
{
    if ( !m_compositor ) { return false; }
    if ( isEnable ) {
        m_compositor->enableLODControl();
    } else {
        m_compositor->disableLODControl();
    }
    return true;
}

/**
 * set repetition level
 * @param level [in] repetition level
 * @return success(true) or failed(false)
 */
bool KVSStochasticRenderingCompositor::SetRepetitionLevel( int level )
{
    if ( !m_compositor ) { return false; }
    m_compositor->setRepetitionLevel( level );
    m_repetitionLevel = level;
    return true;
}

/**
 * do composite
 * @return success or failed
 * @return success(true) or failed(false)
 */
bool KVSStochasticRenderingCompositor::Composite()
{
    if ( m_screen && m_compositor ) {
        m_timer.start();
        m_screen->setEvent( m_compositor );
        printf( "Composite!\n" );
        m_screen->hide();

        unsigned char* buf = m_img->ImageBuffer()->GetBuffer();

        if ( m_screen ) {
            m_screen->paintEvent();
        }
        const int w = m_img->Width();
        const int h = m_img->Height();

#ifdef __APPLE__
	glReadBuffer( GL_FRONT );
#endif
        glFlush();
        glFinish();
        m_timer.stop();
        std::cout << "[DEBUG] Render time : " << m_timer.msec() << " [ms]" << std::endl;
        m_timer.start();
        glReadPixels( 0, 0, w, h, GL_RGBA, GL_UNSIGNED_BYTE, buf );
        m_timer.stop();
        std::cout << "[DEBUG] Readback time : " << m_timer.msec() << " [ms]" << std::endl;
        glReadBuffer( GL_BACK );
        return true;
    }
    return false;
}
