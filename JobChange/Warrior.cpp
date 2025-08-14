#include <iostream>
#include "Warrior.h"
#include "Monster.h"

Warrior::Warrior(string nickname) : Player(nickname) {
	job_name = "전사";
	level = 1;
	HP = 120;
	MP = 50;
	power = 20;
	defence = 15;
	accuracy = 80;
	speed = 10;
}

//void Warrior::attack() {
//	std::cout << "["<< job_name << "] " << nickname << "이(가) 대검을 휘둘러 피해를 줍니다!" << std::endl;
//}

void Warrior::attack(Monster* monster) {
	// 플레이어의 공격력-몬스터의 방어력을 계산하여 데미지로 정의합니다.
	// 계산된 데미지가 0 이하일 경우, 데미지를 1로 정의합니다.
	// 공격 문장을 출력합니다.
	// - 전사: 계산된 데미지로 1회 공격
	// setHP를 호출하여 몬스터의 HP-데미지를 계산한 값을 매개변수로 전달합니다.
	// 리턴된 생존 여부를 기준으로 분기문이 실행됩니다.
	// 생존했을 경우 몬스터의 남은 HP 출력
	// 생존하지 못했을 경우 몬스터의 남은 HP와 플레이어의 승리 문구 출력
	int damage = power - monster->getDefence();
	if (damage <= 0) {
		damage = 1; // 데미지가 0 이하일 경우 1로 정의
	}
	std::cout << "[" << job_name << "] " << nickname << "이(가) 대검을 휘둘러 " << damage << "의 피해를 줍니다!" << std::endl;

	bool isAlive = monster->setHP(monster->getHP() - damage);

	if (isAlive) {
		std::cout << monster->getName() << "의 남은 HP: " << monster->getHP() << std::endl;
	} else {
		std::cout << monster->getName() << "의 남은 HP: " << monster->getHP() << ", " << std::endl;
		std::cout << "[" << job_name << "] " << nickname << "이(가) 승리했습니다!" << std::endl;
	}
}
