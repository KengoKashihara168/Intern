#pragma once
#include"Utility.h"

#define CARD_MAX 52			// �J�[�h�̖���
#define SPADE   "Spade"		// �X�y�[�h
#define CLUB    "Club"		// �N���u
#define DIAMOND "Diamond"	// �_�C��
#define HEART   "Heart"		// �n�[�g

struct Trump
{
	const char* suit; // �X�[�g
	int number;		  // ����
};
typedef struct Trump Trump;

// �����_���Ńg�����v���擾
Trump GetTrump();