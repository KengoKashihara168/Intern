#include"Concentrate.h"
#include"../Trump.h"

#include<string.h>

// 文字を数字に変換
int ConvertInt(char c);
// 入力されたマスを取得
Index InputIndex(BOOL flag[SUIT_MAX][NUMBER_MAX]);
// TRUEのフラグを数える
int CountTrueFlag(BOOL flag[SUIT_MAX][NUMBER_MAX]);

void ConcentrateMain()
{
	Trump trump[SUIT_MAX][NUMBER_MAX];
	BOOL getFlag[SUIT_MAX][NUMBER_MAX];
	Index first, second;
	int flagCount = 0;
	int i, j;

	// トランプの取得
	for (i = 0; i < SUIT_MAX; i++)
	{
		for (j = 0; j < NUMBER_MAX; j++)
		{
			trump[i][j] = GetTrump();
		}
	}

	// フラグの初期化
	for (i = 0; i < SUIT_MAX; i++)
	{
		for (j = 0; j < NUMBER_MAX; j++)
		{
			getFlag[i][j] = FALSE;
		}
	}

	while (flagCount < CARD_MAX)
	{
		// 入力1
		printf("１回目の入力：");
		first = InputIndex(getFlag);
		WriteCard(trump[first.row][first.column]);
		// 入力２
		printf("２回目の入力：");
		second = InputIndex(getFlag);
		WriteCard(trump[second.row][second.column]);

		// 一致判定
		if (trump[first.row][first.column].number == trump[second.row][second.column].number)
		{
			getFlag[first.row][first.column]   = TRUE;
			getFlag[second.row][second.column] = TRUE;
			printf("一致しました\n");
		}
		else
		{
			printf("一致しませんでした\n");
		}

		// 獲得数の計算
		flagCount = CountTrueFlag(getFlag);
	}
}

// 文字を数字に変換
int ConvertInt(char c)
{
	int convert = NUMBER_MAX;
	char alphabet[] = 
	{
		'A','B','C','D','E','F','G','H','I','J','K','L','M'
	};
	char number[] =
	{
		'1','2','3','4'
	};

	char* p = strchr(alphabet, c);
	if (p != NULL)
	{
		convert = p - alphabet;
	}
	else
	{
		p = strchr(number, c);
		if (p != NULL)
		{
			convert = p - number;
		}
	}

	return convert;
}

// 入力されたマスを取得
Index InputIndex(BOOL flag[SUIT_MAX][NUMBER_MAX])
{
	Index index;
	char input[3];
	BOOL retry = FALSE;
	
	while (retry != TRUE)
	{
		// 入力を変換
		scanf("%s", input);
		index.column = ConvertInt(input[0]);
		index.row = ConvertInt(input[1]);

		if (flag[index.row][index.column] == FALSE)
		{
			retry = TRUE;
		}
		else
		{
			printf("すでに獲得済みです\nもう一度入力してください\n");
		}
	}
	return index;
}

// TRUEのフラグを数える
int CountTrueFlag(BOOL flag[SUIT_MAX][NUMBER_MAX])
{
	int count = 0;
	int i, j;

	for (i = 0; i < SUIT_MAX; i++)
	{
		for (j = 0; j < NUMBER_MAX; j++)
		{
			if (flag[i][j] == TRUE)
			{
				count++;
			}
		}
	}

	return count;
}