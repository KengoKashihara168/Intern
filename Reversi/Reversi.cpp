#include "Reversi.h"
#include <string.h>
#include <stdlib.h>

// 盤面の表示
void WriteBoard();
// 駒の表示
void WriteChip(BoardType chip);
// プレイヤーの入力
Index InputIndex(char* input);
// アルファベットから整数へ変換
int ConvertCtoI(char *list,char c);
// 入力値を確認
BOOL IsBoardRange(Index index);
// 駒を配置
void PutChip(Index index,Index dir,BoardType color);
// 一直線上にある自分の色までの距離を取得
int GetDistance(Index from, Index dir,BoardType myType, int distance);

BoardType board[BOARD_SIZE][BOARD_SIZE];

void ReversiMain()
{
	char input[10];
	Index index;
	Index dir;
	BOOL isPut = FALSE;
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
	WriteBoard();

	index.row	 = BOARD_SIZE;
	index.column = BOARD_SIZE;

	// プレイヤーの入力
	while (IsBoardRange(index) != TRUE)
	{
		printf("A～H,1～8を入力してください\n");
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

// 盤面の表示
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

// 駒の表示
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

// 入力値を確認
BOOL IsBoardRange(Index index)
{
	if (index.row	 >= BOARD_SIZE) return FALSE;
	if (index.column >= BOARD_SIZE) return FALSE;
	if (index.row	 <  0)		    return FALSE;
	if (index.column <  0)			return FALSE;
	return TRUE;
}

// 駒を配置
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
	BoardType current;	// 現在のマス
	BoardType next;		// 隣のマス
	Index nextIndex;

	// 次のインデックス
	nextIndex.row = from.row + dir.row;
	nextIndex.column = from.column + dir.column;

	// 盤面の外になったら
	if (nextIndex.row >= BOARD_SIZE || nextIndex.column >= BOARD_SIZE)return 0;
	current = board[from.row][from.column];
	next = board[nextIndex.row][nextIndex.column];
	// 現在のマスと隣のマスが同じだったら
	if (myType == next) return distance;
	// 隣のマスに何もなければ
	if (next == None) return 0;
	
	return GetDistance(nextIndex, dir,myType, distance + 1);
}