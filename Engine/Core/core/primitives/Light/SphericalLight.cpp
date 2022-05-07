#include "SphericalLight.hpp"
namespace Lights
{

    SphericalLight::SphericalLight(float x, float y, float lumen, float r, float g, float b)
    {
        this->x = x;
        this->y = y;
        this->lumen = lumen;
        this->r = r;
        this->g = g;
        this->b = b;
    }
    void SphericalLight::setPosition(float x, float y)
    {
        this->x = x;
        this->y = y;
    }
    void SphericalLight::Move(float x, float y)
    {
        this->x = this->x + x;
        this->y = this->y + y;
    }
    void SphericalLight::setColor(float r, float g, float b)
    {
        this->r = r;
        this->g = g;
        this->b = b;
    }
    void SphericalLight::setLumen(float lumen)
    {
        this->lumen = lumen;
    }
    void SphericalLight::setAlpha(float alpha)
    {
        this->alpha = alpha;
    }
    float SphericalLight::getX()
    {
        return this->x;
    }
    float SphericalLight::getY()
    {
        return this->y;
    }
    float SphericalLight::getLumen()
    {
        return this->lumen;
    }
    float SphericalLight::getAlpha()
    {
        return this->alpha;
    }
    float SphericalLight::getR()
    {
        return this->r;
    }
    float SphericalLight::getG()
    {
        return this->g;
    }
    float SphericalLight::getB()
    {
        return this->b;
    }
    SphericalLight::~SphericalLight()
    {
    }
    
} // namespace 
