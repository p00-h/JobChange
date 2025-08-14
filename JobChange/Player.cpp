#include "Player.h"

// Player 클래스 생성자
Player::Player(string nickname) : nickname(nickname), 
	level(1), 
	HP(100), 
	MP(50), 
	power(10), 
	defence(5), 
	accuracy(75), 
	speed(10) {}


void Player::printPlayerStatus() {
    cout << "------------------------------------" << endl;
    cout << "* 현재 능력치" << endl;
    cout << "닉네임: " << nickname << endl;
    cout << "직업: " << job_name << endl;
    cout << "Lv. " << level << endl;
    cout << "HP: " << HP << endl;
    cout << "MP: " << MP << endl;
    cout << "공격력: " << power << endl;
    cout << "방어력: " << defence << endl;
    cout << "정확도: " << accuracy << endl;
    cout << "속도: " << speed << endl;
    cout << "------------------------------------" << endl;
}

// getter 함수들
string Player::getJobName() {    return job_name;}
string Player::getNickname() {    return nickname;}
int Player::getLevel() {    return level;}
int Player::getHP() {    return HP;}
int Player::getMP() {    return MP;}
int Player::getPower() {    return power;}
int Player::getDefence() {    return defence;}
int Player::getAccuracy() {    return accuracy;}
int Player::getSpeed() {    return speed;}

// setter 함수들
void Player::setNickname(string nickname) {    this->nickname = nickname;}
bool Player::setHP(int HP) {
    if (HP <= 0) {
		this->HP = 0; // HP가 0 이하일 경우 0으로 설정
        return false;
    }
    this->HP = HP;
    return true;
}    
bool Player::setMP(int MP) {
    if (MP <= 0) {
		this->MP = 0; // MP가 0 이하일 경우 0으로 설정
		return false;
    }
	this->MP = MP;
	return true;
}
void Player::setPower(int power) {    this->power = power;}
void Player::setDefence(int defence) {    this->defence = defence;}
void Player::setAccuracy(int accuracy) {    this->accuracy = accuracy;}
void Player::setSpeed(int speed) {    this->speed = speed;}