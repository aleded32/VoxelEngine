#include "indexBuffer.h"

indexBuffer::indexBuffer()	
{
	

	glGenBuffers(1, &m_RendererID);
	bind();

	for (int i = 0; i < m_maxIndexCount; i+=6) 
	{
		m_indicies[i + 0] = 0 + m_offset;
		m_indicies[i + 1] = 1 + m_offset;
		m_indicies[i + 2] = 2 + m_offset;

		m_indicies[i + 3] = 2 + m_offset;
		m_indicies[i + 4] = 3 + m_offset;
		m_indicies[i + 5] = 0 + m_offset;

		m_offset += 4;
	}


	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_maxIndexCount * sizeof(unsigned int), m_indicies, GL_STATIC_DRAW);
}

indexBuffer::indexBuffer(unsigned int size, const void* data)
{
	glGenBuffers(1, &m_RendererID);
	bind();

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);

}

indexBuffer::~indexBuffer()
{
	glDeleteBuffers(1, &m_RendererID);
}