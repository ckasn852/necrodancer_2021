#include "stdafx.h"
#include "Beat.h"

Beat::Beat()
{
	beatLines.resize(8);
	for (int i = 0; i < 4; i++)
	{
		int j = i * 2;
		beatLines[j].beatLine = new Sprite(HudTextures, Shaders9, 200, 10, 206, 40);
		beatLines[j + 1].beatLine = new Sprite(HudTextures, Shaders9, 200, 10, 206, 40);

		beatLines[j].XShift = -int(Width) / 2 / 3 * (i + 4);
		beatLines[j + 1].XShift = int(Width) / 2 / 3 * (i + 4);

		beatLines[j].beatLine->Position(-int(Width) / 2 / 3 * (i + 4), -280);//width==1000(uint)
		beatLines[j + 1].beatLine->Position(int(Width) / 2 / 3 * (i + 4), -280);

		beatLines[j].bDirection = true;//right
		beatLines[j + 1].bDirection = false;//left
	}

	missSprite = new Sprite(CryptTextures + L"Miscellaneous/Korean/text/TEMP_missed.png", Shaders9, 36, 13);
}

Beat::~Beat()
{
	for (BeatLine beatLine : beatLines)
		SAFE_DELETE(beatLine.beatLine);
	SAFE_DELETE(missSprite);
}

void Beat::Position(D3DXVECTOR2 & cameraPo)
{
	this->cameraPo = cameraPo;
	beatState = eAllStop;
	for (int i = 0; i < 8; i++)//비트이동
	{
		if (beatLines[i].bDirection)
		{
			beatLines[i].XShift += Timer->Elapsed()*(1 / BEATFRAME * 50);
			beatLines[i].beatLine->Position(cameraPo.x + beatLines[i].XShift, cameraPo.y - beatPoY);
			if (beatLines[i].XShift >= -beatEndSpot)
			{
				beatLines[i].beatLine->Position(cameraPo.x - int(Width) / 2 / 3 * 4, cameraPo.y - beatPoY);
				beatLines[i].XShift = -int(Width) / 2 / 3 * 4;
			}
		}
		else
		{
			beatLines[i].XShift -= Timer->Elapsed() *(1 / BEATFRAME * 50);
			beatLines[i].beatLine->Position(cameraPo.x + beatLines[i].XShift, cameraPo.y - beatPoY);
			if (beatLines[i].XShift <= beatEndSpot)
			{
				beatLines[i].beatLine->Position(cameraPo.x + int(Width) / 2 / 3 * 4, cameraPo.y - beatPoY);
				beatLines[i].XShift = int(Width) / 2 / 3 * 4;
				beatState = eBeatEnd;
			}
		}
	}
	{
		sort(beatLines.begin(), beatLines.end());
		currentBeatPoX = beatLines[beatLines.size() / 2].XShift;

		if (currentBeatPoX <= 130)
			beatState = ePlayerCanMove;
		if (currentBeatPoX <= beatStartSpot)
			beatState = eBeatStart;
	}
	if (bMiss)
	{
		missTimer += Timer->Elapsed();
		missSprite->Position(cameraPo.x, cameraPo.y -beatPoY + missTimer * SCALE*GRID);
		if (missTimer > 1)
		{
			missTimer = 0;
			bMiss = false;
		}
	}
}

void Beat::Update(D3DXMATRIX & V, D3DXMATRIX & P)
{
	for (BeatLine beatLine : beatLines)
		beatLine.beatLine->Update(V, P);
	if (bMiss)
		missSprite->Update(V, P);
}

void Beat::Render()
{
	for (BeatLine beatLine : beatLines)
		beatLine.beatLine->Render();
}

void Beat::MissRender()
{
	if (bMiss)
		missSprite->Render();
}
