#ifndef PRIMITIVE_HPP
#define PRIMITIVE_HPP
#include "vertexHandler.hpp"

class Primitive : public vertexHandler
{
protected:
    enum prim_type
    {
        RECTANAGLE,
        TRIANGLE,
        SQUARE,
    } TYPE;
public:
    float sin(float r);
    float cos(float r);
    Primitive(prim_type);
    virtual bool isVisible() = 0;
    virtual bool isNear(float, float, float) = 0;
    virtual ~Primitive();
};

#endif