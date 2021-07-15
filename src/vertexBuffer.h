#pragma once
#include "glew.h"
#include "glfw3.h"
#include <iostream>



class vertexBuffer 
{
public:


	

	vertexBuffer(unsigned int maxVertexCount);
	vertexBuffer(unsigned int size,const void* data);
	~vertexBuffer();

	const void bind() const { glBindBuffer(GL_ARRAY_BUFFER, m_RendererID); }
	const void unbind() const { glBindBuffer(GL_ARRAY_BUFFER, 0); }
	inline const unsigned int getRendererID() const& { return m_RendererID; }

private:

	unsigned int m_RendererID;


};