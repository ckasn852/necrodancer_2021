#include "stdafx.h"
#include "Fire.h"

Fire::Fire()
{
	fire = new Animation();
	Clip* clip;
	{
		clip = new Clip(PlayMode::Loop);
		clip->AddFrame(new Sprite(wallSprite, Shaders9, 456, 288, 468, 310), ANIMATIONFRAME);
		clip->AddFrame(new Sprite(wallSprite, Shaders9, 468, 288, 480, 310), ANIMATIONFRAME);
		clip->AddFrame(new Sprite(wallSprite, Shaders9, 480, 288, 492, 310), ANIMATIONFRAME);
		clip->AddFrame(new Sprite(wallSprite, Shaders9, 492, 288, 504, 310), ANIMATIONFRAME);
		fire->AddClip(clip);
	}
	fire->Play(0);
}

Fire::~Fire()
{
	SAFE_DELETE(fire);
}

void Fire::Update(D3DXMATRIX & V, D3DXMATRIX & P)
{
	fire->Update(V, P);
}

void Fire::Render()
{
	fire->Render();
}

void Fire::Render(D3DXVECTOR2 & vec)
{
	fire->Render(vec);
}
