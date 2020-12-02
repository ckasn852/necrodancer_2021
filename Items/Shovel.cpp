#include "stdafx.h"
#include "Shovel.h"

Shovel::Shovel()
{
	shovels.resize(shovelsCount);

	{
		for (int i = 0; i < 7; i++)
			shovels[i] = new Sprite(spriteFile, Shaders9, i * 29, 0, (i + 1) * 29, 27);
		shovels[7]=new Sprite(spriteFile, Shaders9, 7 * 29, 0, (7 + 1) * 29, 27);
		for (int i = 0; i < 7; i++)
			shovels[i+8] = new Sprite(spriteFile, Shaders9, i * 29, 27, (i + 1) * 29, 54);
		shovels[15] = new Sprite(spriteFile, Shaders9, 7 * 29, 0, (7 + 1) * 29, 27);
	}
	shovelFrame = new Sprite(HudTextures, Shaders9, 0, 53, 35, 88);
	bRender = true;
}

Shovel::~Shovel()
{
	for (Sprite* shovel : shovels)
		SAFE_DELETE(shovel);
	SAFE_DELETE(shovelFrame);
}

void Shovel::Position(D3DXVECTOR2 & cameraPo)
{
	if (bRender)
	{
		shovelFrame->Position(cameraPo.x - (int)Width / 2 + ITEMFRAME / 2 * SCALE, cameraPo.y + (int)Height / 2 - ITEMFRAME / 2 * SCALE);
		shovels[name]->Position(cameraPo.x - (int)Width / 2 + ITEMFRAME / 2 * SCALE, cameraPo.y + (int)Height / 2 - ITEMFRAME / 2 * SCALE);
	}
}

void Shovel::Update(D3DXMATRIX & V, D3DXMATRIX & P)
{
	playerPo = D3DXVECTOR2(*CameraPosition);
	if (bRender)
	{
		shovelFrame->Position(playerPo.x - (int)Width / 2 + ITEMFRAME / 2 * SCALE, playerPo.y + (int)Height / 2 - ITEMFRAME / 2 * SCALE);
		shovels[name]->Position(playerPo.x - (int)Width / 2 + ITEMFRAME / 2 * SCALE, playerPo.y + (int)Height / 2 - ITEMFRAME / 2 * SCALE);
	}
	if (bRender || bTempRender)
	{
		shovels[name]->Update(V, P);
		shovelFrame->Update(V, P);
	}
		
	if (bRender)
		shovelFrame->Update(V, P);
}

void Shovel::RenderSecond(float second, D3DXVECTOR2 & vec)
{
	renderTimerMax = second;
	renderPo = vec;
	bTempRender = true;
}

void Shovel::Render()
{
	if(bTempRender)
	{
		shovels[name]->Render(renderPo);
		renderTimer += Timer->Elapsed();
		if (renderTimer > renderTimerMax)
		{
			bTempRender = false;
			renderTimer = 0;
		}
	}
	if (bRender)
	{
		shovels[name]->Render();
		shovelFrame->Render();
	}
}

void Shovel::Activate()
{
}
