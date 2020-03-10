#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

////////////////// じゃんけんゲーム //////////////////
void JankenMain();

/*----------ゲーム関数----------*/

void JankenInitialize();	 // 初期化
int  JankenUpdate();		 // 更新
void JankenRender();		 // 描画
void JankenFinalize();		 // 終了