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
	int active = 0;

};

struct quad 
{
	vertex vertices[4];
};

struct cube 
{
	std::vector<quad> quadFaces;
};

struct dummy 
{
	quad faces[6];
};

class quadRenderer 
{
public:

	quadRenderer(const int maxVertexCount);
	~quadRenderer();

	void draw(camera* cam);

	quad createQuadFront(float x, float y, float  z, float textureID, float size) 
	{
		quad targetQuad;
		targetQuad.vertices[0].position = {x,y,z};
		targetQuad.vertices[0].texCoord = { 0.0f, 0.0f };
		targetQuad.vertices[0].texID = textureID;
		targetQuad.vertices[0].active = true;

		targetQuad.vertices[1].position = { x + size,y,z };
		targetQuad.vertices[1].texCoord = { 1.0f, 0.0f };
		targetQuad.vertices[1].active = true;

		targetQuad.vertices[2].position = { x + size,y + size,z };
		targetQuad.vertices[2].texCoord = { 1.0f, 1.0f };
		targetQuad.vertices[2].active = true;

		targetQuad.vertices[3].position = { x,y + size,z };
		targetQuad.vertices[3].texCoord = { 0.0f, 1.0f };
		targetQuad.vertices[3].active = true;

	
		return targetQuad;

	}

	quad createQuadUp(float x, float y, float  z, float textureID, float size)
	{
		quad targetQuad;
		targetQuad.vertices[0].position = { x,y,z};
		targetQuad.vertices[0].texCoord = { 0.0f, 0.0f };
		targetQuad.vertices[0].texID = textureID;
		targetQuad.vertices[0].active = true;


		targetQuad.vertices[1].position = { x,y,z + size };
		targetQuad.vertices[1].texCoord = { 1.0f, 0.0f };
		targetQuad.vertices[1].texID = textureID;
		targetQuad.vertices[1].active = true;

		targetQuad.vertices[2].position = { x + size,y,z + size};
		targetQuad.vertices[2].texCoord = { 1.0f, 1.0f };
		targetQuad.vertices[2].texID = textureID;
		targetQuad.vertices[2].active = true;

		targetQuad.vertices[3].position = { x + size,y,z };
		targetQuad.vertices[3].texCoord = { 0.0f, 1.0f };
		targetQuad.vertices[3].texID = textureID;
		targetQuad.vertices[3].active = true;


		return targetQuad;

	}

	quad createQuadDown(float x, float y, float  z, float textureID, float size)
	{
		quad targetQuad;
		targetQuad.vertices[0].position = { x,y + size,z };
		targetQuad.vertices[0].texCoord = { 0.0f, 0.0f };
		targetQuad.vertices[0].texID = textureID;
		targetQuad.vertices[0].active = true;
		

		targetQuad.vertices[1].position = { x,y + size,z + size };
		targetQuad.vertices[1].texCoord = { 1.0f, 0.0f };
		targetQuad.vertices[1].texID = textureID;
		targetQuad.vertices[1].active = true;
		

		targetQuad.vertices[2].position = { x + size,y + size,z + size };
		targetQuad.vertices[2].texCoord = { 1.0f, 1.0f };
		targetQuad.vertices[2].texID = textureID;
		targetQuad.vertices[2].active = true;
		

		targetQuad.vertices[3].position = { x + size,y + size,z };
		targetQuad.vertices[3].texCoord = { 0.0f, 1.0f };
		targetQuad.vertices[3].texID = textureID;
		targetQuad.vertices[3].active = true;
		

		return targetQuad;

	}

	quad createQuadBack(float x, float y, float  z, float textureID, float size)
	{
		quad targetQuad;
		targetQuad.vertices[0].position = { x,y,z + size};
		targetQuad.vertices[0].texCoord = { 0.0f, 0.0f };
		targetQuad.vertices[0].texID = textureID;
		targetQuad.vertices[0].active = true;
		

		targetQuad.vertices[1].position = { x + size,y,z + size};
		targetQuad.vertices[1].texCoord = { 1.0f, 0.0f };
		targetQuad.vertices[1].texID = textureID;
		targetQuad.vertices[1].active = true;

		targetQuad.vertices[2].position = { x + size,y + size,z + size};
		targetQuad.vertices[2].texCoord = { 1.0f, 1.0f };
		targetQuad.vertices[2].texID = textureID;
		targetQuad.vertices[2].active = true;

		targetQuad.vertices[3].position = { x,y + size,z + size};
		targetQuad.vertices[3].texCoord = { 0.0f, 1.0f };
		targetQuad.vertices[3].texID = textureID;
		targetQuad.vertices[3].active = true;

		return targetQuad;

	}

