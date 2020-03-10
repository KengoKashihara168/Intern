#pragma once

enum RPS
{
	Rock,
	Paper,
	Scissors,
	RPS_MAX
};

/*----------関数----------*/

// ランダムな手を取得
RPS RandomHand();
// 手を文字列に変換
const char* GetHandText(RPS hand);
// 入力値された手を取得
RPS InputHand(char input);

// 結果判定
bool Judge();

// グーの判定
const char* RockJudge();
// パーの判定
const char* PaperJudge();
// チョキの判定
const char* ScissorsJudge();

/*----------変数----------*/
RPS npcHand;
RPS playerHand;
const char* result;