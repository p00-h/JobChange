#pragma once
#include <string>
#include <iostream>

using namespace std;

class Monster; // 전방 선언

// Player 클래스 정의
class Player {
public:
	// 생성자
    Player(string nickname);
	// 가상 소멸자
	virtual ~Player() = default;

	// 순수 가상 함수
    //virtual void attack() = 0;
	// 몬스터를 공격하는 함수
	virtual void attack(Monster* monster) = 0;
	// 플레이어 상태 출력 함수
    void printPlayerStatus();

    // getter 함수
    string getJobName();
    string getNickname();
    int getLevel();
    int getHP();
    int getMP();
    int getPower();
    int getDefence();
    int getAccuracy();
    int getSpeed();

    // setter 함수
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