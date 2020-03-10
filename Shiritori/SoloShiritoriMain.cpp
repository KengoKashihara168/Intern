#include"SoloShiritoriMain.h"

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
	printf("Initialize\n");
}

// 更新
int SoloShiritoriUpdate()
{
	printf("Update\n");

	return 1;
}

// 描画
void SoloShiritoriRender()
{
	printf("Render\n");
}

// 終了
void SoloShiritoriFinalize()
{
	printf("終了\n");
	getchar();
}