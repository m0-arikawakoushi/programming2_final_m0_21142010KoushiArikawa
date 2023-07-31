#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

//乱数エンジン
random_device engine;

//ビンゴ関数（ビンゴで用いる1から75の整数を重複なくランダムに表示）
int Bingo(int b) {

    cin.get();  //キーボード入力待ち
    cout << "BINGOゲームスタート!!!\n";
    cout << "Enterキーを押してみて。数字が出てくるよ\n" << endl;

    //vectorを2つ用意
    vector<int>vb(75);
    vector<int>vB;
    //vbに1から75の整数を前から順番に並べる
     for (int i = 0; i < 75; ++i) {
         vb[i] = i + 1;
    }
    //vBに1から75の整数を重複なくランダムに、vbから移す
     int r = 0;
     for (int i = 0; i < 75; ++i) {  //75回処理を繰り返す

         //vbのどの部屋から数字を選ぶかをランダムにする(乱数で選択する部屋番号を決める)
         uniform_int_distribution <unsigned> vb_room_num(0, 74-i); //乱数生成、処理が1回終わるごとに範囲を数字1つ分減らす
         r = vb_room_num(engine); //一度生成した乱数を1回の処理の中で、使い続けるのでrで固定するイメージ

         vB.push_back(vb[r]); //vbからランダムに選んだ数をvBに前から順番に詰める
         vb.erase(vb.begin()  + r ); //選ばれた数字(要素)は削除しておくことで次からの処理でそれを選ぶことはなく、重複はない
      }                              //削除するとvbの部屋の数(要素番号の最大値）が1つ減るので乱数の範囲の最大値もその都度1つ減らす

     cin.get();
     system("cls"); //画面クリア

     for (auto x : vB) {
         cout << x << endl;//vBの中を見れば、1から75の整数が重複なく並んでいる
         //数字を1つずつ表示する
         cout << "Enterキーを押して" << endl; 
         cin.get();
         system("cls");
     }

     return 0;
}

uniform_int_distribution <unsigned> fortune_num_w(0, 4); //仕事運の計算に使う
uniform_int_distribution <unsigned> fortune_num_l(0, 1); //恋愛運、金運の計算に使う

