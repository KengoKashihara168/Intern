#include"LeetQuizMain.h"

void LeetQuizMain()
{
	const char alphabet[ROW + 1] = {'A','B','C','D','E','F','G','H', 'I','J','K','L', 'M','N','O','P', 'Q','R','S','T', 'U','V','W','X', 'Y','Z','\0'};
	const char leet[ROW][COLUMN] = 
	{ 
		 {'/','\\','\0'} // A
		,{'I','3','\0'}  // B
		,{'(',' ','\0'}  // C
		,{'|',')','\0'}  // D
		,{'[','-','\0'}  // E
		,{'|','=','\0'}  // F
		,{'(','.','\0'}  // G
		,{'#',' ','\0' } // H
		,{'!',' ','\0'}  // I
		,{'_','|','\0'}  // J
		,{'|','<','\0'}  // K
		,{'|','_','\0'}  // L
		,{'A','A','\0'}  // M
		,{'^','/','\0'}  // N
		,{'(',')','\0'}  // O
		,{'|','*','\0'}  // P
		,{'0','_','\0'}  // Q
		,{'I','2','\0'}  // R
		,{'e','s','\0'}  // S
		,{'7',' ','\0'}  // T
		,{'v',' ','\0'}  // U
		,{'|','/','\0'}  // V
		,{'v','v','\0'}  // W
		,{'>','<','\0'}  // X
		,{'\\',' ','\0'} // Y
		,{'7','_','\0'}  // Z
	};
	int num[WORD_NUM];
	char input[WORD_NUM];
	char* p_input = input;
	char answer[WORD_NUM + 1];
	int i;
	// �����_���ŕ\�����镶����ݒ�
	for (i = 0; i < WORD_NUM; i++)
	{
		num[i] = GetRand(ROW);
	}

	// Leet�����̕\��
	WriteQuestion(leet, num);

	// ����
	p_input = PlayerInput();

	// �����̕\��
	for (i = 0; i < WORD_NUM; i++)
	{
		answer[i] = alphabet[num[i]];
	}
	answer[WORD_NUM] = '\0';
	printf("%s\n", &answer);

	// ����
	Judge(answer, p_input);
}

// ���̕\��
void WriteQuestion(const char (*leet)[COLUMN], int num[WORD_NUM])
{
	int i;
	for (i = 0; i < WORD_NUM; i++)
	{
		printf("%s ", leet[num[i]]);
	}
	printf("\n");
}

// �v���C���[�̓���
char* PlayerInput()
{
	static char input[WORD_NUM];
	if (scanf("%s", input) < 0)
	{
		printf("���͎��s\n");
	}

	return input;
}

// ���딻��
void Judge(char* answer, char* input)
{
	if (strcmp(answer, input) == TRUE)
	{
		printf("����\n");
	}
	else
	{
		printf("�s����\n");
	}
}