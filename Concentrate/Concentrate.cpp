#include"Concentrate.h"
#include"../Trump.h"

#include<string.h>

// �����𐔎��ɕϊ�
int ConvertInt(char c);

void ConcentrateMain()
{
	Trump trump[SUIT_MAX][NUMBER_MAX];
	char input[256];
	int row, column;
	int i, j;

	// �g�����v�̎擾
	for (i = 0; i < SUIT_MAX; i++)
	{
		for (j = 0; j < NUMBER_MAX; j++)
		{
			trump[i][j] = GetTrump();
			//printf("%s��%d\n", trump[i][j].suit, trump[i][j].number);
		}
	}

	// ����1
	scanf("%s", input);
	row = ConvertInt(input[0]);
	column = ConvertInt(input[1]);
	WriteCard(trump[row][column]);

	// ���͂Q
	scanf("%s", input);
	row = ConvertInt(input[0]);
	column = ConvertInt(input[1]);
	WriteCard(trump[row][column]);
}

// �����𐔎��ɕϊ�
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