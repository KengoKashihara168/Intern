#include"Poker.h"
#include "../Trump.h"

// 役の表示
void WrightRole(Role role);
// 結果の表示
void WrightResult(Role player,Role npc);

// 役の取得
Role GetRole(Trump trump[]);

// ペアのカウント
int CountPair(Trump trump[]);
// ペア役の取得
Role GetPairRole(int pair);
// スート役の取得
Role GetSuitRole(Trump trump[]);

// 連番か判定
BOOL IsSerial(Trump trump[]);
// スートが揃っているか判定
BOOL IsSameSuit(Trump trump[]);

void PokerMain()
{
	Trump player[HAND_MAX]; // プレイヤーの手
	Trump npc[HAND_MAX];	// NPCの手
	Role  playerRole;		// プレイヤーの役
	Role  npcRole;			// NPCの役
	int i;

	// トランプの取得
	for (i = 0; i < HAND_MAX; i++)
	{
		player[i] = GetTrump();
		npc[i] = GetTrump();
		printf("Player:%sの%d\n", player[i].suit, player[i].number);
	}

	// 役の判定
	playerRole = GetRole(player);
	npcRole = GetRole(npc);
	
	// 結果の表示
	printf("\n～ 結果 ～\n");
	WrightResult(playerRole, npcRole);
}

// 役の表示
void WrightRole(Role role)
{
	const char* roleName[] = 
	{ 
		"ハイカード","ワンペア","ツーペア","スリーカード",
		"ストレート","フラッシュ","フルハウス","フォーカード","ストレートフラッシュ"
	};
	printf("%s\n", roleName[role]);
}

// 結果の表示
void WrightResult(Role player, Role npc)
{
	// 役の表示
	printf("プレイヤー：");
	WrightRole(player);
	printf("NPC：");
	WrightRole(npc);

	// 勝敗判定
	if (player > npc)
	{
		printf("勝ち！\n");
	}
	else if (player < npc)
	{
		printf("負け…\n");
	}
	else
	{
		printf("引き分け\n");
	}
}

// 役の取得
Role GetRole(Trump trump[])
{
	Role role = Role::HighCard;
	int pair = CountPair(trump);

	if (pair > 0)
	{
		role = GetPairRole(pair);
	}
	else
	{
		role = GetSuitRole(trump);
	}

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
		break;

	case 2:
		role = Role::TwoPair;
		break;

	case 3:
		role = Role::ThreeCard;
		break;

	case 4:
		role = Role::FullHouse;
		break;

	case 6:
		role = Role::FourCard;
		break;
	}

	return role;
}

// スート役の取得
Role GetSuitRole(Trump trump[])
{
	Role role = Role::HighCard;

	if (IsSerial(trump) == TRUE)
	{
		if (IsSameSuit(trump) == TRUE)
		{
			role = Role::StraightFlush;
		}
		else
		{
			role = Role::Straight;
		}
	}
	else if (IsSameSuit(trump) == TRUE)
	{
		role = Role::Flush;
	}

	return role;
}

// 連番か判定
BOOL IsSerial(Trump trump[])
{
	BOOL isSerial = FALSE;
	Trump tmp;
	int serial = 0;
	int i, j;

	// 降順に並べ替える
	for (i = 0; i < HAND_MAX - 1; i++)
	{
		for (j = i + 1; j < HAND_MAX; j++)
		{
			if (trump[i].number < trump[j].number)
			{
				tmp = trump[i];
				trump[i] = trump[j];
				trump[j] = tmp;
			}
		}
	}

	// 数字の差を計算
	for (i = 1; i < HAND_MAX; i++)
	{
		serial += trump[i - 1].number - trump[i].number;
	}

	if (serial == 4)
	{
		isSerial = TRUE;
	}

	return isSerial;
}

// スートが揃っているか判定
BOOL IsSameSuit(Trump trump[])
{
	BOOL suitFlag = TRUE;
	int i;

	for (i = 1; i < HAND_MAX; i++)
	{
		if (trump[i - 1].suit != trump[i].suit)
		{
			suitFlag = FALSE;
		}
	}

	return suitFlag;
}