#include "vertexBuffer.h"
#include "quadRenderer.h"

vertexBuffer::vertexBuffer(unsigned int maxVertexCount)
{
	glGenBuffers(1, &m_RendererID);
	bind();

	glBufferData(GL_ARRAY_BUFFER, maxVertexCount * sizeof(vertex), nullptr, GL_DYNAMIC_DRAW);
}

vertexBuffer::vertexBuffer(unsigned int size, const void* data)
{
	glGenBuffers(1, &m_RendererID);
	bind();

	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	
}

vertexBuffer::~vertexBuffer()
{
	glDeleteBuffers(1, &m_RendererID);
}
