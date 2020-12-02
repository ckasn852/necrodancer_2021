#include "stdafx.h"
#include "Wall.h"

Wall::Wall()
{
	for (int i = 0; i < 34; i++)
		walls[i] = new Sprite(wallSprite, Shaders9, GRID * i, 0, GRID * i + GRID, 42);
	for (int i = 0; i < 19; i++)
		walls[i + 34] = new Sprite(wallSprite, Shaders9, GRID * i, 288, GRID * i + GRID, 330);
}

Wall::~Wall()
{
	for (Sprite* wall : walls)
		SAFE_DELETE(wall);
}

void Wall::Update(D3DXMATRIX & V, D3DXMATRIX & P)
{
	for (Sprite* wall : walls)
		wall->Update(V, P);
}

void Wall::Update(WallName name, D3DXMATRIX & V, D3DXMATRIX & P)
{
	walls[name]->Update(V, P);
}

void Wall::Render()
{
	for (Sprite* wall : walls)
		wall->Render();
}

void Wall::Render(WallName name)
{
	walls[name]->Render();
}

void Wall::Render(WallName name, D3DXVECTOR2 & vec)
{
	walls[name]->Render(vec);
}