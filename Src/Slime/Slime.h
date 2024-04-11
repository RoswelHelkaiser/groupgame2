#pragma once

#define SLIME_GREEN_PATH	("Data/PlayImage/Slime/SlimeGreen.png")	//スライム(緑)のパス
#define SLIME_RED_PATH		("Data/PlayImage/Slime/SlimeRed.png")	//スライム(赤)のパス
#define SLIME_NUM	(175)	//スライムのスポーン数
#define SLIME_KIND	(2)		//スライムの種類

struct SlimeInfo	//スライム情報構造体
{
	int ImageHandle[SLIME_KIND];	//画像ハンドル
	int KindIndex;		//スライムの種類用変数
	float PosX, PosY;	//X座標,Y座標
	bool isDraw;		//描画フラグ
};

void InitSlime();	//スライムの初期化

void StepSlime();	//スライム通常処理

void DrawSlime();	//スライム描画処理

void FinSlime();	//スライム後処理

void SpornSlime();	//スライムスポーン処理

SlimeInfo* GetSlimeInfo();	//スライム情報取得
