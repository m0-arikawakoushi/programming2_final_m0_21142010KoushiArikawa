#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

//�����G���W��
random_device engine;

//�r���S�֐��i�r���S�ŗp����1����75�̐������d���Ȃ������_���ɕ\���j
int Bingo(int b) {

    cin.get();  //�L�[�{�[�h���͑҂�
    cout << "BINGO�Q�[���X�^�[�g!!!\n";
    cout << "Enter�L�[�������Ă݂āB�������o�Ă����\n" << endl;

    //vector��2�p��
    vector<int>vb(75);
    vector<int>vB;
    //vb��1����75�̐�����O���珇�Ԃɕ��ׂ�
     for (int i = 0; i < 75; ++i) {
         vb[i] = i + 1;
    }
    //vB��1����75�̐������d���Ȃ������_���ɁAvb����ڂ�
     int r = 0;
     for (int i = 0; i < 75; ++i) {  //75�񏈗����J��Ԃ�

         //vb�̂ǂ̕������琔����I�Ԃ��������_���ɂ���(�����őI�����镔���ԍ������߂�)
         uniform_int_distribution <unsigned> vb_room_num(0, 74-i); //���������A������1��I��邲�Ƃɔ͈͂𐔎�1�����炷
         r = vb_room_num(engine); //��x��������������1��̏����̒��ŁA�g��������̂�r�ŌŒ肷��C���[�W

         vB.push_back(vb[r]); //vb���烉���_���ɑI�񂾐���vB�ɑO���珇�Ԃɋl�߂�
         vb.erase(vb.begin()  + r ); //�I�΂ꂽ����(�v�f)�͍폜���Ă������ƂŎ�����̏����ł����I�Ԃ��Ƃ͂Ȃ��A�d���͂Ȃ�
      }                              //�폜�����vb�̕����̐�(�v�f�ԍ��̍ő�l�j��1����̂ŗ����͈̔͂̍ő�l�����̓s�x1���炷

     cin.get();
     system("cls"); //��ʃN���A

     for (auto x : vB) {
         cout << x << endl;//vB�̒�������΁A1����75�̐������d���Ȃ�����ł���
         //������1���\������
         cout << "Enter�L�[��������" << endl; 
         cin.get();
         system("cls");
     }

     return 0;
}

uniform_int_distribution <unsigned> fortune_num_w(0, 4); //�d���^�̌v�Z�Ɏg��
uniform_int_distribution <unsigned> fortune_num_l(0, 1); //�����^�A���^�̌v�Z�Ɏg��

