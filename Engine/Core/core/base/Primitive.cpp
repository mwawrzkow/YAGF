
#include "Primitive.hpp"

// Primitive::Primitive(prim_type, float vert[], int sizofvert, int indc[], int sizofindc):vertexHandler(){
//     this->setVertexHandler(vert,sizofvert, indc, sizofindc);
// }
Primitive::Primitive(prim_type type)
{
    this->TYPE = type; 
}
Primitive::~Primitive()
{
}