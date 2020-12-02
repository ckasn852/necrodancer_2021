#include "stdafx.h"
#include "Object.h"

void Object::Move()
{
	
}

Object::Object()
{
}

Object::~Object()
{
}

void Object::Update()
{
	if (!bCheckMove&&moving)
	{
		bCheckMove = true;
		switch (moving)
		{
		case LEFT:
			prePo = location.po;
			break;
		case RIGHT:
			prePo = location.po;
			break;
		case UP:
			gravity = 0.5f / BEATFRAME;
			prePo = location.po;
			sinX = 0;
			break;
		case DOWN:
			gravity = 2.0f / BEATFRAME;
			prePo = location.po;
			sinX = 0;
			break;
		default:
			break;
		}
	}

	//좌우 > sin형
	//상 > 일정 지점 도달시 y속력=0, 후 일정 지점 도달시 정지
	//하 > 일정 지점 도달시 정지
	switch (moving)
	{
	case LEFT:
		location.po.x -= velocityX * Timer->Elapsed();
		location.po.y = prePo.y - sinf((location.po.x - prePo.x)*M_PI / (GRID*SCALE))*GRID / 10 * SCALE;
		if (location.po.x - prePo.x < -GRID * SCALE)
		{
			bCheckMove = false;
			moving = false;
			location.po.x = prePo.x - GRID * SCALE;
			location.po.y = prePo.y;
			location.grid.x -= 1;
		}
		break;
	case RIGHT:
		location.po.x += velocityX * Timer->Elapsed();
		location.po.y = prePo.y + sinf((location.po.x - prePo.x)*M_PI / (GRID*SCALE))*GRID / 10 * SCALE;
		if (location.po.x - prePo.x > GRID*SCALE)
		{
			bCheckMove = false;
			moving = false;
			location.po.x = prePo.x + GRID * SCALE;
			location.po.y = prePo.y;
			location.grid.x += 1;
		}
		break;
	case UP:
		sinX += Timer->Elapsed();
		location.po.y = prePo.y + sinf(sinX*M_PI*2)*SCALE*GRID*1.1;
		if (sinX>=0.25f)
		{
			bUpClimax = true;
		}
		if (location.po.y - prePo.y < GRID*SCALE && bUpClimax)
		{
			bCheckMove = false;
			moving = false;
			location.po.y = prePo.y + GRID * SCALE;
			location.po.x = prePo.x;
			location.grid.y += 1;
			bUpClimax = false;
		}
		break;
	case DOWN:
		sinX += Timer->Elapsed();
		location.po.y = prePo.y + (sinf(sinX*M_PI * 2+M_PI*0.4f)-sinf(M_PI*0.4f))*SCALE*GRID*1.1;
		if (location.po.y - prePo.y < -GRID * SCALE)
		{
			bCheckMove = false;
			moving = false;
			location.po.y = prePo.y - GRID * SCALE;
			location.po.x = prePo.x;
			location.grid.y -= 1;
		}
		break;
	default:
		break;
	}//상하좌우 이동
}
