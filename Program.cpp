#include "stdafx.h"
#include "Viewer/Freedom.h"
#include "./Systems/Device.h"
#include "Scenes/PlayGame.h"
#include "Scenes/Editor.h"
#include "Scenes/Scene.h"

Scene* scene;
PlayGame* playGame;
Editor* editor;
bool bEditor;
bool bPlay;

void InitScene()
{
	playGame = new PlayGame();
	editor = new Editor();
}

void DestroyScene()
{
	SAFE_DELETE(playGame);
	SAFE_DELETE(editor);
}

void Update()
{
	if (bPlay)
	{
		scene->Update();
	}
	if (bEditor)
	{
		scene->Update();
	}
}

void Render()
{
	D3DXCOLOR bgColor = D3DXCOLOR(0, 0, 0, 1);
	DeviceContext->ClearRenderTargetView(RTV, (float *)bgColor);
	{
		if (bPlay)
		{
			scene->Render();
		}
		if (bEditor)
		{
			scene->Render();
		}
		if (!bEditor)
			if (ImGui::Button("Editor"))
			{
				scene = new Editor();
				bEditor = true;
				bPlay = false;
			}
		if (!bPlay)
			if (ImGui::Button("Play"))
			{
				scene = new PlayGame();
				bEditor = false;
				bPlay = true;
				scene->Start(L"lobby.bin");
			}
		
	}
	ImGui::Render();

	SwapChain->Present(0, 0);
}

