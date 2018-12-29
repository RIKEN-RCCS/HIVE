/**
 * @file KVSTransferFunction.cpp
 */
#include "KVSTransferFunction.h"
#include <kvs/Message>
#include <kvs/TransferFunction>

/// constructor
KVSTransferFunction::KVSTransferFunction()
{
    kvs::TransferFunction* tf = new kvs::TransferFunction();
    if ( !tf )
    {
	kvsMessageError( "Cannot creat a transfer function.");
    }
    m_tf = tf;
}

/// destructor
KVSTransferFunction::~KVSTransferFunction()
{
    delete m_tf;
}

/**
 * get transfer function
 * @return transfer function pointer
 */ 
const char* KVSTransferFunction::TransferFunction() const
{
    return reinterpret_cast<const char*>( m_tf );
}

/**
 * set file path for import
 * @param file [in] filepath for import
 * @return success(true) or failed(false)
 */
bool KVSTransferFunction::SetFile( std::string& file )
{
    if ( file.empty() ) { return false; }
    m_tf->read( file );

    return true;
}
