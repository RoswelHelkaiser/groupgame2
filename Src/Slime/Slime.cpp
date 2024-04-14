#include "DxLib.h"
#include "../Common.h"
#include "../Input/Input.h"
#include "Slime.h"
#include "../SlimeBox/SlimeBox.h"
#include "../Score/Score.h"

SlimeInfo greenslimeInfo[SLIME_NUM] = { 0 }; //スライム(緑)情報構造体の宣言

SlimeInfo redslimeInfo[SLIME_NUM] = { 0 }; //スライム(赤)情報構造体の宣言

int HandleIndex;	//画像ハンドル添え字用変数

int ColorType;	//スライムの色

int MouseX, MouseY;	//マウスカーソルのX座標,Y座標

void InitSlime()	//スライムの初期化
{
	SlimeInfo* green = greenslimeInfo;	//スライム(緑)情報取得
	SlimeInfo* red = redslimeInfo;	//スライム(赤)情報取得

	//スライム(緑)画像読み込み
	LoadGreenSlime(GREEN_SLIME_1);	//Green_Slime1
	LoadGreenSlime(GREEN_SLIME_2);	//Green_Slime2
	LoadGreenSlime(GREEN_SLIME_3);	//Green_Slime3
	LoadGreenSlime(GREEN_SLIME_4);	//Green_Slime4
	LoadGreenSlime(GREEN_SLIME_5);	//Green_Slime5

	//スライム(赤)画像読み込み
	LoadRedSlime(RED_SLIME_1);	//Red_Slime1
	LoadRedSlime(RED_SLIME_2);	//Red_Slime2
	LoadRedSlime(RED_SLIME_3);	//Red_Slime3
	LoadRedSlime(RED_SLIME_4);	//Red_Slime4
	LoadRedSlime(RED_SLIME_5);	//Red_Slime5

	for (int i = 0; i < SLIME_NUM; i++, green++)
	{
		green->KindIndex = 0;	//添え字をリセット
		green->PosX = 640.0f;	//初期X座標を設定
		green->PosY = 360.0f;	//初期Y座標を設定
		green->isDraw = false;	//描画フラグを折る
		green->AnimeFrame = 0;	//アニメフレームをリセット
		green->isGoal = false;	//ゴール到達フラグを折る
	}

	for (int i = 0; i < SLIME_NUM; i++, red++)
	{
		red->KindIndex = 0;		//添え字をリセット
		red->PosX = 640.0f;		//初期X座標を設定
		red->PosY = 360.0f;		//初期Y座標を設定
		red->isDraw = false;	//描画フラグを折る
		red->AnimeFrame = 0;	//アニメフレームをリセット
		red->isGoal = false;	//ゴール到達フラグを折る
	}

	HandleIndex = 0;	//添え字を0にリセット

	ColorType = 0;	//0なら緑,1なら赤
}

void StepSlime()	//スライム通常処理
{
	SlimeInfo* green = greenslimeInfo;	//スライム(緑)情報取得
	SlimeInfo* red = redslimeInfo;	//スライム(赤)情報取得

	ChangeSlime(); //スライムのアニメーション処理
	GetMousePoint(&MouseX, &MouseY);	//マウスカーソルの位置を取得

	for (int i = 0; i < SLIME_NUM; i++, green++)
	{
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)	//マウスの左ボタンが押されているなら
		{
			if (green->PosX - 45.0f < MouseX && MouseX < green->PosX + 45.0f)	//X軸方向でカーソルがスライムと当たっているなら
			{
				if (green->PosY - 45.0f < MouseY && MouseY < green->PosY + 45.0f)	//Y軸方向でカーソルがスライムと当たっているなら
				{
					green->PosX = (float)MouseX;	//X座標をカーソルに合わせる
					green->PosY = (float)MouseY;	//Y座標をカーソルに合わせる
				}
			}
		}
	}

	for (int i = 0; i < SLIME_NUM; i++, red++)
	{
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)	//マウスの左ボタンが押されているなら
		{
			if (red->PosX - 45.0f < MouseX && MouseX < red->PosX + 45.0f)	//X軸方向でカーソルがスライムと当たっているなら
			{
				if (red->PosY - 45.0f < MouseY && MouseY < red->PosY + 45.0f)	//Y軸方向でカーソルがスライムと当たっているなら
				{
					red->PosX = (float)MouseX;	//X座標をカーソルに合わせる
					red->PosY = (float)MouseY;	//Y座標をカーソルに合わせる
				}
			}
		}
	}
}

