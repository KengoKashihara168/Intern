#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

////////////////// ����񂯂�Q�[�� //////////////////
void JankenMain();

/*----------�Q�[���֐�----------*/

void Initialize();	 // ������
bool Update();		 // �X�V
void Render();		 // �`��
void Finalize();	 // �I��