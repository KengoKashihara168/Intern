#include"Poker.h"
#include "../Trump.h"

void PokerMain()
{
	Trump trump = GetTrump();

	printf("%s‚Ì%d\n", trump.suit, trump.number);
}