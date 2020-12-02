#include "stdafx.h"
#include "Resources/Coins.h"
#include "Resources/Diamonds.h"
#include "Resources.h"

Resources::Resources()
{
	coins = new Coins();
	diamonds = new Diamonds();
}

Resources::~Resources()
{
	SAFE_DELETE(coins);
	SAFE_DELETE(diamonds);
}

void Resources::Position(D3DXVECTOR2 & cameraPo)
{
	coins->Position(cameraPo);
	diamonds->Position(cameraPo);
}

void Resources::Update(D3DXMATRIX & V, D3DXMATRIX & P)
{
	coins->Update(V, P);
	diamonds->Update(V, P);
}

void Resources::Render()
{
	coins->Render();
	diamonds->Render();
}
