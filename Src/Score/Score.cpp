#include "DxLib.h"
#include "Score.h"

ScoreInfo scoreInfo = { 0 };	//スコア情報構造体の宣言

void InitScore()	//スコア初期化
{
	LoadScore(NUMBER_0);	//0読み込み
	LoadScore(NUMBER_1);	//1読み込み
	LoadScore(NUMBER_2);	//2読み込み
	LoadScore(NUMBER_3);	//3読み込み
	LoadScore(NUMBER_4);	//4読み込み
	LoadScore(NUMBER_5);	//5読み込み
	LoadScore(NUMBER_6);	//6読み込み
	LoadScore(NUMBER_7);	//7読み込み
	LoadScore(NUMBER_8);	//8読み込み
	LoadScore(NUMBER_9);	//9読み込み
	scoreInfo.CurrentScore = 0;	//現在のスコア
	scoreInfo.ChainBonus = 1;		//連続正解ボーナス
	scoreInfo.Minus = MINUS_NUM;	//減点スコア
}

void StepScore()	//スコア通常処理
{
	if (scoreInfo.ChainBonus >= MAX_BONUS)	//ボーナス得点が最大値を超えたら
	{
		scoreInfo.ChainBonus = MAX_BONUS;	//ボーナス得点を最大値にする
	}
}

void DrawScore()	//スコア描画処理
{
	DrawFormatString(600, 90, GetColor(255, 255, 255), "Score:%d", scoreInfo.CurrentScore);
}

void FinScore()		//スコア後処理
{
	for (int i = 0; i < NUMBER_NUM; i++)
	{
		DeleteGraph(scoreInfo.ScoreHandle[i]);	//数字画像破棄
	}
}

void LoadScore(NUMBER_IMAGE type)	//数字画像読み込み
{
	scoreInfo.ScoreHandle[type] = LoadGraph(NumberImage_Path[type]);
}

ScoreInfo* GetScoreInfo()	//スコア情報取得
{
	return &scoreInfo;
}
