#pragma once

enum RPS
{
	Rock,	 // �O�[
	Paper,	 // �p�[
	Scissors,// �`���L
	RPS_MAX	 // �R
};

/*----------�֐�----------*/

// �����_���Ȏ���擾
RPS RandomHand();
// ��𕶎���ɕϊ�
const char* GetHandText(RPS hand);
// ���͂��ꂽ�������`�F�b�N
int CheckInput(char input);
// ���͒l���ꂽ����擾
RPS InputHand(char input);

// ���ʔ���
int Judge();

// �O�[�̔���
void RockJudge();
// �p�[�̔���
void PaperJudge();
// �`���L�̔���
void ScissorsJudge();

/*----------�ϐ�----------*/

RPS npcHand;
RPS playerHand;
const char* result;

/*-------�}�N���萔-------*/

#define IS_ROCK(input)		 input == 'g' ||  input == 'r'
#define IS_SCISSORS(input)	 input == 'c' || input == 's'
#define IS_PAPER(input)		 input == 'p'

#define WIN "�����I"
#define LOSE "����..."
#define DRAW "�������Łc"