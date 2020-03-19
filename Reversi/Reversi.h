#pragma once
#include "../Utility.h"

enum BoardType
{
	None,
	Black,
	White
};

enum Dir
{
	Right,
	Left,
	Top,
	Bottom
};

#define BOARD_SIZE (8)
#define NONE  ("�@")
#define BLACK ("�Z")
#define WHITE ("��")


/*----------�֐�----------*/

void ReversiMain();