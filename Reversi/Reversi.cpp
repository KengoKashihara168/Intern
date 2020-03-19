#include "Reversi.h"

// 盤面の表示
void WriteBoard(BoardType board[BOARD_SIZE][BOARD_SIZE]);
// 駒の表示
void WriteChip(BoardType chip);

void ReversiMain()
{
	BoardType board[BOARD_SIZE][BOARD_SIZE];

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

	WriteBoard(board);
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