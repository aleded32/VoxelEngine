#include "chunkGenerator.h"



chunkGen::chunkGen(int maxChunksizeXZ) :
	quadRen(new quadRenderer(500000)), m_maxChunkSizeXZ(maxChunksizeXZ), m_maxChunksX(4), m_maxChunksZ(4)
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



void chunkGen::cullblocks(chunk &targetChunk,int maxX)
{
	
	std::cout << targetChunk.blocks.size() << std::endl;

	for (int i = 0; i < targetChunk.blocks.size() - 1; i++)
	{
		
			if (targetChunk.blocks[i].quadFaces[(int)faces::right].vertices[0].position.x == targetChunk.blocks[i + 1].quadFaces[(int)faces::left].vertices[1].position.x)
			{
				targetChunk.blocks[i].quadFaces[(int)faces::right] = cube{}.quadFaces[(int)faces::right];
				targetChunk.blocks[i+1].quadFaces[(int)faces::left] = cube{}.quadFaces[(int)faces::left];
			}
		

	}

	for (int i = 0; i < targetChunk.blocks.size() - maxX ; i++)
	{
		
		
			if (targetChunk.blocks[i].quadFaces[(int)faces::down].vertices[0].position.y == targetChunk.blocks[i + maxX ].quadFaces[(int)faces::up].vertices[0].position.y)
			{
				
				targetChunk.blocks[i].quadFaces[(int)faces::down] = cube{}.quadFaces[(int)faces::down];
				targetChunk.blocks[i + maxX ].quadFaces[(int)faces::up] = cube{}.quadFaces[(int)faces::up];
			}
		
	}

	for (int i = 0; i < targetChunk.blocks.size() - (maxX * MAX_CUBE_Y); i++)
	{
		

			if (targetChunk.blocks[i].quadFaces[(int)faces::back].vertices[0].position.z == targetChunk.blocks[i + (MAX_CUBE_Y * maxX) ].quadFaces[(int)faces::front].vertices[0].position.z)
			{
				
				targetChunk.blocks[i].quadFaces[(int)faces::back] = cube{}.quadFaces[(int)faces::back];
				targetChunk.blocks[i + (MAX_CUBE_Y * maxX) ].quadFaces[(int)faces::front] = cube{}.quadFaces[(int)faces::front];
			}
		



	}

	
	
	


}

void chunkGen::GenChunk(int maxChunkX, int maxChunkZ)
{
	
	

	


	for (float z = 0; z < maxChunkZ; z++)
	{
		for (float y = 0; y < MAX_CUBE_Y; y++)
		{

			for (float x = 0; x < maxChunkX; x++)
			{

				if ((int)x >= 15 * currentChunk && (int)y >= 255 && (int)z >= 15 * currentChunk)
				{


					cullblocks(tmpChunk, m_maxChunksX * m_maxChunkSizeXZ);
					chunklist.push_back(tmpChunk);

					tmpChunk.blocks.clear();
					currentChunk++;

				}
				else
				{

					if (y > BASE_HEIGHT_Y)
						tmpChunk.blocks.push_back(cube{});
					else
					{
						targetCube.quadFaces[0] = quadRen->createQuadFront(x, y, z, 0.0f, 1.0f);
						targetCube.quadFaces[1] = quadRen->createQuadUp(x, y, z, 0.0f, 1.0f);
						targetCube.quadFaces[2] = quadRen->createQuadDown(x, y, z, 0.0f, 1.0f);
						targetCube.quadFaces[3] = quadRen->createQuadBack(x, y, z, 0.0f, 1.0f);
						targetCube.quadFaces[4] = quadRen->createQuadLeft(x, y, z, 0.0f, 1.0f);
						targetCube.quadFaces[5] = quadRen->createQuadRight(x, y, z, 0.0f, 1.0f);


						tmpChunk.blocks.push_back(targetCube);
					}


				}
			}
		}
	}


	

	for (const auto& chunk : chunklist)
	{

		for (int i = 0; i < chunk.blocks.size(); i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (chunk.blocks[i].quadFaces[j].vertices->faceType == 1)
				{
					viewableBlocks.push_back(chunk.blocks[i].quadFaces[j]);
				}
			}
		}
	}
	
	

	
	
		

	
	

	
}

void chunkGen::proceduralChunkGen(const glm::vec3& playerPos)
{
	int currentChunkPosZ = ((int)playerPos.z / 16) * 16;
	int currentChunkPosX = ((int)playerPos.x / 16) * 16;
	
	
	

}

void chunkGen::GenChunks()
{
	if (m_terrainGen == false)
	{
		
		
				GenChunk(m_maxChunksX * m_maxChunkSizeXZ, m_maxChunksZ * m_maxChunkSizeXZ);
				
			
		
		
		m_terrainGen = true;
	}

}
