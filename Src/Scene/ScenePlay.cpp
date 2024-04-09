#include "DxLib.h"
#include "../Common.h"
#include "../Effect/Effect.h"
#include "../Input/Input.h"
#include "Scene.h"
#include "ScenePlay.h"

//フレームカウント用変数
int FrameCount;

//ループカウント用変数
int LoopCount;

//制限時間
int TimeLimit;

//制限時間を減らすフラグ
bool isMinusTime;

//クリアシーンに進むフラグ
bool isNextClear;

//プレイシーン初期化
void InitPlay()
{
	//フレームカウントをリセット
	FrameCount = 0;

	//ループカウントをリセット
	LoopCount = 0;

	//制限時間をリセット
	TimeLimit = 30;

	//制限時間減少フラグを折る
	isMinusTime = false;

	//クリアシーンに進むフラグを折る
	isNextClear = false;

	//プレイシーンループへ
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}

//プレイシーン通常処理
void StepPlay()
{
	//制限時間が残っていたら
	if (TimeLimit > 0)
	{
		//ループカウントが2より小さいなら
		if (LoopCount < 2)
		{
			//フレームカウントを増やす
			FrameCount++;

			//フレームカウントが一定の値を超えたら
			if (FrameCount > FRAME_RATE / 2)
			{
				LoopCount++;	//ループカウントを増やす
				FrameCount = 0;	//フレームカウントをリセット
			}
		}

		//ループカウントが2以上になったら
		else if (LoopCount >= 2)
		{
			//制限時間減少フラグを立てる
			isMinusTime = true;
		}

		//制限時間減少フラグがtrueなら
		if (isMinusTime)
		{
			TimeLimit--;	//制限時間を減らす
			LoopCount = 0;	//ループカウントをリセット
			isMinusTime = false;	//制限時間減少フラグを折る
		}
	}

	//制限時間がなくなったら
	if (TimeLimit <= 0)
	{
		//ループカウントが4より小さいなら
		if (LoopCount < 4)
		{
			//フレームカウントを増やす
			FrameCount++;

			//フレームカウントが一定の値を超えたら
			if (FrameCount > FRAME_RATE / 2)
			{
				LoopCount++;	//ループカウントを増やす
				FrameCount = 0;	//フレームカウントをリセット
			}
		}

		//ループカウントが4以上になったら
		else if (LoopCount >= 4)
		{
			//クリアシーンに進むフラグを立てる
			isNextClear = true;
		}

		//クリアシーンに進むフラグがtrueなら
		if (isNextClear)
		{
			//プレイシーン後処理へ移動
			g_CurrentSceneID = SCENE_ID_FIN_PLAY;
		}
	}
}

//プレイシーン描画処理
void DrawPlay()
{
	//制限時間描画
	DrawFormatString(600, 60, GetColor(255, 255, 255), "Time:%d", TimeLimit);
}

//プレイシーン後処理
void FinPlay()
{
	//クリアシーンへ移動
	g_CurrentSceneID = SCENE_ID_INIT_CLEAR;
}
