#include"SoloShiritoriMain.h"

void SoloShiritoriMain()
{
	// ������
	SoloShiritoriInitialize();

	int game = 0; // 0�Ȃ�Q�[����
	while (game == 0)
	{
		// �X�V
		game = SoloShiritoriUpdate();

		// �`��
		SoloShiritoriRender();
	}

	// �I��
	SoloShiritoriFinalize();
}

// ������
void SoloShiritoriInitialize()
{
	printf("Initialize\n");
}

// �X�V
int SoloShiritoriUpdate()
{
	printf("Update\n");

	return 1;
}

// �`��
void SoloShiritoriRender()
{
	printf("Render\n");
}

// �I��
void SoloShiritoriFinalize()
{
	printf("�I��\n");
	getchar();
}