#include "stdafx.h"
#include "Element.h"

Element::Element()
{
	elements[0] = new Sprite(wallSprite, Shaders9, 504, 288, 528, 312);

	elements[1] = new Sprite(wallSprite, Shaders9, 528, 288, 552, 312);
	elements[2] = new Sprite(wallSprite, Shaders9, 552, 288, 572, 312);
	elements[3] = new Sprite(wallSprite, Shaders9, 572, 288, 596, 312);
	elements[4] = new Sprite(wallSprite, Shaders9, 596, 288, 616, 312);

	elements[5] = new Sprite(wallSprite, Shaders9, 528, 312, 552, 336);
	elements[6] = new Sprite(wallSprite, Shaders9, 552, 312, 572, 336);
	elements[7] = new Sprite(wallSprite, Shaders9, 572, 312, 596, 336);
	elements[8] = new Sprite(wallSprite, Shaders9, 596, 312, 616, 336);

}

Element::~Element()
{
	for (Sprite* element : elements)
		SAFE_DELETE(element);
}

void Element::Update(D3DXMATRIX & V, D3DXMATRIX & P)
{
	for (Sprite* element : elements)
		element->Update(V, P);
}

void Element::Update(ElementsName name, D3DXMATRIX & V, D3DXMATRIX & P)
{
	elements[name]->Update(V, P);
}

void Element::Render()
{
	for (Sprite* element : elements)
		element->Render();
}

void Element::Render(ElementsName name)
{
	elements[name]->Render();
}

void Element::Render(ElementsName name, D3DXVECTOR2 & vec)
{
	elements[name]->Render(vec);
}
