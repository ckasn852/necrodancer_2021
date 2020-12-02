#pragma once

class Animation
{
public:
	Animation();
	~Animation();

	//Animation operator=(Animation& a)
	//{//sprite, shader, ÁÂÇ¥

	//}

	void AddClip(Clip* clip);
	void Play(UINT clipNumber);
	void Stop();

	void Position(float x, float y);
	void Position(D3DXVECTOR2 vec);
	D3DXVECTOR2 Position() { return position; }

	void Scale(float x, float y);
	void Scale(D3DXVECTOR2 vec);
	D3DXVECTOR2 Scale() { return scale; }

	void Rotation(float x, float y, float z);
	void Rotation(D3DXVECTOR3& vec);
	D3DXVECTOR3 Rotation() { return rotation; }

	void RotationDegree(float x, float y, float z);
	void RotationDegree(D3DXVECTOR3& vec);
	D3DXVECTOR3 RotationDegree();

	D3DXVECTOR2 TextureSize();

	bool AABB(D3DXVECTOR2& position);
	bool AABB(Sprite* b);

	void Update(D3DXMATRIX& V, D3DXMATRIX& P);
	void Render(float x, float y);
	void Render(D3DXVECTOR2& vec) { Render(vec.x, vec.y); }
	void Render();

	Clip* GetClip();
	Sprite* GetSprite();

private:
	D3DXVECTOR2 position;
	D3DXVECTOR2 scale = D3DXVECTOR2(SCALE, SCALE);
	D3DXVECTOR3 rotation;

	int currentClip;
	vector<Clip*> clips;

};