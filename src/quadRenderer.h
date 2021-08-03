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

struct vertex 
{
	glm::vec3 position;
	glm::vec2 texCoord;
	float texID;
	

};

struct quad 
{
	vertex vertices[4];
};

struct cube 
{
	quad quadFaces[6];
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
		

		targetQuad.vertices[1].position = { x + size,y,z };
		targetQuad.vertices[1].texCoord = { 1.0f, 0.0f };
		targetQuad.vertices[0].texID = textureID;

		targetQuad.vertices[2].position = { x + size,y + size,z };
		targetQuad.vertices[2].texCoord = { 1.0f, 1.0f };
		targetQuad.vertices[0].texID = textureID;

		targetQuad.vertices[3].position = { x,y + size,z };
		targetQuad.vertices[3].texCoord = { 0.0f, 1.0f };
		targetQuad.vertices[0].texID = textureID;

	
		return targetQuad;

	}

	quad createQuadUp(float x, float y, float  z, float textureID, float size)
	{
		quad targetQuad;
		targetQuad.vertices[0].position = { x,y,z};
		targetQuad.vertices[0].texCoord = { 0.0f, 0.0f };
		targetQuad.vertices[0].texID = textureID;
		


		targetQuad.vertices[1].position = { x,y,z + size };
		targetQuad.vertices[1].texCoord = { 1.0f, 0.0f };
		targetQuad.vertices[1].texID = textureID;
		

		targetQuad.vertices[2].position = { x + size,y,z + size};
		targetQuad.vertices[2].texCoord = { 1.0f, 1.0f };
		targetQuad.vertices[2].texID = textureID;
		

		targetQuad.vertices[3].position = { x + size,y,z };
		targetQuad.vertices[3].texCoord = { 0.0f, 1.0f };
		targetQuad.vertices[3].texID = textureID;
		


		return targetQuad;

	}

	quad createQuadDown(float x, float y, float  z, float textureID, float size)
	{
		quad targetQuad;
		targetQuad.vertices[0].position = { x,y + size,z };
		targetQuad.vertices[0].texCoord = { 0.0f, 0.0f };
		targetQuad.vertices[0].texID = textureID;
		
		

		targetQuad.vertices[1].position = { x,y + size,z + size };
		targetQuad.vertices[1].texCoord = { 1.0f, 0.0f };
		targetQuad.vertices[1].texID = textureID;
		
		

		targetQuad.vertices[2].position = { x + size,y + size,z + size };
		targetQuad.vertices[2].texCoord = { 1.0f, 1.0f };
		targetQuad.vertices[2].texID = textureID;
		
		

		targetQuad.vertices[3].position = { x + size,y + size,z };
		targetQuad.vertices[3].texCoord = { 0.0f, 1.0f };
		targetQuad.vertices[3].texID = textureID;
		
		

		return targetQuad;

	}

	quad createQuadBack(float x, float y, float  z, float textureID, float size)
	{
		quad targetQuad;
		targetQuad.vertices[0].position = { x,y,z + size};
		targetQuad.vertices[0].texCoord = { 0.0f, 0.0f };
		targetQuad.vertices[0].texID = textureID;
		
		

		targetQuad.vertices[1].position = { x + size,y,z + size};
		targetQuad.vertices[1].texCoord = { 1.0f, 0.0f };
		targetQuad.vertices[1].texID = textureID;
		

		targetQuad.vertices[2].position = { x + size,y + size,z + size};
		targetQuad.vertices[2].texCoord = { 1.0f, 1.0f };
		targetQuad.vertices[2].texID = textureID;
		

		targetQuad.vertices[3].position = { x,y + size,z + size};
		targetQuad.vertices[3].texCoord = { 0.0f, 1.0f };
		targetQuad.vertices[3].texID = textureID;
		

		return targetQuad;

	}

	quad createQuadLeft(float x, float y, float  z, float textureID, float size)
	{
		quad targetQuad;
		targetQuad.vertices[0].position = { x,y,z };
		targetQuad.vertices[0].texCoord = { 0.0f, 0.0f };
		targetQuad.vertices[0].texID = textureID;
		
		

		targetQuad.vertices[1].position = { x,y,z + size };
		targetQuad.vertices[1].texCoord = { 1.0f, 0.0f };
		targetQuad.vertices[1].texID = textureID;
		

		targetQuad.vertices[2].position = { x,y + size,z + size };
		targetQuad.vertices[2].texCoord = { 1.0f, 1.0f };
		targetQuad.vertices[2].texID = textureID;
		
		

		targetQuad.vertices[3].position = { x,y + size,z };
		targetQuad.vertices[3].texCoord = { 0.0f, 1.0f };
		targetQuad.vertices[3].texID = textureID;
		
		

		return targetQuad;

	}

	quad createQuadRight(float x, float y, float  z, float textureID, float size)
	{
		quad targetQuad;
		targetQuad.vertices[0].position = { x + size,y,z };
		targetQuad.vertices[0].texCoord = { 0.0f, 0.0f };
		targetQuad.vertices[0].texID = textureID;
		
		

		targetQuad.vertices[1].position = { x + size,y,z + size };
		targetQuad.vertices[1].texCoord = { 1.0f, 0.0f };
		targetQuad.vertices[1].texID = textureID;
		
		

		targetQuad.vertices[2].position = { x + size,y + size,z + size };
		targetQuad.vertices[2].texCoord = { 1.0f, 1.0f };
		targetQuad.vertices[2].texID = textureID;
		
		

		targetQuad.vertices[3].position = { x + size,y + size,z };
		targetQuad.vertices[3].texCoord = { 0.0f, 1.0f };
		targetQuad.vertices[3].texID = textureID;
		
		

		return targetQuad;

	}

	

	cube m_cube(float x, float y, float z) 
	{
		cube targetCube;
		
		
			targetCube.quadFaces[0] = createQuadFront(x, y, z, 0.0f, 1.0f);
			targetCube.quadFaces[1] = createQuadUp(x, y, z, 0.0f, 1.0f);
			targetCube.quadFaces[2] = createQuadDown(x, y, z, 0.0f, 1.0f);
			targetCube.quadFaces[3] = createQuadBack(x, y, z, 0.0f, 1.0f);
			targetCube.quadFaces[4] = createQuadLeft(x, y, z, 0.0f, 1.0f);
			targetCube.quadFaces[5] = createQuadRight(x, y, z, 0.0f, 1.0f);
		

		return targetCube;
	}

	void createCube(float x, float y, float z);

	void CubeDetection();
	std::vector<cube> buffer;

	vertexArray* va;
	vertexBuffer* vb;
	vertexBufferLayout layout;
	indexBuffer* ib;
	shader* Shader;
	texture* tex;

	enum class faces { front, up, down, back, left, right };

	faces currentFace = faces::front;

private:

	
	
	
	const int m_maxVertexCount;
	
	bool terrainGen = false;

	//normal variables for application use


	

	

};
