#pragma once

////////////////// ポーカー //////////////////

enum Role
{
	HighCard,
	OnePair,
	TwoPair,
	ThreeCard,
	Straight,
	Flush,
	FullHouse,
	FourCard,
	StraightFlush,
	RoyalStraightFlush,
	RoleMax
};
typedef enum Role Role;

#define HAND_MAX 5

/*----------関数----------*/

void PokerMain();