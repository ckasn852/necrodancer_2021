#include "stdafx.h"
#include "Maps/Map.h"//맵 타일 관련 정보 끌어 쓰자
#include "Viewer/Freedom.h"
#include "Editor.h"

Editor::Editor()
{
	{//view projection
		values = new SceneValues();
		values->MainCamera = new Freedom();
		D3DXMatrixIdentity(&values->Projection);
	}
	map = new Map();
}

Editor::~Editor()
{
	SAFE_DELETE(values->MainCamera);
	SAFE_DELETE(values);
	SAFE_DELETE(map);
}

void Editor::Update()
{
	values->MainCamera->Update();
	D3DXMatrixOrthoOffCenterLH
	(
		&values->Projection,
		(float)Width*-0.5f, (float)Width*0.5f, (float)Height*-0.5f, (float)Height*0.5f,
		-10, 10
	);
	D3DXVECTOR2 cameraPo = values->MainCamera->Position();
	D3DXVECTOR2 mousePo = Mouse->Position();
	D3DXVECTOR2 tempPo = cameraPo + mousePo;
	mouseGrid.x = (tempPo.x - GRID * SCALE / 2) / (GRID*(SCALE));
	mouseGrid.y = (tempPo.y - GRID * SCALE / 2) / (GRID*(SCALE));
	
	if (tempPo.y > GRID * SCALE / 2)//complement
		mouseGrid.y++;
	if (tempPo.x > GRID * SCALE / 2)
		mouseGrid.x++;

	if (Mouse->Press(0) && (bStates & 0b00000100) == 0b00000100)
	{//해당 격자에 배치된경우 제거	
		if (bEditors & 0b00000001)
			tileInfos.remove(GridInfo(mouseGrid, 0));
		if (bEditors & 0b00000010)
			wallInfos.remove(GridInfo(mouseGrid, 0));
		if (bEditors & 0b00000100)
			eleInfos.remove(GridInfo(mouseGrid, 0));
		if (bEditors & 0b00001000)
			fireInfos.remove(GridInfo(mouseGrid, 0));
	}

	if (Key->Down('X') && (bStates&0b00000010))
		bStates ^= 0b00000010;
	

	if (Mouse->Press(0) && (bStates & 0b00001010)==0b00001010)
	{//배치 격자에 위치한 경우, 그 격자에 배치시킴(float3에 위치,타일숫자 저장)
		if (bEditors & 0b00000001)
		{
			tileInfos.remove(GridInfo(mouseGrid, 0));
			tileInfos.push_back(GridInfo(mouseGrid, choiceNum));
		}
		else if (bEditors & 0b00000010)
		{
			wallInfos.remove(GridInfo(mouseGrid, 0));
			wallInfos.push_back(GridInfo(mouseGrid, choiceNum));
			wallInfos.sort();
		}
		else if (bEditors & 0b00000100)
		{
			eleInfos.remove(GridInfo(mouseGrid, 0));
			eleInfos.push_back(GridInfo(mouseGrid, choiceNum));
		}
		else if (bEditors & 0b00001000)
		{
			fireInfos.remove(GridInfo(mouseGrid, 0));
			fireInfos.push_back(GridInfo(mouseGrid, choiceNum));
		}
	}
	if (Mouse->DoubleClick(0))
	{//해당 마우스 위치 타일 렌더
		if (bEditors & 0b00000001)
			for (int i = 0; i < map->tileMax; i++)
				if (map->tiles[i]->AABB(tempPo))
				{
					bStates |= 0b00000010;
					dragSprite = new Sprite(*map->tiles[i]);
					choiceNum = i;
				}
		if (bEditors & 0b00000010)
			for(int i=0;i< map->wallMax;i++)
				if (map->walls[i]->AABB(tempPo))
				{
					bStates |= 0b00000010;
					dragSprite = new Sprite(*map->walls[i]);
					choiceNum = i;
				}
		if (bEditors & 0b00000100)
		{
			for (int i = 0; i < map->tWElementMax; i++)
				if (map->elements[i]->AABB(tempPo))
				{
					bStates |= 0b00000010;
					dragSprite = new Sprite(*map->elements[i]);
					choiceNum = i;
				}
		}
		if (bEditors & 0b00001000)
		{
			for(int i=0;i<map->fireMax;i++)
				if (map->fires[i]->AABB(tempPo))
				{
					bStates |= 0b00000010;
					dragSprite = new Sprite(*map->fires[i]->GetSprite());
					choiceNum = i;
				}
		}	
	}
	map->Update(View(), Projection());

	if (bEditors & 0b00000001)
	{
		for (int horiz = 0; horiz < 15; horiz++)
			for (int verti = 0; verti < 5; verti++)
			{
				if (horiz * 5 + verti >= map->tileMax)
					break;
				map->tiles[horiz * 5 + verti]->Position(Width / 2 - (4.5 - float(verti)) * GRID*SCALE + cameraPo.x, Height / 2 - (0.5 + float(horiz)) * GRID*SCALE + cameraPo.y);
			}
	}
	if (bEditors & 0b00000010)
	{
		for(int horiz=0;horiz<15;horiz++)
			for (int verti = 0; verti < wHoriz; verti++)
			{
				if (horiz * wHoriz + verti >= map->wallMax)
					break;
				map->walls[horiz * wHoriz + verti]->Position(Width / 2 - (wHoriz-0.5f - float(verti)) * GRID*SCALE + cameraPo.x, Height / 2 - (0.5 + float(horiz)) * WALLHEI*SCALE + cameraPo.y);
			}
	}
	if (bEditors & 0b00000100)
	{
		for(int horiz=0;horiz<10;horiz++)
			for (int verti = 0; verti < 5; verti++)
			{
				if (horiz * 5 + verti >= map->tWElementMax)
					break;
				map->elements[horiz * 5 + verti]->Position(Width / 2 - (4.5 - float(verti)) * GRID*SCALE + cameraPo.x, Height / 2 - (0.5 + float(horiz)) * GRID*SCALE + cameraPo.y);
			}
	}
	if (bEditors & 0b00001000)
	{
		for (int horiz = 0; horiz < 10; horiz++)
			for (int verti = 0; verti < aniEleHoriz; verti++)
			{
				if (horiz * 5 + verti >= map->fireMax)
					break;
				map->fires[horiz * 5 + verti]->Position(Width / 2 - (4.5 - float(verti)) * GRID*SCALE + cameraPo.x, Height / 2 - (0.5 + float(horiz)) * GRID*SCALE + cameraPo.y);
			}
	}

	if (bStates & 0b00000010)
	{
		dragSprite->Update(View(), Projection());
	}
}

