#pragma once
#include<string.h>
#include"../Utility.h"
#include"../Rand.h"

////////////////// リートクイズ //////////////////

/*----------定数----------*/

#define ROW 26
#define COLUMN 3
#define WORD_NUM 3

/*----------関数----------*/

// メイン関数
void LeetQuizMain();
// 問題文の表示
void WriteQuestion(const char (*leet)[COLUMN],int num[WORD_NUM]);
// プレイヤーの入力
char* PlayerInput();
// 正誤判定
void Judge(char* answer, char* input);