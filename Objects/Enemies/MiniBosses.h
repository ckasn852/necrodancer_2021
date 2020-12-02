#pragma once
#include "../Object.h"
enum MiniBossesName
{

};

class MiniBosses :public Object
{
public:
	MiniBosses();
	~MiniBosses();

	void Update(D3DXMATRIX& V, D3DXMATRIX& P);
	void Render();
private:
	vector<vector<Sprite>>miniBosses;
};