#include "Square.hpp"
#include <iostream>
#include <cmath>
#include <iostream>
namespace Primitives
{
    Square::verticies_array Square::rotateVertices()
    {
        Square::verticies_array rotated_vertices = {};
        for (int i = 0; i < 4; i++)
            rotated_vertices[i] = {verticies_arr[i].x, verticies_arr[i].y};
        float px = (rotated_vertices[0].x + rotated_vertices[1].x) / 2;
        float py = (rotated_vertices[0].y + rotated_vertices[3].y) / 2;
        for (int i = 0; i < 4; i++)
        {
            float x1 = rotated_vertices[i].x;
            float y1 = rotated_vertices[i].y;
            rotated_vertices[i].x = px + (x1 - px) * cos(angle) - (y1 - py) * sin(angle);
            rotated_vertices[i].y = py + (x1 - px) * sin(angle) + (y1 - py) * cos(angle);
        }
        return rotated_vertices;
    }
    void Square::calculateMatrixes()
    {
        const int &width = window->getWindowWidth();
        const int &height = window->getWindowHeight();
        auto vertices = rotateVertices();
        float vert_ptr[] = {
            vertices[0].x / float(width) - 1.0f, vertices[0].y / float(height) - 1.0f,
            vertices[1].x / float(width) - 1.0f, vertices[1].y / float(height) - 1.0f,
            vertices[2].x / float(width) - 1.0f, vertices[2].y / float(height) - 1.0f,
            vertices[3].x / float(width) - 1.0f, vertices[3].y / float(height) - 1.0f};
        float vert[] = {
            /*    cords                   |    RGBA color                                                                       | TexturePos*/
            vert_ptr[0], vert_ptr[1], 0.0f, color_arr[0].color.r, color_arr[0].color.g, color_arr[0].color.b, color_arr[0].alpha, 1.0f, 1.0f,
            vert_ptr[2], vert_ptr[3], 0.0f, color_arr[1].color.r, color_arr[1].color.g, color_arr[1].color.b, color_arr[1].alpha, 0.0f, 1.0f,
            vert_ptr[4], vert_ptr[5], 0.0f, color_arr[2].color.r, color_arr[2].color.g, color_arr[2].color.b, color_arr[2].alpha, 0.0f, 0.0f,
            vert_ptr[6], vert_ptr[7], 0.0f, color_arr[3].color.r, color_arr[3].color.g, color_arr[3].color.b, color_arr[3].alpha, 1.0f, 0.0f};
        this->setVertexHandler(vert, sizeof(vert), this->inc, sizeof(this->inc));
    }
    void Square::calculateVerticesArr()
    {
        verticies_arr[0] = {x - size / 2, y - size / 2};
        verticies_arr[1] = {x + size / 2, y - size / 2};
        verticies_arr[2] = {x + size / 2, y + size / 2};
        verticies_arr[3] = {x - size / 2, y + size / 2};
    }
    Square::Square(float x, float y, float a, float alpha)
        : Primitive(Primitive::prim_type::SQUARE)
    {
        for (int i = 0; i < 4; i++)
            color_arr[i] =
                ColorRGBAF{
                    {1.0f,
                     1.0f,
                     1.0f},
                    alpha};
        this->x = x;
        this->y = y;
        this->size = a;
        calculateVerticesArr();
        window = &Global::WindowProperties::getInstance();
        calculateMatrixes();
    }
    Square::Square(const Square &s)
        : Primitive(s)
    {
        for (int i = 0; i < 4; i++)
        {
            this->verticies_arr[i] = PointF{s.verticies_arr[i].x, s.verticies_arr[i].y};
            this->color_arr[i] =
                ColorRGBAF{
                    {s.color_arr[i].color.r,
                     s.color_arr[i].color.g,
                     s.color_arr[i].color.b},
                    s.color_arr[i].alpha};
        }
        this->x = s.x;
        this->y = s.y;
        this->size = s.size;
        this->window = &Global::WindowProperties::getInstance();
        this->calculateMatrixes();
    }
    Square &Square::operator=(const Square &s)
    {
        this->TYPE = s.TYPE;
        for (int i = 0; i < 4; i++)
        {
            this->verticies_arr[i] = PointF{s.verticies_arr[i].x, s.verticies_arr[i].y};
            this->color_arr[i] =
                ColorRGBAF{
                    {s.color_arr[i].color.r,
                     s.color_arr[i].color.g,
                     s.color_arr[i].color.b},
                    s.color_arr[i].alpha};
        }
        this->x = s.x;
        this->y = s.y;
        this->size = s.size;
        this->window = &Global::WindowProperties::getInstance();
        this->calculateMatrixes();
        return *this;
    }
    void Square::setTexture(std::string data)
    {
        this->setTextureData(data);
    }
    void Square::setPosition(float x, float y)
    {
        this->x = x;
        this->y = y;
        calculateVerticesArr();
        if (isVisible())
            calculateMatrixes();
    }
    void Square::Move(float x, float y)
    {
        setPosition(this->x + x, this->y + y);
    }
    void Square::setR(float r)
    {
        for (auto &c : color_arr)
        {
            c.color.r = r;
        }

        if (isVisible())
            calculateMatrixes();
    }
    void Square::setG(float g)
    {
        for (auto &c : color_arr)
        {
            c.color.g = g;
        }
        if (isVisible())
            calculateMatrixes();
    }
    void Square::setB(float b)
    {
        for (auto &c : color_arr)
        {
            c.color.b = b;
        }
        if (isVisible())
            calculateMatrixes();
    }
    Square::~Square()
    {
    }
    bool Square::isVisible()
    {
        const int &width = window->getWindowWidth();
        const int &height = window->getWindowHeight();
        if (x >= 0 || x <= width)
            if (y >= 0 || y <= height)
                return true;
        return false;
    }
    void Square::Display()
    {
        glBindTexture(GL_TEXTURE_2D, this->getTexture());
        glBindVertexArray(this->getVAO());
        glBindBuffer(GL_ARRAY_BUFFER, this->getVBO());
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->getEBO());
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }
    float Square::getX()
    {
        return x;
    }
    float Square::getY()
    {
        return y;
    }
    bool Square::isNear(float x, float y, float radius)
    {
        if (x > this->x - radius && x < this->x + radius)
            if (y > this->y - radius && y < this->y + radius)
                return true;
        return false;
    }
    void Square::setAlpha(float alpha)
    {
        for (auto &c : color_arr)
        {
            c.alpha = alpha;
        }
        if (isVisible())
            calculateMatrixes();
    }
    void Square::setRotation(float angle)
    {
        if (angle > 2 * M_PI)
            angle = angle - (2 * M_PI);
        if (angle < -2 * M_PI)
            angle = angle + (2 * M_PI);
        this->angle = angle;
        if (isVisible())
            calculateMatrixes();
    }
    float Square::getRotation()
    {
        return angle;
    }
    void Square::rotate(float angle)
    {
        setRotation(this->angle + angle);
    }
    void Square::setColor(float r, float g, float b, float alpha)
    {
        for (auto &c : color_arr)
        {
            c.color.r = r;
            c.color.g = g;
            c.color.b = b;
            c.alpha = alpha;
        }
        if (isVisible())
            calculateMatrixes();
    }
    void Square::SetVerticeColor(int index, float value, ColorType colorType)
    {
        color_arr[index][colorType] = value;
    }
}