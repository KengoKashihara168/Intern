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
// 現在の末尾文字と一致しているかチェック
int IsSame(char tail[]);

// 末尾の文字を取得
void GetTail(char word[],char* tail);
// 先頭の文字を取得
void GetHead(char word[], char* head);


/*----------変数----------*/

char g_tail[EM_SIZE];