#include "stdafx.h"
#include "Map.h"

Map::Map()
{
	tiles.resize(tileMax);
	walls.resize(wallMax);
	elements.resize(tWElementMax);
	fires.resize(fireMax);
	int inte = 2 + GRID;//inteval
	{
		tiles[0] = new Sprite(tileSprite, shaderFile, inte + 1, 1, inte + 1 + GRID, 1 + GRID);
		tiles[1] = new Sprite(tileSprite, shaderFile, 1, 1, 1 + GRID, 1 + GRID);
		tiles[2] = new Sprite(tileSprite, shaderFile, inte + 1, inte + 1, inte + 1 + GRID, inte + 1 + GRID);
		tiles[3] = new Sprite(tileSprite, shaderFile, inte * 2 + 1, inte + 1, inte * 2 + 1 + GRID, inte + 1 + GRID);
		tiles[4] = new Sprite(tileSprite, shaderFile, inte * 4 + 1, 1, inte * 4 + 1 + GRID, 1 + GRID);
		tiles[5] = new Sprite(tileSprite, shaderFile, inte * 3 + 1, 1, inte * 3 + 1 + GRID, 1 + GRID);
		tiles[6] = new Sprite(tileSprite, shaderFile, inte * 4 + 1, inte + 1, inte * 4 + 1 + GRID, inte + 1 + GRID);
		tiles[7] = new Sprite(tileSprite, shaderFile, inte * 5 + 1, inte + 1, inte * 5 + 1 + GRID, inte + 1 + GRID);

		tiles[8] = new Sprite(tileSprite, shaderFile, inte * 6 + 1, 1, inte * 6 + 1 + GRID, 1 + GRID);
		tiles[9] = new Sprite(tileSprite, shaderFile, inte * 7 + 1, 1, inte * 7 + 1 + GRID, 1 + GRID);
		tiles[10] = new Sprite(tileSprite, shaderFile, inte * 6 + 1, inte + 1, inte * 6 + 1 + GRID, inte + 1 + GRID);
		tiles[11] = new Sprite(tileSprite, shaderFile, inte * 7 + 1, inte + 1, inte * 7 + 1 + GRID, inte + 1 + GRID);

		tiles[12] = new Sprite(tileSprite, shaderFile, 1, inte * 2 + 1, 1 + GRID, inte * 2 + 1 + GRID);
		tiles[13] = new Sprite(tileSprite, shaderFile, inte + 1, inte * 2 + 1, inte + 1 + GRID, inte * 2 + 1 + GRID);
		tiles[14] = new Sprite(tileSprite, shaderFile, inte * 2 + 1, inte * 2 + 1, inte * 2 + 1 + GRID, inte * 2 + 1 + GRID);
		tiles[15] = new Sprite(tileSprite, shaderFile, inte * 3 + 1, inte * 2 + 1, inte * 3 + 1 + GRID, inte * 2 + 1 + GRID);
		tiles[16] = new Sprite(tileSprite, shaderFile, inte * 4 + 1, inte * 2 + 1, inte * 4 + 1 + GRID, inte * 2 + 1 + GRID);
		tiles[17] = new Sprite(tileSprite, shaderFile, inte * 5 + 1, inte * 2 + 1, inte * 5 + 1 + GRID, inte * 2 + 1 + GRID);

		tiles[18] = new Sprite(tileSprite, shaderFile, 1, inte * 3 + 1, 1 + GRID, inte * 3 + 1 + GRID);
		tiles[19] = new Sprite(tileSprite, shaderFile, inte + 1, inte * 3 + 1, inte + 1 + GRID, inte * 3 + 1 + GRID);
		tiles[20] = new Sprite(tileSprite, shaderFile, inte * 2 + 1, inte * 3 + 1, inte * 2 + 1 + GRID, inte * 3 + 1 + GRID);
		tiles[21] = new Sprite(tileSprite, shaderFile, inte * 3 + 1, inte * 3 + 1, inte * 3 + 1 + GRID, inte * 3 + 1 + GRID);
		tiles[22] = new Sprite(tileSprite, shaderFile, inte * 4 + 1, inte * 3 + 1, inte * 4 + 1 + GRID, inte * 3 + 1 + GRID);
		tiles[23] = new Sprite(tileSprite, shaderFile, inte * 5 + 1, inte * 3 + 1, inte * 5 + 1 + GRID, inte * 3 + 1 + GRID);

		tiles[24] = new Sprite(tileSprite, shaderFile, 1, inte * 4 + 1, 1 + GRID, inte * 4 + 1 + GRID);
		tiles[25] = new Sprite(tileSprite, shaderFile, inte + 1, inte * 4 + 1, inte + 1 + GRID, inte * 4 + 1 + GRID);
		tiles[26] = new Sprite(tileSprite, shaderFile, inte * 2 + 1, inte * 4 + 1, inte * 2 + 1 + GRID, inte * 4 + 1 + GRID);
		tiles[27] = new Sprite(tileSprite, shaderFile, inte * 3 + 1, inte * 4 + 1, inte * 3 + 1 + GRID, inte * 4 + 1 + GRID);
		tiles[28] = new Sprite(tileSprite, shaderFile, inte * 4 + 1, inte * 4 + 1, inte * 4 + 1 + GRID, inte * 4 + 1 + GRID);
		tiles[29] = new Sprite(tileSprite, shaderFile, inte * 5 + 1, inte * 4 + 1, inte * 5 + 1 + GRID, inte * 4 + 1 + GRID);

		tiles[30] = new Sprite(tileSprite, shaderFile, 1, inte * 5 + 1, 1 + GRID, inte * 5 + 1 + GRID);
		tiles[31] = new Sprite(tileSprite, shaderFile, inte + 1, inte * 5 + 1, inte + 1 + GRID, inte * 5 + 1 + GRID);
		tiles[32] = new Sprite(tileSprite, shaderFile, inte * 2 + 1, inte * 5 + 1, inte * 2 + 1 + GRID, inte * 5 + 1 + GRID);
		tiles[33] = new Sprite(tileSprite, shaderFile, inte * 3 + 1, inte * 5 + 1, inte * 3 + 1 + GRID, inte * 5 + 1 + GRID);
		tiles[34] = new Sprite(tileSprite, shaderFile, inte * 4 + 1, inte * 5 + 1, inte * 4 + 1 + GRID, inte * 5 + 1 + GRID);
		tiles[35] = new Sprite(tileSprite, shaderFile, inte * 5 + 1, inte * 5 + 1, inte * 5 + 1 + GRID, inte * 5 + 1 + GRID);

		tiles[36] = new Sprite(tileSprite, shaderFile, inte * 6 + 1, inte * 2 + 1, inte * 6 + 1 + GRID, inte * 2 + 1 + GRID);
		tiles[37] = new Sprite(tileSprite, shaderFile, inte * 7 + 1, inte * 2 + 1, inte * 7 + 1 + GRID, inte * 2 + 1 + GRID);
		tiles[38] = new Sprite(tileSprite, shaderFile, inte * 8 + 1, inte * 2 + 1, inte * 8 + 1 + GRID, inte * 2 + 1 + GRID);
		tiles[39] = new Sprite(tileSprite, shaderFile, inte * 6 + 1, inte * 3 + 1, inte * 6 + 1 + GRID, inte * 3 + 1 + GRID);
		tiles[40] = new Sprite(tileSprite, shaderFile, inte * 7 + 1, inte * 3 + 1, inte * 7 + 1 + GRID, inte * 3 + 1 + GRID);

		tiles[41] = new Sprite(tileSprite, shaderFile, inte * 6 + 1, inte * 4 + 1, inte * 6 + 1 + GRID, inte * 4 + 1 + GRID);
		tiles[42] = new Sprite(tileSprite, shaderFile, inte * 7 + 1, inte * 4 + 1, inte * 7 + 1 + GRID, inte * 4 + 1 + GRID);
		tiles[43] = new Sprite(tileSprite, shaderFile, inte * 8 + 1, inte * 4 + 1, inte * 8 + 1 + GRID, inte * 4 + 1 + GRID);
		tiles[44] = new Sprite(tileSprite, shaderFile, inte * 6 + 1, inte * 5 + 1, inte * 6 + 1 + GRID, inte * 5 + 1 + GRID);
		tiles[45] = new Sprite(tileSprite, shaderFile, inte * 7 + 1, inte * 5 + 1, inte * 7 + 1 + GRID, inte * 5 + 1 + GRID);
		tiles[tileMax-1] = new Sprite(tileSprite, shaderFile, inte * 8 + 1, inte * 5 + 1, inte * 8 + 1 + GRID, inte * 5 + 1 + GRID);
	}
	{
		for (int i = 0; i < 34; i++)
			walls[i] = new Sprite(wallSprite, shaderFile, GRID * i, 0, GRID * i + GRID, 42);
		for (int i = 0; i < 19; i++)
			walls[i+34] = new Sprite(wallSprite, shaderFile, GRID * i, 288, GRID * i + GRID, 330);
	}

	{
		elements[0]= new Sprite(wallSprite, shaderFile, 504, 288, 528, 312);

		elements[1] = new Sprite(wallSprite, shaderFile, 528, 288, 552, 312);
		elements[2] = new Sprite(wallSprite, shaderFile, 552, 288, 572, 312);
		elements[3] = new Sprite(wallSprite, shaderFile, 572, 288, 596, 312);
		elements[4] = new Sprite(wallSprite, shaderFile, 596, 288, 616, 312);

		elements[5] = new Sprite(wallSprite, shaderFile, 528, 312, 552, 336);
		elements[6] = new Sprite(wallSprite, shaderFile, 552, 312, 572, 336);
		elements[7] = new Sprite(wallSprite, shaderFile, 572, 312, 596, 336);
		elements[tWElementMax-1] = new Sprite(wallSprite, shaderFile, 596, 312, 616, 336);
	}
	{
		fires[0] = new Animation();
		Clip* clip;
		{
			clip = new Clip(PlayMode::Loop);
			clip->AddFrame(new Sprite(wallSprite, shaderFile, 456, 288, 468, 310), ANIMFRAME);
			clip->AddFrame(new Sprite(wallSprite, shaderFile, 468, 288, 480, 310), ANIMFRAME);
			clip->AddFrame(new Sprite(wallSprite, shaderFile, 480, 288, 492, 310), ANIMFRAME);
			clip->AddFrame(new Sprite(wallSprite, shaderFile, 492, 288, 504, 310), ANIMFRAME);
			fires[0]->AddClip(clip);
		}
		fires[0]->Play(0);
	}

	//////////////////////////////////////////////////


	{
		wallParticle = new Animation();
		Clip* clip;
		{
			clip = new Clip(PlayMode::Loop);
			//clip->AddFrame(new Sprite());
			wallParticle->AddClip(clip);
		}
		wallParticle->Play(0);
	}
}

Map::~Map()
{
	for (Sprite* tile : tiles)
		SAFE_DELETE(tile);
	for (Sprite* wall : walls)
		SAFE_DELETE(wall);
	for (Sprite* elementTW : elements)
		SAFE_DELETE(elementTW);
	for (Animation* mEle : fires)
		SAFE_DELETE(mEle);
	SAFE_DELETE(wallParticle);
}

void Map::Update(D3DXMATRIX & V, D3DXMATRIX & P)
{
	for (Sprite* tile : tiles)
		tile->Update(V, P);
	for (Sprite* wall : walls)
		wall->Update(V, P);
	for (Sprite* elementTW : elements)
		elementTW->Update(V, P);
	for (Animation* mEle : fires)
		mEle->Update(V, P);
	//wallParticle->Update(V, P);
}

void Map::Render()
{
	for (Sprite* tile : tiles)
		tile->Render();
	for (Sprite* wall : walls)
		wall->Render();
	for (Sprite* elementTW : elements)
		elementTW->Render();
	for (Animation* mEle : fires)
		mEle->Render();
}

void Map::WallCrush(D3DXVECTOR2 & vec)
{
	wallParticle->Render(vec);
}
