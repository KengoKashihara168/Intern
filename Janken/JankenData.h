#pragma once

enum RPS
{
	Rock,
	Paper,
	Scissors,
	RPS_MAX
};

/*----------�֐�----------*/

// �����_���Ȏ���擾
RPS RandomHand();
// ��𕶎���ɕϊ�
const char* GetHandText(RPS hand);
// ���͒l���ꂽ����擾
RPS InputHand(char input);

// ���ʔ���
bool Judge();

// �O�[�̔���
const char* RockJudge();
// �p�[�̔���
const char* PaperJudge();
// �`���L�̔���
const char* ScissorsJudge();

/*----------�ϐ�----------*/
RPS npcHand;
RPS playerHand;
const char* result;