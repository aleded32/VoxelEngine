#include "chunkGenerator.h"

chunkGen::chunkGen(int maxChunksizeXZ) :
	quadRen(new quadRenderer(200000)), m_maxChunkSizeXZ(maxChunksizeXZ)
{

}

chunkGen::~chunkGen()
{
	delete quadRen;
}

void chunkGen::drawChunks(camera& cam)
{
	quadRen->ib->bind();
	quadRen->va->bind();
	quadRen->Shader->bind();

	quadRen->Shader->setUniform1i("u_texture", 0);
	quadRen->Shader->setUniformMat4("u_projection", cam.getProjection());
	quadRen->Shader->setUniformMat4("u_view", cam.getView());

	glBindBuffer(GL_ARRAY_BUFFER, quadRen->vb->getRendererID());

	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(chunk) * 576 * m_rendererdChunks.size(), &m_rendererdChunks[0]);
	glDrawElements(GL_TRIANGLES, quadRen->ib->getMaxIndexCount(), GL_UNSIGNED_INT, nullptr);
}

chunk chunkGen::GenChunk(int chunkOffsetX, int chunkOffsetZ, int maxChunkX, int maxChunkZ)
{
	chunk baseChunk;
	

		for (float z = chunkOffsetZ; z < maxChunkZ; z++)
		{
			for (float y = 0; y < MAX_CUBE_Y; y++)
			{
				for (float x = chunkOffsetX; x < maxChunkX; x++)
				{
					/*if (y > BASE_HEIGHT_Y || y < BASE_HEIGHT_Y)
						quadRen->buffer.push_back(cube{});
					else
						
					*/
					
					quadRen->createCube(x, y, z);


				}
			}
		}

		
		baseChunk.blocks = quadRen->buffer.data();
		
		quadRen->buffer.clear();

		for (auto i : m_chunkCache)
		{
			if (i.second.blocks[0].quadFaces[0].vertices[0].position.x != baseChunk.blocks[0].quadFaces[0].vertices[0].position.x)
			{
				i.second = baseChunk;
			}
		}

		
	
	

	return baseChunk;
}

void chunkGen::GenChunks()
{
	if (m_terrainGen == false)
	{
		
		for (int i = 0; i < m_maxChunksX * m_maxChunkSizeXZ; i += 16)
		{
			for (int j = 0; j < m_maxChunksZ * m_maxChunkSizeXZ; j += 16)
			{
				std::cout << "working" << std::endl;
				m_rendererdChunks.push_back(GenChunk(i, j, m_maxChunkSizeXZ, m_maxChunkSizeXZ));
				
			}
		}
		m_terrainGen = true;
	}

}
