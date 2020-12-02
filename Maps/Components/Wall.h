#pragma once
//dirt1~  level1
//dirtStone1~  level2
//stoneLight1~  level3
//gold~ level4
//black1~ non
enum WallName
{
	//1
	dirt1, dirt2, dirt3, dirt4, dirt5, dirt6, dirt7, dirt8, dirt9, dirt10, dirt11, dirt12, dirt13, dirt14, dirt15, dirt16, dirt17, dirt18, dirt19, dirt20, dirt21, dirt22, dirt23, dirt24, dirt25, dirt26, dirt27, dirt28, dirt29,
	//2
	dirtStone1, dirtStone2, 
	//3
	stoneLight1, stoneLight2, stoneLight3,
	//4
	gold1, gold2, silver1, silver2,
	//non
	black1, black2, black3, black4, black5, black6, black7, black8,
	
	//other
	vertiDoor, horizDoor, vertiLockDoor, horizLockDoor,
	Locked1, Locked2, Locked3
};

class Wall
{
public:
	Wall();
	~Wall();

	void Update(D3DXMATRIX& V, D3DXMATRIX& P);
	void Update(WallName name, D3DXMATRIX& V, D3DXMATRIX& P);
	void Render();
	void Render(WallName name);
	void Render(WallName name, D3DXVECTOR2& vec);
	void Render(WallName name, float x, float y) { Render(name,D3DXVECTOR2(x, y)); }
	

private:
	Sprite* walls[53];
	wstring wallSprite = CryptTextures + L"StageElements/Walls.png";
	enum WallSprites
	{
		dirt1, dirt2, dirt3, dirt4, dirt5, dirt6, dirt7, dirt8, dirt9, dirt10, dirt11, dirt12, dirt13, dirt14, dirt15, dirt16, dirt17, dirt18, dirt19, dirt20, dirt21, dirt22, dirt23, dirt24, dirt25, dirt26, dirt27, dirt28, dirt29,
		dirtStone1, dirtStone2, stoneLight1, stoneLight2, stoneLight3,
		gold1, gold2, silver1, silver2,
		black1, black2, black3, black4, black5, black6, black7, black8,
		vertiDoor, horizDoor, vertiLockDoor, horizLockDoor,
		Locked1, Locked2, Locked3
	};
};

class WallInfo
{
public:
	WallInfo(){}
	~WallInfo(){}
	DoubleInt grid;

	bool operator <(WallInfo a)
	{
		if (grid.y > a.grid.y)
			return true;
		else
			return false;
	}
	bool operator ==(WallInfo a)
	{//for erase (!!egnore tileNum)
		if (grid == a.grid)
			return true;
		else
			return false;
	}
};