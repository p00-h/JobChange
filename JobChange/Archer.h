#pragma once
#include "Player.h"

// Archer.h
class Archer : public Player {
public:
	// 생성자
	Archer(string nickname);
	// 공격 함수 재정의
	void attack() override;
};