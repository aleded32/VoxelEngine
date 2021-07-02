#include "texture.h"

texture::texture(const std::string& filepath) 
	:m_width(0), m_height(0), m_bitsPerPixel(0), m_filepath(filepath.c_str())
{

	stbi_set_flip_vertically_on_load(1);

	m_localBuffer = stbi_load(m_filepath, &m_width, &m_height, &m_bitsPerPixel,4);

	glGenTextures(1, &m_renderer_ID);
	glBindTexture(GL_TEXTURE_2D, m_renderer_ID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_localBuffer);

	if (m_localBuffer)
		stbi_image_free(m_localBuffer);

}

texture::~texture()
{
	glDeleteTextures(1, &m_renderer_ID);
}


