#pragma once
#include "vertexBufferLayout.h"
#include "vertexBuffer.h"

class vertexArray 
{
public:

	vertexArray();
	~vertexArray();

	const void bind() const { glBindVertexArray(m_rendererID); }
	const void unbind() const { glBindVertexArray(0); }

	void addBufferLayout(const vertexBuffer& vb, const vertexBufferLayout& layout);


private:

	unsigned int getSizeOfType(unsigned int type) 
	{
		switch (type)
		{
		case GL_FLOAT:
			return 4;
			break;
		case GL_INT:
			return 2;
			break;
		}
	}

	unsigned int m_rendererID;
	unsigned int m_offset;

};