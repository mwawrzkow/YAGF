
namespace Primitives{ 
    Line::Line(int x0, int y0, int x1, int y1, int r, int g, int b, float alpha)
        :Primitive(Primitive::prim_type::LINE), Square(x0, y0, 1, alpha)
    {
        this->x0 = x0;
        this->y0 = y0;
        this->x1 = x1;
        this->y1 = y1;
        this->r = r;
        this->g = g;
        this->b = b;
        this->alpha = alpha;
        window = &Global::WindowProperties::getInstance();
        calculateMatrixes();
    }

}