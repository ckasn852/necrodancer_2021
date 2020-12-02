#include "stdafx.h"
#include "Viewer/Freedom.h"
#include "../Objects/Player.h"
#include "../Maps/Map.h"
#include "./Huds/Hud.h"
#include "./Objects/Npcs.h"
#include "Objects/Enemies.h"
#include "PlayGame.h"


PlayGame::PlayGame()
{
	sentence = new Sentence();
	player = new Player();
	hud = new Hud();
	map = new Map();
	npcs = new Npcs();
	enemies = new Enemies();
	{//view projection
		values = new SceneValues();
		values->MainCamera = new Freedom();
		D3DXMatrixIdentity(&values->Projection);
	}
	
	{
		fontX = new Sprite(CryptTextures + L"Miscellaneous/Fonts.png", shaderFile, 299, 0, 307, 10);
	}
	player->Position(0, SCALE*GRID / 4);
}

PlayGame::~PlayGame()
{
	SAFE_DELETE(values->MainCamera);
	SAFE_DELETE(values);
	
	SAFE_DELETE(map);
	SAFE_DELETE(player);
	SAFE_DELETE(enemies);
	SAFE_DELETE(npcs);
	SAFE_DELETE(hud);

	SAFE_DELETE(fontX);
	SAFE_DELETE(sentence);
}

void PlayGame::Update()
{
	{
		values->MainCamera->Update();
		D3DXMatrixOrthoOffCenterLH
		(
			&values->Projection,
			(float)Width*-0.5f, (float)Width*0.5f, (float)Height*-0.5f, (float)Height*0.5f,
			-10, 10
		);
		Camera(player->Grid().x * GRID * SCALE, player->Grid().y * GRID * SCALE);
		cameraPo = values->MainCamera->Position();
		CameraPosition = &cameraPo;
	}
	
	{//Position
		player->Position(cameraPo);
		hud->Position(cameraPo);
	}
	{
		DecidePlayerMovement();
	}
	if (Beats->GetBeatState() == eBeatEnd)
		DivertTileBlacked();

	{//Update
		enemies->Update(View(), Projection());
		sentence->Update(View(), Projection());
		npcs->Update(View(), Projection());
		fontX->Update(View(), Projection());
		map->Update(View(), Projection());
		player->Update(View(), Projection());
		hud->Update(View(), Projection());
	}
	TileExecute();
}

void PlayGame::Render()
{
	D3DXVECTOR2 cameraPo = values->MainCamera->Position();
	{
		for (GridInfo tileInfo : tileInfos)
			map->tiles[tileInfo.tileNum]->Render((tileInfo.grid.x)* GRID*SCALE, (tileInfo.grid.y)* GRID*SCALE);
		player->Render();
		for (GridInfo wallInfo : wallInfos)
			map->walls[wallInfo.tileNum]->Render((wallInfo.grid.x)* GRID*SCALE, (wallInfo.grid.y)* GRID*SCALE + 6 * SCALE);
		for (GridInfo eleInfo : eleInfos)
			map->elements[eleInfo.tileNum]->Render((eleInfo.grid.x)* GRID*SCALE, (eleInfo.grid.y)* GRID*SCALE);
		for (GridInfo aniEleInfo : fireInfos)
			map->fires[aniEleInfo.tileNum]->Render((aniEleInfo.grid.x)* GRID*SCALE, (aniEleInfo.grid.y)* GRID*SCALE);
	}
	{
		if(!bTemp)
			sentence->Render();
		if (!bTemp)
			npcs->Render();
		fontX->Render(cameraPo.x + Width / 2 - GRID * SCALE*1.3, cameraPo.y + Height / 2 - GRID * SCALE / 2);
		fontX->Render(cameraPo.x + Width / 2 - GRID * SCALE*1.3, cameraPo.y + Height / 2 - GRID * SCALE / 2 * 3);
		player->StateRender();
		if (bTemp)
		{
			enemies->Render(eGreenSlime, 2 * GRID*SCALE, 2 * GRID*SCALE);
			enemies->Render(eBlueSlime, 1 * GRID*SCALE, 2 * GRID*SCALE);
			enemies->Render(eGoldSlime, 3 * GRID*SCALE, 0 * GRID*SCALE);
			enemies->Render(eFireSlime, 4 * GRID*SCALE, 2 * GRID*SCALE);
			enemies->Render(eIceSlime, 1 * GRID*SCALE, 0 * GRID*SCALE);
		}
			
		hud->Render();
	}
	ImGui::LabelText("playerX", "%d", player->Grid().x);
	ImGui::LabelText("playerY", "%d", player->Grid().y);

	ImGui::LabelText("cameraX", "%f", values->MainCamera->Position().x);
	ImGui::LabelText("cameraY", "%f", values->MainCamera->Position().y);
	
}

void PlayGame::Camera(float x, float y)
{
	values->MainCamera->Position(x, y);
}

void PlayGame::DivertTileBlacked()
{
	for (int i = 0; i < tileInfos.size(); i++)
	{//Â¦¼ö <> È¦¼ö ·Î ¹Ù²Ü¼ö ÀÖ°Ô ¹Ù²ãÁÖ±â
		if (tileInfos[i].tileNum == tileDirt1)
			tileInfos[i].tileNum = tileDirtDark1;
		else if (tileInfos[i].tileNum == tileDirtDark1)
			tileInfos[i].tileNum = tileDirt1;
		else if (tileInfos[i].tileNum == tileDirtDark2)
			tileInfos[i].tileNum = tileDirt2;
		else if (tileInfos[i].tileNum == tileDirt2)
			tileInfos[i].tileNum = tileDirtDark2;
		else if (tileInfos[i].tileNum == tileDirtGreen1)
			tileInfos[i].tileNum = tileDirtPurple1;
		else if (tileInfos[i].tileNum == tileDirtPurple1)
			tileInfos[i].tileNum = tileDirtGreen1;
		else if (tileInfos[i].tileNum == tileDirtGreen2)
			tileInfos[i].tileNum = tileDirtPurple2;
		else if (tileInfos[i].tileNum == tileDirtPurple2)
			tileInfos[i].tileNum = tileDirtGreen2;
	}
}

