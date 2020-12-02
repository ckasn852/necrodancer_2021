#pragma once
#include "Components.h"
//맵 파일들의 타일 관련 정보, 함수
//리턴 함수
//타일 Sprite 파일

enum MapName
{
	eLobby,eTutorial,eZone1
};

enum GridType
{
	eTile,eWall,eElement,eFire
};

struct GridInfo
{
	GridInfo() {}
	GridInfo(DoubleInt x, int y) { grid = x; tileNum = y; }

	DoubleInt grid;
	int tileNum;

	bool operator <(GridInfo a)
	{
		if (grid.y > a.grid.y)
			return true;
		else
			return false;
	}
	bool operator ==(GridInfo a)
	{//for erase (!!egnore tileNum)
		if (grid == a.grid)
			return true;
		else
			return false;
	}
};

class Map
{
public:
	Map();
	virtual ~Map();

	const int tileMax = 47;
	const int wallMax = 53;
	const int tWElementMax = 9;
	const int fireMax = 1;

	vector<Sprite*> tiles;
	vector<Sprite*> walls;
	vector<Sprite*> elements;
	vector<Animation*> fires;
	
	void Update(D3DXMATRIX& V, D3DXMATRIX& P);
	void Render();
public:
	void WallCrush(D3DXVECTOR2& vec);
	void WallCrush(float x, float y) { WallCrush(D3DXVECTOR2(x, y)); }
private:
	Animation* wallParticle;
private:
	wstring tileSprite = CryptTextures + L"StageElements/Tiles.png";
	wstring wallSprite = CryptTextures + L"StageElements/Walls.png";
	wstring shaderFile = Shaders + L"009_Sprite.fx";
};