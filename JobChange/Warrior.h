#pragma once
#include "Player.h"

// Warrior.h`
class Warrior : public Player {
public:
	// 생성자
	Warrior(string nickname);
	// 공격 함수 재정의
	void attack() override;
};