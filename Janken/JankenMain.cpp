#pragma warning(disable: 4996)
#include"JankenMain.h"
#include"JankenData.h"
#include"../Rand.h"

void JankenMain()
{
	// ������
	Initialize();

	int game = 0; // 0�Ȃ�Q�[����
	while (game == 0)
	{
		// �X�V
		game = Update();
		
		// �`��
		Render();
	}

	// �I��
	Finalize();
}

// ������
void Initialize()
{
	printf("�O�[�@�F�ug�v�ur�v\n");
	printf("�`���L�F�uc�v�us�v\n");
	printf("�p�[�@�F�up�v\n");
	printf("�ǂ̎���o�������͂��Ă�������\n");
}

// �X�V
int Update()
{
	// NPC�̎�����߂�
	npcHand = RandomHand();

	char input,feed;
	scanf("%c%c",&input,&feed);

	while (CheckInput(input) == 0)
	{
		printf("��������������͂��Ă�������\n");
		scanf("%c%c", &input, &feed);
	}

	// ���͂��ꂽ����擾
	playerHand = InputHand(input);

	return Judge();
}

// �`��
void Render()
{
	// ���ʂ̕\��
	printf("NPC�F%s", GetHandText(npcHand));
	printf(" vs ");
;
	printf("���Ȃ��F%s\n", GetHandText(playerHand));
	printf("%s\n", result);
}

// �I��
void Finalize()
{
	//system("cls");
	printf("�I��\n");
}

// �����_���Ȏ���擾
RPS RandomHand()
{
	int rand = GetRand(RPS_MAX - 1); // 0�`2�̗���

	RPS hand; // ��
	switch (rand)
	{
	case Rock:
		hand = Rock;
		break;
	case Paper:
		hand = Paper;
		break;
	case Scissors:
		hand = Scissors;
		break;
	}

	return hand;
}

// ��𕶎���ɕϊ�
const char* GetHandText(RPS hand)
{
	const char* text = "";
	switch (hand)
	{
	case Rock:
		text = "�O�[";
		break;
	case Paper:
		text = "�p�[";
		break;
	case Scissors:
		text = "�`���L";
		break;
	}

	return text;
}

// ���͂��ꂽ�������`�F�b�N
int CheckInput(char input)
{
	int checkFlag = 0;
	if (IS_ROCK(input))		checkFlag = 1;
	if (IS_SCISSORS(input))	checkFlag = 1;
	if (IS_PAPER(input))	checkFlag = 1;

	return checkFlag;
}

// ���͂��ꂽ����擾
RPS InputHand(char input)
{
	RPS hand = RPS_MAX;
	if (IS_ROCK(input))		hand = Rock;
	if (IS_SCISSORS(input))	hand = Scissors;
	if (IS_PAPER(input))	hand = Paper;

	return hand;
}

// ���ʔ���
int Judge()
{
	switch (playerHand)
	{
	case Rock:
		// �O�[�̔���
		RockJudge();
		break;
	case Paper:
		// �p�[�̔���
		PaperJudge();
		break;
	case Scissors:
		// �`���L�̔���
		ScissorsJudge();
		break;
	}

	if (result == DRAW)return 0;

	return 1;
}

// �O�[�̔���
void RockJudge()
{
	result = DRAW;
	if (npcHand == Scissors)result = WIN;
	if (npcHand == Paper)result = LOSE;
}

// �p�[�̔���
void PaperJudge()
{
	result = DRAW;
	if (npcHand == Rock)result = WIN;
	if (npcHand == Scissors)result = LOSE;
}

// �`���L�̔���
void ScissorsJudge()
{
	result = DRAW;
	if (npcHand == Paper)result = WIN;
	if (npcHand == Rock)result = LOSE;
}
