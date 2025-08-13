/*
- Player��� �⺻ Ŭ������ ���� �մϴ�.
- Player Ŭ�������� `attack()`�̶�� ���� ���� �Լ��� �����մϴ�.
- `attack()` �Լ��� ���⸦ �ֵθ��⸸ �ϴ� �⺻���� ���� �Լ��Դϴ�.
- Player Ŭ������ ��ӹ޾� �پ��� ���� Ŭ������ �����մϴ�.
- ��) Warrior, Magician, Thief, Archer
- �� ���� Ŭ�������� `attack()`�Լ��� **������**(�������̵�)�Ͽ� �ش� ������ ������ ����ϸ� �˴ϴ�!
- ���� �Լ����� Player Ÿ���� ������ �迭�� �����ϰ�, �ش��ϴ� ��ȣ�� �Է��ϸ� (1. ���� 2. ������ 3. ���� 4. �ü�)  
    Warrior, Magician, Thief, Archer�� ���� �迭�� ���ҷ� �����մϴ�.
    �� ���� Player�� `attack()` �Լ��� ȣ���Ͽ� �����մϴ�.
*/

#include <iostream>
#include "player.h"
#include "warrior.h"
#include "magician.h"
#include "thief.h"
#include "archer.h"
using namespace std;

// ���� �Լ�
int main() {
    string jobs[] = { "����", "������", "����", "�ü�" };
    int job_choice = 0;
    string nickname;

    Player* player = nullptr;

    cout << "* �г����� �Է����ּ���: ";
    cin >> nickname;

    cout << "<���� �ý���>" << endl;
    cout << nickname << "��, ȯ���մϴ�!" << endl;
    cout << "* ���Ͻô� ������ �������ּ���." << endl;

    for (int i = 0; i < 4; i++) {
        cout << (i + 1) << ". " << jobs[i] << endl;
    }

    cout << "����: ";
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
        cout << "�߸��� �Է��Դϴ�." << endl;
        return 1;
    }

    player->attack();
    player->printPlayerStatus();

    delete player;

    return 0;
}