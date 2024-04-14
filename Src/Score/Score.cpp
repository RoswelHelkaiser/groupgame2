#include "DxLib.h"
#include "Score.h"

ScoreInfo scoreInfo = { 0 };	//スコア情報構造体の宣言

void InitScore()	//スコア初期化
{
	//LoadScore(NUMBER_0);	//0読み込み
	//LoadScore(NUMBER_1);	//1読み込み
	//LoadScore(NUMBER_2);	//2読み込み
	//LoadScore(NUMBER_3);	//3読み込み
	//LoadScore(NUMBER_4);	//4読み込み
	//LoadScore(NUMBER_5);	//5読み込み
	//LoadScore(NUMBER_6);	//6読み込み
	//LoadScore(NUMBER_7);	//7読み込み
	//LoadScore(NUMBER_8);	//8読み込み
	//LoadScore(NUMBER_9);	//9読み込み
	scoreInfo.CurrentScore = 0;	//現在のスコア
	scoreInfo.ChainBonus = 0;		//連続正解ボーナス
	scoreInfo.Minus = MINUS_NUM;	//減点スコア
}

void DrawScore()	//スコア描画処理
{
	int Score = scoreInfo.CurrentScore;	//スコアを仮置き変数に代入
	int count = 0;	//カウント用変数
	//while(Score > 0)	//スコアが0より大きいなら
	//{
		int num = Score % 10;	//数字の添え字を決める
		Score /= 10;	//スコアを10で割る
		DrawGraph(450 - count * 10, 0, scoreInfo.ScoreHandle[num], true);
		count++;	//カウントを増やす
	//}

		DrawFormatString(0, 0, GetColor(255, 255, 255), "%d", scoreInfo.CurrentScore);
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
