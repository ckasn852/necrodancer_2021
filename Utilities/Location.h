#pragma once
//위치 정보, 이동
struct Location
{
public:
	Location();
	Location(int locationX,int locationY);
	~Location();

	void Move(char tileShift);//x,y 이동
	DoubleInt grid;
	D3DXVECTOR2 po;

};