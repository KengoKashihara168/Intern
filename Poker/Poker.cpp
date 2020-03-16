#include"Poker.h"
#include "../Trump.h"

// 役の取得
Role GetRole(Trump trump[]);

// ペアのカウント
int CountPair(Trump trump[]);
// ペア役の取得
Role GetPairRole(int pair);

void Test2(Trump trump[]);

void PokerMain()
{
	Trump trump[HAND_MAX];
	int i;

	/* デバッグ用 */
	trump[0].number = 11;
	trump[0].suit = SPADE;
	
	trump[1].number = 11;
	trump[1].suit = CLUB;

	trump[2].number = 12;
	trump[2].suit = DIAMOND;

	trump[3].number = 9;
	trump[3].suit = HEART;

	trump[4].number = 9;
	trump[4].suit = SPADE;

	for (i = 0; i < HAND_MAX; i++)
	{
		//trump[i] = GetTrump();
		printf("%sの%d\n", trump[i].suit, trump[i].number);
	}

	GetRole(trump);
	//Test(trump);
	//printf("\nソート後\n");
	//Test2(trump);
}

// 役の取得
Role GetRole(Trump trump[])
{
	Role role = Role::HighCard;
	int pair = CountPair(trump);

	role = GetPairRole(pair);

	return role;
}

// ペアのカウント
int CountPair(Trump trump[])
{
	int pair = 0;
	int i, j;

	for (i = 0; i < HAND_MAX - 1; i++)
	{
		for (j = i + 1; j < HAND_MAX; j++)
		{
			if (trump[i].number == trump[j].number)
			{
				pair++;
			}
		}
	}

	return pair;
}

// ペア役の取得
Role GetPairRole(int pair)
{
	Role role = Role::HighCard;

	switch (pair)
	{
	case 1:
		role = Role::OnePair;
		printf("ワンペア\n");
		break;

	case 2:
		role = Role::TwoPair;
		printf("ツーペア\n");
		break;

	case 3:
		role = Role::ThreeCard;
		printf("スリーカード\n");
		break;

	case 4:
		role = Role::FullHouse;
		printf("フルハウス\n");
		break;

	case 6:
		role = Role::FourCard;
		printf("フォーカード\n");
		break;
	}

	return role;
}