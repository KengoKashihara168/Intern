#include "Trump.h"
#include "Rand.h"

BOOL outFlag[CARD_MAX] = { TRUE }; // �g�����v�̔z�z�t���O

// �����_����52���̃J�[�h�ԍ����擾
int GetCardNum();
// �J�[�h�ԍ������ƂɃX�[�g���擾
const char* GetSuit(int num);
// �J�[�h�ԍ������Ƃɐ������擾
int GetNumber(int num);

Trump GetTrump()
{
	Trump trump; // �g�����v
	int cardNum; // �J�[�h�ԍ�

	// �J�[�h�̃����_���擾
	cardNum = GetCardNum();

	// �ԍ������ƂɃJ�[�h�����擾
	trump.suit = GetSuit(cardNum);
	trump.number = GetNumber(cardNum);

	// �z�z�ς݂ɂ���
	outFlag[cardNum] = FALSE;

	return trump;
}

// �����_����52���̃J�[�h�ԍ����擾
int GetCardNum()
{
	int rand, count;

	rand = GetRand(CARD_MAX);
	count = 0;

	// �܂��z�z����Ă��Ȃ��J�[�h�ԍ���T��
	while (outFlag[rand] != TRUE || count < CARD_MAX)
	{
		rand = GetRand(CARD_MAX - 1);
		count++;
	}

	return rand;
}

// �J�[�h�ԍ������ƂɃX�[�g���擾
const char* GetSuit(int num)
{
	//  0�`12:�X�y�[�h 13�`25:�N���u
	// 26�`38:�_�C��   39�`51:�n�[�g
	int suitNum = num / NUMBER_MAX;
	const char* suit = "";

	switch (suitNum)
	{
	case 0:
		suit = SPADE;
		break;
	case 1:
		suit = CLUB;
		break;
	case 2:
		suit = DIAMOND;
		break;
	case 3:
		suit = HEART;
		break;
	}

	return suit;
}

// �J�[�h�ԍ������Ƃɐ������擾
int GetNumber(int num)
{
	int number = num % NUMBER_MAX + 1;
	return number;
}