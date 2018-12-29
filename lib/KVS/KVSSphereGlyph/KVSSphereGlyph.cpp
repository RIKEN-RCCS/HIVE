/**
 * @file KVSSphereGlyph.cpp
  */
#include "KVSSphereGlyph.h"
#include <kvs/Message>
#include <kvs/SphereGlyph>

/// constructor
KVSSphereGlyph::KVSSphereGlyph()
{
    // Create an sphere glyph renderer.
    kvs::SphereGlyph* glyph = new kvs::SphereGlyph();
    if ( !glyph )
    {
        kvsMessageError( "Cannot creat a glyph renderer." );
    }
    m_glyph = glyph;

    // Set properties.
    const kvs::TransferFunction transfer_function( 256 );
    glyph->setTransferFunction( transfer_function );
    glyph->setNumberOfSlices( 20 );
    glyph->setNumberOfStacks( 20 );
}

/// destructor
KVSSphereGlyph::~KVSSphereGlyph()
{
    delete m_glyph;
}

/**
 * get renderer
 * @return renderer pointer
 */ 
const char* KVSSphereGlyph::Renderer() const
{
    return reinterpret_cast<const char*>( m_glyph );
}
