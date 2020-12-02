#pragma once
#include "../Object.h"
enum MonsterName
{
	eGreenSlime,eBlueSlime,eGoldSlime,eFireSlime,eIceSlime
};

enum MonsterState1
{
	eIdle1,eDark1
};
enum MonsterState2
{
	eIdle2, eReadyForMove2, eDark2, eDarkReadyForMove
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
	vector<Animation*>monsters;
	Animation* attackEffect;

private:
	wstring slimeSprite = CryptTextures + L"Monsters/Slimes.png";
	wstring skeletonSprite = CryptTextures + L"Monsters/Skeletons.png";
	wstring ghostSprite = CryptTextures + L"Monsters/Ghost.png";
	wstring zombieSprite = CryptTextures + L"Monsters/Zombies.png";

};