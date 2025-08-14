#include "Monster.h"

// Monster Ŭ���� ������
Monster::Monster(string name) : name(name),
	HP(10),
	power(30),
	defence(10),
	speed(10) {}

void Monster::attack(Player* player) {
	int damege = power - player->getDefence(); // ������ ���ݷ� - �÷��̾��� ����
	if (damege <= 0) {
		damege = 1; // �������� 0 ������ ��� 1�� ����
	}
	// ���� ������ ����մϴ�.
	cout << name << "��(��) " << player->getNickname() << "���� " << damege << "�� �������� �������ϴ�." << endl;
	
	// �÷��̾��� HP���� �������� ����, setHP�� ȣ���Ͽ� ���� ���θ� Ȯ���մϴ�.
	bool isAlive = player->setHP(player->getHP() - damege);
	// ���� ���ο� ���� �б⹮�� �����մϴ�.
	if (isAlive == 1) {
		std::cout << player->getNickname() << "�� HP�� " << player->getHP() << " ���ҽ��ϴ�." << std::endl;
	}
	else {
		std::cout << player->getNickname() << "�� HP�� " << player->getHP() << " ���ҽ��ϴ�." << std::endl;
		std::cout << name << "��(��) �¸��߽��ϴ�!" << std::endl;
	}
}

// ������ �Ӽ����� �����ϴ� get �Լ���
string Monster::getName() { return name; }
int Monster::getHP() { return HP; }
int Monster::getPower() { return power; }
int Monster::getDefence() { return defence; }
int Monster::getSpeed() { return speed; }

// ������ �Ӽ����� �����ϴ� set �Լ���
void Monster::setName(string name) { this->name = name; }
bool Monster::setHP(int HP) {
	if (HP <= 0) {
		this->HP = 0; // HP�� 0 ������ ��� 0���� ����
		return false; // HP�� 0 ������ ��� false ����
	}
	this->HP = HP; // ���ο� HP�� ����
	return true; // ���� �����̹Ƿ� true ����
}
void Monster::setPower(int power) { this->power = power; }
void Monster::setDefence(int defence) { this->defence = defence; }
void Monster::setSpeed(int speed) { this->speed = speed; }
