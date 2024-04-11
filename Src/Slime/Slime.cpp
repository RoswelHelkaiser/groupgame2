#include "DxLib.h"
#include "../Common.h"
#include "Slime.h"

SlimeInfo slimeInfo[SLIME_NUM] = { 0 }; //スライム情報構造体の宣言

int HandleIndex;	//画像ハンドル添え字用変数

int FrameNum;	//フレームカウント用変数

int Waiting;		//ループカウント用変数

void InitSlime()	//スライムの初期化
{
	SlimeInfo* slime = slimeInfo;	//スライム情報取得
	for (int i = 0; i < SLIME_NUM; i++, slime++)
	{
		slime->ImageHandle[0] = LoadGraph(SLIME_GREEN_PATH);	//スライム(緑)画像読み込み
		slime->ImageHandle[1] = LoadGraph(SLIME_RED_PATH);	//スライム(赤)画像読み込み
		slime->KindIndex = 0;	//添え字をリセット
		slime->PosX = 640.0f;	//初期X座標を設定
		slime->PosY = 360.0f;	//初期Y座標を設定
		slime->isDraw = false;	//描画フラグを折る
	}

	HandleIndex = 0;	//添え字を0にリセット

	FrameNum = 0;	//フレームカウントをリセット

	Waiting = 0;		//ループカウントをリセット
}

void StepSlime()	//スライム通常処理
{
	SlimeInfo* slime = slimeInfo;	//スライム情報取得
}

void DrawSlime()	//スライム描画処理
{
	SlimeInfo* slime = slimeInfo;	//スライム情報取得
	for (int i = 0; i < SLIME_NUM; i++, slime++)
	{
		if (slime->isDraw)	//描画フラグがtrueなら
		{
			DrawRotaGraph((int)slime->PosX, (int)slime->PosY,
						  1.0f, 0.0f, slime->ImageHandle[slime->KindIndex], true);	//スライム画像描画
		}
	}
}

void FinSlime()		//スライム後処理
{
	SlimeInfo* slime = slimeInfo;	//スライム情報取得
	for (int i = 0; i < SLIME_NUM; i++, slime++)
	{
		for (int j = 0; j < SLIME_KIND; j++)
		{
			DeleteGraph(slime->ImageHandle[j]);	//スライム画像破棄
		}
	}
}

void SpornSlime()	//スライムスポーン処理
{
	slimeInfo[HandleIndex].KindIndex = GetRand(1);			//スライムの種類をランダムに決める
	slimeInfo[HandleIndex].PosX = GetRand(600) + 328.0f;	//X座標をランダムにセット
	slimeInfo[HandleIndex].PosY = GetRand(400) + 200.0f;
	slimeInfo[HandleIndex].isDraw = true;	//描画フラグを立てる
	HandleIndex++;	//次のスライムにする
}

SlimeInfo* GetSlimeInfo()	//スライム情報取得
{
	return slimeInfo;
}