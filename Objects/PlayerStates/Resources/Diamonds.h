#pragma once
class Diamonds
{
public:
	Diamonds();
	~Diamonds();

	void Position(D3DXVECTOR2& cameraVec);
	void Position(float cameraX, float cameraY) { Position(D3DXVECTOR2(cameraX, cameraY)); }

	void Update(D3DXMATRIX& V, D3DXMATRIX& P);
	void Render();
private:
	D3DXVECTOR2 cameraPo;
	Sprite* diamond;
	Sprite* diaNums[2];
};