#pragma once
#include"Utility.h"

#define CARD_MAX 52			// �J�[�h�̖���
#define SPADE   "�X�y�[�h"
#define CLUB    "�N���u"
#define DIAMOND "�_�C��"
#define HEART   "�n�[�g"
#define NUMBER_MAX 13

struct Trump
{
	const char* suit; // �X�[�g
	int number;		  // ����
};
typedef struct Trump Trump;

// �����_���Ńg�����v���擾
Trump GetTrump();