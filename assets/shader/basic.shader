#shader vertex
#version 330 core

layout(location = 0)in vec3 position; 
layout(location = 1)in vec4 color;

out vec4 v_color;


void main()
{
	v_color = color;
	gl_Position = vec4(position,1.0f); 
	
};

#shader fragment
#version 330 core

layout(location = 0)out vec4 color; 


in vec4 v_color;


void main()
{
		
	color = vec4(0.4f, 0.3f,0.0f, 1.0f);
	
	
};
