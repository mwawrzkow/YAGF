#pragma once
#include "../base/Primitive.hpp"
#include "../WindowProperties.hpp"
#include "Square.hpp"
 namespace Primitives{ 
     class Line: protected Square{
         public:  
         /**
          * @brief Construct a new Line object
          * 
          * @param x0 - x coordinate of first point
          * @param y0 - y coordinate of first point
          * @param x1 - x coordinate of second point
          * @param y1 - y coordinate of second point
          * @param w - width of line
          * @param r - red color component
          * @param g - green color component
          * @param b - blue color component
          * @param alpha - alpha value of line
          */
          Line(int x0, int y0, int x1, int y1, int w ,int r, int g, int b, float alpha); 
          /**
           * @brief Display the Line
           * 
           */
          void Display(); 
          /**
           * @brief is the Line visible
           * 
           * @return true 
           * @return false 
           */
          bool isVisible() override; 
     };
 }