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
	quadRen->Shader->bind();

	quadRen->Shader->setUniform1i("u_texture", 0);
	quadRen->Shader->setUniformMat4("u_projection", cam.getProjection());
	quadRen->Shader->setUniformMat4("u_view", cam.getView());

	

	quadRen->vb->bind();

	
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(quad) * viewableBlocks.size(), &viewableBlocks[0]);
		glDrawElements(GL_TRIANGLES, quadRen->ib->getMaxIndexCount(), GL_UNSIGNED_INT, nullptr);
	

	
	
}



void chunkGen::cullblocks(chunk &targetChunk,int maxX, int maxZ)
{
	for (int i = 0; i < targetChunk.blocks.size() - 1; i++)
	{
		if (targetChunk.blocks[i].quadFaces[0].vertices[1].texCoord != cube{}.quadFaces[0].vertices[1].texCoord)
		{
			if (targetChunk.blocks[i].quadFaces[(int)faces::right].vertices[0].position.x == targetChunk.blocks[i + 1].quadFaces[(int)faces::left].vertices[1].position.x)
			{
				targetChunk.blocks[i].quadFaces[(int)faces::right] = cube{}.quadFaces[(int)faces::right];
				targetChunk.blocks[i+1].quadFaces[(int)faces::left] = cube{}.quadFaces[(int)faces::left];
			}
		}

	}

	for (int i = 0; i < targetChunk.blocks.size() - maxX; i++)
	{
		if (targetChunk.blocks[i].quadFaces[0].vertices[1].texCoord != cube{}.quadFaces[0].vertices[1].texCoord)
		{
			if (targetChunk.blocks[i].quadFaces[(int)faces::down].vertices[3].position.y == targetChunk.blocks[i + maxX].quadFaces[(int)faces::up].vertices[0].position.y)
			{
				targetChunk.blocks[i].quadFaces[(int)faces::down] = cube{}.quadFaces[(int)faces::down];
				targetChunk.blocks[i + maxX].quadFaces[(int)faces::up] = cube{}.quadFaces[(int)faces::up];
			}
		}
	}

	for (int i = 0; i < targetChunk.blocks.size() - (maxX * MAX_CUBE_Y); i++)
	{
		if (targetChunk.blocks[i].quadFaces[3].vertices[1].texCoord != cube{}.quadFaces[3].vertices[1].texCoord)
		{

			if (targetChunk.blocks[i].quadFaces[(int)faces::back].vertices[0].position.z == targetChunk.blocks[i + ((BASE_HEIGHT_Y+1) * maxX)].quadFaces[(int)faces::front].vertices[0].position.z)
			{
				
				targetChunk.blocks[i].quadFaces[(int)faces::back] = cube{}.quadFaces[(int)faces::back];
				targetChunk.blocks[i + ((BASE_HEIGHT_Y+1) * maxX)].quadFaces[(int)faces::front] = cube{}.quadFaces[(int)faces::front];
			}
		}



	}

	
	
	


}

void chunkGen::GenChunk(int chunkOffsetX, int chunkOffsetZ, int maxChunkX, int maxChunkZ)
{
	chunk baseChunk;


	for (float z = chunkOffsetZ; z < maxChunkZ; z++)
	{
		for (float y = 0; y < MAX_CUBE_Y; y++)
		{

			for (float x = chunkOffsetX; x < maxChunkX; x++)
			{




				if (y > BASE_HEIGHT_Y)
					baseChunk.blocks.push_back(cube{});
				else
					m_cube(x, y, z, *quadRen, baseChunk.blocks);

				



			}
		}
	}


	
	baseChunk.blocks.erase(std::remove_if(baseChunk.blocks.begin(), baseChunk.blocks.end(), [&](cube const& block) {return block.quadFaces->vertices->faceType == 0; }), baseChunk.blocks.end());
	cullblocks(baseChunk, maxChunkX, maxChunkZ);

	for (int i = 0; i < baseChunk.blocks.size(); i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (baseChunk.blocks[i].quadFaces[j].vertices->faceType == 1)
			{
				viewableBlocks.push_back(baseChunk.blocks[i].quadFaces[j]);
			}
		}
	}
		

	
		
		
		/*for (auto i : m_chunkCache)
		{
			if (i.second.blocks[0].quadFaces[0].vertices[0].position.x != baseChunk.blocks[0].quadFaces[0].vertices[0].position.x)
			{
				i.second = baseChunk;
			}
		}*/

		
	
	

	
}

void chunkGen::GenChunks()
{
	if (m_terrainGen == false)
	{
		
		for (int i = 0; i < m_maxChunksZ * m_maxChunkSizeXZ; i += 16)
		{
			for (int j = 0; j < m_maxChunksX * m_maxChunkSizeXZ; j += 16)
			{
				GenChunk(j, i, m_maxChunksX * m_maxChunkSizeXZ, m_maxChunksZ * m_maxChunkSizeXZ);
				
			}
		}
		
		
		m_terrainGen = true;
	}

}
