#pragma once
#include "Enemies/MiniBosses.h"
#include "Enemies/Monsters.h"

class Enemies
{
public:
	Enemies();
	~Enemies();

	void Update(D3DXMATRIX& V, D3DXMATRIX& P);
	void Render();
	void Render(MonsterName name, D3DXVECTOR2& vec);
	void Render(MonsterName name, float x, float y) { Render(name, D3DXVECTOR2(x, y)); }



	void OpenBinaryFile(wstring file);
private:
	struct EnemyInfo
	{
		EnemyInfo() {}
		~EnemyInfo() {}

		DoubleInt grid;

	};
private:
	Monsters monsters;
	MiniBosses miniBosses;
private:
	vector<struct GridInfo>monsterInfos;
};