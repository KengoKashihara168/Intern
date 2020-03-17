#include"Poker.h"
#include "../Trump.h"

// ���̕\��
void WrightRole(Role role);
// ���ʂ̕\��
void WrightResult(Role player,Role npc);

// ���̎擾
Role GetRole(Trump trump[]);

// �y�A�̃J�E���g
int CountPair(Trump trump[]);
// �y�A���̎擾
Role GetPairRole(int pair);
// �X�[�g���̎擾
Role GetSuitRole(Trump trump[]);

// �A�Ԃ�����
BOOL IsSerial(Trump trump[]);
// �X�[�g�������Ă��邩����
BOOL IsSameSuit(Trump trump[]);

void PokerMain()
{
	Trump player[HAND_MAX]; // �v���C���[�̎�
	Trump npc[HAND_MAX];	// NPC�̎�
	Role  playerRole;		// �v���C���[�̖�
	Role  npcRole;			// NPC�̖�
	int i;

	// �g�����v�̎擾
	for (i = 0; i < HAND_MAX; i++)
	{
		player[i] = GetTrump();
		npc[i] = GetTrump();
		printf("Player:%s��%d\n", player[i].suit, player[i].number);
	}

	// ���̔���
	playerRole = GetRole(player);
	npcRole = GetRole(npc);
	
	// ���ʂ̕\��
	printf("\n�` ���� �`\n");
	WrightResult(playerRole, npcRole);
}

// ���̕\��
void WrightRole(Role role)
{
	const char* roleName[] = 
	{ 
		"�n�C�J�[�h","�����y�A","�c�[�y�A","�X���[�J�[�h",
		"�X�g���[�g","�t���b�V��","�t���n�E�X","�t�H�[�J�[�h","�X�g���[�g�t���b�V��"
	};
	printf("%s\n", roleName[role]);
}

// ���ʂ̕\��
void WrightResult(Role player, Role npc)
{
	// ���̕\��
	printf("�v���C���[�F");
	WrightRole(player);
	printf("NPC�F");
	WrightRole(npc);

	// ���s����
	if (player > npc)
	{
		printf("�����I\n");
	}
	else if (player < npc)
	{
		printf("�����c\n");
	}
	else
	{
		printf("��������\n");
	}
}

// ���̎擾
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

// �X�[�g���̎擾
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

// �A�Ԃ�����
BOOL IsSerial(Trump trump[])
{
	BOOL isSerial = FALSE;
	Trump tmp;
	int serial = 0;
	int i, j;

	// �~���ɕ��בւ���
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

	// �����̍����v�Z
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

// �X�[�g�������Ă��邩����
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