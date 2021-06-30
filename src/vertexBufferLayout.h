#pragma once
#include "glew.h"
#include "glfw3.h"
#include <iostream>
#include <vector>

struct element 
{
	unsigned int count;
	unsigned int type;
	unsigned int normalized;
};

class vertexBufferLayout 
{
public:

	template <typename T>
	void add(unsigned int count) 
	{
	}

	template<>
	void add<float>(unsigned int count)
	{
		m_elements.push_back({ count, GL_FLOAT,GL_FALSE });
		m_stride += count * sizeof(float);
	}

	template<>
	void add<int>(unsigned int count)
	{
		m_elements.push_back({ count, GL_INT,GL_FALSE });
		m_stride += count * sizeof(int);
	}

	inline const auto getElements() const& { return m_elements; }
	inline const uint32_t getStride() const& { return m_stride; }

private:

	unsigned int m_stride;
	std::vector<element> m_elements;

};