// 占い関数
int Fortune_telling(int f) {

    int m = 0;
    string fname = " ";
    int fage = 0;
    int fbirth_month = 0;
    string fblood_type = " ";
    int favorite_num = 0;
    int num_fblood_type = 0;
    int new_fage = 0;

    cout << "「名前」 「年齢」 「誕生月」 「血液型」 「1から6のうち好きな整数」のように入力してEnterキーを押してください。\n" ;
    cout << "例) Taro 25 12 AB 6\n";
    cin.get(); //キーボード入力待ち
    cin >> fname >> fage >> fbirth_month >> fblood_type >> favorite_num;
    cin.get();
   
    //年齢は範囲が広いので、1から8の数字に変換
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

    //血液型はstring型であるので、数字にして計算に使う
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
    cout << "何か（半角）文字を直感で入力してください。そのあとEnterキーを押してください。あなたの明日の運勢が表示されます。\n";
    cout << "例)sushi\n";
    cout << "\n";
   
    cin.get();
    system("cls"); //画面クリア

    //仕事運ナンバー(4～34)
    int work = (new_fage + fbirth_month + num_fblood_type + favorite_num) + fortune_num_w(engine);
    //恋愛運ナンバー(0～30)
    int love = new_fage * fortune_num_l(engine) + fbirth_month * fortune_num_l(engine) + num_fblood_type * fortune_num_l(engine) + favorite_num * fortune_num_l(engine);
    //金運ナンバー(4～34)
    int money = (new_fage + fbirth_month + num_fblood_type + favorite_num) + fortune_num_l(engine) + fortune_num_l(engine) + fortune_num_l(engine) + fortune_num_l(engine);

    int a = 0;
    int b = 0;
    int c = 0;
    
    //ナンバーに応じて、表示する★の数の設定
    string star_work = "";

    if (work == 4 || work == 9 || work == 14 || work == 19 || work == 24 || work == 29 || work == 34) {
        star_work = "★";
        a = 1; //星の数を後で平均して総合運とするので数字も設定しておく
    }
    else if (work == 5 || work == 10 || work == 15 || work == 20 || work == 25 || work == 30) {
        star_work = "★★";
        a = 2;
    }
    else if (work == 6 || work == 11 || work == 16 || work == 21 || work == 26 || work == 31) {
        star_work = "★★★";
        a = 3;
    }
    else if (work == 7 || work == 12 || work == 17 || work == 22 || work == 27 || work == 32) {
        star_work = "★★★★";
        a = 4;
    }
    else if (work == 8 || work == 13 || work == 18 || work == 23 || work == 28 || work == 33) {
        star_work = "★★★★★";
        a = 5;
    }

    string star_love = "";
    
    if (love == 1|| love == 6 || love == 11 || love == 16 || love == 21 || love == 26) {
        star_love = "★";
        b = 1;
    }
    else if (love == 2 || love == 7 || love == 12 || love == 17 || love == 22 || love == 27) {
        star_love = "★★";
        b = 2;

    }
    else if (love == 3 || love == 8 || love == 13 || love == 18 || love == 23 || love == 28) {
        star_love = "★★★";
        b = 3;
    }
    else if (love == 4 || love == 9 || love == 14 || love == 19 || love == 24 || love == 29) {
        star_love = "★★★★";
        b = 4;
    }
    else if (love == 5 || love == 10 || love == 15 || love == 20 || love == 25 || love == 30 || love == 0) {
        star_love = "★★★★★";
        b = 5;
    }

    string star_money = "";

    if (money == 4 || money == 9 || money == 14 || money == 19 || money == 24 || money == 29 || money == 34) {
        star_money = "★";
        c = 1;
    }
    else if (money == 5 || money == 10 || money == 15 || money == 20 || money == 25 || money == 30) {
        star_money = "★★";
        c = 2;
    }
    else if (money == 6 || money == 11 || money == 16 || money == 21 || money == 26 || money == 31) {
        star_money = "★★★";
        c = 3;
    }
    else if (money == 7 || money == 12 || money == 17 || money == 22 || money == 27 || money == 32) {
        star_money = "★★★★";
        c = 4;
    }
    else if (money == 8 || money == 13 || money == 18 || money == 23 || money == 28 || money == 33 ) {
        star_money = "★★★★★";
        c = 5;
    }

    cout << "あなたの明日の\n" << endl;
    cout << "仕事運は\n" << star_work << endl;
    cout << "恋愛運は\n" << star_love << endl;
    cout << "金運は\n" << star_money << endl;

    //平均値から総合運を算出
    string star = ""; 
    if (1 <= double((a + b + c) / 3) && double((a + b + c) / 3) < 1.5) {
        star = "★";
    }
    else if (1.5 <= double((a + b + c) / 3) && double((a + b + c) / 3) < 2.5) {
        star = "★★";
    }
    else if (2.5 <= double((a + b + c) / 3) && double((a + b + c) / 3) < 3.5) {
        star = "★★★";
    }
    else if (3.5 <= double((a + b + c) / 3) && double((a + b + c) / 3) < 4.5) {
        star = "★★★★";
    }
    else if (4.5 <= double((a + b + c) / 3) && double((a + b + c) / 3) <= 5) {
        star = "★★★★★";
    }

    cout << "総合運は\n" << star << endl;

    return 0;
}

// 人のクラス（名前、年齢）
struct Person {
    string name;
    int age;
    Person() : age(0) {} //初期化
};

