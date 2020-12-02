#pragma once
#include "Item.h"
enum WeaponName
{
	eOriginalSword, eBloodSword, eDiaSword, eGoldSword, eTitanumSword, eObsidianSword,

	eOriginalBigSword, eBloodBigSword, eDiaBigSword, eGoldBigSword, eTitanumBigSword,

	eOriginalLongSword, eBloodLongSword, eDiaLongSword, eGoldLongSword, eTitanumLongSword,
};

struct WeaponInfo
{
	WeaponInfo() {}
	~WeaponInfo(){}

	ItemMaterial material = eOriginal;
	WeaponName name = eOriginalSword;
	bool bDark = false;
};

class Weapon:public Item
{
public:
	Weapon();
	~Weapon();

	void Update(D3DXMATRIX& V, D3DXMATRIX& P);
	void Render(float x, float y);
	void Render();

	void Activate()override;
	WeaponName GetWeaponName() { return name; }
private:
	BYTE weaponsCount = 32;
	WeaponName name = eOriginalSword;

	D3DXVECTOR2 cameraPo;
private:
	vector<Sprite*> weapons;
	Sprite* weaponFrame;
private:
	Animation* effects[4];
private:
	wstring effectSprite = CryptTextures + L"Miscellaneous/AttackSwipes.png";
	wstring spriteFile = CryptTextures + L"Items/Weapons.png";
private:
	enum WeaponSprites
	{
		eOriginalSwordSprite, eBloodSwordSprite, eDiaSwordSprite, eGoldSwordSprite, eTitanumSwordSprite, eObsidianSwordSprite,
		eDarkOriginalSwordSprite, eDarkBloodSwordSprite, eDarkDiaSwordSprite, eDarkGoldSwordSprite, eDarkTitanumSwordSprite, eDarkObsidianSwordSprite,

		eOriginalBigSwordSprite, eBloodBigSwordSprite, eDiaBigSwordSprite, eGoldBigSwordSprite, eTitanumBigSwordSprite,
		eDarkOriginalBigSwordSprite, eDarkBloodBigSwordSprite, eDarkDiaBigSwordSprite, eDarkGoldBigSwordSprite, eDarkTitanumBigSwordSprite,

		eOriginalLongSwordSprite, eBloodLongSwordSprite, eDiaLongSwordSprite, eGoldLongSwordSprite, eTitanumLongSwordSprite,
		eDarkOriginalLongSwordSprite, eDarkBloodLongSwordSprite, eDarkDiaLongSwordSprite, eDarkGoldLongSwordSprite, eDarkTitanumLongSwordSprite
	};
};