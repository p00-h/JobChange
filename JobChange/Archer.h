#pragma once
#include "Player.h"

// Archer.h
class Archer : public Player {
public:
	// ������
	Archer(string nickname);
	// ���� �Լ� ������
	void attack() override;
};