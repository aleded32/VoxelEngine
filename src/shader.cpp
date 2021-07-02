#include "shader.h"

shader::shader(const char* filepath)
{
	FILE* file = fopen(filepath, "r+");

	if (!file) 
	{
		std::cout << "could not find file" << std::endl;
	}
	else 
	{
		char buf[128];
		char line[128];

		std::stringstream ss[2];

		enum class shaderType {NONE = 0, VERTEX = 1, FRAGEMENT = 2};
		
		shaderType currentType = shaderType::NONE;

		while (fgets(line, sizeof(line), file) != NULL) 
		{
			if (line[8] == *"v" && line[9] == *"e" && line[10] == *"r") 
			{
				currentType = shaderType::VERTEX;
			}
			else if (line[8] == *"f" && line[9] == *"r" && line[10] == *"a")
			{
				currentType = shaderType::FRAGEMENT;
			}
			else 
			{
				if (currentType == shaderType::VERTEX) 
				{
					ss[0] << line;
				}
				else if (currentType == shaderType::FRAGEMENT)
				{
					ss[1] << line;
				}
			}
		}

		m_vertexShader = ss[0].str();
		m_fragmentShader = ss[1].str();

		m_rendererID = createShader(m_vertexShader, m_fragmentShader);
		glUseProgram(m_rendererID);
		
	}
}

shader::~shader()
{
}

unsigned int shader::createShader(const std::string& vertexShader, const std::string& fragmentShader)
{
	unsigned int program = glCreateProgram();
	unsigned int vs = compileShader(vertexShader, GL_VERTEX_SHADER);
	unsigned int fs = compileShader(fragmentShader, GL_FRAGMENT_SHADER);

	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vs);
	glDeleteShader(fs);

	return program;

}

unsigned int shader::compileShader(const std::string& source, unsigned int type)
{
	unsigned int shaderID = glCreateShader(type);

	const char* src = source.c_str();

	if (src != nullptr)
	{
		glShaderSource(shaderID, 1, &src, nullptr);
		glCompileShader(shaderID);


		int result;
		glGetShaderiv(shaderID, GL_COMPILE_STATUS, &result);

		if (result == GL_FALSE)
		{
			int length;
			glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &length);

			char* message = (char*)alloca(length * sizeof(char));
			glGetShaderInfoLog(shaderID, length, &length, message);
			std::cout << "Failed to compile shader " << std::endl;
			std::cout << message << std::endl;
			glDeleteShader(shaderID);
			return 0;


		}

		return shaderID;
	}

}
