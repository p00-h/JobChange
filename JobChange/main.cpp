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
#include "player.h"
#include "warrior.h"
#include "magician.h"
#include "thief.h"
#include "archer.h"
using namespace std;

// 메인 함수
int main() {
    string jobs[] = { "전사", "마법사", "도적", "궁수" };
    int job_choice = 0;
    string nickname;

    Player* player = nullptr;

    cout << "* 닉네임을 입력해주세요: ";
    cin >> nickname;

    cout << "<전직 시스템>" << endl;
    cout << nickname << "님, 환영합니다!" << endl;
    cout << "* 원하시는 직업을 선택해주세요." << endl;

    for (int i = 0; i < 4; i++) {
        cout << (i + 1) << ". " << jobs[i] << endl;
    }

    cout << "선택: ";
    cin >> job_choice;

    switch (job_choice) {
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

    player->attack();
    player->printPlayerStatus();

    delete player;

    return 0;
}