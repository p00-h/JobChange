#include <iostream>
#include "Archer.h"
#include "Monster.h"

Archer::Archer(string nickname) : Player(nickname) {
	job_name = "궁수";
	level = 1;
	HP = 90;
	MP = 80;
	power = 32;
	defence = 10;
	accuracy = 85;
	speed = 15;
}

//void Archer::attack(){
//	std::cout << "[" << job_name << "] " << nickname << "이(가) 화살을 연사합니다!" << std::endl;
//}

void Archer::attack(Monster& monster) {
	// 플레이어의 공격력-몬스터의 방어력을 계산하여 데미지로 정의합니다.
	// 계산된 데미지가 0 이하일 경우, 데미지를 1로 정의합니다.
	// 공격 문장을 출력합니다.
	// - 궁수: 계산된 데미지/3으로 3회 공격 (소수점 생략)
	// setHP를 호출하여 몬스터의 HP-데미지를 계산한 값을 매개변수로 전달합니다.
	// 리턴된 생존 여부를 기준으로 분기문이 실행됩니다.
	// 생존했을 경우 몬스터의 남은 HP 출력
	// 생존하지 못했을 경우 몬스터의 남은 HP와 플레이어의 승리 문구 출력
	int damage = (power - monster.getDefence()) / 3;
	if (damage <= 0) {
		damage = 1; // 데미지가 0 이하일 경우 1로 정의
	}
	bool isAlive;

	// 공격 문장 출력
	// 궁수는 화살을 연사하는 공격을 합니다.
	// 데미지는 power의 1/3로 정의합니다.
	for (int i = 0; i < 3; i++) { // 궁수는 3회 연사
		std::cout << "[" << job_name << "] " << nickname << "이(가) 화살을 발사해 " << damage << "의 피해를 줍니다!" << std::endl;
		isAlive = monster.setHP(monster.getHP() - (damage));
		if (!isAlive) {
			std::cout << monster.getName() << "의 남은 HP: " << monster.getHP() << ", " << std::endl;
			std::cout << "[" << job_name << "] " << nickname << "이(가) 승리했습니다!" << std::endl;
			break; // 몬스터가 죽으면 반복문 종료
		}
	}
	if (isAlive) {
		std::cout << monster.getName() << "의 남은 HP: " << monster.getHP() << std::endl;
	}
}