// �肢�֐�
int Fortune_telling(int f) {

    int m = 0;
    string fname = " ";
    int fage = 0;
    int fbirth_month = 0;
    string fblood_type = " ";
    int favorite_num = 0;
    int num_fblood_type = 0;
    int new_fage = 0;

    cout << "�u���O�v �u�N��v �u�a�����v �u���t�^�v �u1����6�̂����D���Ȑ����v�̂悤�ɓ��͂���Enter�L�[�������Ă��������B\n" ;
    cout << "��) Taro 25 12 AB 6\n";
    cin.get(); //�L�[�{�[�h���͑҂�
    cin >> fname >> fage >> fbirth_month >> fblood_type >> favorite_num;
    cin.get();
   
    //�N��͔͈͂��L���̂ŁA1����8�̐����ɕϊ�
    if (fage < 10) {
        new_fage = 1;
    }
    else if (10 <= fage && fage < 20) {
        new_fage = 2;
    }
    else if (20 <= fage && fage < 30) {
        new_fage = 3;
    }
    else if (30 <= fage && fage < 40) {
        new_fage = 4;
    }
    else if (40 <= fage && fage < 50) {
        new_fage = 5;
    }
    else if (50 <= fage && fage < 60) {
        new_fage = 6;
    }
    else if (60 <= fage && fage < 80) {
        new_fage = 7;
    }
    else if (80 <= fage ) {
        new_fage = 8;
    }

    //���t�^��string�^�ł���̂ŁA�����ɂ��Čv�Z�Ɏg��
    if (fblood_type == "A"||fblood_type == "a") {
        num_fblood_type = 1;
    }
    else if (fblood_type == "B" || fblood_type == "b") {
        num_fblood_type = 2;
    }
    else if (fblood_type == "O" || fblood_type == "o") {
        num_fblood_type = 3;
    }
    else if (fblood_type == "AB" || fblood_type == "ab") {
        num_fblood_type = 4;
    }

    cout << "\n";
    cout << "�����i���p�j�����𒼊��œ��͂��Ă��������B���̂���Enter�L�[�������Ă��������B���Ȃ��̖����̉^�����\������܂��B\n";
    cout << "��)sushi\n";
    cout << "\n";
   
    cin.get();
    system("cls"); //��ʃN���A

    //�d���^�i���o�[(4�`34)
    int work = (new_fage + fbirth_month + num_fblood_type + favorite_num) + fortune_num_w(engine);
    //�����^�i���o�[(0�`30)
    int love = new_fage * fortune_num_l(engine) + fbirth_month * fortune_num_l(engine) + num_fblood_type * fortune_num_l(engine) + favorite_num * fortune_num_l(engine);
    //���^�i���o�[(4�`34)
    int money = (new_fage + fbirth_month + num_fblood_type + favorite_num) + fortune_num_l(engine) + fortune_num_l(engine) + fortune_num_l(engine) + fortune_num_l(engine);

    int a = 0;
    int b = 0;
    int c = 0;
    
    //�i���o�[�ɉ����āA�\�����遚�̐��̐ݒ�
    string star_work = "";

    if (work == 4 || work == 9 || work == 14 || work == 19 || work == 24 || work == 29 || work == 34) {
        star_work = "��";
        a = 1; //���̐�����ŕ��ς��đ����^�Ƃ���̂Ő������ݒ肵�Ă���
    }
    else if (work == 5 || work == 10 || work == 15 || work == 20 || work == 25 || work == 30) {
        star_work = "����";
        a = 2;
    }
    else if (work == 6 || work == 11 || work == 16 || work == 21 || work == 26 || work == 31) {
        star_work = "������";
        a = 3;
    }
    else if (work == 7 || work == 12 || work == 17 || work == 22 || work == 27 || work == 32) {
        star_work = "��������";
        a = 4;
    }
    else if (work == 8 || work == 13 || work == 18 || work == 23 || work == 28 || work == 33) {
        star_work = "����������";
        a = 5;
    }

    string star_love = "";
    
    if (love == 1|| love == 6 || love == 11 || love == 16 || love == 21 || love == 26) {
        star_love = "��";
        b = 1;
    }
    else if (love == 2 || love == 7 || love == 12 || love == 17 || love == 22 || love == 27) {
        star_love = "����";
        b = 2;

    }
    else if (love == 3 || love == 8 || love == 13 || love == 18 || love == 23 || love == 28) {
        star_love = "������";
        b = 3;
    }
    else if (love == 4 || love == 9 || love == 14 || love == 19 || love == 24 || love == 29) {
        star_love = "��������";
        b = 4;
    }
    else if (love == 5 || love == 10 || love == 15 || love == 20 || love == 25 || love == 30 || love == 0) {
        star_love = "����������";
        b = 5;
    }

    string star_money = "";

    if (money == 4 || money == 9 || money == 14 || money == 19 || money == 24 || money == 29 || money == 34) {
        star_money = "��";
        c = 1;
    }
    else if (money == 5 || money == 10 || money == 15 || money == 20 || money == 25 || money == 30) {
        star_money = "����";
        c = 2;
    }
    else if (money == 6 || money == 11 || money == 16 || money == 21 || money == 26 || money == 31) {
        star_money = "������";
        c = 3;
    }
    else if (money == 7 || money == 12 || money == 17 || money == 22 || money == 27 || money == 32) {
        star_money = "��������";
        c = 4;
    }
    else if (money == 8 || money == 13 || money == 18 || money == 23 || money == 28 || money == 33 ) {
        star_money = "����������";
        c = 5;
    }

    cout << "���Ȃ��̖�����\n" << endl;
    cout << "�d���^��\n" << star_work << endl;
    cout << "�����^��\n" << star_love << endl;
    cout << "���^��\n" << star_money << endl;

    //���ϒl���瑍���^���Z�o
    string star = ""; 
    if (1 <= double((a + b + c) / 3) && double((a + b + c) / 3) < 1.5) {
        star = "��";
    }
    else if (1.5 <= double((a + b + c) / 3) && double((a + b + c) / 3) < 2.5) {
        star = "����";
    }
    else if (2.5 <= double((a + b + c) / 3) && double((a + b + c) / 3) < 3.5) {
        star = "������";
    }
    else if (3.5 <= double((a + b + c) / 3) && double((a + b + c) / 3) < 4.5) {
        star = "��������";
    }
    else if (4.5 <= double((a + b + c) / 3) && double((a + b + c) / 3) <= 5) {
        star = "����������";
    }

    cout << "�����^��\n" << star << endl;

    return 0;
}

// �l�̃N���X�i���O�A�N��j
struct Person {
    string name;
    int age;
    Person() : age(0) {} //������
};

