#ifndef vertexHandler_HPP
#define vertexHandler_HPP
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <fstream>
#include <sstream>
class vertexHandler
{
private:
    /* data */
    unsigned int VBO, VAO, EBO;
    unsigned int texture;

public:
    vertexHandler(/* args */);
    vertexHandler(const vertexHandler &other);
    ~vertexHandler();
    void setVertexHandler(float vertices[], int VerticesSize, unsigned int indices[], int indicesSize);
    void setTextureData(const std::string);
    int getTexture(); 
    int getVBO(); 
    int getEBO(); 
    int getVAO(); 
};

#endif