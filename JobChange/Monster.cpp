#include "Monster.h"

// Monster 클래스 생성자
Monster::Monster(string name) : name(name),
	HP(10),
	power(30),
	defence(10),
	speed(10) {}

void Monster::attack(Player* player) {
	int damege = power - player->getDefence(); // 몬스터의 공격력 - 플레이어의 방어력
	if (damege <= 0) {
		damege = 1; // 데미지가 0 이하일 경우 1로 정의
	}
	// 공격 문장을 출력합니다.
	cout << name << "이(가) " << player->getNickname() << "에게 " << damege << "의 데미지를 입혔습니다." << endl;
	
	// 플레이어의 HP에서 데미지를 빼고, setHP를 호출하여 생존 여부를 확인합니다.
	bool isAlive = player->setHP(player->getHP() - damege);
	// 생존 여부에 따라 분기문을 실행합니다.
	if (isAlive == 1) {
		std::cout << player->getNickname() << "의 HP가 " << player->getHP() << " 남았습니다." << std::endl;
	}
	else {
		std::cout << player->getNickname() << "의 HP가 " << player->getHP() << " 남았습니다." << std::endl;
		std::cout << name << "이(가) 승리했습니다!" << std::endl;
	}
}

// 몬스터의 속성값을 리턴하는 get 함수들
string Monster::getName() { return name; }
int Monster::getHP() { return HP; }
int Monster::getPower() { return power; }
int Monster::getDefence() { return defence; }
int Monster::getSpeed() { return speed; }

// 몬스터의 속성값을 정의하는 set 함수들
void Monster::setName(string name) { this->name = name; }
bool Monster::setHP(int HP) {
	if (HP <= 0) {
		this->HP = 0; // HP가 0 이하일 경우 0으로 설정
		return false; // HP가 0 이하일 경우 false 리턴
	}
	this->HP = HP; // 새로운 HP값 정의
	return true; // 생존 상태이므로 true 리턴
}
void Monster::setPower(int power) { this->power = power; }
void Monster::setDefence(int defence) { this->defence = defence; }
void Monster::setSpeed(int speed) { this->speed = speed; }
