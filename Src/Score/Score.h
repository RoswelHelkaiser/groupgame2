#pragma once

#define MAX_BONUS	(5)	//ボーナスの最大値
#define MINUS_NUM	(3)	//減点される量

enum NUMBER_IMAGE	//数字の種類
{
	NUMBER_0 = 0,	//0
	NUMBER_1,		//1
	NUMBER_2,		//2
	NUMBER_3,		//3
	NUMBER_4,		//4
	NUMBER_5,		//5
	NUMBER_6,		//6
	NUMBER_7,		//7
	NUMBER_8,		//8
	NUMBER_9,		//9

	NUMBER_NUM,
};

const char NumberImage_Path[NUMBER_NUM][100] =
{
	"Data/PlayImage/Text/0.png",	//0
	"Data/PlayImage/Text/1.png",	//1
	"Data/PlayImage/Text/2.png",	//2
	"Data/PlayImage/Text/3.png",	//3
	"Data/PlayImage/Text/4.png",	//4
	"Data/PlayImage/Text/5.png",	//5
	"Data/PlayImage/Text/6.png",	//6
	"Data/PlayImage/Text/7.png",	//7
	"Data/PlayImage/Text/8.png",	//8
	"Data/PlayImage/Text/9.png",	//9
};

struct ScoreInfo	//スコア情報構造体
{
	int ScoreHandle[NUMBER_NUM];	//数字画像ハンドル
	int CurrentScore;	//現在のスコア
	int ChainBonus;		//連続正解ボーナス
	int Minus;			//減点スコア
};

void InitScore();	//スコアの初期化

void DrawScore();	//スコア描画処理

void FinScore();	//スコア後処理

void LoadScore(NUMBER_IMAGE type);	//数字画像読み込み

ScoreInfo* GetScoreInfo();	//スコア情報取得

