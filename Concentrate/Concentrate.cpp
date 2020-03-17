#include"Concentrate.h"
#include"../Trump.h"

#include<string.h>

// 文字を数字に変換
int ConvertInt(char c);

void ConcentrateMain()
{
	Trump trump[SUIT_MAX][NUMBER_MAX];
	char input[256];
	int row, column;
	int i, j;

	// トランプの取得
	for (i = 0; i < SUIT_MAX; i++)
	{
		for (j = 0; j < NUMBER_MAX; j++)
		{
			trump[i][j] = GetTrump();
			//printf("%sの%d\n", trump[i][j].suit, trump[i][j].number);
		}
	}

	// 入力1
	scanf("%s", input);
	row = ConvertInt(input[0]);
	column = ConvertInt(input[1]);
	printf("%sの%d\n", trump[row][column].suit, trump[row][column].number);

	// 入力２
	scanf("%s", input);
	row = ConvertInt(input[0]);
	column = ConvertInt(input[1]);
	printf("%sの%d\n", trump[row][column].suit, trump[row][column].number);
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