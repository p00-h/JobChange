#pragma once
#include "Player.h"

// Magician.h
class Magician : public Player {
public:
	// ������
	Magician(string nickname);
	// ���� �Լ� ������
	void attack() override;
};