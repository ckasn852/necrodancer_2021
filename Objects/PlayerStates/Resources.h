#pragma once
class Resources
{
public:
	Resources();
	~Resources();

	void Position(D3DXVECTOR2& cameraPo);
	void Update(D3DXMATRIX& V, D3DXMATRIX& P);
	void Render();
private:
	class Diamonds* diamonds;
	class Coins* coins;
};