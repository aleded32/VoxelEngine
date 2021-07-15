#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "glew.h"
#include <sstream>
#include <unordered_map>
#include <iostream>
#include "vendor/glm/glm.hpp"


class shader 
{
public:

	shader(const char* filepath);
	~shader();

	void setUniform4f(const char* uniformName, float v0, float v1, float v2, float v3) 
	{
		unsigned int location = getUniformLocation(uniformName);

		glUniform4f(location, v0, v1, v2, v3);
	}

	void setUniform1i(const char* uniformName, int v0) 
	{
		unsigned int location = getUniformLocation(uniformName);
		glUniform1i(location, v0);
	}

	void setUniformMat4(const char* uniformName, const glm::mat4& matrix) 
	{
		unsigned int location = getUniformLocation(uniformName);
		glUniformMatrix4fv(location, 1, GL_FALSE, &matrix[0][0]);
	}

	const void bind() const { glUseProgram(m_rendererID); }
	const void unbind() const { glUseProgram(0); }

private:
	
	unsigned int m_rendererID;
	std::string m_vertexShader;
	std::string m_fragmentShader;

	std::unordered_map<std::string, unsigned int> uniformLocationCache;

	unsigned int getUniformLocation(const char* uniformName) 
	{
		unsigned int location = glGetUniformLocation(m_rendererID, uniformName);

		if (uniformLocationCache.find(uniformName) != uniformLocationCache.end()) 
		{
			return uniformLocationCache[uniformName];
		}
		else if(location != -1)
		{
			uniformLocationCache[uniformName] = location;
			return location;
		}
		else 
		{
			
			std::cout << "uniform " << uniformName << " " << "does not exist" << std::endl;
		}
	}

	static unsigned int createShader(const std::string& vertexShader, const std::string& fragmentShader);
	static unsigned int compileShader(const std::string& source, unsigned int type);

};