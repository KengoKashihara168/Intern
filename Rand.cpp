#include"Rand.h"
#include<stdlib.h>
#include<time.h>

// min����max�܂ł̐����^�������擾
int GetRand(int min, int max)
{
	if (min < 0)min = 0;				// �ŏ��l�͂O
	if (max > RAND_MAX)max = RAND_MAX;	// �ő�l��32767

	static bool randFlag = true; // �V�[�h�l�����̂ݐݒ肷�邽�߂̃t���O
	if (randFlag)
	{
		// ���ݎ����ŃV�[�h�l��ݒ�
		srand((unsigned int)time(NULL));
		randFlag = false;
	}

	return rand() % (max + 1 - min) + min;
}

// 0����max�܂ł̐����^�������擾
int GetRand(int max)
{
	if (max > RAND_MAX)max = RAND_MAX;	// �ő�l��32767

	static bool randFlag = true; // �V�[�h�l�����̂ݐݒ肷�邽�߂̃t���O
	if (randFlag)
	{
		// ���ݎ����ŃV�[�h�l��ݒ�
		srand((unsigned int)time(NULL));
		randFlag = false;
	}

	return rand() % (max + 1);
}

