#pragma once
#include "PlayerItems.h"
class PlayerStates
{
public:
	PlayerStates();
	~PlayerStates();

	void Position(D3DXVECTOR2& cameraPo);
	void Update(D3DXMATRIX& V, D3DXMATRIX& P);
	void Render(WhichItem item, float second, D3DXVECTOR2& vec) { playerItems->Render(item, second, vec); }
	void Render();

public:
	ShovelName GetShovelName() { return playerItems->GetShovelName(); }
	WeaponName GetWeaponName() { return playerItems->GetWeaponName(); }

private:
	class PlayerItems* playerItems;
	class Resources* resources;
	class Hearts* hearts;
};