#pragma once
#include<wchar.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>
#include"../Utility.h"

#define EM_SIZE 3
#define WORD_LOWER 4
#define WORD_UPPER 20

/*----------�֐�----------*/

// �������̃`�F�b�N
int CheckWordLength(char word[]);
// ���݂̖��������ƈ�v���Ă��邩�`�F�b�N
int IsSame(char a[],char b[]);

// �����̕������擾
void GetTail(char word[],char* tail);
// �擪�̕������擾
void GetHead(char word[], char* head);

// ���������ɓo�^����
void SetTail(char tail[]);

/*----------�ϐ�----------*/

char g_tail[EM_SIZE];
char END_CHAR[EM_SIZE] = "��";