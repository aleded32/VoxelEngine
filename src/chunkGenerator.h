#pragma once
#include "quadRenderer.h"
#include <unordered_map>
#include <algorithm>


#define MAX_CUBE_Y 256
#define BASE_HEIGHT_Y 64


struct chunk
{
	std::vector<cube> blocks;
};

class chunkGen
{
public:
	chunkGen(int maxChunkSizeXZ);
	~chunkGen();

	void drawChunks(camera& cam);
	
	void GenChunks();

	void proceduralChunkGen(const glm::vec3& playerDir);


private:

	void cullblocks(chunk &targetChunk,int maxX);
	

	void GenChunk(int maxChunkX, int maxChunkZ);
	quadRenderer* quadRen;
	std::vector<chunk> chunklist;
	

	bool m_terrainGen = false;
	int m_maxChunksX;
	int m_maxChunksZ;
	int m_maxChunkSizeXZ;
	chunk baseChunk;

	enum class faces { front, up, down, back, left, right };

	

	cube targetCube;

	std::vector<quad> viewableBlocks;
	int currentChunk = 1;
	chunk tmpChunk;

	
	
	
	
};

