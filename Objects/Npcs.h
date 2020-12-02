#pragma once
#include "Object.h"
enum NpcName
{
	eHephaestus,eDungeonMaster,eMerlin, eBeastMaster, eWeaponMaster, eShopKeeper
};

class Npcs :public Object
{
public:
	Npcs();
	~Npcs();


	void Update(D3DXMATRIX& V, D3DXMATRIX& P);
	void Render();
private:
	vector<Animation*>npcs;

private:
	wstring spriteFile = CryptTextures + L"Npcs/";
};