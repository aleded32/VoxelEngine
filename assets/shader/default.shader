#shader vertex
#version 330 core

layout(location = 0)in vec3 position;
layout(location = 1)in vec4 color;

out vec4 v_color;


void main() 
{
	v_color = color;
	gl_position = position;
}

#shader fragment
#version 330 core

layout(location = 0)out vec4 color;
in vec4 v_color;


void main() 
{
	color = v_color;
}