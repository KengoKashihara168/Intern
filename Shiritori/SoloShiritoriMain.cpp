#include"SoloShiritoriMain.h"
#include"SoloShiritori.h"

void SoloShiritoriMain()
{
	// 初期化
	SoloShiritoriInitialize();

	int game = 0; // 0ならゲーム中
	while (game == 0)
	{
		// 更新
		game = SoloShiritoriUpdate();
	}

	// 終了
	SoloShiritoriFinalize();
}

// 初期化
void SoloShiritoriInitialize()
{
	//wprintf(L"しりとり->\n");
}

// 更新
int SoloShiritoriUpdate()
{
	char str[256];
	if (scanf("%s", &str) < 0)
	{
		printf("入力失敗\n");
	}

	// 末尾の文字を取得
	GetTail(str);
	printf("%sの最後の文字は「%s」\n", &str, &tail);

	return 1;

}

// 終了
void SoloShiritoriFinalize()
{
	printf("終了\n");
	getchar();
}

// 末尾の文字を取得
void GetTail(char word[])
{
	// 末尾の文字の開始位置を計算
	int length = strlen(word);
	int tailNum = length - 2;

	// 最後の１文字をtailに格納
	for (int i = 0; i < EM_SIZE; i++)
	{
		int j = tailNum + i;
		tail[i] = word[j];
	}
}