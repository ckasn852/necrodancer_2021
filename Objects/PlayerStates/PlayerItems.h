#pragma once
#include "Items/Shovel.h"
#include "Items/Weapon.h"
#include "Items/Footwear.h"
enum WhichItem
{
	eShovel,eWeapon,eFootwear
};

class PlayerItems
{
public:
	PlayerItems();
	~PlayerItems();

	void Update(D3DXMATRIX& V, D3DXMATRIX& P);
	void Render(WhichItem item,float second, D3DXVECTOR2& vec);
	void Render();

public:
	ShovelName GetShovelName() { return shovel->GetShovelName(); }
	WeaponName GetWeaponName() { return weapon->GetWeaponName(); }
private:
	class Shovel* shovel;
	class Weapon* weapon;
	class Footwear* footwear;
};