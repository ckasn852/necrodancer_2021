#pragma once

class Object//이동 함수
{
public:
	virtual void Move();
	bool Moving() { return moving; }
	DoubleInt Grid() { return DoubleInt(location.grid.x, location.grid.y); }
	
protected:
	Object();
	~Object();

	void Update();

	Location location;
	BYTE moving = false;//define 참고
	D3DXVECTOR2 prePo;
	float sinX = 0;
	const float setVelocityY = 0.5f / BEATFRAME;
private:
	const float velocityX = 40.0f / BEATFRAME;
	float gravity = 0;
	bool bUpClimax = false;
	bool bCheckMove = false;
};