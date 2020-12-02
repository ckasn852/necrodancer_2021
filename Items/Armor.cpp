#include "stdafx.h"
#include "Armor.h"

Armor::Armor()
{
	armors.resize(armorsCount);
	{
		armors[0] = new Sprite(spriteFile, Shaders9,0,4, 24, 24);
		armors[1] = new Sprite(spriteFile, Shaders9, 29, 2, 47, 25);
		armors[2] = new Sprite(spriteFile, Shaders9, 52, 4, 76, 24);
		armors[3] = new Sprite(spriteFile, Shaders9, 81, 4, 105, 24);
		armors[4] = new Sprite(spriteFile, Shaders9, 110, 2, 125, 25);
		armors[5] = new Sprite(spriteFile, Shaders9, 130, 2, 154, 25);

		armors[6] = new Sprite(spriteFile, Shaders9, 0, 28, 24, 48);
		armors[7] = new Sprite(spriteFile, Shaders9, 29, 26, 47, 49);
		armors[8] = new Sprite(spriteFile, Shaders9, 52, 28, 76, 48);
		armors[9] = new Sprite(spriteFile, Shaders9, 81, 28, 105, 48);
		armors[10] = new Sprite(spriteFile, Shaders9, 110, 26, 125, 49);
		armors[11] = new Sprite(spriteFile, Shaders9, 130, 26, 154, 49);
	}
	armorFrame = new Sprite(HudTextures, Shaders9, 75, 53, 105, 88);
}

Armor::~Armor()
{
	for (Sprite* armor : armors)
		SAFE_DELETE(armor);
	SAFE_DELETE(armorFrame);
}

void Armor::Update(D3DXMATRIX & V, D3DXMATRIX & P)
{
	if (bRender)
	{
		armors[armorInfo.name]->Update(V, P);
		armorFrame->Update(V, P);
	}
}

void Armor::Render()
{
	if (bRender)
	{
		armors[armorInfo.name]->Render();
		armorFrame->Render();
	}
}