void DrawSlime()	//スライム描画処理
{
	SlimeInfo* green = greenslimeInfo;	//スライム(緑)情報取得
	for (int i = 0; i < SLIME_NUM; i++, green++)
	{
		if (green->isDraw)	//描画フラグがtrueなら
		{
			DrawRotaGraph((int)green->PosX, (int)green->PosY,
						  1.0f, 0.0f, greenslimeInfo[HandleIndex].ImageHandle[green->KindIndex], true);	//スライム画像描画
		}
	}

	SlimeInfo* red = redslimeInfo;	//スライム(赤)情報取得
	for (int i = 0; i < SLIME_NUM; i++, red++)
	{
		if (red->isDraw)	//描画フラグがtrueなら
		{
			DrawRotaGraph((int)red->PosX, (int)red->PosY,
						  1.0f, 0.0f, redslimeInfo[HandleIndex].ImageHandle[red->KindIndex], true);	//スライム画像描画
		}
	}
}

void FinSlime()		//スライム後処理
{
	SlimeInfo* green = greenslimeInfo;	//スライム(緑)情報取得
	for (int i = 0; i < SLIME_NUM; i++, green++)
	{
		for (int j = 0; j < SLIME_KIND; j++)
		{
			DeleteGraph(green->ImageHandle[j]);	//スライム(緑)画像破棄
		}
	}

	SlimeInfo* red = redslimeInfo;	//スライム(赤)情報取得
	for (int i = 0; i < SLIME_NUM; i++, red++)
	{
		for (int j = 0; j < SLIME_KIND; j++)
		{
			DeleteGraph(red->ImageHandle[j]);	//スライム(赤)画像破棄
		}
	}
}

void LoadGreenSlime(GREEN_SLIME_IMAGE type)	//スライム(緑)画像読み込み
{
	SlimeInfo* green = greenslimeInfo;	//スライム(緑)情報取得
	for (int i = 0; i < SLIME_NUM; i++, green++)
	{
		green->ImageHandle[type] = LoadGraph(GreenSlimeImage_Path[type]);
	}
}

void LoadRedSlime(RED_SLIME_IMAGE type)	//スライム(赤)画像読み込み
{
	SlimeInfo* red = redslimeInfo;	//スライム(赤)情報取得
	for (int i = 0; i < SLIME_NUM; i++, red++)
	{
		red->ImageHandle[type] = LoadGraph(RedSlimeImage_Path[type]);
	}
}

void SpornSlime()	//スライムスポーン処理
{
	ColorType = GetRand(1);	//0か1を取得
	switch (ColorType)	//色で場合分け
	{
		case 0:	//緑なら
		{
			greenslimeInfo[HandleIndex].PosX = GetRand(400) + 400.0f;	//X座標をランダムにセット
			greenslimeInfo[HandleIndex].PosY = GetRand(400) + 200.0f;	//Y座標をランダムにセット
			greenslimeInfo[HandleIndex].isDraw = true;	//描画フラグを立てる
		}
		break;

		case 1:	//赤なら
		{
			redslimeInfo[HandleIndex].PosX = GetRand(400) + 400.0f;	//X座標をランダムにセット
			redslimeInfo[HandleIndex].PosY = GetRand(400) + 200.0f;	//Y座標をランダムにセット
			redslimeInfo[HandleIndex].isDraw = true;	//描画フラグを立てる
		}
		break;
	}

	HandleIndex++;	//次のスライムにする
}

void ChangeSlime()	//スライムのアニメーション処理
{
	SlimeInfo* green = greenslimeInfo;	//スライム(緑)情報取得
	for (int i = 0; i < SLIME_NUM; i++, green++)
	{
		green->AnimeFrame++;	//再生時間をカウント
		if (green->AnimeFrame >= FRAME_RATE / 2)	//一定の時間に達したら
		{
			green->AnimeFrame = 0;	//再生時間をリセット

			if (green->KindIndex == 4)	//最後の画像なら
			{
				green->KindIndex = 0;	//最初の画像にする
			}
			else	//最後の画像でないなら
			{
				green->KindIndex++;		//次の画像に切り替える
			}
		}
	}

	SlimeInfo* red = redslimeInfo;	//スライム(赤)情報取得
	for (int i = 0; i < SLIME_NUM; i++, red++)
	{
		red->AnimeFrame++;	//再生時間をカウント
		if (red->AnimeFrame >= FRAME_RATE / 2)	//一定の時間に達したら
		{
			red->AnimeFrame = 0;	//再生時間をリセット

			if (red->KindIndex == 4)	//最後の画像なら
			{
				red->KindIndex = 0;	//最初の画像にする
			}
			else	//最後の画像でないなら
			{
				red->KindIndex++;		//次の画像に切り替える
			}
		}
	}
}

