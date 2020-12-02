#pragma once
class BeatHeart
{
public:
	BeatHeart();
	~BeatHeart();

	void UpdateState(BeatState beatState);
	void Position(D3DXVECTOR2& cameraPo);
	void Update(D3DXMATRIX& V, D3DXMATRIX& P);
	void Render();

private:
	Sprite* bigHeart;
	Sprite* smallHeart;
	Sprite* beatHeart;
};