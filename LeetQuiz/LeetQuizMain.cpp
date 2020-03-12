#include"LeetQuizMain.h"

void LeetQuizMain()
{
	const int row = 26;
	const int column = 3;
	const int wordNum = 3;
	const char alphabet[row + 1] = {'A','B','C','D','E','F','G','H', 'I','J','K','L', 'M','N','O','P', 'Q','R','S','T', 'U','V','W','X', 'Y','Z','\0'};
	const char leet[row][column] = 
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
	int num[wordNum];
	char input[wordNum + 1];
	int i;
	char answer[wordNum + 1];

	// Leet�����̕\��
	for (i = 0; i < row; i++)
	{
		printf("%c�F%s\n", alphabet[i],&leet[i]);
	}

	// �����_���ŕ\�����镶����ݒ�
	for (i = 0; i < 3; i++)
	{
		num[i] = GetRand(row);
		printf("%d,", num[i]);
	}
	printf("\n\n");

	// Leet�����̕\��
	for (i = 0; i < 3; i++)
	{
		printf("%s ", leet[num[i]]);
	}
	printf("\n");

	// �����̕\��
	for (i = 0; i < wordNum; i++)
	{
		answer[i] = alphabet[num[i]];
	}
	answer[wordNum] = '\0';
	printf("%s\n", &answer);

	// ����
	if (scanf("%s", &input) < 0)
	{
		printf("���͎��s\n");
	}
	input[wordNum] = '\0';
	printf("%s\n", &input);

	// ����
	if (strcmp(answer,input) == TRUE)
	{
		printf("����\n");
	}
	else
	{
		printf("�s����\n");
	}

}