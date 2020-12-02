#include "stdafx.h"
#include "Weapon.h"

Weapon::Weapon()
{
	weapons.resize(weaponsCount);
	BYTE countsSum = 0;

	{
		BYTE swordCount = 6;
		
		for (BYTE i = 0; i < swordCount; i++)
			weapons[i] = new Sprite(spriteFile, Shaders9, i * 18, 0, (i + 1) * 18, 18);
			
		for (BYTE i = 0; i < swordCount; i++)
			weapons[i + swordCount] = new Sprite(spriteFile, Shaders9, i * 18, 24, (i + 1) * 18, 42);
		countsSum += swordCount * 2;
	}
	
	{
		BYTE bigSwordCount = 5;
		for (BYTE i = 0; i < bigSwordCount; i++)
			weapons[i + countsSum] = new Sprite(spriteFile, Shaders9, i * 28, 52, (i + 1) * 28, 78);
			
		for (BYTE i = 0; i < bigSwordCount; i++)
			weapons[i + countsSum + bigSwordCount] = new Sprite(spriteFile, Shaders9, i * 28, 78, (i + 1) * 28, 103);
		countsSum += bigSwordCount * 2;
	}
	
	{
		BYTE longSwordCount = 5;
		for (BYTE i = 0; i < longSwordCount; i++)
			weapons[i + countsSum] = new Sprite(spriteFile, Shaders9, i * 28, 115, (i + 1) * 28, 140);
			
		for (BYTE i = 0; i < longSwordCount; i++)
			weapons[i + countsSum + longSwordCount] = new Sprite(spriteFile, Shaders9, i * 28, 142, (i + 1) * 28, 167);
		
		countsSum += longSwordCount * 2;
	}
	weaponFrame = new Sprite(HudTextures, Shaders9, 35, 53, 70, 88);

	
	{
		Clip* clip;
		for(int i=0;i<4;i++)
		{
			effects[i] = new Animation();
			clip = new Clip(PlayMode::End);
			clip->AddFrame(new Sprite(effectSprite, Shaders9, 300, 20 + 23 * i, 313, 33 + 23 * i),ANIMATIONFRAME);
			clip->AddFrame(new Sprite(effectSprite, Shaders9, 325, 20 + 23 * i, 337, 33 + 23 * i), ANIMATIONFRAME);
			clip->AddFrame(new Sprite(effectSprite, Shaders9, 342, 20 + 23 * i, 360, 33 + 23 * i), ANIMATIONFRAME);
			effects[i]->AddClip(clip);
			effects[i]->Play(0);
		}
	}

	bRender = true;
}

Weapon::~Weapon()
{
	for (Sprite* weapon : weapons)
		SAFE_DELETE(weapon);
	for (Animation* action : effects)
		SAFE_DELETE(action);
	SAFE_DELETE(weaponFrame);
}

void Weapon::Update(D3DXMATRIX & V, D3DXMATRIX & P)
{
	cameraPo = D3DXVECTOR2(*CameraPosition);
	if (bRender)
	{
		weapons[name]->Position(cameraPo.x - (int)Width / 2 + ITEMFRAME / 2 * SCALE*3, cameraPo.y + (int)Height / 2 - ITEMFRAME / 2 * SCALE);
		weaponFrame->Position(cameraPo.x - (int)Width / 2 + ITEMFRAME / 2 * SCALE * 3, cameraPo.y + (int)Height / 2 - ITEMFRAME / 2 * SCALE);
		weapons[name]->Update(V, P);
		weaponFrame->Update(V, P);
		
	}
	
	
}

void Weapon::Render(float x, float y)
{
}

void Weapon::Render()
{
	if (bRender)
	{
		weapons[name]->Render();
		weaponFrame->Render();
	}
}

void Weapon::Activate()
{

}
