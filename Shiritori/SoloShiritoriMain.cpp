#include"SoloShiritoriMain.h"
#include"SoloShiritori.h"

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
	setlocale(LC_CTYPE, "ja_JP.UTF-8");
	//wprintf(L"����Ƃ�->\n");
}

// �X�V
int SoloShiritoriUpdate()
{
	// �}���`�o�C�g�����̓��o��
	//char a[256];
	//scanf("%s", &a);
	//printf("%s", &a);

	// ���C�h����
	wchar_t wa[] = L"������";
	wprintf(L"%ls\n", &wa);
	wprintf(L"%lc\n", wa[0]);

	// ���C�h�����̓��o��
	wchar_t wb[256];
	wscanf(L"%ls", &wb);
	wprintf(L"%ls\n", &wb);
	wprintf(L"%lc\n", wb[0]);

	return 1;
}

// �`��
void SoloShiritoriRender()
{
	
}

// �I��
void SoloShiritoriFinalize()
{
	printf("�I��\n");
	getchar();
}