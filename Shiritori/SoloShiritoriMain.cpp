#include"SoloShiritoriMain.h"
#include"SoloShiritori.h"

void SoloShiritoriMain()
{
	// 初期化
	SoloShiritoriInitialize();

	BOOL game = TRUE; // 0ならゲーム中
	while (game == TRUE)
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
	char start[] = "しりとり";
	printf("%s->\n",&start);
	GetTail(start,&g_tail[0]);
	printf("%s\n", &g_tail);
}

// 更新
int SoloShiritoriUpdate()
{
	BOOL playFlag = TRUE;
	char str[256];
	char head[EM_SIZE];
	char tail[EM_SIZE];

	while (CheckWordLength(str))
	{
		if (scanf("%s", &str) < 0)
		{
			printf("入力失敗\n");
		}
	}

	// 先頭の文字を取得
	GetHead(str, head);

	if (IsSame(g_tail,head) < 0)
	{
		printf("一致しませんでした\n");
		playFlag = FALSE;
	}
	else
	{
		// 末尾の文字を取得
		GetTail(str, &tail[0]);
		printf("%s->\n", &str);

		if (IsSame(tail,END_CHAR) >= 0)
		{
			printf("「ん」がついた\n");
			playFlag = FALSE;
		}

		SetTail(tail);
	}

	return playFlag;

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
	BOOL checkFlag = TRUE;
	int length = strlen(word);
	
	// 文字数が２より少ない
	if (length < WORD_LOWER || length > WORD_UPPER)
	{
		checkFlag = FALSE;
		printf("%d文字以上%d文字以下で入力してください\n",
				WORD_LOWER / 2, WORD_UPPER / 2);
	}

	return checkFlag;
}

// 現在の末尾文字と一致しているかチェック
int IsSame(char a[],char b[])
{
	BOOL isSame = TRUE;
	
	if (strcmp(a, b) != TRUE)
	{
		isSame = FALSE;
	}

	return isSame;
}

// 末尾の文字を取得
void GetTail(char word[],char* tail)
{
	// 末尾の文字の開始位置を計算
	int length = strlen(word);
	int tailNum = length - 2;
	int i, j;

	// 最後の１文字をtailに格納
	for (i = 0; i < EM_SIZE - 1; i++)
	{
		j = tailNum + i;
		*tail = word[j];
		tail++;
	}
	*tail = '\0';
}

// 先頭の文字を取得
void GetHead(char word[], char *head)
{
	int i;
	for (i = 0; i < EM_SIZE - 1; i++)
	{
		*head = word[i];
		head++;
	}
	*head = '\0';
}

// 末尾文字に登録
void SetTail(char tail[])
{
	int i;
	for (i = 0; i < EM_SIZE; i++)
	{
		g_tail[i] = tail[i];
	}
}