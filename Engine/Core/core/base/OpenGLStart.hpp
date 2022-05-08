#ifndef OpenGLStart_HPP
#define OpenGLStart_HPP
#include <string>
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
namespace OpenGLInstance
{

    GLFWwindow *InitWindow(int width, int height, std::string name = "A-Engine");
    void setClearColor(float, float, float, float);
    std::vector<GLuint> CreateAndCompileShaders(const char *, const char *);
    GLuint CreateProgramAndLinkShaders(const std::vector<GLuint>);
}

#endif