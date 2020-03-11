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
	printf("����Ƃ�->\n");
	char start[] = "����Ƃ�";
	GetTail(start,&g_tail[0]);
	printf("%s\n", &g_tail);
}

// �X�V
int SoloShiritoriUpdate()
{
	char str[256];

	while (CheckWordLength(str))
	{
		if (scanf("%s", &str) < 0)
		{
			printf("���͎��s\n");
		}
	}

	// �����̕������擾
	char tail[EM_SIZE];
	GetTail(str,&tail[0]);
	printf("%s�̍Ō�̕����́u%s�v\n", &str, &tail);

	if (IsSame(tail) < 0)
	{
		printf("��v���܂���ł���\n");
	}
	else
	{
		printf("��v���܂���\n");
	}

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

// ���݂̖��������ƈ�v���Ă��邩�`�F�b�N
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


// �����̕������擾
void GetTail(char word[],char* tail)
{
	// �����̕����̊J�n�ʒu���v�Z
	int length = strlen(word);
	int tailNum = length - 2;

	// �Ō�̂P������tail�Ɋi�[
	for (int i = 0; i < EM_SIZE; i++)
	{
		int j = tailNum + i;
		*tail = word[j];
		tail++;
	}
}