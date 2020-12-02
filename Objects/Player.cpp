#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	playerStates = new PlayerStates();
	wstring textureFile = CryptTextures + L"Cadence.png";
	wstring shaderFile = Shaders + L"009_Sprite.fx";
	Clip* clip;
	{
		head = new Animation();	
		
		{//Idle
			clip = new Clip(PlayMode::Loop);
			clip->AddFrame(new Sprite(textureFile, shaderFile, 4, 0, 18, 12), ANIMFRAME);
			clip->AddFrame(new Sprite(textureFile, shaderFile, 28, 0, 42, 12),ANIMFRAME);
			clip->AddFrame(new Sprite(textureFile, shaderFile, 52, 0, 66, 12),ANIMFRAME);
			clip->AddFrame(new Sprite(textureFile, shaderFile, 76, 0, 90, 12),ANIMFRAME);
			clip->AddFrame(new Sprite(textureFile, shaderFile, 4, 24, 18, 36),ANIMFRAME);
			clip->AddFrame(new Sprite(textureFile, shaderFile, 28, 24, 42, 36), ANIMFRAME);
			clip->AddFrame(new Sprite(textureFile, shaderFile, 52, 24, 66, 36), ANIMFRAME);
			clip->AddFrame(new Sprite(textureFile, shaderFile, 76, 24, 90, 36), ANIMFRAME);
			head->AddClip(clip);
		}
	}//Animation head

	{
		body = new Animation();
		{//Idle
			clip = new Clip(PlayMode::Loop);
			clip->AddFrame(new Sprite(textureFile, shaderFile, 3, 57, 20, 71), ANIMFRAME);
			clip->AddFrame(new Sprite(textureFile, shaderFile, 27, 57, 44, 71),ANIMFRAME);
			clip->AddFrame(new Sprite(textureFile, shaderFile, 51, 57, 68, 71),ANIMFRAME);
			clip->AddFrame(new Sprite(textureFile, shaderFile, 75, 57, 92, 71),ANIMFRAME);
			body->AddClip(clip);
		}
	}//Animation body

	location.grid.x = 0;
	location.grid.y = 0;
	location.po = D3DXVECTOR2(0, 0+SCALE*GRID/5);
	head->Position(0, 0);
	head->Play(0);
	body->Position(0, -SCALE * 9);
	body->Play(0);
}

Player::~Player()
{
	SAFE_DELETE(head);
	SAFE_DELETE(body);
	SAFE_DELETE(playerStates);
}

void Player::Location(D3DXVECTOR2 & location)
{
	this->location.po = location;
	this->location.grid.x = location.x / SCALE / GRID;
	this->location.grid.y = location.y / SCALE / GRID;
	moving = false;
}

void Player::Position(D3DXVECTOR2 & cameraPo)
{
	playerStates->Position(cameraPo);
}


void Player::Update(D3DXMATRIX & V, D3DXMATRIX & P)
{
	__super::Update();

	head->Position(location.po);
	body->Position(location.po.x, location.po.y - SCALE*9);
	head->Update(V, P);
	body->Update(V, P);
	playerStates->Update(V, P);
}

void Player::Render()
{
	body->Render();
	head->Render();
}

void Player::Move()
{
	if (!moving)
	{
		if (Key->Press('A'))
		{
			moving = LEFT;
			head->RotationDegree(0, 180, 0);
			body->RotationDegree(0, 180, 0);
		}
		else if (Key->Press('D'))
		{
			moving = RIGHT;
			head->RotationDegree(0, 0, 0);
			body->RotationDegree(0, 0, 0);
		}
		else if (Key->Press('W'))
			moving = UP;
		else if (Key->Press('S'))
			moving = DOWN;
	}
}