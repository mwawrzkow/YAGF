#pragma once

namespace Lights
{
    class GlobalLight
    {
    private:
        float x, y, lumen;
        float alpha = 1.0f;
        float r, g, b;

    public:
        GlobalLight(float, float, float, float, float, float);
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
        ~GlobalLight();
    };

} // namespace Lights
