#include <iostream>
#include "Warrior.h"

Warrior::Warrior(string nickname) : Player(nickname) {
	job_name = "����";
	level = 1;
	HP = 120;
	MP = 50;
	power = 20;
	defence = 15;
	accuracy = 80;
	speed = 10;
}

void Warrior::attack() {
	std::cout << "["<< job_name << "]" << nickname << "��(��) ����� �ֵθ��ϴ�!" << std::endl;
}

