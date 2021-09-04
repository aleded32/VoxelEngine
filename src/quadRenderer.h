#pragma once
#include "vendor/glm/glm.hpp"
#include <iostream>
#include <vector>
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
	int faceType = 0;

};

struct quad 
{
	vertex vertices[4];
};





class quadRenderer 
{
public:

	quadRenderer(const int maxVertexCount);
	~quadRenderer();


	quad createQuadFront(float x, float y, float  z, float textureID, float size) 
	{
		quad targetQuad;
		targetQuad.vertices[0].position = {x,y,z};
		targetQuad.vertices[0].texCoord = { 0.0f, 0.0f };
		
		

		targetQuad.vertices[1].position = { x + size,y,z };
		targetQuad.vertices[1].texCoord = { 1.0f, 0.0f };
		

		targetQuad.vertices[2].position = { x + size,y + size,z };
		targetQuad.vertices[2].texCoord = { 1.0f, 1.0f };
		

		targetQuad.vertices[3].position = { x,y + size,z };
		targetQuad.vertices[3].texCoord = { 0.0f, 1.0f };
		

		targetQuad.vertices->faceType = 1;

	
		return targetQuad;

	}

	quad createQuadUp(float x, float y, float  z, float textureID, float size)
	{
		quad targetQuad;
		targetQuad.vertices[0].position = { x,y,z};
		targetQuad.vertices[0].texCoord = { 0.0f, 0.0f };
		
		


		targetQuad.vertices[1].position = { x,y,z + size };
		targetQuad.vertices[1].texCoord = { 1.0f, 0.0f };
		
		

		targetQuad.vertices[2].position = { x + size,y,z + size};
		targetQuad.vertices[2].texCoord = { 1.0f, 1.0f };
		
		

		targetQuad.vertices[3].position = { x + size,y,z };
		targetQuad.vertices[3].texCoord = { 0.0f, 1.0f };
		
		
		targetQuad.vertices->faceType = 2;


		return targetQuad;

	}

	quad createQuadDown(float x, float y, float  z, float textureID, float size)
	{
		quad targetQuad;
		targetQuad.vertices[0].position = { x,y + size,z };
		targetQuad.vertices[0].texCoord = { 0.0f, 0.0f };
		
		
		

		targetQuad.vertices[1].position = { x,y + size,z + size };
		targetQuad.vertices[1].texCoord = { 1.0f, 0.0f };
		
		
		

		targetQuad.vertices[2].position = { x + size,y + size,z + size };
		targetQuad.vertices[2].texCoord = { 1.0f, 1.0f };
		
		
		

		targetQuad.vertices[3].position = { x + size,y + size,z };
		targetQuad.vertices[3].texCoord = { 0.0f, 1.0f };
		
		
		targetQuad.vertices->faceType = 3;


		return targetQuad;

	}

	quad createQuadBack(float x, float y, float  z, float textureID, float size)
	{
		quad targetQuad;
		targetQuad.vertices[0].position = { x,y,z + size};
		targetQuad.vertices[0].texCoord = { 0.0f, 0.0f };
		
		
		

		targetQuad.vertices[1].position = { x + size,y,z + size};
		targetQuad.vertices[1].texCoord = { 1.0f, 0.0f };
		
		

		targetQuad.vertices[2].position = { x + size,y + size,z + size};
		targetQuad.vertices[2].texCoord = { 1.0f, 1.0f };
		
		

		targetQuad.vertices[3].position = { x,y + size,z + size};
		targetQuad.vertices[3].texCoord = { 0.0f, 1.0f };
		
		
		targetQuad.vertices->faceType = 4;


		return targetQuad;

	}

	quad createQuadLeft(float x, float y, float  z, float textureID, float size)
	{
		quad targetQuad;
		targetQuad.vertices[0].position = { x,y,z };
		targetQuad.vertices[0].texCoord = { 0.0f, 0.0f };
		
		
		

		targetQuad.vertices[1].position = { x,y,z + size };
		targetQuad.vertices[1].texCoord = { 1.0f, 0.0f };
		
		

		targetQuad.vertices[2].position = { x,y + size,z + size };
		targetQuad.vertices[2].texCoord = { 1.0f, 1.0f };
		
		
		

		targetQuad.vertices[3].position = { x,y + size,z };
		targetQuad.vertices[3].texCoord = { 0.0f, 1.0f };
		
		
		targetQuad.vertices->faceType = 5;


		return targetQuad;

	}

	quad createQuadRight(float x, float y, float  z, float textureID, float size)
	{
		quad targetQuad;
		targetQuad.vertices[0].position = { x + size,y,z };
		targetQuad.vertices[0].texCoord = { 0.0f, 0.0f };
		
		
		

		targetQuad.vertices[1].position = { x + size,y,z + size };
		targetQuad.vertices[1].texCoord = { 1.0f, 0.0f };
		
		
		

		targetQuad.vertices[2].position = { x + size,y + size,z + size };
		targetQuad.vertices[2].texCoord = { 1.0f, 1.0f };
		
		
		

		targetQuad.vertices[3].position = { x + size,y + size,z };
		targetQuad.vertices[3].texCoord = { 0.0f, 1.0f };
		
		
		targetQuad.vertices->faceType = 6;


		return targetQuad;

	}


	vertexArray* va;
	vertexBuffer* vb;
	vertexBufferLayout layout;
	indexBuffer* ib;
	shader* Shader;
	texture* tex;

private:

	
	
	
	const int m_maxVertexCount;
	



	

	

};
