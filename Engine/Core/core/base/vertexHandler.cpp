#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <fstream>
#include <sstream>
#include "vertexHandler.hpp"
#include <chrono>
#include <thread>
#include "../WindowProperties.hpp"
vertexHandler::vertexHandler(/* args */)
{
    Global::WindowProperties* WP = &Global::WindowProperties::getInstance(); 
    GPU::ArrayHandler* AH = WP->getAH(); 
    if (!AH->areFreeBuffers())
        AH->alocateBuffer(100);
    auto Buffers = AH->getFirstAvailavleBuffer(); 
    this->VAO = Buffers->getVAO();
    this->VBO = Buffers->getVBO();
    this->EBO = Buffers->getEBO();
    #if DEBUG
    printf("VAO: %i,  VBO: %i, EBO: %i \n", VAO, VBO, EBO);
    #endif
}
vertexHandler::vertexHandler(const vertexHandler &other)
{
    this->VAO = other.VAO;
    this->VBO = other.VBO;
    this->EBO = other.EBO;
    this->texture = other.texture;
}

vertexHandler::~vertexHandler()
{
    // glDeleteVertexArrays(1, &VAO);
    // glDeleteBuffers(1, &VBO);
    // glDeleteBuffers(1,&EBO);
}

void vertexHandler::setVertexHandler(float vertices[], int VerticesSize, unsigned int indices[], int indicesSize)
{
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, VerticesSize, vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesSize, indices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // texture coord attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)(7 * sizeof(float)));
    glEnableVertexAttribArray(2);
}
void vertexHandler::setTextureData(const std::string data)
{
    AEG::Textures* TextureHandler = Global::WindowProperties::getInstance().getTextures(); 
    TextureHandler->loadTexture(data); 
    this->texture = TextureHandler->getTextureIndex(data); 
}
int vertexHandler::getTexture()
{
    return texture;
}
int vertexHandler::getVBO()
{
    return VBO;
}
int vertexHandler::getEBO()
{
    return EBO;
}
int vertexHandler::getVAO()
{
    return VAO;
}