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
        float x, y , size; // x and y coordinates of the center of the square
        void calculateMatrixes(); 
        // R component of the color
        float r;
        // G component of the color
        float g;
        // B component of the color
        float b; 
        // Alpha value of the color
        float alpha = 1.0f;
        // rotation angle of the square
        float angle = 0.0f;
        /**
         * @brief  Rotate the vertices of the square
         * 
         * @param vertices - vertices of the square
         * @param rot - rotation matrix
         */
        void rotateVertices(std::vector<float>&  vertices);
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
        void setRotation(float);
        float getRotation();
        void rotate(float);
        virtual ~Square();
    };

}

#endif
