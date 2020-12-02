#include "stdafx.h"
#include "Word.h"

Word::Word()
{
	{
		numbers[0] = new Sprite(HudTextures, Shaders9, 200, 44, 204, 50);
		numbers[1] = new Sprite(HudTextures, Shaders9, 0, 12, 32, 30);
		numbers[2] = new Sprite(HudTextures, Shaders9, 33, 12, 45, 30);
		numbers[3] = new Sprite(HudTextures, Shaders9, 46, 12, 58, 30);
		numbers[4] = new Sprite(HudTextures, Shaders9, 59, 12, 72, 30);
		numbers[5] = new Sprite(HudTextures, Shaders9, 85, 12, 73, 30);
		numbers[6] = new Sprite(HudTextures, Shaders9, 86, 12, 98, 30);
		numbers[7] = new Sprite(HudTextures, Shaders9, 99, 12, 111, 30);
		numbers[8] = new Sprite(HudTextures, Shaders9, 112, 12, 124, 30);
		numbers[9] = new Sprite(HudTextures, Shaders9, 125, 12, 137, 30);
	}
	{
		strings.push_back(new Sprite(CryptTextures + L"Miscellaneous/Fonts.png", Shaders9, 299, 0, 307, 10));
	}
}

Word::~Word()
{
	for (Sprite* number : numbers)
		SAFE_DELETE(number);
	for (Sprite* string : strings)
		SAFE_DELETE(string);
}

Sprite* Word::Number(BYTE num)
{
	return numbers[num];
}