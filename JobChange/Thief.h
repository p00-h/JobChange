#pragma once
#include "Player.h"

// Thief.h
class Thief : public Player {
public: 
	// ������
	Thief(string nickname);
	// ���� �Լ� ������
	void attack() override;
};