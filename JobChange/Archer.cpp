#include <iostream>
#include "archer.h"

Archer::Archer(string nickname) : Player(nickname) {
	job_name = "�ü�";
	level = 1;
	HP = 90;
	MP = 80;
	power = 15;
	defence = 10;
	accuracy = 85;
	speed = 15;
}

void Archer::attack(){
	std::cout << "[" << job_name << "] " << nickname << "��(��) ȭ���� �����մϴ�!" << std::endl;
}

