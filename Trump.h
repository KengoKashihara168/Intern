#pragma once
#include"Utility.h"

#define CARD_MAX 52			// カードの枚数
#define SPADE   "スペード"
#define CLUB    "クラブ"
#define DIAMOND "ダイヤ"
#define HEART   "ハート"
#define NUMBER_MAX 13

struct Trump
{
	const char* suit; // スート
	int number;		  // 数字
};
typedef struct Trump Trump;

// ランダムでトランプを取得
Trump GetTrump();