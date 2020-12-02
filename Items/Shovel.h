#pragma once
#include "Item.h"
//original:1
//titanum:1~2
//dia:1~3 breakable
//obsitian:multiply coin 1~3
enum ShovelName
{
	eOriginalShovel,eTitanumShovel,eDiaShovel,eObsidianShovel,eBloodShovel,ePick
};


struct ShovelInfo
{
	ShovelInfo(){}
	~ShovelInfo(){}

	ShovelName name = eOriginalShovel;
	bool bDark = false;
};

class Shovel:public Item
{
public:
	Shovel();
	~Shovel();

	void Position(D3DXVECTOR2& cameraPo);
	void Update(D3DXMATRIX& V, D3DXMATRIX& P);
	void RenderSecond(float second, D3DXVECTOR2& vec);
	void Render();

	void Activate()override;
	ShovelName GetShovelName() { return name; }

private:
	BYTE shovelsCount = 16;
	ShovelName name = eOriginalShovel;

	D3DXVECTOR2 playerPo;
	float renderTimerMax;
	float renderTimer = 0;


private:
	vector<Sprite*>shovels;
	Sprite* shovelFrame;
private:
	wstring spriteFile = CryptTextures + L"Items/Shovels.png";
private:
	enum ShovelSprites
	{
		eOriginalShovelSprite, eTitanumShovelSprite, eDiaShovelSprite, eObsidianShovelSprite0, eObsidianShovelSprite1, eObsidianShovelSprite2, eBloodShovelSprite, ePickSprite,
		eDartOriginalShovelSprite, eDartTitanumShovelSprite, eDartDiaShovelSprite, eDartObsidianShovelSprite0, eDartObsidianShovelSprite1, eDartObsidianShovelSprite2, eDartBloodShovel, eDarkPickSprite
	};
};