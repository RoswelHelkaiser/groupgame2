#include "DxLib.h"
#include "../Common.h"
#include "../Effect/Effect.h"
#include "../Input/Input.h"
#include "Scene.h"
#include "ScenePlay.h"

Text text;	//文字クラスの宣言

int FrameCount;	//フレームカウント用変数

int LoopCount;	//ループカウント用変数

int TimeLimit;	//制限時間

bool isMinusTime;	//制限時間を減らすフラグ

bool isNextClear;	//クリアシーンに進むフラグ

void InitPlay()	//プレイシーン初期化
{
	text.InitText();	//文字の初期化

	FrameCount = 0;		//フレームカウントをリセット

	LoopCount = 0;		//ループカウントをリセット

	TimeLimit = TIME_MAX_NUM;	//制限時間をリセット

	isMinusTime = false;	//制限時間減少フラグを折る

	isNextClear = false;	//クリアシーンに進むフラグを折る

	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;	//プレイシーンループへ
}

void StepPlay()	//プレイシーン通常処理
{
	text.StepText();	//文字通常処理

	if (text.isStart)	//ゲームを進ませるフラグがtrueなら
	{
		if (TimeLimit > 0)	//制限時間が残っていたら
		{
			if (LoopCount < 1)	//ループカウントが1より小さいなら
			{
				FrameCount++;	//フレームカウントを増やす

				if (FrameCount > FRAME_RATE)	//フレームカウントが一定の値を超えたら
				{
					LoopCount++;	//ループカウントを増やす
					FrameCount = 0;	//フレームカウントをリセット
				}
			}

			else if (LoopCount >= 1)	//ループカウントが1以上になったら
			{
				isMinusTime = true;		//制限時間減少フラグを立てる
			}

			if (isMinusTime)	//制限時間減少フラグがtrueなら
			{
				TimeLimit--;	//制限時間を減らす
				LoopCount = 0;	//ループカウントをリセット
				isMinusTime = false;	//制限時間減少フラグを折る
			}
		}
	}	

	if (TimeLimit <= 0)	//制限時間がなくなったら
	{
		text.HandleIndex = 2;	//「Finish!」にする
		text.isDraw = true;		//描画フラグを立てる
		text.Size = 3.0f;		//大きさを3倍にする

		if (LoopCount < 2)	//ループカウントが2より小さいなら
		{
			FrameCount++;	//フレームカウントを増やす

			if (FrameCount > FRAME_RATE)	//フレームカウントが一定の値を超えたら
			{
				LoopCount++;	//ループカウントを増やす
				FrameCount = 0;	//フレームカウントをリセット
			}
		}

		else if (LoopCount >= 2)	//ループカウントが2以上になったら
		{
			isNextClear = true;		//クリアシーンに進むフラグを立てる
		}

		if (isNextClear)	//クリアシーンに進むフラグがtrueなら
		{
			g_CurrentSceneID = SCENE_ID_FIN_PLAY;	//プレイシーン後処理へ移動
		}
	}
}

void DrawPlay()	//プレイシーン描画処理
{
	DrawFormatString(600, 60, GetColor(255, 255, 255), "Time:%d", TimeLimit);	//制限時間描画

	text.DrawTextImage();	//文字描画処理
}

//プレイシーン後処理
void FinPlay()
{
	text.FinText();	//文字後処理

	g_CurrentSceneID = SCENE_ID_INIT_CLEAR;	//クリアシーンへ移動
}
