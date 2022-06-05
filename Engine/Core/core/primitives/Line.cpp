#include "Line.hpp"

namespace Primitives
{
    Line::Line(int x0, int y0, int x1, int y1, int r, int g, int b, float alpha)
        : Primitive(Primitive::prim_type::LINE, false)
    {
        // calculate angle of line
        float angle = atan2(y1 - y0, x1 - x0);
        // calculate length of line
        float length = sqrt((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0));
        // r is the width of line
        float w = 100;
        // find midpoint of line
        float x = (x0 + x1) / 2;
        float y = (y0 + y1) / 2;
        rectanagles.push_back(Rectanagle(x, y, w, length, angle));
        rectanagles.back().setColor(r, g, b, alpha);
        rectanagles.back().setRotation(angle);
    }
    Line::Line(const Line &l)
        : Primitive(Primitive::prim_type::LINE, false)
    {
        this->rectanagles = l.rectanagles;
    }
    Line Line::operator=(const Line &l)
    {
        this->rectanagles = l.rectanagles;
        return *this;
    }
    void Line::Display()
    {
        for (int i = 0; i < this->rectanagles.size(); i++)
        {
            this->rectanagles[i].Display();
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
    void Line::setTexture(std::string texture)
    {
        for (int i = 0; i < this->rectanagles.size(); i++)
        {
            this->rectanagles[i].setTexture(texture);
        }
    }
}