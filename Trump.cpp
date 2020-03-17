#include "Trump.h"
#include "Rand.h"

BOOL outFlag[CARD_MAX] = { TRUE }; // トランプの配布フラグ

// ランダムで52枚のカード番号を取得
int GetCardNum();
// カード番号をもとにスートを取得
const char* GetSuit(int num);
// カード番号をもとに数字を取得
int GetNumber(int num);

Trump GetTrump()
{
	Trump trump; // トランプ
	int cardNum; // カード番号

	// カードのランダム取得
	cardNum = GetCardNum();

	// 番号をもとにカード情報を取得
	trump.suit = GetSuit(cardNum);
	trump.number = GetNumber(cardNum);

	// 配布済みにする
	outFlag[cardNum] = FALSE;

	return trump;
}

// ランダムで52枚のカード番号を取得
int GetCardNum()
{
	int rand, count;

	rand = GetRand(CARD_MAX);
	count = 0;

	// まだ配布されていないカード番号を探す
	while (outFlag[rand] != TRUE || count < CARD_MAX)
	{
		rand = GetRand(CARD_MAX - 1);
		count++;
	}

	return rand;
}

// カード番号をもとにスートを取得
const char* GetSuit(int num)
{
	//  0～12:スペード 13～25:クラブ
	// 26～38:ダイヤ   39～51:ハート
	int suitNum = num / NUMBER_MAX;
	const char* suit = "";

	switch (suitNum)
	{
	case 0:
		suit = SPADE;
		break;
	case 1:
		suit = CLUB;
		break;
	case 2:
		suit = DIAMOND;
		break;
	case 3:
		suit = HEART;
		break;
	}

	return suit;
}

// カード番号をもとに数字を取得
int GetNumber(int num)
{
	int number = num % NUMBER_MAX + 1;
	return number;
}