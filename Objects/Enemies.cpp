#include "stdafx.h"
#include "Enemies.h"

Enemies::Enemies()
{
}

Enemies::~Enemies()
{
}

void Enemies::Update(D3DXMATRIX & V, D3DXMATRIX & P)
{
	monsters.Update(V, P);
	miniBosses.Update(V, P);
}

void Enemies::Render()
{
	monsters.Render();
	miniBosses.Render();
}

void Enemies::Render(MonsterName name, D3DXVECTOR2 & vec)
{
	monsters.Render(name, vec);
}

void Enemies::OpenBinaryFile(wstring file)
{
}
