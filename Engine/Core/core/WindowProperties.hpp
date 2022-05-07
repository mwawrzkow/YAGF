#ifndef ELO_WINDOW_PROPERTIES_HPP
#define ELO_WINDOW_PROPERTIES_HPP
#include "OpenGLArrays/ArrayHandler.hpp"
#include "base/Texture.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
namespace Global
{
    class WindowProperties
    {
    private:
        WindowProperties();
    private:
        int windowHeight, windowWidth;
        /**
         * @brief  ArrayHandler for All GPU bindings
         * @note   
         * @retval None
         */ 
    public:
        WindowProperties(WindowProperties &other) = delete;
        void operator=(const WindowProperties &) = delete;
        static WindowProperties &getInstance();
        GPU::ArrayHandler* getAH();
        AEG::Textures* getTextures(); 
        ~WindowProperties();
        const int &getWindowHeight();
        const int &getWindowWidth();
        void setWindowWidth(int);
        void setWindowHeight(int);
    };

}

#endif
