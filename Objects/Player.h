#pragma once
#include "PlayerStates/PlayerStates.h"
#include "Object.h"

class Player: public Object
{
public:
	Player();
	~Player();

	void Location(D3DXVECTOR2& location);
	void Position(D3DXVECTOR2& cameraPo);
	void Position(float x, float y) { Position(D3DXVECTOR2(x, y)); }

	void Update(D3DXMATRIX& V, D3DXMATRIX& P);
	void Render(WhichItem item, float second, D3DXVECTOR2& vec) { playerStates->Render(item, second, vec); }
	void Render();
	void StateRender() { playerStates->Render(); }
	

	void Move();//방향을 정해주고 super::Move() call

public:
	ShovelName GetShovelName() { return playerStates->GetShovelName(); }
	WeaponName GetWeaponName() { return playerStates->GetWeaponName(); }


private:
	class PlayerStates* playerStates;
	Animation* head;
	Animation* body;
};