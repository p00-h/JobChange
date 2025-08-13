#include <iostream>
#include "Thief.h"

Thief::Thief(string nickname) : Player(nickname) {
	job_name = "도적";
	level = 1;
	HP = 100;
	MP = 80;
	power = 15;
	defence = 10;
	accuracy = 80;
	speed = 20;
}

void Thief::attack(){
	std::cout << "[" << job_name << "]" << nickname << "이(가) 단검을 투척합니다!" << std::endl;
}
