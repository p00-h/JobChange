#pragma once
#include "Player.h"

// Warrior.h`
class Warrior : public Player {
public:
	// ������
	Warrior(string nickname);
	//void attack() override; // ���� �Լ� ������
	// ���� �Լ� ������
	void attack(Monster* monster) override;
};