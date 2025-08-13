#include <iostream>
#include "archer.h"

Archer::Archer(string nickname) : Player(nickname) {
	job_name = "궁수";
	level = 1;
	HP = 90;
	MP = 80;
	power = 15;
	defence = 10;
	accuracy = 85;
	speed = 15;
}

void Archer::attack(){
	std::cout << "[" << job_name << "] " << nickname << "이(가) 화살을 연사합니다!" << std::endl;
}

