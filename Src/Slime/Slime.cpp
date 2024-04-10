#include "DxLib.h"
#include "../Common.h"
#include "Slime.h"

SlimeInfo slimeInfo[SLIME_NUM][SLIME_KIND] = { 0 }; //スライム情報構造体の宣言

int HandleIndex;	//画像ハンドル添え字用変数

int KindIndex;		//スライムの種類用変数

int FrameNum;	//フレームカウント用変数

int Wating;		//ループカウント用変数

void InitSlime()	//スライムの初期化
{
	for (int i = 0; i < SLIME_NUM; i++)
	{
		for (int j = 0; j < SLIME_KIND; j++)
		{
			slimeInfo[i][0].ImageHandle = LoadGraph(SLIME_GREEN_PATH);	//スライム(緑)画像読み込み
			slimeInfo[i][1].ImageHandle = LoadGraph(SLIME_RED_PATH);	//スライム(赤)画像読み込み
			slimeInfo[i][j].PosX = 640.0f;		//初期X座標を設定
			slimeInfo[i][j].PosY = 360.0f;		//初期Y座標を設定
			slimeInfo[i][j].isDraw = false;		//描画フラグを折る
		}
	}

	HandleIndex = 0;	//添え字を0にリセット

	KindIndex = 0;	//スライム(緑)を初期設定

	FrameNum = 0;	//フレームカウントをリセット

	Wating = 0;		//ループカウントをリセット
}

void StepSlime()	//スライム通常処理
{
	//if (Wating < 1)	//ループカウントが1より小さいなら
	//{
	//	FrameNum++;	//フレームカウントを増やす

	//	if (FrameNum > FRAME_RATE)	//フレームカウントが一定の値を超えたら
	//	{
	//		Wating++;	//ループカウントを増やす
	//		FrameNum = 0;	//フレームカウントをリセット
	//	}
	//}

	//else if (Wating >= 1)	//ループカウントが1以上になったら
	//{
	//}
}

void DrawSlime()	//スライム描画処理
{
	if (slimeInfo[HandleIndex][KindIndex].isDraw)	//描画フラグがtrueなら
	{
		DrawRotaGraph((int)slimeInfo[HandleIndex][KindIndex].PosX,
					  (int)slimeInfo[HandleIndex][KindIndex].PosY,
					  1.0f, 0.0f, slimeInfo[HandleIndex][KindIndex].ImageHandle, true);	//スライム画像描画
	}
}

void FinSlime()		//スライム後処理
{
	for (int i = 0; i < SLIME_NUM; i++)
	{
		for (int j = 0; j < SLIME_KIND; j++)
		{
			DeleteGraph(slimeInfo[i][j].ImageHandle);	//スライム画像破棄
		}
	}
}

void SpornSlime()	//スライムスポーン処理
{
	GetRand(1);		//スライムの種類をランダムに決める
	slimeInfo[HandleIndex][KindIndex].isDraw = true;	//描画フラグを立てる
	HandleIndex++;	//次のスライムにする
}