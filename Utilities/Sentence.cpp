#include "stdafx.h"
#include "Sentence.h"

Sentence::Sentence()
{
	sentences.push_back(new Sprite(CryptTextures + L"Miscellaneous/Lobby_Font/lobby_tutorial.png", Shaders9, 70, 18));
	sentences[0]->Scale(SCALE/3, SCALE/3);
	sentences[0]->Position(1 * SCALE*GRID, -1 * SCALE*GRID -GRID*SCALE/2 + sentences[0]->Scale().y / 2*GRID);
}

Sentence::~Sentence()
{
	for (Sprite* sentence : sentences)
		SAFE_DELETE(sentence);
}

void Sentence::Update(D3DXMATRIX & V, D3DXMATRIX & P)
{
	for (Sprite* sentence : sentences)
		sentence->Update(V, P);
}

void Sentence::Render()
{
	for (Sprite* sentence : sentences)
		sentence->Render();
}
