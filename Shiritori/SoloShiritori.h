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

// �����̕������擾
void GetTail(char word[]);


/*----------�ϐ�----------*/

char tail[EM_SIZE];