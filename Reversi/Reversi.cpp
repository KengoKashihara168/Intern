#include "Reversi.h"
#include <string.h>

// �Ֆʂ̕\��
void WriteBoard(BoardType board[BOARD_SIZE][BOARD_SIZE]);
// ��̕\��
void WriteChip(BoardType chip);
// �v���C���[�̓���
Index InputIndex(char* input);
// �A���t�@�x�b�g���琮���֕ϊ�
int ConvertCtoI(char *list,char c);

void ReversiMain()
{
	BoardType board[BOARD_SIZE][BOARD_SIZE];
	char input[10];
	Index index;

	int i, j;

	// �{�[�h�̏�����
	for (i = 0; i < BOARD_SIZE; i++)
	{
		for (j = 0; j < BOARD_SIZE; j++)
		{
			board[i][j] = None;
		}
	}
	// ���̏������z�u
	board[3][3] = Black;
	board[4][4] = Black;
	// ���̏������z�u
	board[3][4] = White;
	board[4][3] = White;

	// �Ֆʂ̕\��
	WriteBoard(board);

	// �v���C���[�̓���
	scanf("%s", input);
	index = InputIndex(input);
	printf("(%d,%d)\n", index.row, index.column);
}

void WriteBoard(BoardType board[BOARD_SIZE][BOARD_SIZE])
{
	int i, j;

	printf("    A  B  C  D  E  F  G  H\n");
	for (i = 0; i < BOARD_SIZE; i++)
	{
		printf(" %d |",i + 1);
		for (j = 0; j < BOARD_SIZE; j++)
		{
			WriteChip(board[i][j]);
			printf("|");
		}
		printf("\n");
	}
}

void WriteChip(BoardType chip)
{
	switch (chip)
	{
	case None:
		printf("%s", NONE);
		break;
	case Black:
		printf("%s", BLACK);
		break;
	case White:
		printf("%s", WHITE);
		break;
	default:
		break;
	}
}

// �v���C���[�̓���
Index InputIndex(char* input)
{
	Index index;
	char alphabet[] =
	{
		'A','B','C','D','E','F','G','H','\0'
	};
	char number[] =
	{
		'1','2','3','4','5','6','7','8','\0'
	};

	// �s�Ɨ�֕ϊ�
	index.column = ConvertCtoI(alphabet, input[0]);
	index.row = ConvertCtoI(number,input[1]);

	return index;
}

// ���͕����𐮐��ɕϊ�
int ConvertCtoI(char* list, char c)
{
	int convert = BOARD_SIZE;
	char* p = strchr(list, c);

	if (p != NULL)
	{
		convert = p - list;
	}

	return convert;
}