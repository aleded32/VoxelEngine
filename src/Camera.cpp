#include "Camera.h"

camera::camera(float width, float height, float fieldOfView, float nearClip, float farClip)
    :m_cameraProjection(glm::mat4(1.0f)), m_position(glm::vec3(0,0,0)), m_view(glm::mat4(1.0f)), m_FOV(fieldOfView), m_nearClip(nearClip), m_farClip(farClip),
     m_camFront(glm::vec3(0,0,-1.0f)), m_camUp(glm::vec3(0,1.0f,0))
{
    m_cameraProjection = glm::perspective(glm::radians(45.0f), float(width / height), m_nearClip, m_farClip);
    m_view = glm::lookAt(m_position, m_position + m_camFront, m_camUp);
}

camera::camera(float left, float right, float top, float bottom)
    :m_left(left), m_right(right), m_top(top), m_bottom(bottom)
{
    m_cameraProjection = glm::ortho(left, right, bottom, top);
    m_view = glm::mat4(1.0f);
}

camera::~camera()
{
}
