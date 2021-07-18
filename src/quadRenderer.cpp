#include "quadRenderer.h"

#define MAX_CUBE_X 16
#define MAX_CUBE_Y 256
#define MAX_CUBE_Z 1

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
	layout.add<int>(1);
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

	Shader->setUniform1i("u_texture", 0);
	Shader->setUniformMat4("u_projection", cam->getProjection());
	Shader->setUniformMat4("u_view", cam->getView());

	
	if (terrainGen == false) {

		for (float z = 0; z < MAX_CUBE_Z; z++)
		{
			for (float y = 0; y < MAX_CUBE_Y; y++)
			{
				for (float x = 0; x < MAX_CUBE_X; x++)
				{
					
					createCube(x, y, z, faces::front);

					
				}
			}
		}
		
		CubeDetection(currentFace);
		terrainGen = true;
	}
	

	
	
	
	
	
	

	glBindBuffer(GL_ARRAY_BUFFER, vb->getRendererID());
	
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(quad) * buffer.size(), &buffer[0]);

	glDrawElements(GL_TRIANGLES, ib->getMaxIndexCount(), GL_UNSIGNED_INT, nullptr);
	
}

void quadRenderer::createCube(float x, float y, float z, faces currentFace)
{
	
	
	
	buffer.push_back(createQuadFront(x, y, z, 0.0f, 1.0f));
	buffer.push_back(createQuadUp(x, y, z, 0.0f, 1.0f));
	buffer.push_back(createQuadDown(x, y, z, 0.0f, 1.0f));
	buffer.push_back(createQuadBack(x, y, z, 0.0f, 1.0f));
	buffer.push_back(createQuadLeft(x, y, z, 0.0f, 1.0f));
	buffer.push_back(createQuadRight(x, y, z, 0.0f, 1.0f));

	
	
	
}

void quadRenderer::CubeDetection(faces currentFace)
{
	for (int i = 0; i < buffer.size() - 9; i++) {
		if (buffer[i + 4].vertices[0].position.x == buffer[i + 9].vertices[0].position.x)
		{



			buffer[i + 4] = quad{};
			buffer[i + 9] = quad{};

			//buffer.erase(buffer.begin() + i + 9);
			//buffer.erase(buffer.begin() + i + 4);


		}
		
	}

	/*for (int i = 0; i < buffer.size() - 7; i++)
	{
		if (buffer[i].vertices[0].position.y == buffer[i + 6].vertices[4].position.y)
		{


		buffer[i + 1] = quad{};
		buffer[i + 7] = quad{};


		//buffer.erase(buffer.begin() + i + 7);
		//buffer.erase(buffer.begin() + i + 1);


		}
	}*/

	
}
