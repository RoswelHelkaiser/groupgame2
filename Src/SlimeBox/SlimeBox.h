#pragma once

#define GREEN_BOX_PATH	("Data/PlayImage/Slime/GreenSlimeBox.png")	//緑の箱画像のパス
#define RED_BOX_PATH	("Data/PlayImage/Slime/RedSlimeBox.png")	//赤の箱画像のパス

#define BOX_NUM	(2)	//箱の数

struct BoxInfo //箱情報構造体
{
	int BoxHandle[BOX_NUM];	//画像ハンドル
	float PosX, PosY;		//X座標,Y座標
};

void InitBox();	//箱の初期化

void DrawBox();	//箱描画処理

void FinBox();	//箱後処理

BoxInfo* GetBoxInfo();	//箱情報取得
