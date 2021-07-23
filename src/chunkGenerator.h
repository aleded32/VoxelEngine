#pragma once
#include "quadRenderer.h"
#include <unordered_map>

#define MAX_CUBE_X 16
#define MAX_CUBE_Y 256
#define MAX_CUBE_Z 16
#define BASE_HEIGHT_Y 64

struct chunk
{
	cube* blocks;
};

class chunkGen
{
public:
	chunkGen(int maxChunkSizeXZ);
	~chunkGen();

	void drawChunks(camera& cam);
	
	void GenChunks();


private:

	void cullBlocks();
	chunk GenChunk(int chunkOffsetX, int chunkOffsetZ, int maxChunkX, int maxChunkZ);
	quadRenderer* quadRen;
	std::unordered_map<unsigned int, chunk> m_chunkCache;
	std::vector<chunk> m_rendererdChunks;
	bool m_terrainGen = false;
	int m_maxChunksX = 1;
	int m_maxChunksZ = 1;

	int m_maxChunkSizeXZ;
};

