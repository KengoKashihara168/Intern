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
	}

	// �I��
	SoloShiritoriFinalize();
}

// ������
void SoloShiritoriInitialize()
{
	//wprintf(L"����Ƃ�->\n");
}

// �X�V
int SoloShiritoriUpdate()
{
	char str[256];
	if (scanf("%s", &str) < 0)
	{
		printf("���͎��s\n");
	}

	// �����̕������擾
	GetTail(str);
	printf("%s�̍Ō�̕����́u%s�v\n", &str, &tail);

	return 1;

}

// �I��
void SoloShiritoriFinalize()
{
	printf("�I��\n");
	getchar();
}

// �����̕������擾
void GetTail(char word[])
{
	// �����̕����̊J�n�ʒu���v�Z
	int length = strlen(word);
	int tailNum = length - 2;

	// �Ō�̂P������tail�Ɋi�[
	for (int i = 0; i < EM_SIZE; i++)
	{
		int j = tailNum + i;
		tail[i] = word[j];
	}
}