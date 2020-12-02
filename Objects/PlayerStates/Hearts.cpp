#include "stdafx.h"
#include "Hearts.h"

Hearts::Hearts()
{
	//hearts
	static Sprite fHeart(HudTextures, Shaders9, 0, 0, 24, 22);//full
	//fHeart = Sprite(HudTextures, Shaders9, 0, 0, 24, 22);// 24,22
	hHeart = new Sprite(HudTextures, Shaders9, 29, 0, 53, 22);
	eHeart = new Sprite(HudTextures, Shaders9, 58, 0, 82, 22);


	{//hearts-init
		hearts.push_back(new Sprite(HudTextures, Shaders9, 0, 0, 24, 22));
		hearts.push_back(new Sprite(HudTextures, Shaders9, 0, 0, 24, 22));
		hearts.push_back(new Sprite(HudTextures, Shaders9, 0, 0, 24, 22));
	}

}

Hearts::~Hearts()
{
	SAFE_DELETE(hHeart);
	SAFE_DELETE(eHeart);
	for (Sprite* heart : hearts)
		SAFE_DELETE(heart);
}

void Hearts::Position(D3DXVECTOR2 & cameraPo)
{
	for (int i = 0; i < hearts.size(); i++)
		hearts[i]->Position(cameraPo.x + Width / 2 - GRID * 0.5 - (GRID * SCALE * (3 + i)), cameraPo.y + Height / 2 - GRID * SCALE / 2);

}

void Hearts::Update(D3DXMATRIX & V, D3DXMATRIX & P)
{
	if (bBigHeart)
	{
		heartBeatTimer += Timer->Elapsed();
		if (heartBeatTimer > 0.3f)
		{
			bBigHeart = false;
			heartBeatTimer = 0;
		}
	}
	if (!bBigHeart)
		hearts[heartBeat]->Scale(SCALE, SCALE);

	if (Beats->GetBeatState() == eBeatEnd)
		bPass = false;

	if (Beats->GetBeatState() == eBeatStart && !bPass)
	{
		if (heartBeat == 0)
			heartBeat = hearts.size() - 1;
		else
			heartBeat--;

		hearts[heartBeat]->Scale(4.5, 4.5);
		bBigHeart = true;
		bPass = true;
	}
	

	for (Sprite* heart : hearts)
		heart->Update(V, P);
}

void Hearts::Render()
{
	for (Sprite* heart : hearts)
		heart->Render();
}

void Hearts::CalculateLife()
{
	if (lifeMax != lastLifeMax)
	{
		hearts.clear();
		if (lifeMax - (int)lifeMax != 0)
		{

		}
		for (int i = 0; i < (int)lifeMax; i++)
		{
			hearts.push_back(new Sprite(HudTextures, Shaders9, 0, 0, 24, 22));
		}
		lastLifeMax = lifeMax;
	}
}