void PlayGame::TileExecute()
{
	for (int i = 0; i < tileInfos.size(); i++)
	{
		if (tileInfos[i].grid == player->Grid())
		{
			if (tileInfos[i].tileNum == tileStairs)
				ChangeMap(eTutorial);
			return;
		}
	}
}

void PlayGame::DecidePlayerMovement()
{
	DoubleInt gridPlus;
	if (Key->Down('A'))
		gridPlus = DoubleInt(-1, 0);
	else if (Key->Down('D'))
		gridPlus = DoubleInt(1, 0);
	else if (Key->Down('W'))
		gridPlus = DoubleInt(0, 1);
	else if (Key->Down('S'))
		gridPlus = DoubleInt(0, -1);

	//°Ë»ö¼ø¼­: º® > ¸ó½ºÅÍ > Æ®·¦

	//º®
	if (Beats->GetBeatState() >= ePlayerCanMove && !player->Moving() && gridPlus != DoubleInt(0, 0))
	{
		for (int i = 0; i < wallInfos.size(); i++)
			if (wallInfos[i].grid == player->Grid() + gridPlus)
			{
				if (wallInfos[i].tileNum == vertiDoor || wallInfos[i].tileNum == horizDoor)
				{
					wallInfos.erase(wallInfos.begin() + i);
					break;
				}
				else if (player->GetShovelName()<=eDiaShovel)
				{
					if (player->GetShovelName() == eOriginalShovel)
					{
						if (wallInfos[i].tileNum < dirtStone1)
						{//dirt particle
							wallInfos.erase(wallInfos.begin() + i);
							break;
						}
						else {
							player->Render(eShovel, 0.6f, D3DXVECTOR2(wallInfos[i].grid.Position().x, wallInfos[i].grid.Position().y + (WALLHEI - GRID)*SCALE / 2));
							Beats->MissBeat(cameraPo); break; }
					}
					else if (player->GetShovelName() == eTitanumShovel)
					{
						if (wallInfos[i].tileNum < stoneLight1)
						{//stone particle
							wallInfos.erase(wallInfos.begin() + i);
							break;
						}
						else {
							player->Render(eShovel, 0.6f, D3DXVECTOR2(wallInfos[i].grid.Position().x, wallInfos[i].grid.Position().y + (WALLHEI - GRID)*SCALE / 2));
							Beats->MissBeat(cameraPo); break; }
					}
					else if (player->GetShovelName() == eDiaShovel)
					{
						if (wallInfos[i].tileNum < gold1)
						{//stone particle
							wallInfos.erase(wallInfos.begin() + i);
							break;
						}
						else 
						{
							player->Render(eShovel, 0.6f, D3DXVECTOR2(wallInfos[i].grid.Position().x, wallInfos[i].grid.Position().y + (WALLHEI - GRID)*SCALE / 2));
							Beats->MissBeat(cameraPo); break; 
						}
					}
				}
				else
				{
					player->Render(eShovel, 0.6f, D3DXVECTOR2(wallInfos[i].grid.Position().x, wallInfos[i].grid.Position().y + (WALLHEI - GRID)*SCALE / 2));
					Beats->MissBeat(cameraPo);
				}
				break;
			}
			else if (i == wallInfos.size() - 1)
			{
				player->Move();
				break;
			}
	}
	else if (gridPlus != DoubleInt(0, 0))
		Beats->MissBeat(cameraPo);

	//¸ó½ºÅÍ



	//Æ®·¦
}

void PlayGame::ChangeMap(enum MapName mapName)
{
	if (mapName == eTutorial)
	{
		player->Location(D3DXVECTOR2(0, SCALE*GRID / 4));
		player->Update(View(), Projection());
		OpenBinaryFile(L"tutorial.bin");
		bTemp = true;
	}
}

vector<GridInfo> PlayGame::FindCanClashWalls()
{
	vector<GridInfo>selectWallInfos;
	DoubleInt playerPo = player->Grid();
	while (true)
	{//find wallPo.y == playerPo.y+2 else y+1
		int start = 0;
		int end= wallInfos.size();
		int mid = (end - start) / 2;
		if (wallInfos[mid].grid.y == playerPo.y + 2)
		{

			break;
		}
	}

	while (true)
	{//find wallPo.y == playerPo.y-2 else y-1
		int start = 0;
		int end = wallInfos.size();
		int mid = (end - start) / 2;
		if (wallInfos[mid].grid.y == playerPo.y - 2)
		{

			break;
		}
	}
	return selectWallInfos;
}

void PlayGame::OpenBinaryFile(wstring name)
{
	tileInfos.clear();
	wallInfos.clear();
	eleInfos.clear();
	fireInfos.clear();

	BinaryReader* r = new BinaryReader;
	r->Open(L"Maps/"+name);

	BYTE infoOfSave;

	UINT loadTileCount;
	UINT loadWallCount;
	UINT loadeleCount;
	UINT loadAniEleCount;

	{
		void* ptr = (void*)&(infoOfSave);
		r->Byte(&ptr, sizeof(BYTE));
	}
	if (infoOfSave & 0b00000001)
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
	if (infoOfSave & 0b00000010)
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
	if (infoOfSave & 0b00000100)
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
	if (infoOfSave & 0b00001000)
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