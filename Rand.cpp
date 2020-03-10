#include"Rand.h"
#include<stdlib.h>
#include<time.h>

// minからmaxまでの整数型乱数を取得
int GetRand(int min, int max)
{
	if (min < 0)min = 0;				// 最小値は０
	if (max > RAND_MAX)max = RAND_MAX;	// 最大値は32767

	static bool randFlag = true; // シード値を一回のみ設定するためのフラグ
	if (randFlag)
	{
		// 現在時刻でシード値を設定
		srand((unsigned int)time(NULL));
		randFlag = false;
	}

	return rand() % (max + 1 - min) + min;
}

// 0からmaxまでの整数型乱数を取得
int GetRand(int max)
{
	if (max > RAND_MAX)max = RAND_MAX;	// 最大値は32767

	static bool randFlag = true; // シード値を一回のみ設定するためのフラグ
	if (randFlag)
	{
		// 現在時刻でシード値を設定
		srand((unsigned int)time(NULL));
		randFlag = false;
	}

	return rand() % (max + 1);
}

