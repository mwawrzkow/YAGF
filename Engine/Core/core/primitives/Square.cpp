#include "Square.hpp"
#include <iostream>
#include <cmath>
#include <iostream>
namespace Primitives
{
    void Square::rotateVertices(std::vector<float> &vertices)
    {
        // calculate center of the square using x and y coordinates from vertices
        float px = (vertices[0]+vertices[2])/2;
        float py = (vertices[1]+vertices[5])/2;
        
        // given vertices which are set in pairs, calculate the new vertices using the rotation matrix
        for (int i = 0; i < 4; i++)
        {
            float x1 = vertices[i*2];
            float y1 = vertices[i*2+1];
            vertices[i * 2] = px + (x1 -px)*cos(angle) - (y1 -py)*sin(angle);
            vertices[(i * 2) + 1] = py + (x1 -px)*sin(angle) + (y1 -py)*cos(angle);
        }
    }
    void Square::calculateMatrixes()
    {
        const int &width = window->getWindowWidth();
        const int &height = window->getWindowHeight();
        float ay = (size / float(height) / 2.f), ax = (size / float(width) / 2.f);
        std::vector<float> vertices = {
            2 * (((x) - float(width) / 2) / float(width)) - ax, 2 * ((y - float(height)) / float(height)) - ay + 1.0f,
            2 * (((x) - float(width) / 2) / float(width)) + ax, 2 * ((y - float(height)) / float(height)) - ay + 1.0f,
            2 * (((x) - float(width) / 2) / float(width)) + ax, 2 * ((y - float(height)) / float(height)) + ay + 1.0f,
            2 * (((x) - float(width) / 2) / float(width)) - ax, 2 * ((y - float(height)) / float(height)) + ay + 1.0f};
        rotateVertices(vertices);
        float vert[] = {
            /*    cords                   |    RGBA color     |    TexturePos        */
            vertices[0], vertices[1], 0.0f, 1.0f, 1.0f, 1.0f, alpha, 1.0f, 1.0f,
            vertices[2], vertices[3], 0.0f, 1.0f, 1.0f, 1.0f, alpha, 0.0f, 1.0f,
            vertices[4], vertices[5], 0.0f, 1.0f, 1.0f, 1.0f, alpha, 0.0f, 0.0f,
            vertices[6], vertices[7], 0.0f, 1.0f, 1.0f, 1.0f, alpha, 1.0f, 0.0f};
        unsigned int inc[] = {
            0, 1, 2,
            0, 2, 3};
        this->setVertexHandler(vert, sizeof(vert), inc, sizeof(inc));
    }
    Square::Square(float x, float y, float a, float alpha)
        : Primitive(Primitive::prim_type::SQUARE)
    {
        this->x = x;
        this->y = y;
        this->size = a;
        this->alpha = alpha;
        window = &Global::WindowProperties::getInstance();
        calculateMatrixes();
        std::cout << std::endl;
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
        this->alpha = alpha;
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
}