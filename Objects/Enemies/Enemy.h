#pragma once
#include "Objects/Object.h"
//플레이어에게 공격 받았을때 function
class Enemy:public Object
{
public:
	

protected:
	void Attacked();
	BYTE life;
private:
	
};