#pragma once
#include "Scene.h"


class PlayGame: public Scene
{
public:
	PlayGame();
	~PlayGame();

	void Update()override;
	void Render()override;
	void Camera(float x, float y);

	void Start(wstring map) { OpenComplete(map); }
private:
	vector<struct GridInfo>tileInfos;
	vector<struct GridInfo>wallInfos;
	vector<struct GridInfo>eleInfos;//element Infomation
	vector<struct GridInfo>fireInfos;
	vector<struct GridInfo>sentenceInfos;

	class Sentence* sentence;
	D3DXVECTOR2 cameraPo;
private://beatInfo
	float playGameBeat = 1 / BEATFRAME /7;

	void DivertTileBlacked();//비트 끝났을때 실행

private://글자
	Sprite* fontX;

private: //조건부 추가 생성되는 것들
	float wallClashTimer = 0;
	
	
private:
	void TileExecute();
	void DecidePlayerMovement();
	void ChangeMap(enum MapName mapName);
	
	vector<GridInfo> FindCanClashWalls();

	class Player* player;
	struct Map* map;
	class Hud* hud;
	class Npcs* npcs;
private:
	void OpenComplete(wstring name);

private:
	wstring shaderFile = Shaders + L"009_Sprite.fx";
	wstring hudFile = CryptTextures + L"Miscellaneous/HUD.png";
private:
	bool bTemp = false;
};