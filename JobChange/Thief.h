#pragma once
#include "Player.h"

// Thief.h
class Thief : public Player {
public: 
	// ������
	Thief(string nickname);
	
	//void attack() override;// ���� �Լ� ������
	// ���� �Լ� ������
	void attack(Monster* monster) override;
};