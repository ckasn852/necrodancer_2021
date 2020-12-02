#pragma once
#include "Item.h"
enum ArmorName
{
	eDefence05ArmorSprite, eDefence1ArmorSprite, eDefence2ArmorSprite, eDefence3ArmorSprite, eAtt1ArmorSprite, eGlassArmorSprite
};
struct ArmorInfo
{
	ArmorInfo(){}
	~ArmorInfo(){}
	ArmorName name = eDefence05ArmorSprite;
	bool bDark = false;
};
class Armor:public Item
{
public:
	Armor();
	~Armor();

	void Update(D3DXMATRIX& V, D3DXMATRIX& P);
	void Render();
private:
	vector<Sprite*>armors;
	Sprite* armorFrame;
private:
	ArmorInfo armorInfo;
	BYTE armorsCount = 12;
private:
	wstring spriteFile = CryptTextures + L"Items/Armors.png";
private:
	enum ArmorSprites
	{
		eDefence05ArmorSprite,eDefence1ArmorSprite,eDefence2ArmorSprite,eDefence3ArmorSprite,eAtt1ArmorSprite,eGlassArmorSprite,
		eDarkDefence05ArmorSprite, eDarkDefence1ArmorSprite, eDarkDefence2ArmorSprite, eDarkDefence3ArmorSprite, eDarkAtt1ArmorSprite, eDarkGlassArmorSprite
	};
};