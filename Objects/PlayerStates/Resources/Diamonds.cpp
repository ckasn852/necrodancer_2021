#include "stdafx.h"
#include "Diamonds.h"

Diamonds::Diamonds()
{
	diamond=new Sprite(HudTextures,Shaders9, 87, 0, 112, 20);
	diaNums[0] = new Sprite(*Words->Number(0));
	diaNums[1] = NULL;
	diaNums[0]->Scale(6, 6);
}

Diamonds::~Diamonds()
{
	SAFE_DELETE(diamond);
}

void Diamonds::Position(D3DXVECTOR2 & cameraVec)
{
	cameraPo = cameraVec;
	diamond->Position(cameraPo.x + Width / 2 - GRID * SCALE * 2, cameraPo.y + Height / 2 - GRID * SCALE / 2 * 3);
}

void Diamonds::Update(D3DXMATRIX & V, D3DXMATRIX & P)
{
	diamond->Update(V, P);
	diaNums[0]->Update(V, P);
}

void Diamonds::Render()
{
	diaNums[0]->Render(cameraPo.x + Width / 2 - GRID * SCALE*0.8, cameraPo.y + Height / 2 - GRID * SCALE / 2 * 3);
	diamond->Render();
}
