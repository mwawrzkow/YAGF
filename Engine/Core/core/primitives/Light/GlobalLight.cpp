#include "GlobalLight.hpp"


namespace Lights
{
    //define all methods from GlobalLight.hpp
    GlobalLight::GlobalLight(float x, float y, float lumen, float r, float g, float b)
    {
        this->x = x;
        this->y = y;
        this->lumen = lumen;
        this->r = r;
        this->g = g;
        this->b = b;
    }

    void GlobalLight::setPosition(float x, float y)
    {
        this->x = x;
        this->y = y;
    }

    void GlobalLight::Move(float x, float y)
    {
        this->x += x;
        this->y += y;
    }

    void GlobalLight::setColor(float r, float g, float b)
    {
        this->r = r;
        this->g = g;
        this->b = b;
    }

    void GlobalLight::setLumen(float lumen)
    {
        this->lumen = lumen;
    }

    void GlobalLight::setAlpha(float alpha)
    {
        this->alpha = alpha;
    }

    float GlobalLight::getX()
    {
        return this->x;
    }

    float GlobalLight::getY()
    {
        return this->y;
    }

    float GlobalLight::getLumen()
    {
        return this->lumen;
    }

    float GlobalLight::getAlpha()
    {
        return this->alpha;
    }

    float GlobalLight::getR()
    {
        return this->r;
    }

    float GlobalLight::getG()
    {
        return this->g;
    }

    float GlobalLight::getB()
    {
        return this->b;
    }

    GlobalLight::~GlobalLight()
    {
    }
}