#include "quadRenderer.h"

quadRenderer::quadRenderer(const int maxVertCount)
{

	va = new vertexArray();
	vb = new vertexBuffer(100000);
	ib = new indexBuffer();
	layout.add<float>(3);
	layout.add<float>(2);
	layout.add<float>(1);
	va->addBufferLayout(*vb, layout);
	Shader = new shader("assets/shader/default.shader");
	tex = new texture("assets/Textures/testTex.png");
	tex->bind();

	

	vertArray[maxVertCount];


	ib->unbind();
	vb->unbind();
	va->unbind();
	Shader->unbind();


}

quadRenderer::~quadRenderer()
{
	delete vertArray;
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

	std::array<vertex, 25000> quads;
	auto buffer = quads.data();
	
	for(int x = 0; x < 5; x++)
	{
		for (int y = 0; y < 5; y++)
		{
			for (int z = 0; z < 5; z++)
			{
				buffer = createQuadFront(buffer, x, y, z, 0.0f, 1.0f);
				buffer = createQuadUp(buffer, x, y, z, 0.0f, 1.0f);
				buffer = createQuadDown(buffer, x, y, z, 0.0f, 1.0f);
				buffer = createQuadBack(buffer, x, y, z, 0.0f, 1.0f);
				buffer = createQuadLeft(buffer, x, y, z, 0.0f, 1.0f);
				buffer = createQuadRight(buffer, x, y, z, 0.0f, 1.0f);
			}
		}
	}
	

	std::cout << sizeof(quads) << std::endl;
	
	
	
	

	glBindBuffer(GL_ARRAY_BUFFER, vb->getRendererID());
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(quads), quads.data());

	glDrawElements(GL_TRIANGLES, ib->getMaxIndexCount(), GL_UNSIGNED_INT, nullptr);
	
}
