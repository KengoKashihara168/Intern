#pragma warning(disable: 4996)
#include"JankenMain.h"
#include"JankenData.h"
#include"../Rand.h"

void JankenMain()
{
	// ������
	Initialize();

	bool game = true; // true�Ȃ�Q�[����
	while (game)
	{
		// �X�V
		game = Update();
		
		// �`��
		//system("cls");
		Render();
	}

	// �I��
	Finalize();
}

// ������
void Initialize()
{
	npcHand = RandomHand();

	printf("�O�[�@�F�ug�v�ur�v\n");
	printf("�`���L�F�uc�v�us�v\n");
	printf("�p�[�@�F�up�v\n");
	printf("�ǂ̎���o�������͂��Ă�������\n");
}

// �X�V
bool Update()
{
	char input,feed;
	scanf("%c%c",&input,&feed);

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
	printf("���ʂ́c %s�I\n", result);
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

// ���͂��ꂽ����擾
RPS InputHand(char input)
{
	RPS hand = RPS_MAX;
	if (input == 'g' || input == 'r')hand = Rock;
	if (input == 'c' || input == 's')hand = Scissors;
	if (input == 'p') hand = Paper;

	return hand;
}

// ���ʔ���
bool Judge()
{
	result = "";
	switch (playerHand)
	{
	case Rock:
		// �O�[�̔���
		result = RockJudge();
		break;
	case Paper:
		// �p�[�̔���
		result = PaperJudge();
		break;
	case Scissors:
		// �`���L�̔���
		result = ScissorsJudge();
		break;
	}

	if (result == "������")return true;
	return false;
}

// �O�[�̔���
const char* RockJudge()
{
	if (npcHand == Scissors)return "����";
	if (npcHand == Paper)return "����";
	return "������";
}

// �p�[�̔���
const char* PaperJudge()
{
	if (npcHand == Rock)return "����";
	if (npcHand == Scissors)return "����";
	return "������";
}

// �`���L�̔���
const char* ScissorsJudge()
{
	if (npcHand == Paper)return "����";
	if (npcHand == Rock)return "����";
	return "������";
}
