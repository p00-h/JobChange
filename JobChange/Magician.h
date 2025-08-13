#pragma once
#include "Player.h"

// Magician.h
class Magician : public Player {
public:
	// 생성자
	Magician(string nickname);
	// 공격 함수 재정의
	void attack() override;
};