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
	char str[256] = { "" };

	while (CheckWordLength(str))
	{
		if (scanf("%s", &str) < 0)
		{
			printf("���͎��s\n");
		}
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

// �������̃`�F�b�N
int CheckWordLength(char word[])
{
	int checkFlag = 0;
	int length = strlen(word);
	
	// ���������Q��菭�Ȃ�
	if (length < WORD_LOWER || length > WORD_UPPER)
	{
		checkFlag = -1;
		printf("%d�����ȏ�%d�����ȉ��œ��͂��Ă�������\n",
				WORD_LOWER / 2, WORD_UPPER / 2);
	}

	return checkFlag;
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