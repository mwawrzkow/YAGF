#include "WindowProperties.hpp"

namespace Global
{

    WindowProperties::WindowProperties(/* args */)
    {
    }

    WindowProperties::~WindowProperties()
    {
    }

    WindowProperties &WindowProperties::getInstance()
    {
      static WindowProperties INSTANCE;
      return INSTANCE;
    }
    const int &WindowProperties::getWindowHeight()
    {
        return windowHeight;
    }
    const int &WindowProperties::getWindowWidth()
    {
        return windowWidth;
    }
    void WindowProperties::setWindowWidth(int width){ 
        this->windowWidth = width; 
    }
    void WindowProperties::setWindowHeight(int height){ 
        this->windowHeight = height;
    }
    GPU::ArrayHandler* WindowProperties::getAH(){ 
        static GPU::ArrayHandler AH; 
        return &AH; 
    }
    AEG::Textures* WindowProperties::getTextures(){ 
        static AEG::Textures Textures; 
        return &Textures;
    }
}