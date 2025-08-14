#include <iostream>
#include "Thief.h"
#include "Monster.h"

Thief::Thief(string nickname) : Player(nickname) {
	job_name = "����";
	level = 1;
	HP = 100;
	MP = 80;
	power = 20;
	defence = 10;
	accuracy = 80;
	speed = 20;
}

//void Thief::attack(){
//	std::cout << "[" << job_name << "]" << nickname << "��(��) �ܰ��� ��ô�մϴ�!" << std::endl;
//}

void Thief::attack(Monster* monster) {
	// �÷��̾��� ���ݷ�-������ ������ ����Ͽ� �������� �����մϴ�.
	// ���� �������� 0 ������ ���, �������� 1�� �����մϴ�.
	// ���� ������ ����մϴ�.
	// - ����: ���� ������/3���� 3ȸ ���� (�Ҽ��� ����)
	// setHP�� ȣ���Ͽ� ������ HP-�������� ����� ���� �Ű������� �����մϴ�.
	// ���ϵ� ���� ���θ� �������� �б⹮�� ����˴ϴ�.
	// �������� ��� ������ ���� HP ���
	// �������� ������ ��� ������ ���� HP�� �÷��̾��� �¸� ���� ���
	int damage = (power - monster->getDefence()) / 3;
	if (damage <= 0) {
		damage = 1; // �������� 0 ������ ��� 1�� ����
	}
	bool isAlive; // ������ ���� ���θ� ������ ����

	// ���� ���� ���
	// ������ �ܰ��� �������� ������ ������ �մϴ�.
	// �������� power�� 1/3�� �����մϴ�.
	for (int i = 0; i < 3; i++) { // ������ 3ȸ ����
		std::cout << "[" << job_name << "] " << nickname << "��(��) �ܰ��� ���� " << damage << "�� ���ظ� �ݴϴ�!" << std::endl;
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
