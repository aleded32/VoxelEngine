#shader vertex
#version 330 core

layout(location = 0)in vec3 position;
layout(location = 1)in vec4 color;
layout(location = 2)in vec2 texCoord;

out vec4 v_color;
out vec2 v_texCoord;

uniform mat4 u_projection;
uniform mat4 u_view;

void main()
{
	v_color = color;
	v_texCoord = texCoord;
	gl_Position = u_projection * u_view * vec4(position,1.0f);
};

#shader fragment
#version 330 core

layout(location = 0)out vec4 color;

in vec4 v_color;
in vec2 v_texCoord;

uniform sampler2D u_texture;

void main()
{
	
	color = texture(u_texture,v_texCoord);
	//color = vec4(v_texCoord, 0.0f,1.0f);
};