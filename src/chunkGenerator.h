#pragma once
#include "quadRenderer.h"
#include <unordered_map>
#include <algorithm>


#define MAX_CUBE_Y 16
#define BASE_HEIGHT_Y 8

//bool comparison for std::remove to check against a flag for a blockType
static bool operator==(cube& block, const char* blockType)
{
	return block.cubeType = blockType;
}

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
	int m_maxChunksX = 1;
	int m_maxChunksZ = 1;
	int m_maxChunkSizeXZ;

	enum class faces { front, up, down, back, left, right };

	faces currentFace = faces::front;


	
	

	
};

