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
	char start[] = "����Ƃ�";
	printf("%s->\n",&start);
	GetTail(start,&g_tail[0]);
	printf("%s\n", &g_tail);
}

// �X�V
int SoloShiritoriUpdate()
{
	char str[256];
	char head[EM_SIZE];
	char tail[EM_SIZE];

	while (CheckWordLength(str))
	{
		if (scanf("%s", &str) < 0)
		{
			printf("���͎��s\n");
		}
	}

	// �擪�̕������擾
	
	GetHead(str, head);

	if (IsSame(g_tail,head) < 0)
	{
		printf("��v���܂���ł���\n");
		return 1;
	}
	else
	{
		// �����̕������擾
		GetTail(str, &tail[0]);
		printf("%s->\n", &str);

		if (IsSame(tail,END_CHAR) >= 0)
		{
			printf("�u��v������\n");
			return 1;
		}

		SetTail(tail);
	}

	return 0;

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
int IsSame(char a[],char b[])
{
	int isSame = 0;
	
	if (strcmp(a, b) != 0)
	{
		isSame = -1;
	}

	return isSame;
}

// �����̕������擾
void GetTail(char word[],char* tail)
{
	// �����̕����̊J�n�ʒu���v�Z
	int length = strlen(word);
	int tailNum = length - 2;
	int i, j;

	// �Ō�̂P������tail�Ɋi�[
	for (i = 0; i < EM_SIZE - 1; i++)
	{
		j = tailNum + i;
		*tail = word[j];
		tail++;
	}
	*tail = '\0';
}

// �擪�̕������擾
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

// ���������ɓo�^
void SetTail(char tail[])
{
	int i;
	for (i = 0; i < EM_SIZE; i++)
	{
		g_tail[i] = tail[i];
	}
}