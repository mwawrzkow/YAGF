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
        float r;
        float g;
        float b; 
        float alpha = 1.0f;
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
        /**
         * @brief Set the Position object
         * @param float x - x coordinate of the center of the square
         * @param float y - y coordinate of the center of the square
         */
        void setPosition(float,float);
        /**
         * @brief move the square relative to the current position
         * @param float x - offset in x direction
         * @param float y - offset in y direction
         */
        void Move(float, float); 
        /**
         * @brief Set the Texture object
         * @param std::string data - path to the texture
         */
        void setTexture(std::string); 
        /**
         * @brief is Object on the screen
         * 
         * @return true - if object is on the screen
         * @return false - if object is not on the screen
         */
        bool isVisible() override; 
        /**
         * @brief Draw the square
         */
        void Display();
        float getX();
        float getY();
        /**
         * @brief Set the Alpha value
         * @param float alpha - alpha value
         */
        void setAlpha(float);
        /**
         * @brief is the Object int the radius
         * 
         * @param float x - x coordinate of the center of the circle
         * @param float y - y coordinate of the center of the circle
         * @param float radius - radius of the circle
         * 
         * @return true - if object is in the radius
         * @return false  - if object is not in the radius
         */
        bool isNear(float, float, float) override;
        /**
         * @brief Set the rotation of the square
         * 
         * @param float angle - angle in radians of the square
         */
        void setRotation(float);
        float getRotation();
        /**
         * @brief rotate the square relative to the current rotation
         * 
         * @param float angle - angle in radians
         */
        void rotate(float);
        virtual ~Square();
    };

}

#endif
