#pragma once

enum RPS
{
	Rock,	 // グー
	Paper,	 // パー
	Scissors,// チョキ
	RPS_MAX	 // ３
};

/*----------関数----------*/

// ランダムな手を取得
RPS RandomHand();
// 手を文字列に変換
const char* GetHandText(RPS hand);
// 入力された文字をチェック
int CheckInput(char input);
// 入力値された手を取得
RPS InputHand(char input);

// 結果判定
int Judge();

// グーの判定
void RockJudge();
// パーの判定
void PaperJudge();
// チョキの判定
void ScissorsJudge();

/*----------変数----------*/

RPS npcHand;
RPS playerHand;
const char* result;

/*-------マクロ定数-------*/

#define IS_ROCK(input)		 input == 'g' ||  input == 'r'
#define IS_SCISSORS(input)	 input == 'c' || input == 's'
#define IS_PAPER(input)		 input == 'p'

#define WIN "勝ち！"
#define LOSE "負け..."
#define DRAW "あいこで…"