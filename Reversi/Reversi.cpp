#include "Reversi.h"
#include <string.h>
#include <stdlib.h>

// �Ֆʂ̕\��
void WriteBoard();
// ��̕\��
void WriteChip(BoardType chip);
// �v���C���[�̓���
Index InputIndex(char* input);
// �A���t�@�x�b�g���琮���֕ϊ�
int ConvertCtoI(char *list,char c);
// ���͒l���m�F
BOOL IsBoardRange(Index index);
// ���z�u
void PutChip(Index index,Index dir,BoardType color);
// �꒼����ɂ��鎩���̐F�܂ł̋������擾
int GetDistance(Index from, Index dir,BoardType myType, int distance);

BoardType board[BOARD_SIZE][BOARD_SIZE];

void ReversiMain()
{
	char input[10];
	Index index;
	Index dir;
	BOOL isPut = FALSE;
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
	WriteBoard();

	index.row	 = BOARD_SIZE;
	index.column = BOARD_SIZE;

	// �v���C���[�̓���
	while (IsBoardRange(index) != TRUE)
	{
		printf("A�`H,1�`8����͂��Ă�������\n");
		scanf("%s", input);
		index = InputIndex(input);
	}

	for (i = -1; i < 3; i++)
	{
		for (j = -1; j < 3; j++)
		{
			dir.row = i;
			dir.column = j;
			PutChip(index, dir, Black);
		}
	}

	WriteBoard();
}

// �Ֆʂ̕\��
void WriteBoard()
{
	int i, j;

	system("cls");
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

// ��̕\��
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

// ���͒l���m�F
BOOL IsBoardRange(Index index)
{
	if (index.row	 >= BOARD_SIZE) return FALSE;
	if (index.column >= BOARD_SIZE) return FALSE;
	if (index.row	 <  0)		    return FALSE;
	if (index.column <  0)			return FALSE;
	return TRUE;
}

// ���z�u
void PutChip(Index index,Index dir, BoardType color)
{
	int distance;
	int i;

	distance = GetDistance(index, dir, color, 0);
	if (distance > 0)
	{
		board[index.row][index.column] = color;
		for (i = 0; i <= distance; i++)
		{
			board[index.row + dir.row][index.column + dir.column] = color;
		}
	}
}

int GetDistance(Index from, Index dir, BoardType myType, int distance)
{
	BoardType current;	// ���݂̃}�X
	BoardType next;		// �ׂ̃}�X
	Index nextIndex;

	// ���̃C���f�b�N�X
	nextIndex.row = from.row + dir.row;
	nextIndex.column = from.column + dir.column;

	// �Ֆʂ̊O�ɂȂ�����
	if (nextIndex.row >= BOARD_SIZE || nextIndex.column >= BOARD_SIZE)return 0;
	current = board[from.row][from.column];
	next = board[nextIndex.row][nextIndex.column];
	// ���݂̃}�X�Ɨׂ̃}�X��������������
	if (myType == next) return distance;
	// �ׂ̃}�X�ɉ����Ȃ����
	if (next == None) return 0;
	
	return GetDistance(nextIndex, dir,myType, distance + 1);
}