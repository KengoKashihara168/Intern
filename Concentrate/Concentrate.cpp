#include"Concentrate.h"
#include"../Trump.h"

#include<string.h>

// �����𐔎��ɕϊ�
int ConvertInt(char c);
// ���͂��ꂽ�}�X���擾
Index InputIndex(BOOL flag[SUIT_MAX][NUMBER_MAX]);
// TRUE�̃t���O�𐔂���
int CountTrueFlag(BOOL flag[SUIT_MAX][NUMBER_MAX]);

void ConcentrateMain()
{
	Trump trump[SUIT_MAX][NUMBER_MAX];
	BOOL getFlag[SUIT_MAX][NUMBER_MAX];
	Index first, second;
	int flagCount = 0;
	int i, j;

	// �g�����v�̎擾
	for (i = 0; i < SUIT_MAX; i++)
	{
		for (j = 0; j < NUMBER_MAX; j++)
		{
			trump[i][j] = GetTrump();
		}
	}

	// �t���O�̏�����
	for (i = 0; i < SUIT_MAX; i++)
	{
		for (j = 0; j < NUMBER_MAX; j++)
		{
			getFlag[i][j] = FALSE;
		}
	}

	while (flagCount < CARD_MAX)
	{
		// ����1
		printf("�P��ڂ̓��́F");
		first = InputIndex(getFlag);
		WriteCard(trump[first.row][first.column]);
		// ���͂Q
		printf("�Q��ڂ̓��́F");
		second = InputIndex(getFlag);
		WriteCard(trump[second.row][second.column]);

		// ��v����
		if (trump[first.row][first.column].number == trump[second.row][second.column].number)
		{
			getFlag[first.row][first.column]   = TRUE;
			getFlag[second.row][second.column] = TRUE;
			printf("��v���܂���\n");
		}
		else
		{
			printf("��v���܂���ł���\n");
		}

		// �l�����̌v�Z
		flagCount = CountTrueFlag(getFlag);
	}
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
		if (p != NULL)
		{
			convert = p - number;
		}
	}

	return convert;
}

// ���͂��ꂽ�}�X���擾
Index InputIndex(BOOL flag[SUIT_MAX][NUMBER_MAX])
{
	Index index;
	char input[3];
	BOOL retry = FALSE;
	
	while (retry != TRUE)
	{
		// ���͂�ϊ�
		scanf("%s", input);
		index.column = ConvertInt(input[0]);
		index.row = ConvertInt(input[1]);

		if (flag[index.row][index.column] == FALSE)
		{
			retry = TRUE;
		}
		else
		{
			printf("���łɊl���ς݂ł�\n������x���͂��Ă�������\n");
		}
	}
	return index;
}

// TRUE�̃t���O�𐔂���
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