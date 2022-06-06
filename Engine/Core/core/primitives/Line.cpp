#include "Line.hpp"
// Line
namespace Primitives
{
    Line::Line(PointI p0, PointI p1, int w, float r, float g, float b, float alpha)
        //  ------- This implementation is required to not generate more warnings/errors. -------
        // float length = sqrt((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0));
        // float w = 100;
        // float x = (x0 + x1) / 2;
        // float y = (y0 + y1) / 2;
        // this->rectanagle = Rectanagle(x, y, w, length, angle);
        : rectanagle((p0.x + p1.x) / 2, (p0.y + p1.y) / 2, w, sqrt((p1.x - p0.x) * (p1.x - p0.x) + (p1.y - p0.y) * (p1.y - p0.y)))
    {
        float dx = p1.x - p0.x;
        float dy = p1.y - p0.y;
        float angle = atan2(dy / 2, dx / 2) - M_PI / 2;
        rectanagle.setColor(r, g, b, alpha);
        rectanagle.setRotation(angle);
    }
    Line::Line(const Line &l)
        : rectanagle(l.rectanagle)
    {
    }
    Line Line::operator=(const Line &l)
    {
        this->rectanagle = l.rectanagle;
        return *this;
    }
    void Line::Display()
    {
        this->rectanagle.Display();
    }
    void Line::setTexture(std::string texture)
    {

        this->rectanagle.setTexture(texture);
    }
    void Line::setColor(int r, int g, int b, float alpha)
    {
        this->rectanagle.setColor(r, g, b, alpha);
    }
}

// BezierLine
namespace Primitives
{
    BezierLine::BezierLine(PointI p0, PointI pc, PointI p1, int w, float r, float g, float b, float alpha)
        : type(QUADRATIC)
    {
        std::vector<PointI> points;
        for (float t = 0; t < 1; t += 0.1f)
        {
            float x = pow(1 - t, 2) * p0.x + 2 * t * (1 - t) * pc.x + pow(t, 2) * p1.x;
            float y = pow(1 - t, 2) * p0.y + 2 * t * (1 - t) * pc.y + pow(t, 2) * p1.y;
            points.push_back({static_cast<int>(x), static_cast<int>(y)});
        }
        for (int i = 0; i < points.size() - 1; i++)
        {
            this->rectanagles.push_back(Line(points[i], points[i + 1]));
        }
    }
    void BezierLine::Display()
    {
        for (auto &line : rectanagles)
        {
            line.Display();
        }
    }
    void BezierLine::setTexture(std::string texture)
    {
        for (auto &line : rectanagles)
        {
            line.setTexture(texture);
        }
    }
}