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
#include <vector>
#include <memory>
#include "Player.h"
#include "Warrior.h"
#include "Magician.h"
#include "Thief.h"
#include "Archer.h"
#include "Monster.h"

using namespace std;

// ���� �Լ�
int main() {
    vector<string> monsters = {"������","��ũ","�巡��"};
	vector<string> jobs = { "����", "������", "����", "�ü�" };         // ���� ���
	int job_choice = 0;                                         // ���� ���� ����
	string nickname;                                            // �÷��̾� �г��� ����

	Player* player = nullptr;                                   // Player Ÿ���� ������ ����

    cout << "* �г����� �Է����ּ���: ";          
	cin >> nickname;                                            // �÷��̾� �г��� �Է�

    cout << "<���� �ý���>" << endl;
    cout << nickname << "��, ȯ���մϴ�!" << endl;
    cout << "* ���Ͻô� ������ �������ּ���." << endl;

	for (size_t i = 0; i < jobs.size(); i++) {                               // ���� ��� ���
        cout << (i + 1) << ". " << jobs[i] << endl;
    }

    cout << "��ȣ ����: ";
    cin >> job_choice;

	switch (job_choice) {                                       // ���� ���ÿ� ���� ��ü ����
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
    player->printPlayerStatus();                                // �÷��̾� ���� ���
    
    //monster->attack(player);                                    // ���� ���� �Լ� ȣ��
    //player->attack(monster);                                    // ���� �Լ� ȣ��
    

    for (size_t i = 0; i < monsters.size() && player->getHP() > 0; i++) {

        auto monster = make_unique<Monster>(monsters[i]);                    // ���� ��ü ����
        cout  << monster->getName() << " ���Ͱ� ��Ÿ�����ϴ�! "<< endl;

        // ���Ϳ� �÷��̾� ���� �ϳ��� ���� ������ ������ �ݺ��մϴ�.
        for(; player->getHP() > 0 && monster->getHP() > 0;) {
		// ���Ͱ� �÷��̾ ����
        monster->attack(player);
		// �÷��̾ ���͸� ����
            if (player->getHP() > 0) {
                player->attack(monster.get());
            }
        }

        // ���� �÷��̾� ���� ���
	    player->printPlayerStatus();

    }

    delete player;
    player = nullptr;

    return 0;
}




/***********************************************************************************************************************
* ���α׷� ����:
* �� ���α׷��� �پ��� ������ ���� �÷��̾ ���Ϳ� ������ ���̴� �����Դϴ�.
* �� ������ Player Ŭ������ ��ӹ޾� ������ ���� ����� �����ϸ�,
* ���ʹ� Player�� �����ϰ�, �÷��̾�� ���͸� �����մϴ�.
* �÷��̾�� �г����� �Է��ϰ�, ���ϴ� ������ �����Ͽ� ������ �����մϴ�.
* ���Ϳ��� ������ �÷��̾��� HP�� 0�� �� ������ ��ӵǸ�,
* �� ���� �� �÷��̾��� ���°� ��µ˴ϴ�.
* ���ʹ� �̸�, HP = 10, ���ݷ� = 30, ���� = 10, �ӵ� = 10 ���� �Ӽ��� ������,
* �÷��̾�� ������ ���� HP, MP, ���ݷ�, ����, ��Ȯ��, �ӵ� ���� �Ӽ��� �����ϴ�.
* �� ������ ������ ���� ����� ������ ������, ���Ϳ��� �������� �¸��� �� �ֽ��ϴ�.
* �� ������ ���� ����� Player Ŭ������ `attack()` �Լ��� �������̵��Ͽ� �����˴ϴ�.
* ���ʹ� Player�� �����ϰ�, Player�� ���͸� �����ϴ� ������� ������ ����˴ϴ�.
* �� ���� �� �÷��̾��� ���°� ��µǸ�, ���Ͱ� ������ ���� ���ͷ� �Ѿ�ϴ�.
* ���Ͱ� ������ �÷��̾��� �¸� �޽����� ��µ˴ϴ�.
* �� ���α׷��� ��ü ���� ���α׷����� ��Ӱ� �������� Ȱ���Ͽ� �پ��� ������ �÷��̾�� ���� ���� ������ �����մϴ�.
***********************************************************************************************************************/