	quad createQuadLeft(float x, float y, float  z, float textureID, float size)
	{
		quad targetQuad;
		targetQuad.vertices[0].position = { x,y,z };
		targetQuad.vertices[0].texCoord = { 0.0f, 0.0f };
		targetQuad.vertices[0].texID = textureID;
		targetQuad.vertices[0].active = true;
		

		targetQuad.vertices[1].position = { x,y,z + size };
		targetQuad.vertices[1].texCoord = { 1.0f, 0.0f };
		targetQuad.vertices[1].texID = textureID;
		targetQuad.vertices[1].active = true;

		targetQuad.vertices[2].position = { x,y + size,z + size };
		targetQuad.vertices[2].texCoord = { 1.0f, 1.0f };
		targetQuad.vertices[2].texID = textureID;
		targetQuad.vertices[2].active = true;
		

		targetQuad.vertices[3].position = { x,y + size,z };
		targetQuad.vertices[3].texCoord = { 0.0f, 1.0f };
		targetQuad.vertices[3].texID = textureID;
		targetQuad.vertices[3].active = true;
		

		return targetQuad;

	}

	quad createQuadRight(float x, float y, float  z, float textureID, float size)
	{
		quad targetQuad;
		targetQuad.vertices[0].position = { x + size,y,z };
		targetQuad.vertices[0].texCoord = { 0.0f, 0.0f };
		targetQuad.vertices[0].texID = textureID;
		targetQuad.vertices[0].active = true;
		

		targetQuad.vertices[1].position = { x + size,y,z + size };
		targetQuad.vertices[1].texCoord = { 1.0f, 0.0f };
		targetQuad.vertices[1].texID = textureID;
		targetQuad.vertices[1].active = true;
		

		targetQuad.vertices[2].position = { x + size,y + size,z + size };
		targetQuad.vertices[2].texCoord = { 1.0f, 1.0f };
		targetQuad.vertices[2].texID = textureID;
		targetQuad.vertices[2].active = true;
		

		targetQuad.vertices[3].position = { x + size,y + size,z };
		targetQuad.vertices[3].texCoord = { 0.0f, 1.0f };
		targetQuad.vertices[3].texID = textureID;
		targetQuad.vertices[3].active = true;
		

		return targetQuad;

	}

	

	cube m_cube(float x, float y, float z) 
	{
		cube targetCube;
		
		
			targetCube.quadFaces.push_back(createQuadFront(x, y, z, 0.0f, 1.0f));
			targetCube.quadFaces.push_back(createQuadUp(x, y, z, 0.0f, 1.0f));
			targetCube.quadFaces.push_back(createQuadDown(x, y, z, 0.0f, 1.0f));
			targetCube.quadFaces.push_back(createQuadBack(x, y, z, 0.0f, 1.0f));
			targetCube.quadFaces.push_back(createQuadLeft(x, y, z, 0.0f, 1.0f));
			targetCube.quadFaces.push_back(createQuadRight(x, y, z, 0.0f, 1.0f));
		

		return targetCube;
	}

	
	

private:

	
	
	
	const int m_maxVertexCount;
	std::vector<quad> buffer;
	bool terrainGen = false;

	//normal variables for application use
	vertexArray* va;
	vertexBuffer* vb;
	vertexBufferLayout layout;
	indexBuffer* ib;
	shader* Shader;
	texture* tex;

	enum class faces {front,up,down,back,left,right};

	faces currentFace = faces::front;

	void createCube(float x, float y, float z, faces currentFace);

	void CubeDetection(faces currentFace);

};
