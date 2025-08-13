#pragma once
#include "Player.h"

// Thief.h
class Thief : public Player {
public: 
	// 생성자
	Thief(string nickname);
	// 공격 함수 재정의
	void attack() override;
};