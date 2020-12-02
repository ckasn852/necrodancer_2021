#include "stdafx.h"
#include "Resources.h"
#include "Hearts.h"
#include "PlayerStates.h"

PlayerStates::PlayerStates()
{
	resources = new Resources();
	hearts = new Hearts();
	playerItems = new PlayerItems();
}


PlayerStates::~PlayerStates()
{
	SAFE_DELETE(resources);
	SAFE_DELETE(hearts);
	SAFE_DELETE(playerItems);
}

void PlayerStates::Position(D3DXVECTOR2 & cameraPo)
{
	resources->Position(cameraPo);
	hearts->Position(cameraPo);
}

void PlayerStates::Update(D3DXMATRIX & V, D3DXMATRIX & P)
{
	resources->Update(V, P);
	hearts->Update(V, P);
	playerItems->Update(V, P);
}

void PlayerStates::Render()
{
	resources->Render();
	hearts->Render();
	playerItems->Render();
}
