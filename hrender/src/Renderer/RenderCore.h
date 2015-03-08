#pragma once

/*
    RenderCore.h
*/

#include "RenderMode.h"

class RenderObject;

class RenderCore
{
public:
    static RenderCore* GetInstance();
    
    void AddRenderObject(RenderObject* robj);
    void Render();
    void ClearRenderObject();
    
    void ClearBuffers(); // Clear RenderBuffer resouces
    
private:
    RenderCore();
    ~RenderCore();

    class Impl;
    Impl* m_imp;
};
