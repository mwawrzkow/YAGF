#include "DirectLight.hpp"


namespace Lights{ 
    //write all methods definied in Light.hpp
    DirectLight::DirectLight(float x, float y, float lumen, float r, float g, float b, float coneAngle, float coneWidth, float coneLength)
    {
        this->x = x;
        this->y = y;
        this->lumen = lumen;
        this->r = r;
        this->g = g;
        this->b = b;
        this->coneAngle = coneAngle;
        this->coneWidth = coneWidth;
        this->coneLength = coneLength;
    }
    void DirectLight::setPosition(float x, float y)
    {
        this->x = x;
        this->y = y;
    }
    void DirectLight::Move(float x, float y)
    {
        this->x += x;
        this->y += y;
    }
    void DirectLight::setColor(float r, float g, float b)
    {
        this->r = r;
        this->g = g;
        this->b = b;
    }
    void DirectLight::setLumen(float lumen)
    {
        this->lumen = lumen;
    }
    void DirectLight::setAlpha(float alpha)
    {
        this->alpha = alpha;
    }
    float DirectLight::getX()
    {
        return this->x;
    }
    float DirectLight::getY()
    {
        return this->y;
    }
    float DirectLight::getLumen()
    {
        return this->lumen;
    }
    float DirectLight::getAlpha()
    {
        return this->alpha;
    }
    float DirectLight::getR()
    {
        return this->r;
    }
    float DirectLight::getG()
    {
        return this->g;
    }
    float DirectLight::getB()
    {
        return this->b;
    }
    float DirectLight::getConeAngle()
    {
        return this->coneAngle;
    }
    float DirectLight::getConeWidth()
    {
        return this->coneWidth;
    }
    float DirectLight::getConeLength()
    {
        return this->coneLength;
    }
    DirectLight::~DirectLight()
    {
    }
    
}