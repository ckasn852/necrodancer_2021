#include "stdafx.h"
#include "Monsters.h"

Monsters::Monsters()
{
	Clip* clip;
	{
		monsters.push_back(new Animation());
		clip = new Clip(PlayMode::Loop);
		clip->AddFrame(new Sprite(slimeSprite, Shaders9, 4, 0, 26, 25), ANIMFRAME);
		clip->AddFrame(new Sprite(slimeSprite, Shaders9, 30, 0, 53, 25), ANIMFRAME);
		clip->AddFrame(new Sprite(slimeSprite, Shaders9, 54, 0, 80, 25), ANIMFRAME);
		clip->AddFrame(new Sprite(slimeSprite, Shaders9, 84, 0, 102, 25), ANIMFRAME);
		monsters[0]->AddClip(clip);

		clip = new Clip(PlayMode::Loop);
		clip->AddFrame(new Sprite(slimeSprite, Shaders9, 4, 0, 26, 25), ANIMFRAME);
		clip->AddFrame(new Sprite(slimeSprite, Shaders9, 30, 0, 53, 25), ANIMFRAME);
		clip->AddFrame(new Sprite(slimeSprite, Shaders9, 54, 0, 80, 25), ANIMFRAME);
		clip->AddFrame(new Sprite(slimeSprite, Shaders9, 84, 0, 102, 25), ANIMFRAME);
		monsters[0]->AddClip(clip);
		monsters[0]->Play(0);
	}
	{
		monsters.push_back(new Animation());
		clip = new Clip(PlayMode::Loop);
		clip->AddFrame(new Sprite(slimeSprite, Shaders9, 4, 56, 23, 81), ANIMFRAME);
		clip->AddFrame(new Sprite(slimeSprite, Shaders9, 29, 56, 49, 81), ANIMFRAME);
		clip->AddFrame(new Sprite(slimeSprite, Shaders9, 54, 56, 76, 81), ANIMFRAME);
		clip->AddFrame(new Sprite(slimeSprite, Shaders9, 81, 56, 103, 81), ANIMFRAME);
		monsters[1]->AddClip(clip);

		clip = new Clip(PlayMode::Loop);
		clip->AddFrame(new Sprite(slimeSprite, Shaders9, 107, 56, 129, 81), ANIMFRAME);
		clip->AddFrame(new Sprite(slimeSprite, Shaders9, 132, 56, 154, 81), ANIMFRAME);
		clip->AddFrame(new Sprite(slimeSprite, Shaders9, 156, 56, 182, 81), ANIMFRAME);
		clip->AddFrame(new Sprite(slimeSprite, Shaders9, 187, 56, 205, 81), ANIMFRAME);
		monsters[1]->AddClip(clip);


		clip = new Clip(PlayMode::Loop);
		clip->AddFrame(new Sprite(slimeSprite, Shaders9, 4, 81, 23, 106), ANIMFRAME);
		clip->AddFrame(new Sprite(slimeSprite, Shaders9, 29, 81, 49, 106), ANIMFRAME);
		clip->AddFrame(new Sprite(slimeSprite, Shaders9, 54, 81, 76, 106), ANIMFRAME);
		clip->AddFrame(new Sprite(slimeSprite, Shaders9, 81, 81, 103, 106), ANIMFRAME);
		monsters[1]->AddClip(clip);

		clip = new Clip(PlayMode::Loop);
		clip->AddFrame(new Sprite(slimeSprite, Shaders9, 107, 81, 129, 106), ANIMFRAME);
		clip->AddFrame(new Sprite(slimeSprite, Shaders9, 132, 81, 154, 106), ANIMFRAME);
		clip->AddFrame(new Sprite(slimeSprite, Shaders9, 156, 81, 182, 106), ANIMFRAME);
		clip->AddFrame(new Sprite(slimeSprite, Shaders9, 187, 81, 205, 106), ANIMFRAME);
		monsters[1]->AddClip(clip);
		monsters[1]->Play(0);
	}
	{//gold slime
		monsters.push_back(new Animation());
		clip = new Clip(PlayMode::Loop);
		clip->AddFrame(new Sprite(slimeSprite, Shaders9, 4, 111, 26, 136), ANIMFRAME);
		clip->AddFrame(new Sprite(slimeSprite, Shaders9, 30, 111, 53, 136), ANIMFRAME);
		clip->AddFrame(new Sprite(slimeSprite, Shaders9, 54, 111, 80, 136), ANIMFRAME);
		clip->AddFrame(new Sprite(slimeSprite, Shaders9, 84, 111, 102, 136), ANIMFRAME);
		monsters[2]->AddClip(clip);

		clip = new Clip(PlayMode::Loop);
		clip->AddFrame(new Sprite(slimeSprite, Shaders9, 4, 137, 26, 162), ANIMFRAME);
		clip->AddFrame(new Sprite(slimeSprite, Shaders9, 30, 137, 53, 162), ANIMFRAME);
		clip->AddFrame(new Sprite(slimeSprite, Shaders9, 54, 137, 80, 162), ANIMFRAME);
		clip->AddFrame(new Sprite(slimeSprite, Shaders9, 84, 137, 102, 162), ANIMFRAME);
		monsters[2]->AddClip(clip);
		monsters[2]->Play(0);
	}
	{//fire slime
		monsters.push_back(new Animation());
		clip = new Clip(PlayMode::Loop);
		clip->AddFrame(new Sprite(slimeSprite, Shaders9, 4, 167, 26, 192), ANIMFRAME);
		clip->AddFrame(new Sprite(slimeSprite, Shaders9, 30, 167, 53, 192), ANIMFRAME);
		clip->AddFrame(new Sprite(slimeSprite, Shaders9, 54, 167, 80, 192), ANIMFRAME);
		clip->AddFrame(new Sprite(slimeSprite, Shaders9, 84, 167, 102, 192), ANIMFRAME);
		monsters[3]->AddClip(clip);

		clip = new Clip(PlayMode::Loop);
		clip->AddFrame(new Sprite(slimeSprite, Shaders9, 4, 193, 26, 218), ANIMFRAME);
		clip->AddFrame(new Sprite(slimeSprite, Shaders9, 30, 193, 53, 218), ANIMFRAME);
		clip->AddFrame(new Sprite(slimeSprite, Shaders9, 54, 193, 80, 218), ANIMFRAME);
		clip->AddFrame(new Sprite(slimeSprite, Shaders9, 84, 193, 102, 218), ANIMFRAME);
		monsters[3]->AddClip(clip);
		monsters[3]->Play(0);
	}
	{//ice slime
		monsters.push_back(new Animation());
		clip = new Clip(PlayMode::Loop);
		clip->AddFrame(new Sprite(slimeSprite, Shaders9, 4, 223, 26, 248), ANIMFRAME);
		clip->AddFrame(new Sprite(slimeSprite, Shaders9, 30, 223, 53, 248), ANIMFRAME);
		clip->AddFrame(new Sprite(slimeSprite, Shaders9, 54, 223, 80, 248), ANIMFRAME);
		clip->AddFrame(new Sprite(slimeSprite, Shaders9, 84, 223, 102, 248), ANIMFRAME);
		monsters[4]->AddClip(clip);

		clip = new Clip(PlayMode::Loop);
		clip->AddFrame(new Sprite(slimeSprite, Shaders9, 4, 249, 26, 274), ANIMFRAME);
		clip->AddFrame(new Sprite(slimeSprite, Shaders9, 30, 249, 53, 274), ANIMFRAME);
		clip->AddFrame(new Sprite(slimeSprite, Shaders9, 54, 249, 80, 274), ANIMFRAME);
		clip->AddFrame(new Sprite(slimeSprite, Shaders9, 84, 249, 102, 274), ANIMFRAME);
		monsters[4]->AddClip(clip);
		monsters[4]->Play(0);
	}
}

Monsters::~Monsters()
{
	for (Animation* monster : monsters)
		SAFE_DELETE(monster);
}

void Monsters::Update(D3DXMATRIX & V, D3DXMATRIX & P)
{
	for (Animation* monster : monsters)
		monster->Update(V, P);
}

void Monsters::Render()
{
	for (Animation* monster : monsters)
		monster->Render();
}

void Monsters::Render(MonsterName name, D3DXVECTOR2 & vec)
{
	monsters[name]->Render(vec);
}
