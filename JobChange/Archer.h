#pragma once
#include "Player.h"

// Archer.h
class Archer : public Player {
public:
	// ������
	Archer(string nickname);

	//void attack() override;// ���� �Լ� ������
	// ���� �Լ� ������
	void attack(Monster* monster) override;
};