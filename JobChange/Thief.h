#pragma once
#include "Player.h"

// Thief.h
class Thief : public Player {
public: 
	// 생성자
	Thief(string nickname);
	
	//void attack() override;// 공격 함수 재정의
	// 공격 함수 재정의
	void attack(Monster& monster) override;
};