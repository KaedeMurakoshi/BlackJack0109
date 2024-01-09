#include <iostream> //入出力

#include "Shoe.h"
#include "Player.h"
#include "Dealer.h"

using namespace std;

//
// 試験用ブラックジャックソース
// 正常動作していない。
//

enum PERSON
{
	DEALER, PLAYER
};

// ★★★★★★★★★★★★★★★★
static void showResult(Person** p, const int num)
{
	cout << "============================" << endl;
	cout << "            result          " << endl;
	cout << "============================" << endl;
	cout << "============================" << endl;
	cout << p[DEALER]->getName() << endl;
	p[DEALER]->showHand();

	for (int i = PLAYER; i < num; ++i)
	{
		cout << "============================\n" << p[i]->getName() << endl;
		p[i]->showHand();
		cout << "============================" << endl;

		if (p[i]->getScore() > p[DEALER]->getScore()) {
			cout << p[i]->getName() << "Win!" << endl;
		}
		else if (p[i]->getScore() < p[DEALER]->getScore()) {
			cout << p[i]->getName() << "Lose" << endl;
		}
		else {
			cout << "Push" << endl;
		}
	}
	
}

static void showHand(Person* p)
{
	//手札の表示
	cout << "====================\n" << p->getName() <<endl;
	p->showHand();
	cout << "====================" << endl;

}

//メイン関数
int main() {

	srand((unsigned int)time(NULL));

	//各オブジェクトの生成
	Shoe shoe;

	//配列に入れて使いやすく
	Person* persons[] = { new Dealer("dealerKaede"), new Player("Yuki"), new Player("Bayashi"), new Player("Ryohei") };

	//人数
	const int num = sizeof(persons) / sizeof(Person*);

	//----カードの配布 ... 初期
	cout << "====================" << endl;
	//全員に一枚ずつ
	for (int i = 0; i < num; i++)
	{
		persons[i]->hit(shoe);
		showHand(persons[i]);
	}
	
	//ディーラーに2枚目を配布
	persons[DEALER]->hit(shoe);


	// ----　勝負開始
	//プレイヤーの実行
	//バーストしているかどうか判別

	for (int i = PLAYER; i < num; ++i)
	{
		printf("～%sのターン～\n", persons[i]->getName());
		//プレイヤーだけに2枚目を配布
		persons[i]->hit(shoe);
		persons[i]->showHand();

		if (persons[i]->play(&shoe)) {
			//バーストせずstandした
		}
		else {
			cout << "Burst" << persons[i]->getName() << "Lose" << endl;
		}
		cout << "====================" << endl;
	}

	//ディーラーの手札を表示
	showHand(persons[DEALER]);

	//ディーラーの自動実行
	persons[DEALER]->play(&shoe);

	//結果の表示
	showResult(persons, num);
	
	//解放
	delete[] persons;
	
	return 0;
}