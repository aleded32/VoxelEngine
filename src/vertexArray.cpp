#include "vertexArray.h"

vertexArray::vertexArray()
	:m_offset(0)
{
	glGenVertexArrays(1,&m_rendererID);
	bind();
}

vertexArray::~vertexArray()
{
	glDeleteVertexArrays(1, &m_rendererID);
}

void vertexArray::addBufferLayout(const vertexBuffer& vb, const vertexBufferLayout& layout)
{
	vb.bind();
	
	const auto& elements = layout.getElements();

	for (size_t i = 0; i < elements.size(); i++) 
	{
		glVertexAttribPointer(i, elements[i].count, elements[i].type, elements[i].normalized, layout.getStride(), (const void*)m_offset);
		glEnableVertexAttribArray(i);
		m_offset += elements[i].count * getSizeOfType(elements[i].type);
	}

}
