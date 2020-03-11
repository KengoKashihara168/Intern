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

		// 描画
		SoloShiritoriRender();
	}

	// 終了
	SoloShiritoriFinalize();
}

// 初期化
void SoloShiritoriInitialize()
{
	setlocale(LC_CTYPE, "ja_JP.UTF-8");
	//wprintf(L"しりとり->\n");
}

// 更新
int SoloShiritoriUpdate()
{
	// マルチバイト文字の入出力
	//char a[256];
	//scanf("%s", &a);
	//printf("%s", &a);

	// ワイド文字
	wchar_t wa[] = L"あいう";
	wprintf(L"%ls\n", &wa);
	wprintf(L"%lc\n", wa[0]);

	// ワイド文字の入出力
	wchar_t wb[256];
	wscanf(L"%ls", &wb);
	wprintf(L"%ls\n", &wb);
	wprintf(L"%lc\n", wb[0]);

	return 1;
}

// 描画
void SoloShiritoriRender()
{
	
}

// 終了
void SoloShiritoriFinalize()
{
	printf("終了\n");
	getchar();
}