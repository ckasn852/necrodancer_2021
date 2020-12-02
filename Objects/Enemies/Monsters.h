#pragma once
#include "../Object.h"
enum MonsterName
{

};
class Monsters :public Object
{
public:
	Monsters();
	~Monsters();


	void Update(D3DXMATRIX& V, D3DXMATRIX& P);
	void Render();
	void Render(MonsterName name, D3DXVECTOR2& vec);
	void Render(MonsterName name, float x, float y) { Render(name, D3DXVECTOR2(x, y)); }
private:
	vector<vector<Sprite*>>monsters;
	Animation* attackEffect;
};