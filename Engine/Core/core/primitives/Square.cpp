#include "Square.hpp"
#include <iostream>
#include <cmath>
#include <iostream>
namespace Primitives
{
    Square::verticies_ptr_array Square::rotateVertices()
    {
        Square::verticies_ptr_array rotated_vertices = {};
        for (int i = 0; i < 4; i++)
            rotated_vertices[i] = std::make_unique<PointF>(PointF{verticies_ptr[i]->x, verticies_ptr[i]->y});
        float px = (rotated_vertices[0]->x + rotated_vertices[1]->x) / 2;
        float py = (rotated_vertices[0]->y + rotated_vertices[3]->y) / 2;
        for (int i = 0; i < 4; i++)
        {
            float x1 = rotated_vertices[i]->x;
            float y1 = rotated_vertices[i]->y;
            rotated_vertices[i]->x = px + (x1 - px) * cos(angle) - (y1 - py) * sin(angle);
            rotated_vertices[i]->y = py + (x1 - px) * sin(angle) + (y1 - py) * cos(angle);
        }
        return rotated_vertices;
    }
    void Square::calculateMatrixes()
    {
        const int &width = window->getWindowWidth();
        const int &height = window->getWindowHeight();
        auto vertices = rotateVertices();
        float vert[] = {
            /*    cords                   |    RGBA color | TexturePos */
            vertices[0]->x / width, vertices[0]->y / height, 0.0f, color_ptr[0]->color.r, color_ptr[0]->color.g, color_ptr[0]->color.b, color_ptr[0]->alpha, 1.0f, 1.0f,
            vertices[1]->x / width, vertices[1]->y / height, 0.0f, color_ptr[1]->color.r, color_ptr[1]->color.g, color_ptr[1]->color.b, color_ptr[1]->alpha, 0.0f, 1.0f,
            vertices[2]->x / width, vertices[2]->y / height, 0.0f, color_ptr[2]->color.r, color_ptr[2]->color.g, color_ptr[2]->color.b, color_ptr[2]->alpha, 0.0f, 0.0f,
            vertices[3]->x / width, vertices[3]->y / height, 0.0f, color_ptr[3]->color.r, color_ptr[3]->color.g, color_ptr[3]->color.b, color_ptr[3]->alpha, 1.0f, 0.0f};
        unsigned int inc[] = {
            0, 1, 2,
            0, 2, 3};
        this->setVertexHandler(vert, sizeof(vert), inc, sizeof(inc));
    }
    Square::Square(float x, float y, float a, float alpha)
        : Primitive(Primitive::prim_type::SQUARE)
    {
        for (int i = 0; i < 4; i++)
            color_ptr[i] = std::make_unique<ColorRGBAF>(
                ColorRGBAF{
                    {1.0f,
                     1.0f,
                     1.0f},
                    alpha});
        this->x = x;
        this->y = y;
        this->size = a;
        this->verticies_ptr[0] = std::make_unique<PointF>(PointF{x - a / 2.0f, y - a / 2.0f});
        this->verticies_ptr[1] = std::make_unique<PointF>(PointF{x + a / 2.0f, y - a / 2.0f});
        this->verticies_ptr[2] = std::make_unique<PointF>(PointF{x + a / 2.0f, y + a / 2.0f});
        this->verticies_ptr[3] = std::make_unique<PointF>(PointF{x - a / 2.0f, y + a / 2.0f});
        window = &Global::WindowProperties::getInstance();
        calculateMatrixes();
    }
    Square::Square(const Square &s)
        : Primitive(Primitive::prim_type::SQUARE)
    {
        for (int i = 0; i < 4; i++)
        {
            this->verticies_ptr[i] = std::make_unique<PointF>(PointF{s.verticies_ptr[i]->x, s.verticies_ptr[i]->y});
            this->color_ptr[i] = std::make_unique<ColorRGBAF>(
                ColorRGBAF{
                    {s.color_ptr[i]->color.r,
                     s.color_ptr[i]->color.g,
                     s.color_ptr[i]->color.b},
                    s.color_ptr[i]->alpha});
        }
        this->x = s.x;
        this->y = s.y;
        this->size = s.size;
        window = &Global::WindowProperties::getInstance();
        calculateMatrixes();
    }
    void Square::setTexture(std::string data)
    {
        this->setTextureData(data);
    }
    void Square::setPosition(float x, float y)
    {
        this->x = x;
        this->y = y;
        if (isVisible())
            calculateMatrixes();
    }
    void Square::Move(float x, float y)
    {
        setPosition(this->x + x, this->y + y);
    }
    void Square::setR(float r)
    {
        for (auto &c : color_ptr)
        {
            c->color.r = r;
        }

        if (isVisible())
            calculateMatrixes();
    }
    void Square::setG(float g)
    {
        for (auto &c : color_ptr)
        {
            c->color.g = g;
        }
        if (isVisible())
            calculateMatrixes();
    }
    void Square::setB(float b)
    {
        for (auto &c : color_ptr)
        {
            c->color.b = b;
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
        if ((x > -size) && (x < width + size))
            return y > -size && y < height + size;
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
        for (auto &c : color_ptr)
        {
            c->alpha = alpha;
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
        for (auto &c : color_ptr)
        {
            c->color.r = r;
            c->color.g = g;
            c->color.b = b;
            c->alpha = alpha;
        }
        if (isVisible())
            calculateMatrixes();
    }
    Square &Square::operator=(const Square &s)
    {
        for (int i = 0; i < 4; i++)
        {
            this->verticies_ptr[i] = std::make_unique<PointF>(PointF{s.verticies_ptr[i]->x, s.verticies_ptr[i]->y});
            this->color_ptr[i] = std::make_unique<ColorRGBAF>(
                ColorRGBAF{
                    {s.color_ptr[i]->color.r,
                     s.color_ptr[i]->color.g,
                     s.color_ptr[i]->color.b},
                    s.color_ptr[i]->alpha});
        }
        this->x = s.x;
        this->y = s.y;
        this->size = s.size;
        window = &Global::WindowProperties::getInstance();
        calculateMatrixes();
        return *this;
    }
}