#pragma once
#include <string>
#include <iostream>

using namespace std;

class Monster; // ���� ����

// Player Ŭ���� ����
class Player {
public:
	// ������
    Player(string nickname);
	// ���� �Ҹ���
	virtual ~Player() = default;

	// ���� ���� �Լ�
    //virtual void attack() = 0;
	// ���͸� �����ϴ� �Լ�
	virtual void attack(Monster* monster) = 0;
	// �÷��̾� ���� ��� �Լ�
    void printPlayerStatus();

    // getter �Լ�
    string getJobName();
    string getNickname();
    int getLevel();
    int getHP();
    int getMP();
    int getPower();
    int getDefence();
    int getAccuracy();
    int getSpeed();

    // setter �Լ�
    void setNickname(string nickname);
    bool setHP(int HP);
    bool setMP(int MP);
    void setPower(int power);
    void setDefence(int defence);
    void setAccuracy(int accuracy);
    void setSpeed(int speed);

protected:
    string job_name;
    string nickname;
    int level;
    int HP;
    int MP;
    int power;
    int defence;
    int accuracy;
    int speed;
};