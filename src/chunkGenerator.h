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


private:

	void cullblocks(chunk& targetChunk, int maxX, int maxZ);
	

	chunk GenChunk(int chunkOffsetX, int chunkOffsetZ,  int maxChunkX, int maxChunkZ);
	quadRenderer* quadRen;
	std::unordered_map<unsigned int, chunk> m_chunkCache;
	std::vector<chunk> m_rendererdChunks;
	bool m_terrainGen = false;
	int m_maxChunksX = 2;
	int m_maxChunksZ = 2;
	int m_maxChunkSizeXZ;

	enum class faces { front, up, down, back, left, right };

	faces currentFace = faces::front;


	
	

	
};

