#pragma once
enum TileName
{
	tileDirt1, tileDirtDark1, tileDirtGreen1, tileDirtPurple1,
	tileDirt2, tileDirtDark2, tileDirtGreen2, tileDirtPurple2,
	tileShop, tileNext, tileUpgrades, tileReset,
	tileGrassA1, tileGrassA1Blue, tileGrassA1Red, tileGrassA2, tileGrassA2Blue, tileGrassA2Red,
	tileGrassB1, tileGrassB1Blue, tileGrassB1Red, tileGrassB2, tileGrassB2Blue, tileGrassB2Red,
	tileGrassC1, tileGrassC1Blue, tileGrassC1Red, tileGrassC2, tileGrassC2Blue, tileGrassC2Red,
	tileGrassD1, tileGrassD1Blue, tileGrassD1Red, tileGrassD2, tileGrassD2Blue, tileGrassD2Red,
	tileStairs, tileStairsDia3, tileStairsSkull, tileStairsLock, tileStarsDia9,
	tileWater1, tileWater2, tileWater3,
	tileLava1, tileLava2, tileLava3
};
struct TileInfo
{
	TileInfo(){}
	~TileInfo(){}
	DoubleInt grid;
	TileName name;
	bool bExecute = false;
};
class Tile
{
public:
	Tile();
	~Tile();

	void Update(D3DXMATRIX& V, D3DXMATRIX& P);
	void Update(TileName name, D3DXMATRIX& V, D3DXMATRIX& P);
	void Render();
	void Render(TileName name);
	void Render(TileName name, D3DXVECTOR2& vec);
	void Render(TileName name, float x, float y) { Render(name, D3DXVECTOR2(x, y)); }


private:
	Sprite* tiles[47];
	wstring tileSprite = CryptTextures + L"StageElements/Tiles.png";

	enum TileSprites
	{
		tileDirt1, tileDirtDark1, tileDirtGreen1, tileDirtPurple1,
		tileDirt2, tileDirtDark2, tileDirtGreen2, tileDirtPurple2,
		tileShop, tileNext, tileUpgrades, tileReset,
		tileGrassA1, tileGrassA1Blue, tileGrassA1Red, tileGrassA2, tileGrassA2Blue, tileGrassA2Red,
		tileGrassB1, tileGrassB1Blue, tileGrassB1Red, tileGrassB2, tileGrassB2Blue, tileGrassB2Red,
		tileGrassC1, tileGrassC1Blue, tileGrassC1Red, tileGrassC2, tileGrassC2Blue, tileGrassC2Red,
		tileGrassD1, tileGrassD1Blue, tileGrassD1Red, tileGrassD2, tileGrassD2Blue, tileGrassD2Red,
		tileStairs, tileStairsDia3, tileStairsSkull, tileStairsLock, tileStarsDia9,
		tileWater1, tileWater2, tileWater3,
		tileLava1, tileLava2, tileLava3

	};
};