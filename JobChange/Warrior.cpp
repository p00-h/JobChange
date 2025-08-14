#include <iostream>
#include "Warrior.h"
#include "Monster.h"

Warrior::Warrior(string nickname) : Player(nickname) {
	job_name = "����";
	level = 1;
	HP = 120;
	MP = 50;
	power = 20;
	defence = 15;
	accuracy = 80;
	speed = 10;
}

//void Warrior::attack() {
//	std::cout << "["<< job_name << "] " << nickname << "��(��) ����� �ֵѷ� ���ظ� �ݴϴ�!" << std::endl;
//}

void Warrior::attack(Monster* monster) {
	// �÷��̾��� ���ݷ�-������ ������ ����Ͽ� �������� �����մϴ�.
	// ���� �������� 0 ������ ���, �������� 1�� �����մϴ�.
	// ���� ������ ����մϴ�.
	// - ����: ���� �������� 1ȸ ����
	// setHP�� ȣ���Ͽ� ������ HP-�������� ����� ���� �Ű������� �����մϴ�.
	// ���ϵ� ���� ���θ� �������� �б⹮�� ����˴ϴ�.
	// �������� ��� ������ ���� HP ���
	// �������� ������ ��� ������ ���� HP�� �÷��̾��� �¸� ���� ���
	int damage = power - monster->getDefence();
	if (damage <= 0) {
		damage = 1; // �������� 0 ������ ��� 1�� ����
	}
	std::cout << "[" << job_name << "] " << nickname << "��(��) ����� �ֵѷ� " << damage << "�� ���ظ� �ݴϴ�!" << std::endl;

	bool isAlive = monster->setHP(monster->getHP() - damage);

	if (isAlive) {
		std::cout << monster->getName() << "�� ���� HP: " << monster->getHP() << std::endl;
	} else {
		std::cout << monster->getName() << "�� ���� HP: " << monster->getHP() << ", " << std::endl;
		std::cout << "[" << job_name << "] " << nickname << "��(��) �¸��߽��ϴ�!" << std::endl;
	}
}
