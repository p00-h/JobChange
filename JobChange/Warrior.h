#pragma once
#include "Player.h"

// Warrior.h`
class Warrior : public Player {
public:
	// ������
	Warrior(string nickname);
	// ���� �Լ� ������
	void attack() override;
};