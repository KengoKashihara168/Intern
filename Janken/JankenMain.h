#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

////////////////// じゃんけんゲーム //////////////////
void JankenMain();

/*----------ゲーム関数----------*/

void Initialize();	 // 初期化
bool Update();		 // 更新
void Render();		 // 描画
void Finalize();	 // 終了