#include "stdafx.h"
#include "Npcs.h"

Npcs::Npcs()
{
	Clip* clip;
	{
		npcs.push_back(new Animation());
		wstring textureFile = CryptTextures + L"Npcs/Hephaestus.png";
		{
			clip = new Clip(PlayMode::Loop);
			clip->AddFrame(new Sprite(textureFile, Shaders9, 0, 0, 65, 68), ANIMFRAME);
			clip->AddFrame(new Sprite(textureFile, Shaders9, 65, 0, 130, 68), ANIMFRAME);
			clip->AddFrame(new Sprite(textureFile, Shaders9, 130, 0, 195, 68), ANIMFRAME);
			clip->AddFrame(new Sprite(textureFile, Shaders9, 195, 0, 260, 68), ANIMFRAME);
			npcs[0]->AddClip(clip);
		}
		{
			clip = new Clip(PlayMode::Loop);
			clip->AddFrame(new Sprite(textureFile, Shaders9, 0, 68, 65, 136), ANIMFRAME);
			clip->AddFrame(new Sprite(textureFile, Shaders9, 65, 68, 130, 136), ANIMFRAME);
			clip->AddFrame(new Sprite(textureFile, Shaders9, 130, 68, 195, 136), ANIMFRAME);
			clip->AddFrame(new Sprite(textureFile, Shaders9, 195, 68, 260, 136), ANIMFRAME);
			npcs[0]->AddClip(clip);
		}
		npcs[0]->Position(-6 * SCALE*GRID, 7 * SCALE*GRID);
		npcs[0]->Play(0);
	}
	{
		npcs.push_back(new Animation());
		wstring textureFile = CryptTextures + L"Npcs/DungeonMaster.png";
		{
			clip = new Clip(PlayMode::Loop);
			for(int i=0;i<4;i++)
			clip->AddFrame(new Sprite(textureFile, Shaders9, 57*i, 0, 57*(i+1), 53), ANIMFRAME);
			npcs[1]->AddClip(clip);
		}
		{
			clip = new Clip(PlayMode::Loop);
			for (int i = 0; i < 4; i++)
				clip->AddFrame(new Sprite(textureFile, Shaders9, 57 * i, 53, 57 * (i + 1), 106), ANIMFRAME);
			npcs[1]->AddClip(clip);
		}
		npcs[1]->Position(0, 10 * SCALE*GRID);
		npcs[1]->Play(0);
	}
	{
		npcs.push_back(new Animation());
		wstring textureFile = CryptTextures + L"Npcs/Merlin.png";
		{
			clip = new Clip(PlayMode::Loop);
			for (int i = 0; i < 5; i++)
				clip->AddFrame(new Sprite(textureFile, Shaders9, 32 * i, 0, 32 * (i + 1), 39), ANIMFRAME);
			npcs[2]->AddClip(clip);
		}
		{
			clip = new Clip(PlayMode::Loop);
			for (int i = 0; i < 5; i++)
				clip->AddFrame(new Sprite(textureFile, Shaders9, 32 * i, 39, 32 * (i + 1), 78), ANIMFRAME);
			npcs[2]->AddClip(clip);
		}
		npcs[2]->Position(6 * SCALE*GRID, 7 * SCALE*GRID);
		npcs[2]->Play(0);
	}
	{
		npcs.push_back(new Animation());
		wstring textureFile = CryptTextures + L"Npcs/BeastMaster.png";
		{
			clip = new Clip(PlayMode::Loop);
			for (int i = 0; i < 4; i++)
				clip->AddFrame(new Sprite(textureFile, Shaders9, 29 * i, 0, 29 * (i + 1), 27), ANIMFRAME);
			npcs[3]->AddClip(clip);
		}
		{
			clip = new Clip(PlayMode::Loop);
			for (int i = 0; i < 4; i++)
				clip->AddFrame(new Sprite(textureFile, Shaders9, 29 * i, 27, 29 * (i + 1), 54), ANIMFRAME);
			npcs[3]->AddClip(clip);
		}
		npcs[3]->Position(-13 * SCALE*GRID, 1 * SCALE*GRID);
		npcs[3]->Play(0);
	}
	{
		npcs.push_back(new Animation());
		wstring textureFile = CryptTextures + L"Npcs/WeaponMaster.png";
		{
			clip = new Clip(PlayMode::Loop);
			for (int i = 0; i < 9; i++)
				clip->AddFrame(new Sprite(textureFile, Shaders9, 48 * i, 0, 48 * (i + 1), 34), ANIMFRAME);
			npcs[4]->AddClip(clip);
		}
		{
			clip = new Clip(PlayMode::Loop);
			for (int i = 0; i < 9; i++)
				clip->AddFrame(new Sprite(textureFile, Shaders9, 48 * i, 34, 48 * (i + 1), 68), ANIMFRAME);
			npcs[4]->AddClip(clip);
		}
		npcs[4]->Position(-17 * SCALE*GRID, -5 * SCALE*GRID);
		npcs[4]->Play(0);
	}
	{
		//npcs.push_back(new Animation());
		//wstring textureFile = CryptTextures + L"Npcs/ShopKeeper.png";
		//{
		//	clip = new Clip(PlayMode::Loop);
		//	for (int i = 0; i < 8; i++)
		//		clip->AddFrame(new Sprite(textureFile, Shaders9, 47 * i, 0, 47 * (i + 1), 38), BEAT);
		//	npcs[5]->AddClip(clip);
		//}
		//{
		//	clip = new Clip(PlayMode::Loop);
		//	for (int i = 0; i < 8; i++)
		//		clip->AddFrame(new Sprite(textureFile, Shaders9, 47 * i, 38, 47 * (i + 1), 76), BEAT);
		//	npcs[5]->AddClip(clip);
		//}
		////npcs[5]->Position(-17 * SCALE*GRID, -5 * SCALE*GRID);
		//npcs[5]->Play(0);
	}
}

Npcs::~Npcs()
{
	for (Animation* npc : npcs)
		SAFE_DELETE(npc);
}

void Npcs::Update(D3DXMATRIX & V, D3DXMATRIX & P)
{
	for (Animation* npc : npcs)
		npc->Update(V, P);
}

void Npcs::Render()
{
	for (Animation* npc : npcs)
		npc->Render();
}
