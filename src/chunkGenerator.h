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
	

	void GenChunk(int chunkOffsetX, int chunkOffsetZ,  int maxChunkX, int maxChunkZ);
	quadRenderer* quadRen;
	std::unordered_map<unsigned int, chunk> m_chunkCache;
	std::vector<quad> m_rendererdChunks;

	bool m_terrainGen = false;
	int m_maxChunksX;
	int m_maxChunksZ;
	int m_maxChunkSizeXZ;

	enum class faces { front, up, down, back, left, right };


	cube targetCube;

	std::vector<quad> viewableBlocks;

	void m_cube(float x, float y, float z, quadRenderer &quadrenderer, std::vector<cube>& blocks)
	{
		


		targetCube.quadFaces[0] = quadrenderer.createQuadFront(x, y, z, 0.0f, 1.0f);
		targetCube.quadFaces[1] = quadrenderer.createQuadUp(x, y, z, 0.0f, 1.0f);
		targetCube.quadFaces[2] = quadrenderer.createQuadDown(x, y, z, 0.0f, 1.0f);
		targetCube.quadFaces[3] = quadrenderer.createQuadBack(x, y, z, 0.0f, 1.0f);
		targetCube.quadFaces[4] = quadrenderer.createQuadLeft(x, y, z, 0.0f, 1.0f);
		targetCube.quadFaces[5] = quadrenderer.createQuadRight(x, y, z, 0.0f, 1.0f);


		blocks.push_back(targetCube);
	}
	

	
};

