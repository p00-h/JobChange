#include <iostream>
#include "Magician.h"
#include "Monster.h"

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

//void Magician::attack(){
//	std::cout << "[" << job_name << "] " << nickname << "��(��) �븶���� �����մϴ�!" << std::endl;
//}

void Magician::attack(Monster* monster) {
	// �÷��̾��� ���ݷ�-������ ������ ����Ͽ� �������� �����մϴ�.
	// ���� �������� 0 ������ ���, �������� 1�� �����մϴ�.
	// ���� ������ ����մϴ�.
	// - ������: ���� �������� 1ȸ ����
	// setHP�� ȣ���Ͽ� ������ HP-�������� ����� ���� �Ű������� �����մϴ�.
	// ���ϵ� ���� ���θ� �������� �б⹮�� ����˴ϴ�.
	// �������� ��� ������ ���� HP ���
	// �������� ������ ��� ������ ���� HP�� �÷��̾��� �¸� ���� ���
	int damage = power - monster->getDefence();
	if (damage <= 0) {
		damage = 1; // �������� 0 ������ ��� 1�� ����
	}
	std::cout << "[" << job_name << "] " << nickname << "��(��) �븶���� ������ " << damage << "�� ���ظ� �ݴϴ�!" << std::endl;

	bool isAlive = monster->setHP(monster->getHP() - damage);

	if (isAlive) {
		std::cout << monster->getName() << "�� ���� HP: " << monster->getHP() << std::endl;
	}
	else {
		std::cout << monster->getName() << "�� ���� HP: " << monster->getHP() << ", " << std::endl;
		std::cout << "[" << job_name << "] " << nickname << "��(��) �¸��߽��ϴ�!" << std::endl;
	}
}
