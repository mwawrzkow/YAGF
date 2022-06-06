#pragma once
#include "../base/Primitive.hpp"
#include "../WindowProperties.hpp"
#include "Square.hpp"
namespace Primitives
{
    class Line : public Renderable
    {
    public:
        /**
         * @brief Construct a new Line object
         *
         * @param x0 - x coordinate of first point
         * @param y0 - y coordinate of first point
         * @param x1 - x coordinate of second point
         * @param y1 - y coordinate of second point
         * @param w - width of line
         * @param r - red color component
         * @param g - green color component
         * @param b - blue color component
         * @param alpha - alpha value of line
         */
        Line(PointI p0, PointI p1, int w = 100, float r = 1.0f , float g = 1.0f, float b = 1.0f , float alpha = 1.0f);
        Line(const Line &);
        Line operator=(const Line &);
        /**
         * @brief Display the Line
         *
         */
        void Display() override;
        void setTexture(std::string);
        void setColor(int r, int g, int b, float alpha);

    private:
        Rectanagle rectanagle;
    };
    class BezierLine : public Renderable
    {
    private:
        enum BezierLineType
        {
            QUADRATIC,
            CUBIC
        } type;

    public:
        BezierLine(PointI p0, PointI pc, PointI p1, int w = 100, float r = 1.0f, float g = 1.0f , float b  = 1.0f, float alpha = 1.0f);
        void Display() override;
        void setTexture(std::string);

    // private:

    private:
        std::vector<Line> rectanagles;
    };
}