#include "quadRenderer.h"

#define MAX_CUBE_X 16
#define MAX_CUBE_Y 32
#define MAX_CUBE_Z 16
#define BASE_HEIGHT_Y 32

quadRenderer::quadRenderer(const int maxVertCount)
	:m_maxVertexCount(maxVertCount)
{

	va = new vertexArray();
	vb = new vertexBuffer(m_maxVertexCount);

	const int maxIndex = (m_maxVertexCount / 4) * 6;

	ib = new indexBuffer(maxIndex);
	layout.add<float>(3);
	layout.add<float>(2);
	layout.add<float>(1);
	va->addBufferLayout(*vb, layout);
	Shader = new shader("assets/shader/default.shader");
	tex = new texture("assets/Textures/testTex.png");
	tex->bind();

	



	ib->unbind();
	vb->unbind();
	va->unbind();
	Shader->unbind();

	

}

quadRenderer::~quadRenderer()
{
	
	delete vb;
	delete va;
	delete Shader;
	
}

void quadRenderer::draw(camera* cam)
{
	ib->bind();
	va->bind();
	Shader->bind();

	//Shader->setUniform1i("u_texture", 0);
	Shader->setUniformMat4("u_projection", cam->getProjection());
	Shader->setUniformMat4("u_view", cam->getView());

	
	if (terrainGen == false) {

		for (float z = 0; z < MAX_CUBE_Z; z++)
		{
			for (float y = 0; y < MAX_CUBE_Y; y++)
			{
				for (float x = 0; x < MAX_CUBE_X; x++)
				{
						if(y > BASE_HEIGHT_Y || y < BASE_HEIGHT_Y)
							buffer.push_back(cube{});							
						else
							createCube(x, y, z);
						
						
						

					
				}
			}
		}
		
		std::cout << buffer.size() << std::endl;

		
		terrainGen = true;
	}
	

	
	
	
	
	
	

	glBindBuffer(GL_ARRAY_BUFFER, vb->getRendererID());
	
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(cube) * buffer.size(), &buffer[0]);

	glDrawElements(GL_TRIANGLES, ib->getMaxIndexCount(), GL_UNSIGNED_INT, nullptr);
	
}

void quadRenderer::createCube(float x, float y, float z)
{
	
	
	buffer.push_back(m_cube(x, y, z, "land"));


	
	
	
}

void quadRenderer::CubeDetection()
{

	for (int i = 0; i < buffer.size() - 1; i++) 
	{
		if (buffer[i].quadFaces[0].vertices[1].texCoord != cube{}.quadFaces[0].vertices[1].texCoord) 
		{
			if (buffer[i].quadFaces[(int)faces::right].vertices[0].position.x == buffer[i + 1].quadFaces[(int)faces::left].vertices[1].position.x)
			{

				buffer[i].quadFaces[(int)faces::right] = cube{}.quadFaces[(int)faces::right];
				buffer[i + 1].quadFaces[(int)faces::left] = cube{}.quadFaces[(int)faces::left];
			}
		}
		
	}

	for (int i = 0; i < buffer.size() - MAX_CUBE_X; i++)
	{
		if (buffer[i].quadFaces[0].vertices[1].texCoord != cube{}.quadFaces[0].vertices[1].texCoord)
		{
			if (buffer[i].quadFaces[(int)faces::down].vertices[3].position.y == buffer[i + MAX_CUBE_X].quadFaces[(int)faces::up].vertices[0].position.y)
			{
				buffer[i].quadFaces[(int)faces::down] = cube{}.quadFaces[(int)faces::down];
				buffer[i + MAX_CUBE_X].quadFaces[(int)faces::up] = cube{}.quadFaces[(int)faces::up];
			}
		}
	}

	for (int i = 0; i < buffer.size() - (MAX_CUBE_X * MAX_CUBE_Y); i++)
	{
		if (buffer[i].quadFaces[3].vertices[1].texCoord != cube{}.quadFaces[3].vertices[1].texCoord)
		{
			
			if (buffer[i].quadFaces[(int)faces::back].vertices[0].position.z == buffer[i + (MAX_CUBE_Y * MAX_CUBE_X)].quadFaces[(int)faces::front].vertices[0].position.z)
			{
				buffer[i].quadFaces[(int)faces::back].vertices[0].texCoord = glm::vec2(5.0f, 1.0f);
				buffer[i].quadFaces[(int)faces::back] = cube{}.quadFaces[(int)faces::back];
				buffer[i + (MAX_CUBE_Y * MAX_CUBE_X)].quadFaces[(int)faces::front] = cube{}.quadFaces[(int)faces::front];
			}
		}

		

	}

	
	
}
