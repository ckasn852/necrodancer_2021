#pragma once
struct DoubleInt
{
	DoubleInt() { x = 0; y = 0; }
	DoubleInt(int n1, int n2) { x = n1; y = n2; }
	DoubleInt Position() { return DoubleInt(x*GRID*SCALE, y*GRID*SCALE); }
	bool operator ==(DoubleInt a)
	{
		if (x == a.x&&y == a.y)
			return true;
		else
			return false;
	}
	bool operator!=(DoubleInt a)
	{
		if (x != a.x || y != a.y)
			return true;
		else
			return false;
	}
	DoubleInt operator+(DoubleInt a)
	{
		return DoubleInt(x + a.x, y + a.y);
	}
	int x;
	int y;
};

class Math
{
public:
	static const float PI;

	static float Modulo(float val1, float val2);

	static float ToRadian(float degree);
	static float ToDegree(float radian);

	static int Random(int r1, int r2);
	static float Random(float r1, float r2);

	static float Clamp(float value, float min, float max);

};