#include"Poker.h"
#include "../Trump.h"

// ���̎擾
Role GetRole(Trump trump[]);

// �y�A�̃J�E���g
int CountPair(Trump trump[]);
// �y�A���̎擾
Role GetPairRole(int pair);

void Test2(Trump trump[]);

void PokerMain()
{
	Trump trump[HAND_MAX];
	int i;

	/* �f�o�b�O�p */
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
		printf("%s��%d\n", trump[i].suit, trump[i].number);
	}

	GetRole(trump);
	//Test(trump);
	//printf("\n�\�[�g��\n");
	//Test2(trump);
}

// ���̎擾
Role GetRole(Trump trump[])
{
	Role role = Role::HighCard;
	int pair = CountPair(trump);

	role = GetPairRole(pair);

	return role;
}

// �y�A�̃J�E���g
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

// �y�A���̎擾
Role GetPairRole(int pair)
{
	Role role = Role::HighCard;

	switch (pair)
	{
	case 1:
		role = Role::OnePair;
		printf("�����y�A\n");
		break;

	case 2:
		role = Role::TwoPair;
		printf("�c�[�y�A\n");
		break;

	case 3:
		role = Role::ThreeCard;
		printf("�X���[�J�[�h\n");
		break;

	case 4:
		role = Role::FullHouse;
		printf("�t���n�E�X\n");
		break;

	case 6:
		role = Role::FourCard;
		printf("�t�H�[�J�[�h\n");
		break;
	}

	return role;
}