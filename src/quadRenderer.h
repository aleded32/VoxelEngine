#pragma once
#include "vendor/glm/glm.hpp"
#include <iostream>
#include "vertexBuffer.h"
#include "indexBuffer.h"
#include "shader.h"
#include "vertexArray.h"
#include "vertexBufferLayout.h"
#include "texture.h"
#include "Camera.h"
#include <array>

struct vertex 
{
	glm::vec3 position;
	glm::vec2 texCoord;
	float texID;

};

class quadRenderer 
{
public:

	quadRenderer(const int maxVertexCount);
	~quadRenderer();

	void draw(camera* cam);

	static vertex* createQuadFront(vertex* targetQuad, float x, float y, float  z, float textureID, float size) 
	{
		targetQuad->position = {x,y,z};
		targetQuad->texCoord = { 0.0f, 0.0f };
		targetQuad->texID = textureID;
		targetQuad++;

		targetQuad->position = { x + size,y,z };
		targetQuad->texCoord = { 1.0f, 0.0f };
		targetQuad->texID = textureID;
		targetQuad++;

		targetQuad->position = { x + size,y + size,z };
		targetQuad->texCoord = { 1.0f, 1.0f };
		targetQuad->texID = textureID;
		targetQuad++;

		targetQuad->position = { x,y + size,z };
		targetQuad->texCoord = { 0.0f, 1.0f };
		targetQuad->texID = textureID;
		targetQuad++;
	
		return targetQuad;

	}

	static vertex* createQuadUp(vertex* targetQuad, float x, float y, float z, float textureID, float size)
	{
		targetQuad->position = { x,y,z};
		targetQuad->texCoord = { 0.0f, 0.0f };
		targetQuad->texID = textureID;
		targetQuad++;

		targetQuad->position = { x,y,z + size };
		targetQuad->texCoord = { 1.0f, 0.0f };
		targetQuad->texID = textureID;
		targetQuad++;

		targetQuad->position = { x + size,y,z + size};
		targetQuad->texCoord = { 1.0f, 1.0f };
		targetQuad->texID = textureID;
		targetQuad++;

		targetQuad->position = { x + size,y,z };
		targetQuad->texCoord = { 0.0f, 1.0f };
		targetQuad->texID = textureID;
		targetQuad++;

		return targetQuad;

	}

	static vertex* createQuadDown(vertex* targetQuad, float x, float y, float z, float textureID, float size)
	{
		targetQuad->position = { x,y + size,z };
		targetQuad->texCoord = { 0.0f, 0.0f };
		targetQuad->texID = textureID;
		targetQuad++;

		targetQuad->position = { x,y + size,z + size };
		targetQuad->texCoord = { 1.0f, 0.0f };
		targetQuad->texID = textureID;
		targetQuad++;

		targetQuad->position = { x + size,y + size,z + size };
		targetQuad->texCoord = { 1.0f, 1.0f };
		targetQuad->texID = textureID;
		targetQuad++;

		targetQuad->position = { x + size,y + size,z };
		targetQuad->texCoord = { 0.0f, 1.0f };
		targetQuad->texID = textureID;
		targetQuad++;

		return targetQuad;

	}

	static vertex* createQuadBack(vertex* targetQuad, float x, float y, float z, float textureID, float size)
	{
		targetQuad->position = { x,y,z + size};
		targetQuad->texCoord = { 0.0f, 0.0f };
		targetQuad->texID = textureID;
		targetQuad++;

		targetQuad->position = { x + size,y,z + size};
		targetQuad->texCoord = { 1.0f, 0.0f };
		targetQuad->texID = textureID;
		targetQuad++;

		targetQuad->position = { x + size,y + size,z + size};
		targetQuad->texCoord = { 1.0f, 1.0f };
		targetQuad->texID = textureID;
		targetQuad++;

		targetQuad->position = { x,y + size,z + size};
		targetQuad->texCoord = { 0.0f, 1.0f };
		targetQuad->texID = textureID;
		targetQuad++;

		return targetQuad;

	}

	static vertex* createQuadLeft(vertex* targetQuad, float x, float y, float z, float textureID, float size)
	{
		targetQuad->position = { x,y,z };
		targetQuad->texCoord = { 0.0f, 0.0f };
		targetQuad->texID = textureID;
		targetQuad++;

		targetQuad->position = { x,y,z + size };
		targetQuad->texCoord = { 1.0f, 0.0f };
		targetQuad->texID = textureID;
		targetQuad++;

		targetQuad->position = { x,y + size,z + size };
		targetQuad->texCoord = { 1.0f, 1.0f };
		targetQuad->texID = textureID;
		targetQuad++;

		targetQuad->position = { x,y + size,z };
		targetQuad->texCoord = { 0.0f, 1.0f };
		targetQuad->texID = textureID;
		targetQuad++;

		return targetQuad;

	}

	static vertex* createQuadRight(vertex* targetQuad, float x, float y, float z, float textureID, float size)
	{
		targetQuad->position = { x + size,y,z };
		targetQuad->texCoord = { 0.0f, 0.0f };
		targetQuad->texID = textureID;
		targetQuad++;

		targetQuad->position = { x + size,y,z + size };
		targetQuad->texCoord = { 1.0f, 0.0f };
		targetQuad->texID = textureID;
		targetQuad++;

		targetQuad->position = { x + size,y + size,z + size };
		targetQuad->texCoord = { 1.0f, 1.0f };
		targetQuad->texID = textureID;
		targetQuad++;

		targetQuad->position = { x + size,y + size,z };
		targetQuad->texCoord = { 0.0f, 1.0f };
		targetQuad->texID = textureID;
		targetQuad++;

		return targetQuad;

	}

	vertex* vertArray;

	inline void setSize(glm::vec2& size) 
	{
		m_size = size;
	}

	inline const glm::vec2 getSize() const& { return m_size; }

	

private:

	vertex* vertices;
	
	
	glm::vec2 m_size;

	//normal variables for application use
	vertexArray* va;
	vertexBuffer* vb;
	vertexBufferLayout layout;
	indexBuffer* ib;
	shader* Shader;
	texture* tex;

};
