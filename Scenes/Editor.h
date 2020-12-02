#pragma once
#include "Scene.h"
//사운드, 비트속도, ... 제어
//맵 생성
//타일(47) 벽(38)
// 마우스 드래그, 파일 저장 불러오기
class Editor:public Scene
{
public:
	Editor();
	~Editor();

	void Update()override;
	void Render()override;

private://state
	BYTE page = 0;
	BYTE lastPage = 2;

	BYTE bEditors = false;//3:mEle 2:twEle 1:wall 0:tile
	BYTE bStates = false;//3:insert 2:erase 1:dragSprite 0:load
private://info
	DoubleInt mouseGrid = DoubleInt(0, 0);
	list<struct GridInfo>tileInfos;
	list<struct GridInfo>wallInfos;
	list<struct GridInfo>eleInfos;
	list<struct GridInfo>fireInfos;

	BYTE tHoriz = 5;//tile
	BYTE wHoriz = 9;//wall
	BYTE tWEHoriz = 5;//twElements
	BYTE aniEleHoriz = 5;//movingElements

private://objects
	BYTE choiceNum;

	Sprite* dragSprite;
	struct Map* map;//포인터로 안하면 "정의되지 않은 struct"오류뜬다

private:
	void SaveComplete(wstring name);
	void OpenComplete(wstring name);
};