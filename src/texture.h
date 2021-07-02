#pragma once
#include "glew.h"
#include <iostream>
#include <string>
#include "vendor/stbi_image/stb_image.h"

class texture 
{
public:

	texture(const std::string& filepath);
	~texture();

	const void bind(unsigned int slot = 0) const { glActiveTexture(GL_TEXTURE0 + slot); glBindTexture(GL_TEXTURE_2D, m_renderer_ID); }
	const void unbind() const { glBindTexture(GL_TEXTURE_2D, 0); }

private:

	//localbuffer is the image data stored in unsigned char array
	unsigned char* m_localBuffer;
	int m_width, m_height;
	unsigned int m_renderer_ID;
	const char* m_filepath;
	int m_bitsPerPixel;

};