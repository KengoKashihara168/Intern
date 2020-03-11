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
	printf("しりとり->\n");
	char start[] = "しりとり";
	GetTail(start,&g_tail[0]);
	printf("%s\n", &g_tail);
}

// 更新
int SoloShiritoriUpdate()
{
	char str[256];

	while (CheckWordLength(str))
	{
		if (scanf("%s", &str) < 0)
		{
			printf("入力失敗\n");
		}
	}

	// 先頭の文字を取得
	char head[EM_SIZE];
	GetHead(str, head);

	if (IsSame(head) < 0)
	{
		printf("一致しませんでした\n");
		return 1;
	}
	else
	{
		// 末尾の文字を取得
		char tail[EM_SIZE];
		GetTail(str, &tail[0]);
		printf("%s->\n", &str);
		SetTail(tail);
	}

	return 0;

}

// 終了
void SoloShiritoriFinalize()
{
	printf("終了\n");
	getchar();
}

// 文字数のチェック
int CheckWordLength(char word[])
{
	int checkFlag = 0;
	int length = strlen(word);
	
	// 文字数が２より少ない
	if (length < WORD_LOWER || length > WORD_UPPER)
	{
		checkFlag = -1;
		printf("%d文字以上%d文字以下で入力してください\n",
				WORD_LOWER / 2, WORD_UPPER / 2);
	}

	return checkFlag;
}

// 現在の末尾文字と一致しているかチェック
int IsSame(char tail[])
{
	int isSame = 0;
	
	for (int i = 0; i < EM_SIZE; i++)
	{
		if (tail[i] != g_tail[i])
		{
			isSame = -1;
		}
	}

	return isSame;
}

// 末尾の文字を取得
void GetTail(char word[],char* tail)
{
	// 末尾の文字の開始位置を計算
	int length = strlen(word);
	int tailNum = length - 2;

	// 最後の１文字をtailに格納
	for (int i = 0; i < EM_SIZE - 1; i++)
	{
		int j = tailNum + i;
		*tail = word[j];
		tail++;
	}
	*tail = '\0';
}

// 先頭の文字を取得
void GetHead(char word[], char *head)
{
	for (int i = 0; i < EM_SIZE - 1; i++)
	{
		*head = word[i];
		head++;
	}
	*head = '\0';
}

// 末尾文字に登録
void SetTail(char tail[])
{
	for (int i = 0; i < EM_SIZE; i++)
	{
		g_tail[i] = tail[i];
	}
}