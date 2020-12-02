#pragma once
class Hud
{
public:
	Hud();
	~Hud();

	void Position(D3DXVECTOR2& cameraPo);
	void Update(D3DXMATRIX& V, D3DXMATRIX& P);
	void Render();
private:
	class BeatHeart* beatHeart;
};