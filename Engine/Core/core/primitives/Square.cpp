#include "Square.hpp"
#include <iostream>
namespace Primitives
{
    void Square::calculateMatrixes()
    {
        const int &width = window->getWindowWidth();
        const int &height = window->getWindowHeight();
        float ay = (size / float(height) / 2.f), ax = (size / float(width) / 2.f);
        float vert[] = {
            /*    cords                                                                                              |    RGBA color     |    TexturePos        */
            2 * (((x) - float(width) / 2) / float(width)) - ax, 2 * ((y - float(height)) / float(height)) - ay + 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, alpha, 1.0f, 1.0f,
            2 * (((x) - float(width) / 2) / float(width)) + ax, 2 * ((y - float(height)) / float(height)) - ay + 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, alpha, 0.0f, 1.0f,
            2 * (((x) - float(width) / 2) / float(width)) + ax, 2 * ((y - float(height)) / float(height)) + ay + 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, alpha, 0.0f, 0.0f,
            2 * (((x) - float(width) / 2) / float(width)) - ax, 2 * ((y - float(height)) / float(height)) + ay + 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, alpha, 1.0f, 0.0f};
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
}