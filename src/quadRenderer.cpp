#include "quadRenderer.h"

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

	Shader->setUniform1i("u_texture", 0);
	Shader->setUniformMat4("u_projection", cam->getProjection());
	Shader->setUniformMat4("u_view", cam->getView());

	
	if (terrainGen == false) {

		for (float x = 0; x < 40000; x++)
		{
			for (float y = 0; y < 1; y++)
			{
				for (float z = 0; z < 1; z++)
				{

					createCube(x, y, z, faces::front);

					

				}
			}
		}

		terrainGen = true;
	}
	
	
	
	//CubeDetection(currentFace);
	
	cube quadss[6];
	std::cout << sizeof(cube::quadFaces.data()) << std::endl;
	
	

	glBindBuffer(GL_ARRAY_BUFFER, vb->getRendererID());
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(quadss)   * buffer.size(), &buffer[0]);

	glDrawElements(GL_TRIANGLES, ib->getMaxIndexCount(), GL_UNSIGNED_INT, nullptr);
	
}

void quadRenderer::createCube(float x, float y, float z, faces currentFace)
{
	
	
	
	buffer.push_back(m_cube(x, y, z));

	
	
}

void quadRenderer::CubeDetection(faces currentFace)
{
	for (int i = 0; i < 39999; i++) {
		if (buffer[i].quadFaces[5].vertices[0].position.x == buffer[i+1].quadFaces[4].vertices[0].position.x)
		{

			

			
			
				buffer[i].quadFaces.erase(buffer[i].quadFaces.begin() + 5);
				buffer[i+1].quadFaces.erase(buffer[i+1].quadFaces.begin() + 4);
			
			
		}
	}
}
