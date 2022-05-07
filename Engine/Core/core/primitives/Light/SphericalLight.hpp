#pragma once

namespace Lights
{

    class SphericalLight
    {
    private:
        float x, y, lumen;
        float alpha = 1.0f;
        float r, g, b;

    public:
        SphericalLight(float x, float y, float lumen, float r, float g, float b);
        void setPosition(float, float);
        void Move(float, float);
        void setColor(float, float, float);
        void setLumen(float);
        void setAlpha(float);
        float getX();
        float getY();
        float getLumen();
        float getAlpha();
        float getR();
        float getG();
        float getB();
        ~SphericalLight();
    };
}