#pragma once
#include<wchar.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

#define EM_SIZE 3
#define WORD_LOWER 4
#define WORD_UPPER 20

/*----------関数----------*/

// 文字数のチェック
int CheckWordLength(char word[]);

// 末尾の文字を取得
void GetTail(char word[]);


/*----------変数----------*/

char tail[EM_SIZE];