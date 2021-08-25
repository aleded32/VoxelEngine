#pragma once
#include "quadRenderer.h"
#include <unordered_map>
#include <algorithm>


#define MAX_CUBE_Y 64
#define BASE_HEIGHT_Y 33


struct chunk
{
	std::vector<quad> blocks;
};

class chunkGen
{
public:
	chunkGen(int maxChunkSizeXZ);
	~chunkGen();

	void drawChunks(camera& cam);
	
	void GenChunks();


private:

	void cullblocks(chunk& targetChunk, int maxX, int maxZ);
	

	chunk GenChunk(int chunkOffsetX, int chunkOffsetZ,  int maxChunkX, int maxChunkZ);
	quadRenderer* quadRen;
	std::unordered_map<unsigned int, chunk> m_chunkCache;
	std::vector<chunk> m_rendererdChunks;
	bool m_terrainGen = false;
	int m_maxChunksX = 3;
	int m_maxChunksZ = 3;
	int m_maxChunkSizeXZ;

	enum class faces { front, up, down, back, left, right };

	faces currentFace = faces::front;

	

	void m_cube(float x, float y, float z, quadRenderer &quadrenderer, std::vector<quad>& blocks)
	{
		

		blocks.push_back(quadrenderer.createQuadRight(x, y, z, 0.0f, 1.0f));
		blocks.push_back(quadrenderer.createQuadLeft(x, y, z, 0.0f, 1.0f));
		blocks.push_back(quadrenderer.createQuadBack(x, y, z, 0.0f, 1.0f));
		blocks.push_back(quadrenderer.createQuadDown(x, y, z, 0.0f, 1.0f));
		blocks.push_back(quadrenderer.createQuadUp(x, y, z, 0.0f, 1.0f));
		blocks.push_back(quadrenderer.createQuadFront(x, y, z, 0.0f, 1.0f));

	}
	

	
};

