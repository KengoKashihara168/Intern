#include"Concentrate.h"
#include"../Trump.h"

#include<string.h>

// �����𐔎��ɕϊ�
int ConvertInt(char c);
// ���͂��ꂽ�}�X���擾
Index InputIndex();

void ConcentrateMain()
{
	Trump trump[SUIT_MAX][NUMBER_MAX];
	BOOL getFlag[SUIT_MAX][NUMBER_MAX] = { FALSE };
	Index first, second;
	int i, j;

	// �g�����v�̎擾
	for (i = 0; i < SUIT_MAX; i++)
	{
		for (j = 0; j < NUMBER_MAX; j++)
		{
			trump[i][j] = GetTrump();
		}
	}

	// ����1
	first = InputIndex();
	WriteCard(trump[first.row][first.column]);

	// ���͂Q
	second = InputIndex();
	WriteCard(trump[second.row][second.column]);
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

// ���͂��ꂽ�}�X���擾
Index InputIndex()
{
	Index index;
	char input[3];

	// ���͂�ϊ�
	scanf("%s", input);
	index.column = ConvertInt(input[0]);
	index.row = ConvertInt(input[1]);
	
	return index;
}