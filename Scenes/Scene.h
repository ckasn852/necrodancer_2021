#pragma once
#include "stdafx.h"

struct SceneValues
{
	class Camera* MainCamera;
	D3DXMATRIX Projection;
};

class Scene
{
public:
	Scene(){}
	virtual ~Scene(){}

	virtual void Update()=0;
	virtual void Render()=0;

	auto View() { return values->MainCamera->View(); }
	auto Projection() { return values->Projection; }

	virtual void Start(wstring map){}
protected:
	SceneValues* values;
};