#pragma once
#include"Utility.h"

#define CARD_MAX 52			// カードの枚数
#define SPADE   "Spade"		// スペード
#define CLUB    "Club"		// クラブ
#define DIAMOND "Diamond"	// ダイヤ
#define HEART   "Heart"		// ハート

struct Trump
{
	const char* suit; // スート
	int number;		  // 数字
};
typedef struct Trump Trump;

// ランダムでトランプを取得
Trump GetTrump();