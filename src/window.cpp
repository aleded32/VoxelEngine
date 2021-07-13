#include "window.h"

window::window(int width, int height, const char* name) 
	: m_width(width), m_height(height), m_name(name)
{
    if (!glfwInit())
    {
        std::cout << "glfw did not initialize" << std::endl;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);


    m_window = glfwCreateWindow(m_width, m_height, m_name, NULL, NULL);

    if (!m_window)
    {
        glfwTerminate();
    }

    glfwMakeContextCurrent(m_window);

    glfwSwapInterval(1);

    err = glewInit();

    if (GLEW_OK != err)
        std::cout << glewGetErrorString(err);

    std::cout << glGetString(GL_VERSION) << std::endl;

}

window::~window()
{
    delete vb;
    delete va;
    delete Shader;
}

void window::onStart()
{
    va = new vertexArray();
    vb = new vertexBuffer(sizeof(vertex),vertex);
    ib = new indexBuffer();
    layout.add<float>(3);
    layout.add<float>(4);
    layout.add<float>(2);
    va->addBufferLayout(*vb, layout);
    Shader = new shader("assets/shader/default.shader");
    tex = new texture("assets/Textures/testTex.png");
    tex->bind();

    cam = new camera(getWidth(), getHeight(), glm::radians(45.0f), 0.1f, 1000.0f);

    cam->setPositon(camX, 0, zoom);

    cam->setCameraView();

    ib->unbind();
    vb->unbind();
    va->unbind();
    Shader->unbind();

    glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

}



void window::onUpdate()
{


    while (!glfwWindowShouldClose(m_window))
    {
        glfwGetCursorPos(m_window, &xpos, &ypos);

       

        float offsetX = xpos- lastX;
        float offsetY = lastY - ypos;
        offsetX *= 0.01f;
        offsetY *= 0.01f;
       

        cam->processMouseCamDir(offsetX, offsetY);

        lastX = xpos; 
        lastY = ypos;
        


        if (glfwGetKey(m_window, GLFW_KEY_S) == GLFW_PRESS)
        {
            zoom-=0.1f;

        }
        else if (glfwGetKey(m_window, GLFW_KEY_W) == GLFW_PRESS)
        {
            zoom+= 0.1f;
            
        }
        if (glfwGetKey(m_window, GLFW_KEY_A) == GLFW_PRESS)
        {
            camX+= 0.1f;

        }
        else if (glfwGetKey(m_window, GLFW_KEY_D) == GLFW_PRESS)
        {
            camX-= 0.1f;

        }

        

        //rotation along the y axis affects the x and z axis, which is why we multiply the cos(pitch) of both x's and y's yaw. 
       

        cam->setPositon(camX, 0, zoom);
        onRender();

        glfwSwapBuffers(m_window);
        glfwPollEvents();


    }

   



    glfwTerminate();
    
}

void window::onRender()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glClearColor(0.1f, 0.5f, 0.9f, 1.0f);

    ib->bind();
    va->bind();
    Shader->bind();

    Shader->setUniform1i("u_texture", 0);
    Shader->setUniformMat4("u_projection", cam->getProjection());
    Shader->setUniformMat4("u_view", cam->getView());

    glDrawElements(GL_TRIANGLES, ib->getMaxIndexCount(), GL_UNSIGNED_INT, nullptr);
}
