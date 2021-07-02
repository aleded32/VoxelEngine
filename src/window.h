#pragma once
#include <iostream>
#include "vertexBuffer.h"
#include "vertexArray.h"
#include "vertexBufferLayout.h"
#include "indexBuffer.h"
#include "shader.h"
#include "texture.h"


class window 
{
public:

    window(int width, int height, const char* name);
    ~window();

    void onStart();
    void onUpdate();
    void onRender();

    inline GLFWwindow* getWindow() {return m_window; }
    inline const int getWidth() const& { return m_width; }
    inline const int getHeight() const& { return m_height; }

private:

    //window specific variables
    GLFWwindow* m_window;
    int m_width, m_height;
    const char* m_name;
    GLenum err;

    //normal variables for application use
    vertexArray* va;
    vertexBuffer* vb;
    vertexBufferLayout layout;
    indexBuffer* ib;
    shader* Shader;
    texture* tex;
    

    float vertex[36] =
    {
         -0.5f,0.5f,0.0f,0.2f,0.4f,0.6,1.0f, 0.0f,1.0f,
        -0.5f,-0.5f,0.0f,0.5f,0.4f,0.6,1.0f, 0.0f,0.0f,
         0.5f,-0.5f,0.0f,0.2f,0.4f,0.6,1.0f, 1.0f,0.0f,
         0.5f,0.5f,0.0f, 0.7f,0.4f,0.6,1.0f, 1.0f,1.0f

    };

    unsigned int indicies[6] = { 0,1,2,2,3,0 };

};