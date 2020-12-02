#pragma once
enum ElementsName
{
	eLightBulb,
	eMushroom1, eMushroom2, eMushroom3, eMushroom4,
	eMushroom1Sha, eMushroom2Sha, eMushroom3Sha, eMushroom4Sha
};
struct ElementInfo
{
	ElementInfo(){}
	~ElementInfo(){}
	DoubleInt grid;
	ElementsName name;
};
class Element
{
public:
	Element();
	~Element();

	void Update(D3DXMATRIX& V, D3DXMATRIX& P);
	void Update(ElementsName name, D3DXMATRIX& V, D3DXMATRIX& P);
	void Render();
	void Render(ElementsName name);
	void Render(ElementsName name, D3DXVECTOR2& vec);
	void Render(ElementsName name, float x, float y) { Render(name, D3DXVECTOR2(x, y)); }

private:
	Sprite* elements[9];
	wstring wallSprite = CryptTextures + L"StageElements/Walls.png";
	enum ElementsSprites
	{
		eLightBulb,
		//¹ö¼¸µé ¸÷À¸·Î Ä¡ÀÚ
		eMushroom1, eMushroom2, eMushroom3, eMushroom4,
		eMushroom1Sha, eMushroom2Sha, eMushroom3Sha, eMushroom4Sha
	};
};