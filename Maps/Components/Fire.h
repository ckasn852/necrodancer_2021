#pragma once
struct FireInfo
{
	FireInfo(){}
	~FireInfo(){}
	DoubleInt grid;
};
class Fire
{
public:
	Fire();
	~Fire();

	void Update(D3DXMATRIX& V, D3DXMATRIX& P);
	void Render();
	void Render( D3DXVECTOR2& vec);
	void Render( float x, float y) { Render( D3DXVECTOR2(x, y)); }

private:
	Animation* fire;
	wstring wallSprite = CryptTextures + L"StageElements/Walls.png";

};