//��y�A��i�ɚ����Ă��炤�֐�
int Seniorty(int s) {
    int m;
    int Sum = 0;
    cout << "Enter�L�[�������ĉ��s���Ȃ���A�����������z�i�S�̂Łj����͂��Ă����A�S�����͂��ĉ��s���I�������C�Ō��Ctrl+Z�L�[�������āA�Ă�Enter�L�[�������Ă��������B\n";

    while (cin >> m) {
        Sum += m; //�L�[�{�[�h���͂��瓾�������𑫂����킹�Ă���
    }
    cin.clear();   
    system("cls");

    cout << "���a�́A�@" << Sum << "�~" << endl; //�p�[�e�B�[�≃��ȂǁA�S�̂ł����������v���z�̕\��
    cout << "Enter�L�[�������Ă��������B\n" << endl;
    cin.get(); //�L�[�{�[�h���͑҂�
    system("cls"); //��ʃN���A
   
    cout << "�l������͂��Ă��������B: "; //���̏����Ŗ��O�ƔN����N���X�Ɏ�荞�ނƂ��́Afor�����ǂꂾ���J��Ԃ��������܂�
    cin >> m;

    vector<Person> Se_people(m); // �N���XPerson��vector�ɓ����
    int age_sum = 0;
    for (int i = 0; i < m; i++) {
        cout << "���O�ƔN�����͂��Ă��������B(" << i + 1 << "�l��): ";
        cin >> Se_people[i].name >> Se_people[i].age; //���O�ƔN�����荞��

        age_sum += Se_people[i].age; //�N��̍��v�B��Ōv�Z�Ɏg��

    }

    cin.get();
    system("cls");
    cout << "Enter�L�[�������Ă��������B1�l������̑�����v�Z���܂��B";

    sort(Se_people.begin(), Se_people.end(), [](Person a, Person b) {return a.age > b.age;}); //�l��N��������ɕ��ёւ���

    cin.get();
    system("cls");

    int age = Se_people[0].age;
    //1�l������̑���́A���z��(���̐l�̔N��)/(�S���̔N��̍��v)�����������̂Ɛݒ�
    cout << age << "�΂̐l������" << double(Sum) * (double(age) / double(age_sum)) << "�~" << endl;

    cout << Se_people[0].name << endl; //�ŏ���for���[�v�̊O��vector��0�Ԃ̐l��\��
    for (int i = 1; i < m; i++) {

        if (Se_people[i].age == age) {
            cout << Se_people[i].name << endl; //�O�̐l�ƔN��Ⴏ��΁A���̐l�̔N��ɉ����������\��
        }
        else {
            age = Se_people[i].age;
            cout << age << "�΂̐l������" << double(Sum) * (double(age) / double(age_sum)) << "�~" << endl;
            cout << Se_people[i].name << endl; // �O�̐l�ƔN����������������������Ȃ̂ŁA���̂܂܈ꏏ�ɕ\�������悤�Ȃ��Ă���
        }
    }

    return 0;
}

// main�֐�
int main() {
    cout << "�����C����ς������Ƃ��̃p�[�e�B�[�A����p�c�[������\n" << endl;
    cout << "\n" << endl;
    cout << "\n" << endl;
    cout << "�ȉ��̃��j���[����ԍ�(1�`3)�őI��ł��������B����Enter�L�[�������Ă��������B\n" << endl;
    cout << "<���j���[>\n" << endl;
    cout << "\n" << endl;
    cout << "1.BINGO��������\n" << endl;
    cout << " 1�`75�̐����������������܂��BBINGO�Q�[���̂Ƃ��Ȃǂɗ��p���Ă��������B\n" << endl;
    cout << "\n" << endl;
    cout << "2.�肢\n" << endl;
    cout << " �u���O�v�A�u�N��v�A�u�a�����v�A�u���t�^�v�A�u�D���Ȑ����v�A�u�����̂��Ȃ��̒����v��\n" << endl;
    cout << " �����̎d���^�A�����^�A���^�A�����^�����܂�܂�(���̐���1�`5�B�傫���قǗǂ��j�B\n" << endl;
    cout << " ���ʂ�����������A���x����蒼���Ă����v�ł��B\n" << endl;
    cout << "\n" << endl;
    cout << "3.��y�A��i�ɚ����Ă��炤\n" << endl;
    cout << " 1�l������̑����N��̍������ɍ����ݒ肷��c�[���ł��B�󋵂ɉ����ė��p���ĉ������B\n" << endl;

    int n = 0; 
    cin >>  n;
    system("cls"); //��ʃN���A

    //BINGO
    if (n == 1) {
        int b = 0;
        Bingo(b);
    }
    //�肢
    else if (n == 2) {

        int f = 0;
        Fortune_telling(f);
    }
    //������
    else if (n == 3) {
        int s = 0;
        Seniorty(s);
    }
}