#pragma once

////////////////// �|�[�J�[ //////////////////

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

/*----------�֐�----------*/

void PokerMain();