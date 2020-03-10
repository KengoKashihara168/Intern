#pragma warning(disable: 4996)
#include"JankenMain.h"
#include"JankenData.h"
#include"../Rand.h"

void JankenMain()
{
	// 初期化
	Initialize();

	bool game = true; // trueならゲーム中
	while (game)
	{
		// 更新
		game = Update();
		
		// 描画
		//system("cls");
		Render();
	}

	// 終了
	Finalize();
}

// 初期化
void Initialize()
{
	npcHand = RandomHand();

	printf("グー　：「g」「r」\n");
	printf("チョキ：「c」「s」\n");
	printf("パー　：「p」\n");
	printf("どの手を出すか入力してください\n");
}

// 更新
bool Update()
{
	char input,feed;
	scanf("%c%c",&input,&feed);

	// 入力された手を取得
	playerHand = InputHand(input);

	return Judge();
}

// 描画
void Render()
{
	// 結果の表示
	printf("NPC：%s", GetHandText(npcHand));
	printf(" vs ");
;
	printf("あなた：%s\n", GetHandText(playerHand));
	printf("結果は… %s！\n", result);
}

// 終了
void Finalize()
{
	//system("cls");
	printf("終了\n");
}

// ランダムな手を取得
RPS RandomHand()
{
	int rand = GetRand(RPS_MAX - 1); // 0～2の乱数

	RPS hand; // 手
	switch (rand)
	{
	case Rock:
		hand = Rock;
		break;
	case Paper:
		hand = Paper;
		break;
	case Scissors:
		hand = Scissors;
		break;
	}

	return hand;
}

// 手を文字列に変換
const char* GetHandText(RPS hand)
{
	const char* text = "";
	switch (hand)
	{
	case Rock:
		text = "グー";
		break;
	case Paper:
		text = "パー";
		break;
	case Scissors:
		text = "チョキ";
		break;
	}

	return text;
}

// 入力された手を取得
RPS InputHand(char input)
{
	RPS hand = RPS_MAX;
	if (input == 'g' || input == 'r')hand = Rock;
	if (input == 'c' || input == 's')hand = Scissors;
	if (input == 'p') hand = Paper;

	return hand;
}

// 結果判定
bool Judge()
{
	result = "";
	switch (playerHand)
	{
	case Rock:
		// グーの判定
		result = RockJudge();
		break;
	case Paper:
		// パーの判定
		result = PaperJudge();
		break;
	case Scissors:
		// チョキの判定
		result = ScissorsJudge();
		break;
	}

	if (result == "あいこ")return true;
	return false;
}

// グーの判定
const char* RockJudge()
{
	if (npcHand == Scissors)return "勝ち";
	if (npcHand == Paper)return "負け";
	return "あいこ";
}

// パーの判定
const char* PaperJudge()
{
	if (npcHand == Rock)return "勝ち";
	if (npcHand == Scissors)return "負け";
	return "あいこ";
}

// チョキの判定
const char* ScissorsJudge()
{
	if (npcHand == Paper)return "勝ち";
	if (npcHand == Rock)return "負け";
	return "あいこ";
}
