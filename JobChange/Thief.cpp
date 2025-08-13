#include <iostream>
#include "Thief.h"

Thief::Thief(string nickname) : Player(nickname) {
	job_name = "����";
	level = 1;
	HP = 100;
	MP = 80;
	power = 15;
	defence = 10;
	accuracy = 80;
	speed = 20;
}

void Thief::attack(){
	std::cout << "[" << job_name << "]" << nickname << "��(��) �ܰ��� ��ô�մϴ�!" << std::endl;
}
