#pragma warning(disable: 4996)
#include"JankenMain.h"
#include"JankenData.h"
#include"../Rand.h"

void JankenMain()
{
	// 初期化
	Initialize();

	int game = 0; // 0ならゲーム中
	while (game == 0)
	{
		// 更新
		game = Update();
		
		// 描画
		Render();
	}

	// 終了
	Finalize();
}

// 初期化
void Initialize()
{
	printf("グー　：「g」「r」\n");
	printf("チョキ：「c」「s」\n");
	printf("パー　：「p」\n");
	printf("どの手を出すか入力してください\n");
}

// 更新
int Update()
{
	// NPCの手を決める
	npcHand = RandomHand();

	char input,feed;
	scanf("%c%c",&input,&feed);

	while (CheckInput(input) == 0)
	{
		printf("正しい文字を入力してください\n");
		scanf("%c%c", &input, &feed);
	}

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
	printf("%s\n", result);
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

// 入力された文字をチェック
int CheckInput(char input)
{
	int checkFlag = 0;
	if (IS_ROCK(input))		checkFlag = 1;
	if (IS_SCISSORS(input))	checkFlag = 1;
	if (IS_PAPER(input))	checkFlag = 1;

	return checkFlag;
}

// 入力された手を取得
RPS InputHand(char input)
{
	RPS hand = RPS_MAX;
	if (IS_ROCK(input))		hand = Rock;
	if (IS_SCISSORS(input))	hand = Scissors;
	if (IS_PAPER(input))	hand = Paper;

	return hand;
}

// 結果判定
int Judge()
{
	switch (playerHand)
	{
	case Rock:
		// グーの判定
		RockJudge();
		break;
	case Paper:
		// パーの判定
		PaperJudge();
		break;
	case Scissors:
		// チョキの判定
		ScissorsJudge();
		break;
	}

	if (result == DRAW)return 0;

	return 1;
}

// グーの判定
void RockJudge()
{
	result = DRAW;
	if (npcHand == Scissors)result = WIN;
	if (npcHand == Paper)result = LOSE;
}

// パーの判定
void PaperJudge()
{
	result = DRAW;
	if (npcHand == Rock)result = WIN;
	if (npcHand == Scissors)result = LOSE;
}

// チョキの判定
void ScissorsJudge()
{
	result = DRAW;
	if (npcHand == Paper)result = WIN;
	if (npcHand == Rock)result = LOSE;
}
