#include <iostream>
#include "Magician.h"

Magician::Magician(string nickname) :Player(nickname) {
	job_name = "������";
	level = 1;
	HP = 80;
	MP = 100;
	power = 20;
	defence = 10;
	accuracy = 90;
	speed = 12;
}

void Magician::attack(){
	std::cout << "[" << job_name << "] " << nickname << "��(��) �븶���� �����մϴ�!" << std::endl;
}