void JudgeSlime()	//仕分けが合っているか判断
{
	BoxInfo* boxInfo = GetBoxInfo();	//箱情報取得
	ScoreInfo* scoreInfo = GetScoreInfo();	//スコア情報取得
	switch (ColorType)	//色で場合分け
	{
		case 0:	//緑なら
		{
			SlimeInfo* green = greenslimeInfo;	//スライム(緑)情報取得
			for (int i = 0; i < SLIME_NUM; i++, green++)
			{
				if ((GetMouseInput() & MOUSE_INPUT_LEFT) == 0)	//マウスの左ボタンが離されたら
				{
					if (green->PosX < boxInfo[0].PosX - 200.0f && boxInfo[0].PosX + 200.0f < green->PosX)	//X軸方向に緑の箱とスライム(緑)が当たっているなら
					{
						if (green->PosY < boxInfo[0].PosY - 150.0f && boxInfo[0].PosX + 200.0f < green->PosY)	//Y軸方向に緑の箱とスライム(緑)が当たっているなら
						{
							scoreInfo->CurrentScore += scoreInfo->ChainBonus;	//スコアを加算
							scoreInfo->ChainBonus++;	//ボーナスを加算
							green->isGoal = true;	//ゴール到達フラグを立てる
							green->isDraw = false;	//描画フラグを折る
						}
					}
					else if (green->PosX < boxInfo[1].PosX - 200.0f && boxInfo[1].PosX + 200.0f < green->PosX)	//X軸方向に赤の箱とスライム(緑)が当たっているなら
					{
						if (green->PosY < boxInfo[1].PosY - 150.0f && boxInfo[1].PosX + 200.0f < green->PosY)	//Y軸方向に赤の箱とスライム(緑)が当たっているなら
						{
							scoreInfo->CurrentScore -= scoreInfo->Minus;	//スコアを減算
							green->isGoal = true;	//ゴール到達フラグを立てる
							green->isDraw = false;	//描画フラグを折る
						}
					}
				}
			}
		}
		break;

		case 1:	//赤なら
		{
			SlimeInfo* red = redslimeInfo;	//スライム(赤)情報取得
			for (int i = 0; i < SLIME_NUM; i++, red++)
			{
				if ((GetMouseInput() & MOUSE_INPUT_LEFT) == 0)	//マウスの左ボタンが離されたら
				{
					if (red->PosX < boxInfo[0].PosX - 200.0f && boxInfo[0].PosX + 200.0f < red->PosX)	//X軸方向に緑の箱とスライム(赤)が当たっているなら
					{
						if (red->PosY < boxInfo[0].PosY - 150.0f && boxInfo[0].PosX + 200.0f < red->PosY)	//Y軸方向に緑の箱とスライム(赤)が当たっているなら
						{
							scoreInfo->CurrentScore -= scoreInfo->Minus;	//スコアを減算
							red->isGoal = true;	//ゴール到達フラグを立てる
							red->isDraw = false;	//描画フラグを折る
						}
					}
					else if (red->PosX < boxInfo[1].PosX - 200.0f && boxInfo[1].PosX + 200.0f < red->PosX)	//X軸方向に赤の箱とスライム(赤)が当たっているなら
					{
						if (red->PosY < boxInfo[1].PosY - 150.0f && boxInfo[1].PosX + 200.0f < red->PosY)	//Y軸方向に赤の箱とスライム(赤)が当たっているなら
						{
							scoreInfo->CurrentScore += scoreInfo->ChainBonus;	//スコアを加算
							scoreInfo->ChainBonus++;	//ボーナスを加算
							red->isGoal = true;	//ゴール到達フラグを立てる
							red->isDraw = false;	//描画フラグを折る
						}
					}
				}
			}
		}
		break;
	}
}

SlimeInfo* GetSlimeInfo()	//スライム情報取得
{
	return greenslimeInfo;
	return redslimeInfo;
}