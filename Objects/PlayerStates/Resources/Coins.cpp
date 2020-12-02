#include "stdafx.h"
#include "Coins.h"

Coins::Coins()
{
	coin = new Sprite(HudTextures, Shaders9, 87, 27, 107, 47);
	coinNums[0] = Words->Number(0);
	coinNums[1] = NULL;
	coinNums[2] = NULL;
	coinNums[0]->Scale(6, 6);
}

Coins::~Coins()
{
	SAFE_DELETE(coin);
}

void Coins::Position(D3DXVECTOR2 & cameraPo)
{
	this->cameraPo = cameraPo;
	coin->Position(cameraPo.x + Width / 2 - GRID * SCALE * 2, cameraPo.y + Height / 2 - GRID * SCALE / 2);
}

void Coins::Update(D3DXMATRIX & V, D3DXMATRIX & P)
{
	
	//for (Sprite* coinNum : coinNums)

	coinNums[0]->Update(V, P);
	coin->Update(V, P);
}

void Coins::Render()
{
	//for (Sprite* coinNum : coinNums)

	coinNums[0]->Render(cameraPo.x + Width / 2 - GRID * SCALE*0.8, cameraPo.y + Height / 2 - GRID * SCALE / 2);
	coin->Render();
}
