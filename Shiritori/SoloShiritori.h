#pragma once
#include<wchar.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

#define EM_SIZE 3

/*----------関数----------*/

// 末尾の文字を取得
void GetTail(char word[]);


/*----------変数----------*/

char tail[EM_SIZE];