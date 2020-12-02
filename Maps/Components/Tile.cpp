#include "stdafx.h"
#include "Tile.h"

Tile::Tile()
{
	int inte = 2 + GRID;//inteval
	{
		tiles[0] = new Sprite(tileSprite, Shaders9, inte + 1, 1, inte + 1 + GRID, 1 + GRID);
		tiles[1] = new Sprite(tileSprite, Shaders9, 1, 1, 1 + GRID, 1 + GRID);
		tiles[2] = new Sprite(tileSprite, Shaders9, inte + 1, inte + 1, inte + 1 + GRID, inte + 1 + GRID);
		tiles[3] = new Sprite(tileSprite, Shaders9, inte * 2 + 1, inte + 1, inte * 2 + 1 + GRID, inte + 1 + GRID);
		tiles[4] = new Sprite(tileSprite, Shaders9, inte * 4 + 1, 1, inte * 4 + 1 + GRID, 1 + GRID);
		tiles[5] = new Sprite(tileSprite, Shaders9, inte * 3 + 1, 1, inte * 3 + 1 + GRID, 1 + GRID);
		tiles[6] = new Sprite(tileSprite, Shaders9, inte * 4 + 1, inte + 1, inte * 4 + 1 + GRID, inte + 1 + GRID);
		tiles[7] = new Sprite(tileSprite, Shaders9, inte * 5 + 1, inte + 1, inte * 5 + 1 + GRID, inte + 1 + GRID);

		tiles[8] = new Sprite(tileSprite, Shaders9, inte * 6 + 1, 1, inte * 6 + 1 + GRID, 1 + GRID);
		tiles[9] = new Sprite(tileSprite, Shaders9, inte * 7 + 1, 1, inte * 7 + 1 + GRID, 1 + GRID);
		tiles[10] = new Sprite(tileSprite, Shaders9, inte * 6 + 1, inte + 1, inte * 6 + 1 + GRID, inte + 1 + GRID);
		tiles[11] = new Sprite(tileSprite, Shaders9, inte * 7 + 1, inte + 1, inte * 7 + 1 + GRID, inte + 1 + GRID);

		tiles[12] = new Sprite(tileSprite, Shaders9, 1, inte * 2 + 1, 1 + GRID, inte * 2 + 1 + GRID);
		tiles[13] = new Sprite(tileSprite, Shaders9, inte + 1, inte * 2 + 1, inte + 1 + GRID, inte * 2 + 1 + GRID);
		tiles[14] = new Sprite(tileSprite, Shaders9, inte * 2 + 1, inte * 2 + 1, inte * 2 + 1 + GRID, inte * 2 + 1 + GRID);
		tiles[15] = new Sprite(tileSprite, Shaders9, inte * 3 + 1, inte * 2 + 1, inte * 3 + 1 + GRID, inte * 2 + 1 + GRID);
		tiles[16] = new Sprite(tileSprite, Shaders9, inte * 4 + 1, inte * 2 + 1, inte * 4 + 1 + GRID, inte * 2 + 1 + GRID);
		tiles[17] = new Sprite(tileSprite, Shaders9, inte * 5 + 1, inte * 2 + 1, inte * 5 + 1 + GRID, inte * 2 + 1 + GRID);

		tiles[18] = new Sprite(tileSprite, Shaders9, 1, inte * 3 + 1, 1 + GRID, inte * 3 + 1 + GRID);
		tiles[19] = new Sprite(tileSprite, Shaders9, inte + 1, inte * 3 + 1, inte + 1 + GRID, inte * 3 + 1 + GRID);
		tiles[20] = new Sprite(tileSprite, Shaders9, inte * 2 + 1, inte * 3 + 1, inte * 2 + 1 + GRID, inte * 3 + 1 + GRID);
		tiles[21] = new Sprite(tileSprite, Shaders9, inte * 3 + 1, inte * 3 + 1, inte * 3 + 1 + GRID, inte * 3 + 1 + GRID);
		tiles[22] = new Sprite(tileSprite, Shaders9, inte * 4 + 1, inte * 3 + 1, inte * 4 + 1 + GRID, inte * 3 + 1 + GRID);
		tiles[23] = new Sprite(tileSprite, Shaders9, inte * 5 + 1, inte * 3 + 1, inte * 5 + 1 + GRID, inte * 3 + 1 + GRID);

		tiles[24] = new Sprite(tileSprite, Shaders9, 1, inte * 4 + 1, 1 + GRID, inte * 4 + 1 + GRID);
		tiles[25] = new Sprite(tileSprite, Shaders9, inte + 1, inte * 4 + 1, inte + 1 + GRID, inte * 4 + 1 + GRID);
		tiles[26] = new Sprite(tileSprite, Shaders9, inte * 2 + 1, inte * 4 + 1, inte * 2 + 1 + GRID, inte * 4 + 1 + GRID);
		tiles[27] = new Sprite(tileSprite, Shaders9, inte * 3 + 1, inte * 4 + 1, inte * 3 + 1 + GRID, inte * 4 + 1 + GRID);
		tiles[28] = new Sprite(tileSprite, Shaders9, inte * 4 + 1, inte * 4 + 1, inte * 4 + 1 + GRID, inte * 4 + 1 + GRID);
		tiles[29] = new Sprite(tileSprite, Shaders9, inte * 5 + 1, inte * 4 + 1, inte * 5 + 1 + GRID, inte * 4 + 1 + GRID);

		tiles[30] = new Sprite(tileSprite, Shaders9, 1, inte * 5 + 1, 1 + GRID, inte * 5 + 1 + GRID);
		tiles[31] = new Sprite(tileSprite, Shaders9, inte + 1, inte * 5 + 1, inte + 1 + GRID, inte * 5 + 1 + GRID);
		tiles[32] = new Sprite(tileSprite, Shaders9, inte * 2 + 1, inte * 5 + 1, inte * 2 + 1 + GRID, inte * 5 + 1 + GRID);
		tiles[33] = new Sprite(tileSprite, Shaders9, inte * 3 + 1, inte * 5 + 1, inte * 3 + 1 + GRID, inte * 5 + 1 + GRID);
		tiles[34] = new Sprite(tileSprite, Shaders9, inte * 4 + 1, inte * 5 + 1, inte * 4 + 1 + GRID, inte * 5 + 1 + GRID);
		tiles[35] = new Sprite(tileSprite, Shaders9, inte * 5 + 1, inte * 5 + 1, inte * 5 + 1 + GRID, inte * 5 + 1 + GRID);

		tiles[36] = new Sprite(tileSprite, Shaders9, inte * 6 + 1, inte * 2 + 1, inte * 6 + 1 + GRID, inte * 2 + 1 + GRID);
		tiles[37] = new Sprite(tileSprite, Shaders9, inte * 7 + 1, inte * 2 + 1, inte * 7 + 1 + GRID, inte * 2 + 1 + GRID);
		tiles[38] = new Sprite(tileSprite, Shaders9, inte * 8 + 1, inte * 2 + 1, inte * 8 + 1 + GRID, inte * 2 + 1 + GRID);
		tiles[39] = new Sprite(tileSprite, Shaders9, inte * 6 + 1, inte * 3 + 1, inte * 6 + 1 + GRID, inte * 3 + 1 + GRID);
		tiles[40] = new Sprite(tileSprite, Shaders9, inte * 7 + 1, inte * 3 + 1, inte * 7 + 1 + GRID, inte * 3 + 1 + GRID);

		tiles[41] = new Sprite(tileSprite, Shaders9, inte * 6 + 1, inte * 4 + 1, inte * 6 + 1 + GRID, inte * 4 + 1 + GRID);
		tiles[42] = new Sprite(tileSprite, Shaders9, inte * 7 + 1, inte * 4 + 1, inte * 7 + 1 + GRID, inte * 4 + 1 + GRID);
		tiles[43] = new Sprite(tileSprite, Shaders9, inte * 8 + 1, inte * 4 + 1, inte * 8 + 1 + GRID, inte * 4 + 1 + GRID);
		tiles[44] = new Sprite(tileSprite, Shaders9, inte * 6 + 1, inte * 5 + 1, inte * 6 + 1 + GRID, inte * 5 + 1 + GRID);
		tiles[45] = new Sprite(tileSprite, Shaders9, inte * 7 + 1, inte * 5 + 1, inte * 7 + 1 + GRID, inte * 5 + 1 + GRID);
		tiles[46] = new Sprite(tileSprite, Shaders9, inte * 8 + 1, inte * 5 + 1, inte * 8 + 1 + GRID, inte * 5 + 1 + GRID);
	}
}

Tile::~Tile()
{
	for (Sprite* tile : tiles)
		SAFE_DELETE(tile);
}

void Tile::Update(D3DXMATRIX & V, D3DXMATRIX & P)
{
	for (Sprite* tile : tiles)
		tile->Update(V, P);
}

void Tile::Update(TileName name, D3DXMATRIX & V, D3DXMATRIX & P)
{
	tiles[name]->Update(V, P);
}

void Tile::Render()
{
	for (Sprite* tile : tiles)
		tile->Render();
}

void Tile::Render(TileName name)
{
	tiles[name]->Render();
}

void Tile::Render(TileName name, D3DXVECTOR2 & vec)
{
	tiles[name]->Render(vec);
}
