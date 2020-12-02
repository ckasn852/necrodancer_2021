#pragma once
class Hearts
{
public:
	Hearts();
	~Hearts();

	void Position(D3DXVECTOR2& cameraPo);
	void Update(D3DXMATRIX& V, D3DXMATRIX& P);
	void Render();

	void CalculateLife();

private:
	BYTE heartBeat = 0;
	float lifeMax = 3;
	float lastLifeMax = lifeMax;

	float heartBeatTimer = 0;
	bool bPass = false;
	bool bBigHeart = false;
private:
	Sprite* eHeart;//empty

	vector<Sprite*> hearts;
	Sprite* hHeart;//half
};