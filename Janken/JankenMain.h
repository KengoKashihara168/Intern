#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

////////////////// ����񂯂�Q�[�� //////////////////
void JankenMain();

/*----------�Q�[���֐�----------*/

void JankenInitialize();	 // ������
int  JankenUpdate();		 // �X�V
void JankenRender();		 // �`��
void JankenFinalize();		 // �I��