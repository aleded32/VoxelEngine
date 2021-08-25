#include "chunkGenerator.h"



chunkGen::chunkGen(int maxChunksizeXZ) :
	quadRen(new quadRenderer(4000000)), m_maxChunkSizeXZ(maxChunksizeXZ)
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
	quadRen->vb->bind();
	quadRen->Shader->bind();

	quadRen->Shader->setUniform1i("u_texture", 0);
	quadRen->Shader->setUniformMat4("u_projection", cam.getProjection());
	quadRen->Shader->setUniformMat4("u_view", cam.getView());

	

	
	
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(quad)  * m_rendererdChunks[0].blocks.size(), &m_rendererdChunks[0].blocks.front());
		glDrawElements(GL_TRIANGLES, quadRen->ib->getMaxIndexCount(), GL_UNSIGNED_INT, nullptr);
	

	
	
}



void chunkGen::cullblocks(chunk& targetChunk, int maxX, int maxZ)
{
	for (int i = 0; i < targetChunk.blocks.size() - 1; i++)
	{
		

	}

	for (int i = 0; i < targetChunk.blocks.size() - maxX; i++)
	{
		
	}

	for (int i = 0; i < targetChunk.blocks.size() - (maxX * MAX_CUBE_Y); i++)
	{
		

	}


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




				if (y > BASE_HEIGHT_Y)
					for(int i = 0; i < 6; i++)
						baseChunk.blocks.push_back(quad{});
				else
					m_cube(x, y, z, *quadRen, baseChunk.blocks);

				



			}
		}
	}


	
	baseChunk.blocks.erase(std::remove_if(baseChunk.blocks.begin(), baseChunk.blocks.end(), [&](quad const& block) {return block.vertices->faceType == 0; }), baseChunk.blocks.end());
	//cullblocks(baseChunk, maxChunkX, maxChunkZ);

	
		

	
		
		
		/*for (auto i : m_chunkCache)
		{
			if (i.second.blocks[0].quadFaces[0].vertices[0].position.x != baseChunk.blocks[0].quadFaces[0].vertices[0].position.x)
			{
				i.second = baseChunk;
			}
		}*/

		
	
	

	return baseChunk;
}

void chunkGen::GenChunks()
{
	if (m_terrainGen == false)
	{
		
		for (int i = 0; i < m_maxChunksZ * m_maxChunkSizeXZ; i += 16)
		{
			for (int j = 0; j < m_maxChunksX * m_maxChunkSizeXZ; j += 16)
			{
				m_rendererdChunks.push_back(GenChunk(j, i, m_maxChunksX * m_maxChunkSizeXZ, m_maxChunksZ * m_maxChunkSizeXZ));
				
			}
		}
		
		
		m_terrainGen = true;
	}

}