void Editor::Render()
{
	D3DXVECTOR2 cameraPo = values->MainCamera->Position();
	D3DXVECTOR2 mousePo = Mouse->Position();

	{
		if (ImGui::Button("Tile"))
			bEditors = 0b00000001;
		if (ImGui::Button("Wall"))
			bEditors = 0b00000010;
		if (ImGui::Button("TWElements"))
			bEditors = 0b00000100;
		if (ImGui::Button("MoveElements"))
			bEditors = 0b00001000;
		if (bEditors)
		{
			if (ImGui::Button("Erase"))
			{
				bStates &= 0b11110111;
				bStates |= 0b00000100;
			}
				
			if (ImGui::Button("Insert"))
			{
				bStates &= 0b11111011;
				bStates |= 0b00001000;
			}
				
		}
			

		ImGui::LabelText("positionX : ", "%f", cameraPo.x + mousePo.x);
		ImGui::LabelText("positionY : ", "%f", cameraPo.y + mousePo.y);
		
		if (ImGui::Button("Save Binary") == true)
		{
			function<void(wstring)>f = bind(&Editor::SaveComplete, this, placeholders::_1);
			Path::SaveFileDialog(L"", L"Binary\0*.bin", L".", f, Hwnd);
		}
		if (ImGui::Button("Load Binary") == true)
		{
			function<void(wstring)>f = bind(&Editor::OpenComplete, this, placeholders::_1);
			Path::OpenFileDialog(L"", L"Binary\0*.bin", L".", f, Hwnd);
		}
		ImGui::LabelText("GridX : ", "%d", mouseGrid.x);
		ImGui::LabelText("GridX : ", "%d", mouseGrid.y);
	}//ImGui

	{//배치된 놈들 렌더링	
		for (GridInfo tileInfo : tileInfos)
			map->tiles[tileInfo.tileNum]->Render((tileInfo.grid.x)* GRID*SCALE, (tileInfo.grid.y)* GRID*SCALE);
		for (GridInfo wallInfo : wallInfos)
			map->walls[wallInfo.tileNum]->Render((wallInfo.grid.x)* GRID*SCALE, (wallInfo.grid.y)* GRID*SCALE + 6 * SCALE);
		for (GridInfo TWEleInfo : eleInfos)
			map->elements[TWEleInfo.tileNum]->Render((TWEleInfo.grid.x)* GRID*SCALE, (TWEleInfo.grid.y)* GRID*SCALE);
		for(GridInfo aniEleInfo: fireInfos)
			map->fires[aniEleInfo.tileNum]->Render((aniEleInfo.grid.x)* GRID*SCALE, (aniEleInfo.grid.y)* GRID*SCALE);
	}
	if (bEditors == 0b00000001)
		for (Sprite* tile : map->tiles)
			tile->Render();
	else if (bEditors == 0b00000010)
		for (Sprite* wall : map->walls)
			wall->Render();
	else if (bEditors == 0b00000100)
		for (Sprite* TWEle : map->elements)
			TWEle->Render();
	else if (bEditors == 0b00001000)
		for (Animation* aniEle : map->fires)
			aniEle->Render();
		
	if (bStates & 0b00000010)
	{
		dragSprite->Render(D3DXVECTOR2(cameraPo.x + mousePo.x, cameraPo.y + mousePo.y));
	}
}

