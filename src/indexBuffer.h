#pragma once
#include "glew.h"
#include "glfw3.h"


class indexBuffer
{
public:

	indexBuffer(const unsigned int& maxIndexCount);
	indexBuffer(unsigned int size, const void* data);
	~indexBuffer();

	const void bind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID); }
	const void unbind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }
	
	inline const unsigned int getMaxIndexCount() const& { return m_maxIndexCount; }

private:

	unsigned int m_RendererID;
	unsigned int m_offset = 0;
	unsigned int* m_indicies;
	const unsigned int m_maxIndexCount;

};