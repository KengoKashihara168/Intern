#pragma once
#include<wchar.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

#define EM_SIZE 3
#define WORD_LOWER 4
#define WORD_UPPER 20

/*----------�֐�----------*/

// �������̃`�F�b�N
int CheckWordLength(char word[]);
// ���݂̖��������ƈ�v���Ă��邩�`�F�b�N
int IsSame(char tail[]);

// �����̕������擾
void GetTail(char word[],char* tail);
// �擪�̕������擾
void GetHead(char word[], char* head);


/*----------�ϐ�----------*/

char g_tail[EM_SIZE];