#ifndef SQUARE_HPP
#define SQUARE_HPP
#include "../base/Primitive.hpp"
#include "../WindowProperties.hpp"
#include "../base/Point.hpp"
#include <memory>
#include <array>
namespace Primitives
{
    class Square : private Primitive
    {
    private:
        typedef std::array<std::unique_ptr<PointF>, 4> verticies_ptr_array;
        typedef std::array<std::unique_ptr<ColorRGBAF>,4> colors_ptr_array; 
        Global::WindowProperties *window;
        float x, y, size; // x and y coordinates of the center of the square
        verticies_ptr_array verticies_ptr = {};
        colors_ptr_array color_ptr;
        void calculateMatrixes();
        float angle = 0.0f;
        /**
         * @brief  Rotate the vertices of the square
         *
         * @param vertices - vertices of the square
         * @param rot - rotation matrix
         */
        verticies_ptr_array rotateVertices();

    public:
        Square(float, float, float, float);
        /**
         * @brief Set the Position object
         * @param float x - x coordinate of the center of the square
         * @param float y - y coordinate of the center of the square
         */
        void setPosition(float, float);
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
        /**
         * @brief Set R color value
         * @param r - red value
         */
        void setR(float);
        /**
         * @brief Set G color value
         * @param g - green value
         */
        void setG(float);
        /*
         * @brief Set B color value
         * @param b - blue value
         */
        void setB(float);
        /**
         * @brief Set the Color value
         * @param float r - red value
         * @param float g - green value
         * @param float b - blue value
         * @param float alpha - alpha value
         */
        void setColor(float, float, float, float = 1.0f);
        Square(const Square &s);
        Square &operator=(const Square &s);
        virtual ~Square();
    };

}

#endif
