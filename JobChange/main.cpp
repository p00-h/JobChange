/*
- Player라는 기본 클래스를 정의 합니다.
- Player 클래스에는 `attack()`이라는 순수 가상 함수를 포함합니다.
- `attack()` 함수는 무기를 휘두르기만 하는 기본적인 공격 함수입니다.
- Player 클래스를 상속받아 다양한 직업 클래스를 생성합니다.
- 예) Warrior, Magician, Thief, Archer
- 각 직업 클래스에서 `attack()`함수를 **재정의**(오버라이딩)하여 해당 직업의 공격을 출력하면 됩니다!
- 메인 함수에서 Player 타입의 포인터 배열을 선언하고, 해당하는 번호를 입력하면 (1. 전사 2. 마법사 3. 도적 4. 궁수)  
    Warrior, Magician, Thief, Archer를 각각 배열의 원소로 선언합니다.
    → 이후 Player는 `attack()` 함수를 호출하여 공격합니다.
*/

#include <iostream>
#include <vector>
#include <memory>
#include "Player.h"
#include "Warrior.h"
#include "Magician.h"
#include "Thief.h"
#include "Archer.h"
#include "Monster.h"

using namespace std;

// 메인 함수
int main() {
    vector<string> monsters = {"슬라임","오크","드래곤"};
	vector<string> jobs = { "전사", "마법사", "도적", "궁수" };         // 직업 목록
	int job_choice = 0;                                         // 직업 선택 변수
	string nickname;                                            // 플레이어 닉네임 변수

	Player* player = nullptr;                                   // Player 타입의 포인터 선언

    cout << "* 닉네임을 입력해주세요: ";          
	cin >> nickname;                                            // 플레이어 닉네임 입력

    cout << "<전직 시스템>" << endl;
    cout << nickname << "님, 환영합니다!" << endl;
    cout << "* 원하시는 직업을 선택해주세요." << endl;

	for (size_t i = 0; i < jobs.size(); i++) {                               // 직업 목록 출력
        cout << (i + 1) << ". " << jobs[i] << endl;
    }

    cout << "번호 선택: ";
    cin >> job_choice;

	switch (job_choice) {                                       // 직업 선택에 따른 객체 생성
    case 1:
        player = new Warrior(nickname);
        break;
    case 2:
        player = new Magician(nickname);
        break;
    case 3:
        player = new Thief(nickname);
        break;
    case 4:
        player = new Archer(nickname);
        break;
    default:
        cout << "잘못된 입력입니다." << endl;
        return 1;
    }
    player->printPlayerStatus();                                // 플레이어 상태 출력
    
    //monster->attack(player);                                    // 몬스터 공격 함수 호출
    //player->attack(monster);                                    // 공격 함수 호출
    

    for (size_t i = 0; i < monsters.size() && player->getHP() > 0; i++) {

        auto monster = make_unique<Monster>(monsters[i]);                    // 몬스터 객체 생성
        cout  << monster->getName() << " 몬스터가 나타났습니다! "<< endl;

        // 몬스터와 플레이어 둘중 하나가 죽을 때까지 공격을 반복합니다.
        for(; player->getHP() > 0 && monster->getHP() > 0;) {
		// 몬스터가 플레이어를 공격
        monster->attack(player);
		// 플레이어가 몬스터를 공격
            if (player->getHP() > 0) {
                player->attack(monster.get());
            }
        }

        // 최종 플레이어 상태 출력
	    player->printPlayerStatus();

    }

    delete player;
    player = nullptr;

    return 0;
}




/***********************************************************************************************************************
* 프로그램 설명:
* 이 프로그램은 다양한 직업을 가진 플레이어가 몬스터와 전투를 벌이는 게임입니다.
* 각 직업은 Player 클래스를 상속받아 고유의 공격 방식을 구현하며,
* 몬스터는 Player를 공격하고, 플레이어는 몬스터를 공격합니다.
* 플레이어는 닉네임을 입력하고, 원하는 직업을 선택하여 게임을 시작합니다.
* 몬스터와의 전투는 플레이어의 HP가 0이 될 때까지 계속되며,
* 각 전투 후 플레이어의 상태가 출력됩니다.
* 몬스터는 이름, HP = 10, 공격력 = 30, 방어력 = 10, 속도 = 10 등의 속성을 가지며,
* 플레이어는 직업에 따라 HP, MP, 공격력, 방어력, 정확도, 속도 등의 속성을 가집니다.
* 각 직업은 고유의 공격 방식을 가지고 있으며, 몬스터와의 전투에서 승리할 수 있습니다.
* 각 직업의 공격 방식은 Player 클래스의 `attack()` 함수를 오버라이드하여 구현됩니다.
* 몬스터는 Player를 공격하고, Player는 몬스터를 공격하는 방식으로 전투가 진행됩니다.
* 각 전투 후 플레이어의 상태가 출력되며, 몬스터가 죽으면 다음 몬스터로 넘어갑니다.
* 몬스터가 죽으면 플레이어의 승리 메시지가 출력됩니다.
* 이 프로그램은 객체 지향 프로그래밍의 상속과 다형성을 활용하여 다양한 직업의 플레이어와 몬스터 간의 전투를 구현합니다.
***********************************************************************************************************************/