//先輩、上司に奢ってもらう関数
int Seniorty(int s) {
    int m;
    int Sum = 0;
    cout << "Enterキーを押して改行しながら、かかった金額（全体で）を入力していき、全部入力して改行し終わったら，最後にCtrl+Zキーを押して、再びEnterキーを押してください。\n";

    while (cin >> m) {
        Sum += m; //キーボード入力から得た数字を足し合わせていく
    }
    cin.clear();   
    system("cls");

    cout << "総和は、　" << Sum << "円" << endl; //パーティーや宴会など、全体でかかった合計金額の表示
    cout << "Enterキーを押してください。\n" << endl;
    cin.get(); //キーボード入力待ち
    system("cls"); //画面クリア
   
    cout << "人数を入力してください。: "; //次の処理で名前と年齢をクラスに取り込むときの、for文をどれだけ繰り返すかが決まる
    cin >> m;

    vector<Person> Se_people(m); // クラスPersonをvectorに入れる
    int age_sum = 0;
    for (int i = 0; i < m; i++) {
        cout << "名前と年齢を入力してください。(" << i + 1 << "人目): ";
        cin >> Se_people[i].name >> Se_people[i].age; //名前と年齢を取り込む

        age_sum += Se_people[i].age; //年齢の合計。後で計算に使う

    }

    cin.get();
    system("cls");
    cout << "Enterキーを押してください。1人当たりの代金を計算します。";

    sort(Se_people.begin(), Se_people.end(), [](Person a, Person b) {return a.age > b.age;}); //人を年齢が高い順に並び替える

    cin.get();
    system("cls");

    int age = Se_people[0].age;
    //1人当たりの代金は、総額に(その人の年齢)/(全員の年齢の合計)をかけたものと設定
    cout << age << "歳の人たちは" << double(Sum) * (double(age) / double(age_sum)) << "円" << endl;

    cout << Se_people[0].name << endl; //最初はforループの外でvectorの0番の人を表示
    for (int i = 1; i < m; i++) {

        if (Se_people[i].age == age) {
            cout << Se_people[i].name << endl; //前の人と年齢が違ければ、その人の年齢に応じた代金を表示
        }
        else {
            age = Se_people[i].age;
            cout << age << "歳の人たちは" << double(Sum) * (double(age) / double(age_sum)) << "円" << endl;
            cout << Se_people[i].name << endl; // 前の人と年齢が同じだったら代金も同じなので、そのまま一緒に表示されるようなっている
        }
    }

    return 0;
}

// main関数
int main() {
    cout << "★★気分を変えたいときのパーティー、宴会用ツール★★\n" << endl;
    cout << "\n" << endl;
    cout << "\n" << endl;
    cout << "以下のメニューから番号(1～3)で選んでください。次にEnterキーを押してください。\n" << endl;
    cout << "<メニュー>\n" << endl;
    cout << "\n" << endl;
    cout << "1.BINGO数字生成\n" << endl;
    cout << " 1～75の数字を自動生成します。BINGOゲームのときなどに利用してください。\n" << endl;
    cout << "\n" << endl;
    cout << "2.占い\n" << endl;
    cout << " 「名前」、「年齢」、「誕生月」、「血液型」、「好きな数字」、「今日のあなたの直感」で\n" << endl;
    cout << " 明日の仕事運、恋愛運、金運、総合運が決まります(★の数が1～5。大きいほど良い）。\n" << endl;
    cout << " 結果が悪かったら、何度もやり直しても大丈夫です。\n" << endl;
    cout << "\n" << endl;
    cout << "3.先輩、上司に奢ってもらう\n" << endl;
    cout << " 1人当たりの代金を年齢の高い順に高く設定するツールです。状況に応じて利用して下さい。\n" << endl;

    int n = 0; 
    cin >>  n;
    system("cls"); //画面クリア

    //BINGO
    if (n == 1) {
        int b = 0;
        Bingo(b);
    }
    //占い
    else if (n == 2) {

        int f = 0;
        Fortune_telling(f);
    }
    //おごり
    else if (n == 3) {
        int s = 0;
        Seniorty(s);
    }
}