/**
 * @file KVSUniColor.h
 */
#ifndef _KVSUNICOLOR_H_
#define _KVSUNICOLOR_H_

#include "Ref.h"
#include "Buffer.h"

namespace kvs {
    class GeometryObjectBase;
}

class KVSUniColor : public RefCount
{
public:
    KVSUniColor();
    ~KVSUniColor();

    const char* Object() const;
    bool SetColor( int red, int green, int blue, int opacity );
    bool SetGeometryObject( void* geometry );

private:
    void* m_input;
    kvs::GeometryObjectBase* m_object;
};

#endif //_KVSUNICOLOR_H_
