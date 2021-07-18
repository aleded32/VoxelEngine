#pragma once
#include <iostream>
#include "quadRenderer.h"



class window
{
public:

    window(int width, int height, const char* name);
    ~window();

    void onStart();
    void onUpdate();
    void onRender();


    inline GLFWwindow* getWindow() { return m_window; }
    inline const int getWidth() const& { return m_width; }
    inline const int getHeight() const& { return m_height; }

private:

    //window specific variables
    GLFWwindow* m_window;
    int m_width, m_height;
    const char* m_name;
    GLenum err;


    camera* cam;
    quadRenderer* renderer;

    double xpos, ypos;
    glm::vec3 camPosition;

    float lastX = m_width / 2;
    float lastY = m_height / 2;
    float prevTime = glfwGetTime();
    int fps = 0;

    void getFPS() 
    {
        float currentTime = glfwGetTime();

        fps++;
        float deltaTime = currentTime - prevTime;
        if (deltaTime >= 1)
        {
            std::cout << fps / deltaTime << std::endl;
            fps = 0;
            prevTime = currentTime;
        }
    }

};