/**
 * @file KVSScreen.cpp
 */
#include <GL/glew.h>

#include "KVSScreen.h"
#include <kvs/Message>
#include <kvs/glut/Application>
#include <kvs/glut/Screen>
#include <kvs/Timer>
#include <iostream>

#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

/// constructor
KVSScreen::KVSScreen()
{
    m_screen = NULL;
    m_img = BufferImageData::CreateInstance();
    m_img->Create( BufferImageData::RGBA8, 512, 512 );

    int argc = 1;
    char arg1[] = "KVSScreen";
    char* argv[] = { arg1 };
    kvs::glut::Application app( argc, argv );
    kvs::glut::Screen* screen = new kvs::glut::Screen( &app );
    screen->setGeometry( 0, 0, m_img->Width(), m_img->Height() );
    screen->show();
    screen->hide();
    glewInit();
    m_screen = screen;
}

/// destructor
KVSScreen::~KVSScreen()
{
    delete m_screen;
}

/**
 * get width
 * @retval int Width
 */
int KVSScreen::Width()
{
    return m_img->Width();
}

/**
 * get height
 * @retval int Height
 */
int KVSScreen::Height()
{
    return m_img->Height();
}

/**
 * get image
 * @return BufferImageData pointer
 */
BufferImageData* KVSScreen::Image()
{
    return m_img;
}

/**
 * render screen
 * @return success or failed
 */
bool KVSScreen::Render()
{
    if ( !m_screen ) { return false; }
    m_timer.start();
    m_screen->hide();

    printf( "Render!\n" );

    unsigned char* buf = m_img->ImageBuffer()->GetBuffer();

    if ( m_screen ) {
        m_screen->paintEvent(); // force redraw
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

/**
 * register object and renderer for render
 * @param obj [in] object
 * @param renderer [in] renderer
 * @return success or failed
 */
bool KVSScreen::Register( void * obj, void* renderer )
{
    if ( !m_screen ) { return false; }
    printf( "render called\n" );
    if ( obj && renderer ) {
        kvs::ObjectBase* object = reinterpret_cast<kvs::ObjectBase*>( obj );
        kvs::RendererBase* renderBase = reinterpret_cast<kvs::RendererBase*>( renderer );
        if ( object && renderBase ) {
            std::pair<int,int> result = m_screen->registerObject( object, renderBase );
            printf( "Register success, %d, %d \n", result.first, result.second );

            m_regstered.push_back( result );

            return true;
        }
    }
    return false;
}

/**
 * set screen size
 * @return success or failed
 */
bool KVSScreen::SetScreenSize(int width, int height)
{
    if ( !m_screen ) { return false; }
    if ( width != m_img->Width() || height != m_img->Height() ) {
        printf("create new image %d, %d \n", width, height);
        RefPtr<BufferImageData> image = BufferImageData::CreateInstance();
        image->Create( BufferImageData::RGBA8, width, height );
        m_screen->resize( image->Width(), image->Height() );
        m_screen->resizeEvent( image->Width(), image->Height() );
        m_screen->setGeometry( 0, 0, width, height );
        m_img = image;
    }
    return true;
}

/**
 * clear render objects
 * @return success or failed
 */
bool KVSScreen::Clear()
{
    if ( !m_screen ) { return false; }
    std::vector<std::pair<int, int> >::iterator it, eit = m_regstered.end();
    for (it = m_regstered.begin(); it != eit; ++it) {
        m_screen->scene()->removeObject( it->first, false, false );
    }
    m_regstered.clear();
    m_screen->reset();
    return true;
}
