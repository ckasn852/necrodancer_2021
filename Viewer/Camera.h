#pragma once

class Camera
{
public:
	Camera();
	virtual ~Camera();

	D3DXMATRIX View() { return view; }
	D3DXVECTOR2 Position() { return position; }

	void Position(float x, float y) { Position(D3DXVECTOR2(x, y)); }
	void Position(D3DXVECTOR2& vec) { position = vec; }

	virtual void Update();

protected:
	D3DXVECTOR2 position;

private:
	D3DXMATRIX view;
};