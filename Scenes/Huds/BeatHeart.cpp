#include "stdafx.h"
#include "BeatHeart.h"

BeatHeart::BeatHeart()
{
	bigHeart = new Sprite(HudTextures, Shaders9, 155, 0, 195, 50);
	smallHeart = new Sprite(HudTextures, Shaders9, 117, 4, 151, 48);
	beatHeart = smallHeart;
}

BeatHeart::~BeatHeart()
{
	if (beatHeart == bigHeart)
	{
		SAFE_DELETE(smallHeart);
	}
	else
		SAFE_DELETE(bigHeart);
	SAFE_DELETE(beatHeart);
}

void BeatHeart::UpdateState(BeatState beatState)
{
	if (beatState == eBeatStart)
		beatHeart = bigHeart;
	else if(beatState==eBeatEnd)
		beatHeart = smallHeart;
}

void BeatHeart::Position(D3DXVECTOR2 & cameraPo)
{
	bigHeart->Position(cameraPo.x, cameraPo.y - beatPoY);
	smallHeart->Position(cameraPo.x, cameraPo.y - beatPoY);
}

void BeatHeart::Update(D3DXMATRIX & V, D3DXMATRIX & P)
{
	beatHeart->Update(V, P);
}

void BeatHeart::Render()
{
	beatHeart->Render();
}
