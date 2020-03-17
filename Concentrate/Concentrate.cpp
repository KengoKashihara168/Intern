#include"Concentrate.h"
#include"../Trump.h"

#include<string.h>

// 文字を数字に変換
int ConvertInt(char c);
// 入力されたマスを取得
Index InputIndex();

void ConcentrateMain()
{
	Trump trump[SUIT_MAX][NUMBER_MAX];
	BOOL getFlag[SUIT_MAX][NUMBER_MAX] = { FALSE };
	Index first, second;
	int i, j;

	// トランプの取得
	for (i = 0; i < SUIT_MAX; i++)
	{
		for (j = 0; j < NUMBER_MAX; j++)
		{
			trump[i][j] = GetTrump();
		}
	}

	// 入力1
	first = InputIndex();
	WriteCard(trump[first.row][first.column]);

	// 入力２
	second = InputIndex();
	WriteCard(trump[second.row][second.column]);
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
		convert = p - number;
	}

	return convert;
}

// 入力されたマスを取得
Index InputIndex()
{
	Index index;
	char input[3];

	// 入力を変換
	scanf("%s", input);
	index.column = ConvertInt(input[0]);
	index.row = ConvertInt(input[1]);
	
	return index;
}