#include <iostream>
#include "Thief.h"
#include "Monster.h"

Thief::Thief(string nickname) : Player(nickname) {
	job_name = "도적";
	level = 1;
	HP = 100;
	MP = 80;
	power = 20;
	defence = 10;
	accuracy = 80;
	speed = 20;
}

//void Thief::attack(){
//	std::cout << "[" << job_name << "]" << nickname << "이(가) 단검을 투척합니다!" << std::endl;
//}

void Thief::attack(Monster* monster) {
	// 플레이어의 공격력-몬스터의 방어력을 계산하여 데미지로 정의합니다.
	// 계산된 데미지가 0 이하일 경우, 데미지를 1로 정의합니다.
	// 공격 문장을 출력합니다.
	// - 도적: 계산된 데미지/3으로 3회 공격 (소수점 생략)
	// setHP를 호출하여 몬스터의 HP-데미지를 계산한 값을 매개변수로 전달합니다.
	// 리턴된 생존 여부를 기준으로 분기문이 실행됩니다.
	// 생존했을 경우 몬스터의 남은 HP 출력
	// 생존하지 못했을 경우 몬스터의 남은 HP와 플레이어의 승리 문구 출력
	int damage = (power - monster->getDefence()) / 3;
	if (damage <= 0) {
		damage = 1; // 데미지가 0 이하일 경우 1로 정의
	}
	bool isAlive; // 몬스터의 생존 여부를 저장할 변수

	// 공격 문장 출력
	// 도적는 단검을 연속으로 던지는 공격을 합니다.
	// 데미지는 power의 1/3로 정의합니다.
	for (int i = 0; i < 3; i++) { // 도적는 3회 연사
		std::cout << "[" << job_name << "] " << nickname << "이(가) 단검을 던져 " << damage << "의 피해를 줍니다!" << std::endl;
		isAlive = monster->setHP(monster->getHP() - (damage));
		if (!isAlive) {
			std::cout << monster->getName() << "의 남은 HP: " << monster->getHP() << ", " << std::endl;
			std::cout << "[" << job_name << "] " << nickname << "이(가) 승리했습니다!" << std::endl;
			break; // 몬스터가 죽으면 반복문 종료
		}
	}
	if (isAlive) {
		std::cout << monster->getName() << "의 남은 HP: " << monster->getHP() << std::endl;
	}
}
