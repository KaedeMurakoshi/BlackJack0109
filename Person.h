#pragma once

#include "common.h"

class Shoe;

class Person
{
private:
	int _hand[HAND_SIZE];	// 理論上これくらい持てばOK...に今回はしちゃう
	bool _calcUpdate;
	int _handNum;
	int _score;
	char* _pName;

public:
	// コンストラクタ
	Person(const char* pName);

	//デストラクタ
	virtual ~Person();

	//スコアの取得(hitされた時のみ再計算される)
	int getScore();

	//カードの追加
	void hit(Shoe& shoe);

	//手札を表示
	void showHand();

	//名前を取得
	char* getName();

	//ターン処理
	bool play(Shoe* shoe);

protected:
	//実体を作れないように
	virtual void playBase(Shoe* shoe) = 0;	//ターン処理本体

};

