#pragma once
#include<string.h>
#include"../Utility.h"
#include"../Rand.h"

////////////////// ���[�g�N�C�Y //////////////////

/*----------�萔----------*/

#define ROW 26
#define COLUMN 3
#define WORD_NUM 3

/*----------�֐�----------*/

// ���C���֐�
void LeetQuizMain();
// ��蕶�̕\��
void WriteQuestion(const char (*leet)[COLUMN],int num[WORD_NUM]);
// �v���C���[�̓���
char* PlayerInput();
// ���딻��
void Judge(char* answer, char* input);