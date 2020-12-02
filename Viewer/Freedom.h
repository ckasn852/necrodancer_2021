#pragma once
#include "Camera.h"

class Freedom : public Camera
{
public:
	Freedom(float speed = 200.0f);
	~Freedom();

	void Update();

private:
	void Move(D3DXVECTOR2& translation);

private:
	float speed;
};