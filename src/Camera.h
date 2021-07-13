#pragma once
#include "vendor/glm/glm.hpp"
#include "vendor/glm/gtc/matrix_transform.hpp"
#include <iostream>

class camera
{
public:

	//determines the projection used for users needs
	camera(float width, float height, float fieldOfView, float nearClip, float farClip);
	camera(float left, float right, float top, float bottom);
	~camera();



	void setPositon(float x, float y, float z)
	{
		m_position = glm::vec3(x, y, z);
		setCameraView();
	}

	void setPositon(glm::vec3& position)
	{
		m_position = glm::vec3(position);
		setCameraView();
	}

	inline const glm::vec3 getPosition() const
	{
		return m_position;
	}

	float m_FOV;
	float m_nearClip;
	float m_farClip;

	float m_left, m_right, m_top, m_bottom;

	void setCameraView()
	{
		m_view = glm::lookAt(m_position, m_position + m_camFront, m_camUp);
	}

	glm::mat4 getView()
	{
		return m_view;
	}

	glm::mat4 getProjection() 
	{
		return m_cameraProjection;
	}

	void setCamFront(float x, float y, float z) 
	{
		m_camFront = glm::vec3(x, y, z);
		
	}

	void setCamFront(glm::vec3 direction)
	{
		m_camFront = glm::vec3(direction);

	}

	//this process the the mouse position and converts the offset to yaw and pitch for camera rotation
	void processMouseCamDir(float &xOffset, float &yOffset) 
	{
		std::cout << xOffset << std::endl;
		yaw += xOffset;
		pitch += yOffset;

		camDir.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
		camDir.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
		camDir.y = sin(glm::radians(pitch));

		setCamFront(camDir);
	}

	float yaw = 90.0f;
	float pitch = 0.0f;
	glm::vec3 camDir;
	glm::vec3 m_camFront;
	glm::vec3 m_camUp;

private:

	glm::mat4 m_cameraProjection;
	glm::mat4 m_view;
	glm::vec3 m_position;

	//camFront is the vector that the camera is facing.
	//camUp is the up vector facing upwards.
	
	
	




};
