#pragma once
#define ITEMFRAME 35
enum ItemMaterial
{
	eOriginal, eBlood, eDiamond, eGold, eTitanum, eObsidian
};
class Item
{
public:

protected:
	virtual void Activate() {}
	
	bool bTempRender = false;
	D3DXVECTOR2 renderPo;

protected:
	bool bRender = false;

};