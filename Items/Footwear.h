#pragma once
#include "Item.h"
class Footwear
{
public:
	Footwear();
	~Footwear();

	void Update(D3DXMATRIX& V, D3DXMATRIX& P);
	void Render();

private:
};