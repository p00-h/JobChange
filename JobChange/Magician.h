#pragma once
#include "Player.h"

// Magician.h
class Magician : public Player {
public:
	// ������
	Magician(string nickname);
	
	//void attack() override;// ���� �Լ� ������
	// ���� �Լ� ������
	void attack(Monster* monster) override;
};