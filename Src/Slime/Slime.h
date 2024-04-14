#pragma once

#define SLIME_NUM	(175)	//スライムのスポーン数
#define SLIME_KIND	(2)		//スライムの種類

enum GREEN_SLIME_IMAGE	//スライム(緑)画像の種類
{
	GREEN_SLIME_1 = 0,	//Green_Slime1
	GREEN_SLIME_2 ,		//Green_Slime2
	GREEN_SLIME_3 ,		//Green_Slime3
	GREEN_SLIME_4 ,		//Green_Slime4
	GREEN_SLIME_5 ,		//Green_Slime5

	GREEN_SLIME_NUM,
};

enum RED_SLIME_IMAGE	//スライム(赤)画像の種類
{
	RED_SLIME_1 = 0,	//Red_Slime1
	RED_SLIME_2,		//Red_Slime2
	RED_SLIME_3,		//Red_Slime3
	RED_SLIME_4,		//Red_Slime4
	RED_SLIME_5,		//Red_Slime5

	RED_SLIME_NUM,
};

const char GreenSlimeImage_Path[GREEN_SLIME_NUM][100] =	//スライム(緑)画像のパス
{
	"Data/PlayImage/Slime/Green_Slime1.png",	//Green_Slime1
	"Data/PlayImage/Slime/Green_Slime2.png",	//Green_Slime2
	"Data/PlayImage/Slime/Green_Slime3.png",	//Green_Slime3
	"Data/PlayImage/Slime/Green_Slime4.png",	//Green_Slime4
	"Data/PlayImage/Slime/Green_Slime5.png",	//Green_Slime5
};

const char RedSlimeImage_Path[RED_SLIME_NUM][100] =	//スライム(赤)画像のパス
{
	"Data/PlayImage/Slime/Red_Slime1.png",	//Green_Slime1
	"Data/PlayImage/Slime/Red_Slime2.png",	//Green_Slime2
	"Data/PlayImage/Slime/Red_Slime3.png",	//Green_Slime3
	"Data/PlayImage/Slime/Red_Slime4.png",	//Green_Slime4
	"Data/PlayImage/Slime/Red_Slime5.png",	//Green_Slime5
};

struct SlimeInfo	//スライム情報構造体
{
	int ImageHandle[10];	//画像ハンドル
	int KindIndex;		//スライムの種類用変数
	float PosX, PosY;	//X座標,Y座標
	bool isDraw;		//描画フラグ
	int AnimeFrame;		//アニメーション用変数
	bool isGoal;		//ゴール到達フラグ
};

void InitSlime();	//スライムの初期化

void StepSlime();	//スライム通常処理

void DrawSlime();	//スライム描画処理

void FinSlime();	//スライム後処理

void LoadGreenSlime(GREEN_SLIME_IMAGE type);	//スライム(緑)画像読み込み

void LoadRedSlime(RED_SLIME_IMAGE type);	//スライム(赤)画像読み込み

void SpornSlime();	//スライムスポーン処理

void ChangeSlime();	//スライムのアニメーション処理

void JudgeSlime();	//仕分けが合っているか判断

SlimeInfo* GetSlimeInfo();	//スライム情報取得
