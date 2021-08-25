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


