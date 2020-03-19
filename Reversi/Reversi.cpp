#include "Reversi.h"
#include <string.h>

// 盤面の表示
void WriteBoard(BoardType board[BOARD_SIZE][BOARD_SIZE]);
// 駒の表示
void WriteChip(BoardType chip);
// プレイヤーの入力
Index InputIndex(char* input);
// アルファベットから整数へ変換
int ConvertCtoI(char *list,char c);

void ReversiMain()
{
	BoardType board[BOARD_SIZE][BOARD_SIZE];
	char input[10];
	Index index;

	int i, j;

	// ボードの初期化
	for (i = 0; i < BOARD_SIZE; i++)
	{
		for (j = 0; j < BOARD_SIZE; j++)
		{
			board[i][j] = None;
		}
	}
	// 黒の初期駒を配置
	board[3][3] = Black;
	board[4][4] = Black;
	// 白の初期駒を配置
	board[3][4] = White;
	board[4][3] = White;

	// 盤面の表示
	WriteBoard(board);

	// プレイヤーの入力
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

// プレイヤーの入力
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

	// 行と列へ変換
	index.column = ConvertCtoI(alphabet, input[0]);
	index.row = ConvertCtoI(number,input[1]);

	return index;
}

// 入力文字を整数に変換
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