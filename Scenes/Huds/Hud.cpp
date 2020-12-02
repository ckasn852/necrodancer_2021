#include "stdafx.h"
#include "BeatHeart.h"
#include "Hud.h"

Hud::Hud()
{
	beatHeart = new BeatHeart();
}

Hud::~Hud()
{
	SAFE_DELETE(beatHeart);
	SAFE_DELETE(Beats);
}

void Hud::Position(D3DXVECTOR2 & cameraPo)
{
	beatHeart->Position(cameraPo);
	Beats->Position(cameraPo);
}

void Hud::Update(D3DXMATRIX & V, D3DXMATRIX & P)
{
	beatHeart->UpdateState(Beats->GetBeatState());
	beatHeart->Update(V, P);
	Beats->Update(V, P);
}

void Hud::Render()
{
	Beats->Render();
	beatHeart->Render();
	Beats->MissRender();
}