void Editor::SaveComplete(wstring name)
{
	BinaryWriter* w = new BinaryWriter();
	w->Open(name);

	BYTE infoOfSave = 0b00000000;//0:tile 1:wall 2:ele 3:fire

	vector<GridInfo>saveTiles;
	for (GridInfo tileInfo : tileInfos)
		saveTiles.push_back(tileInfo);

	vector<GridInfo>saveWalls;
	for (GridInfo wallInfo : wallInfos)
		saveWalls.push_back(wallInfo);

	vector<GridInfo>saveElements;
	for (GridInfo eleInfo : eleInfos)
		saveElements.push_back(eleInfo);

	vector<GridInfo>saveFires;
	for (GridInfo aniEleInfo : fireInfos)
		saveFires.push_back(aniEleInfo);

	if (saveTiles.size() > 0)
		infoOfSave |= 0b00000001;
	if (saveWalls.size() > 0)
		infoOfSave |= 0b00000010;
	if (saveElements.size() > 0)
		infoOfSave |= 0b00000100;
	if (saveFires.size() > 0)
		infoOfSave |= 0b00001000;
	w->Byte(&infoOfSave, sizeof(BYTE));
	{
		if (saveTiles.size() > 0)
		{
			w->UInt(saveTiles.size());
			w->Byte(&saveTiles[0], sizeof(GridInfo)*saveTiles.size());//시작지점~끝(사이즈) 할당함
		}
		if (saveWalls.size() > 0)
		{
			w->UInt(saveWalls.size());
			w->Byte(&saveWalls[0], sizeof(GridInfo)*saveWalls.size());
		}
		if (saveElements.size() > 0)
		{
			w->UInt(saveElements.size());
			w->Byte(&saveElements[0], sizeof(GridInfo)*saveElements.size());
		}
		if (saveFires.size() > 0)
		{
			w->UInt(saveFires.size());
			w->Byte(&saveFires[0], sizeof(GridInfo)*saveFires.size());
		}
	}
	
	w->Close();
	SAFE_DELETE(w);

	wstring temp = name + L"\n저장이 완료되었습니다.";
	MessageBox(Hwnd, temp.c_str(), L"저장완료", MB_OK);
}

void Editor::OpenComplete(wstring name)
{
	bStates = 0b00000001;
	tileInfos.clear();
	wallInfos.clear();
	eleInfos.clear();
	fireInfos.clear();

	BinaryReader* r = new BinaryReader;
	r->Open(name);

	BYTE infoOfSave;

	UINT loadTileCount;
	UINT loadWallCount;
	UINT loadeleCount;
	UINT loadAniEleCount;

	{
		void* ptr = (void*)&(infoOfSave);
		r->Byte(&ptr, sizeof(BYTE));
	}
	if(infoOfSave&0b00000001)
	{
		loadTileCount = r->UInt();

		vector<GridInfo>v;
		v.assign(loadTileCount, GridInfo());

		void* ptr = (void*)&(v[0]);
		r->Byte(&ptr, sizeof(GridInfo)*(loadTileCount));//

		for (UINT i = 0; i < loadTileCount; i++)
		{
			tileInfos.push_back(GridInfo(v[i]));
		}
	}
	if(infoOfSave&0b00000010)
	{
		loadWallCount = r->UInt();

		vector<GridInfo>f;
		f.assign(loadWallCount, GridInfo());

		void* ptr2 = (void*)&(f[0]);
		r->Byte(&ptr2, sizeof(GridInfo)*(loadWallCount));

		for (UINT i = 0; i < loadWallCount; i++)
		{
			wallInfos.push_back(GridInfo(f[i]));
		}
	}
	if(infoOfSave&0b00000100)
	{
		loadeleCount = r->UInt();

		vector<GridInfo>f;
		f.assign(loadeleCount, GridInfo());

		void* ptr3 = (void*)&(f[0]);
		r->Byte(&ptr3, sizeof(GridInfo)*(loadeleCount));

		for (UINT i = 0; i < loadeleCount; i++)
		{
			eleInfos.push_back(GridInfo(f[i]));
		}
	}
	if(infoOfSave&0b00001000)
	{
		loadAniEleCount = r->UInt();

		vector<GridInfo>f;
		f.assign(loadAniEleCount, GridInfo());

		void* ptr3 = (void*)&(f[0]);
		r->Byte(&ptr3, sizeof(GridInfo)*(loadAniEleCount));

		for (UINT i = 0; i < loadAniEleCount; i++)
		{
			fireInfos.push_back(GridInfo(f[i]));
		}
	}
	r->Close();
	SAFE_DELETE(r);
}