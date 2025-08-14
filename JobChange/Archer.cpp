#include <iostream>
#include "archer.h"
#include "Monster.h"

Archer::Archer(string nickname) : Player(nickname) {
	job_name = "�ü�";
	level = 1;
	HP = 90;
	MP = 80;
	power = 32;
	defence = 10;
	accuracy = 85;
	speed = 15;
}

//void Archer::attack(){
//	std::cout << "[" << job_name << "] " << nickname << "��(��) ȭ���� �����մϴ�!" << std::endl;
//}

void Archer::attack(Monster* monster) {
	// �÷��̾��� ���ݷ�-������ ������ ����Ͽ� �������� �����մϴ�.
	// ���� �������� 0 ������ ���, �������� 1�� �����մϴ�.
	// ���� ������ ����մϴ�.
	// - �ü�: ���� ������/3���� 3ȸ ���� (�Ҽ��� ����)
	// setHP�� ȣ���Ͽ� ������ HP-�������� ����� ���� �Ű������� �����մϴ�.
	// ���ϵ� ���� ���θ� �������� �б⹮�� ����˴ϴ�.
	// �������� ��� ������ ���� HP ���
	// �������� ������ ��� ������ ���� HP�� �÷��̾��� �¸� ���� ���
	int damage = (power - monster->getDefence()) / 3;
	if (damage <= 0) {
		damage = 1; // �������� 0 ������ ��� 1�� ����
	}
	bool isAlive;

	// ���� ���� ���
	// �ü��� ȭ���� �����ϴ� ������ �մϴ�.
	// �������� power�� 1/3�� �����մϴ�.
	for (int i = 0; i < 3; i++) { // �ü��� 3ȸ ����
		std::cout << "[" << job_name << "] " << nickname << "��(��) ȭ���� �߻��� " << damage << "�� ���ظ� �ݴϴ�!" << std::endl;
		isAlive = monster->setHP(monster->getHP() - (damage));
		if (!isAlive) {
			std::cout << monster->getName() << "�� ���� HP: " << monster->getHP() << ", " << std::endl;
			std::cout << "[" << job_name << "] " << nickname << "��(��) �¸��߽��ϴ�!" << std::endl;
			break; // ���Ͱ� ������ �ݺ��� ����
		}
	}
	if (isAlive) {
		std::cout << monster->getName() << "�� ���� HP: " << monster->getHP() << std::endl;
	}
}