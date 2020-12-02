#include "stdafx.h"
#include "PlayerItems.h"
PlayerItems::PlayerItems()
{
	shovel = new Shovel();
	weapon = new Weapon();
	footwear = new Footwear();
}

PlayerItems::~PlayerItems()
{
	SAFE_DELETE(shovel);
	SAFE_DELETE(weapon);
	SAFE_DELETE(footwear);
}

void PlayerItems::Update(D3DXMATRIX & V, D3DXMATRIX & P)
{
	shovel->Update(V, P);
	weapon->Update(V, P);
}

void PlayerItems::Render(WhichItem item, float second, D3DXVECTOR2& vec)
{
	switch (item)
	{
		case eShovel:
			shovel->RenderSecond(second, vec);
			break;
		case eWeapon:
			break;
		case eFootwear:
			break;
		default:
			break;
	}
}

void PlayerItems::Render()
{
	shovel->Render();
	weapon->Render();
}
