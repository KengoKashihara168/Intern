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
#define NONE  ("Å@")
#define BLACK ("ÅZ")
#define WHITE ("Åú")
#define DIR_RANGE (2)


/*----------ä÷êî----------*/

void ReversiMain();