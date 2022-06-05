#include "Line.hpp"


namespace Primitives{ 
    Line::Line(int x0, int y0, int x1, int y1, int r, int g, int b, float alpha)
    :Primitive(Primitive::prim_type::LINE,false)
    {
    }
    Line::Line(const Line& l)
    :Primitive(Primitive::prim_type::LINE,false)
    {
        this->squares = l.squares;
    }
    Line Line::operator=(const Line& l)
    {
        this->squares = l.squares;
        return *this;
    }
    void Line::Display()
    {
        for (int i = 0; i < this->squares.size(); i++)
        {
            this->squares[i].Display();
        }
    }
    bool Line::isVisible()
    {
        return true;
    }
    bool Line::isNear(float x, float y, float radius)
    {
        return true;
    }

}