#ifndef SQUARE_HPP
#define SQUARE_HPP
#include "../base/Primitive.hpp"
#include "../WindowProperties.hpp"

namespace Primitives
{
    class Square : private Primitive
    {
    private:
        Global::WindowProperties *window;
        float x, y , size; 
        void calculateMatrixes(); 
        float alpha = 1.0f;
    public:
        Square(float, float, float, float);
        void setPosition(float,float);
        void Move(float, float); 
        void setTexture(std::string); 
        bool isVisible() override; 
        void Display();
        float getX();
        float getY();
        void setAlpha(float);
        bool isNear(float, float, float) override;
        ~Square();
    };

}

#endif
