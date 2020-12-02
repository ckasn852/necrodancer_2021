#pragma once
#pragma once
class Coins
{
public:
	Coins();
	~Coins();

	void Position(D3DXVECTOR2& cameraVec);
	void Position(float cameraX, float cameraY) { Position(D3DXVECTOR2(cameraX, cameraY)); }
	void Update(D3DXMATRIX& V, D3DXMATRIX& P);
	void Render();

private:
	D3DXVECTOR2 cameraPo;
	Sprite* coin;
	Sprite* coinNums[3];
};