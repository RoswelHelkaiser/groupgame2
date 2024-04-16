#include "DxLib.h"
#include "../Collision/Collision.h"
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

int ScorePosX,ScorePosY;	//スコア数字Y座標

int CountFrame;		//フレームカウント用変数

int GetScoreHandle[6];	//スコア数字画像ハンドル

int GetScoreIndex;	//スコア数字添え字用変数

bool isGetScoreDraw;	//スコア数字描画フラグ

int SoundHandle[2];	//効果音ハンドル

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
		green->PosY = 150.0f;	//初期Y座標を設定
		green->isDraw = false;	//描画フラグを折る
		green->AnimeFrame = 0;	//アニメフレームをリセット
		green->isGoal = false;	//ゴール到達フラグを折る
	}

	for (int i = 0; i < SLIME_NUM; i++, red++)
	{
		red->KindIndex = 0;		//添え字をリセット
		red->PosX = 640.0f;		//初期X座標を設定
		red->PosY = 150.0f;		//初期Y座標を設定
		red->isDraw = false;	//描画フラグを折る
		red->AnimeFrame = 0;	//アニメフレームをリセット
		red->isGoal = false;	//ゴール到達フラグを折る
	}

	HandleIndex = 0;	//添え字を0にリセット

	ColorType = 0;	//0なら緑,1なら赤

	GetScoreHandle[0] = LoadGraph(PLUS_1_PATH);	 //「+1」画像読み込み
	GetScoreHandle[1] = LoadGraph(PLUS_2_PATH);	 //「+2」画像読み込み
	GetScoreHandle[2] = LoadGraph(PLUS_3_PATH);	 //「+3」画像読み込み
	GetScoreHandle[3] = LoadGraph(PLUS_4_PATH);	 //「+4」画像読み込み
	GetScoreHandle[4] = LoadGraph(PLUS_5_PATH);	 //「+5」画像読み込み
	GetScoreHandle[5] = LoadGraph(MINUS_3_PATH); //「-3」画像読み込み

	ScorePosX = 0;		//X座標を設定
	ScorePosY = 450;	//Y座標を設定

	SoundHandle[0] = LoadSoundMem(CORRECT_SOUND_PATH);	//正解効果音読み込み
	SoundHandle[1] = LoadSoundMem(WRONG_SOUND_PATH);	//不正解効果音読み込み
}

void StepSlime()	//スライム通常処理
{
	SlimeInfo* green = greenslimeInfo;	//スライム(緑)情報取得
	SlimeInfo* red = redslimeInfo;	//スライム(赤)情報取得

	ChangeSlime(); //スライムのアニメーション処理
	GetMousePoint(&MouseX, &MouseY);	//マウスカーソルの位置を取得

	for (int i = 0; i < SLIME_NUM; i++, green++)
	{
		green->PosY += SLIME_SPEED;	//Y座標を下に動かす

		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)	//マウスの左ボタンが押されているなら
		{
			if (green->PosX - 50.0f < MouseX && MouseX < green->PosX + 50.0f)	//X軸方向でカーソルがスライムと当たっているなら
			{
				if (green->PosY - 50.0f < MouseY && MouseY < green->PosY + 50.0f)	//Y軸方向でカーソルがスライムと当たっているなら
				{
					green->PosX = (float)MouseX;	//X座標をカーソルに合わせる
					green->PosY = (float)MouseY;	//Y座標をカーソルに合わせる
				}
			}
		}
	}
	

	for (int i = 0; i < SLIME_NUM; i++, red++)
	{
		red->PosY += SLIME_SPEED;	//Y座標を下に動かす

		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)	//マウスの左ボタンが押されているなら
		{
			if (red->PosX - 50.0f < MouseX && MouseX < red->PosX + 50.0f)	//X軸方向でカーソルがスライムと当たっているなら
			{
				if (red->PosY - 50.0f < MouseY && MouseY < red->PosY + 50.0f)	//Y軸方向でカーソルがスライムと当たっているなら
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

	if (isGetScoreDraw)	//スコア数字描画フラグがtrueなら
	{
		DrawRotaGraph(ScorePosX, ScorePosY, 1.0f, 0.0f, GetScoreHandle[GetScoreIndex], true);	//スコア数字描画
		ScorePosY -= 5;	//Y座標を上に移動
		CountFrame++;	//フレームカウントを増やす
	}

	if (CountFrame >= FRAME_RATE / 2)	//フレームカウントが一定の値に達したら
	{
		isGetScoreDraw = false;	//スコア数字描画フラグを折る
		ScorePosY = 450;	//Y座標を元に戻す
		CountFrame = 0;	//フレームカウントをリセット
	}

	DrawFormatString(0, 0, GetColor(255, 255, 255), "%d", ColorType);
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

	for (int i = 0; i < 6; i++)
	{
		DeleteGraph(GetScoreHandle[i]);	//スコア数字画像破棄
	}

	for (int i = 0; i < 2; i++)
	{
		DeleteSoundMem(SoundHandle[i]);	//効果音破棄
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
			greenslimeInfo[HandleIndex].PosX = GetRand(200) + 500.0f;	//X座標をランダムにセット
			greenslimeInfo[HandleIndex].PosY = 150.0f;	//Y座標をセット
			greenslimeInfo[HandleIndex].isDraw = true;	//描画フラグを立てる
			redslimeInfo[HandleIndex].isDraw = false;	//描画フラグを折る
		}
		break;

		case 1:	//赤なら
		{
			redslimeInfo[HandleIndex].PosX = GetRand(200) + 500.0f;	//X座標をランダムにセット
			redslimeInfo[HandleIndex].PosY = 150.0f;	//Y座標をセット
			redslimeInfo[HandleIndex].isDraw = true;	//描画フラグを立てる
			greenslimeInfo[HandleIndex].isDraw = false;	//描画フラグを折る
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

void JudgeGreenSlime()	//スライム(緑)の仕分けが合っているか判断
{
	BoxInfo* boxInfo = GetBoxInfo();	//箱情報取得
	ScoreInfo* scoreInfo = GetScoreInfo();	//スコア情報取得
	SlimeInfo* green = greenslimeInfo;	//スライム(緑)情報取得
	SlimeInfo* red = redslimeInfo;	//スライム(赤)情報取得
	for (int i = 0; i < SLIME_NUM; i++, green++)
	{		
		//円形の当たり判定用データを用意
		float Ax = green->PosX;
		float Ay = green->PosY;
		int Ar = 32;

		float Bx = boxInfo[0].PosX;
		float By = boxInfo[0].PosY;
		float B2x = boxInfo[1].PosX;
		float B2y = boxInfo[1].PosY;
		int Br = 200;

		if (IsHitCircle((int)Ax, (int)Ay, Ar, (int)Bx, (int)By, Br))	//緑の箱とスライム(緑)が当たっているなら
		{
			if (!green->isGoal)	//ゴール到達フラグがfalseなら
			{
				if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)	//マウスの左ボタンが押されているなら
				{
					PlaySoundMem(SoundHandle[0], DX_PLAYTYPE_BACK, true);	//正解効果音再生
					scoreInfo->CurrentScore += scoreInfo->ChainBonus;	//スコアを加算
					ScorePosX = 200;	//スコア数字X座標を設定
					GetScoreIndex = scoreInfo->ChainBonus - 1;	//スコア数字の添え字を設定
					if (GetScoreIndex >= 4)
					{
						GetScoreIndex = 4;
					}
					scoreInfo->ChainBonus++;	//ボーナスを加算
					isGetScoreDraw = true;	//スコア数字の描画フラグを立てる
					green->isGoal = true;	//ゴール到達フラグを立てる
					green->isDraw = false;	//描画フラグを折る
				}
			}
		}

		else if (IsHitCircle((int)Ax, (int)Ay, Ar, (int)B2x, (int)B2y, Br))	//赤の箱とスライム(緑)が当たっているなら
		{
			if (!green->isGoal)	//ゴール到達フラグがfalseなら
			{
				if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)	//マウスの左ボタンが押されているなら
				{
					PlaySoundMem(SoundHandle[1], DX_PLAYTYPE_BACK, true);	//不正解効果音再生
					scoreInfo->CurrentScore -= scoreInfo->Minus;	//スコアを減算
					scoreInfo->ChainBonus = 1;	//ボーナスをリセット	
					ScorePosX = 1080;	//スコア数字X座標を設定
					GetScoreIndex = 5;		//スコア数字の添え字を設定
					isGetScoreDraw = true;	//スコア数字の描画フラグを立てる
					green->isGoal = true;	//ゴール到達フラグを立てる
					green->isDraw = false;	//描画フラグを折る
				}
			}
		}
	}	
}

void JudgeRedSlime()	//スライム(赤)の仕分けが合っているか判断
{
	BoxInfo* boxInfo = GetBoxInfo();	//箱情報取得
	ScoreInfo* scoreInfo = GetScoreInfo();	//スコア情報取得
	SlimeInfo* red = redslimeInfo;	//スライム(赤)情報取得
	SlimeInfo* green = greenslimeInfo;	//スライム(緑)情報取得
	for (int i = 0; i < SLIME_NUM; i++, red++)
	{	
		//円形の当たり判定用データを用意
		float Ax = red->PosX;
		float Ay = red->PosY;
		int Ar = 32;

		float Bx = boxInfo[0].PosX;
		float By = boxInfo[0].PosY;
		float B2x = boxInfo[1].PosX;
		float B2y = boxInfo[1].PosY;
		int Br = 200;

		if (IsHitCircle((int)Ax, (int)Ay, Ar, (int)Bx, (int)By, Br))	//緑の箱とスライム(赤)が当たっているなら
		{
			if (!red->isGoal)	//ゴール到達フラグがfalseなら
			{
				if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)	//マウスの左ボタンが押されているなら
				{
					PlaySoundMem(SoundHandle[1], DX_PLAYTYPE_BACK, true);	//不正解効果音再生
					scoreInfo->CurrentScore -= scoreInfo->Minus;	//スコアを減算
					scoreInfo->ChainBonus = 1;	//ボーナスをリセット
					ScorePosX = 200;	//スコア数字X座標を設定
					GetScoreIndex = 5;		//スコア数字の添え字を設定
					isGetScoreDraw = true;	//スコア数字の描画フラグを立てる
					red->isGoal = true;	//ゴール到達フラグを立てる
					red->isDraw = false;	//描画フラグを折る
				}
			}
		}

		else if (IsHitCircle((int)Ax, (int)Ay, Ar, (int)B2x, (int)B2y, Br))	//赤の箱とスライム(赤)が当たっているなら
		{
			if (!red->isGoal)	//ゴール到達フラグがfalseなら
			{
				if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)	//マウスの左ボタンが押されているなら
				{
					PlaySoundMem(SoundHandle[0], DX_PLAYTYPE_BACK, true);	//正解効果音再生
					scoreInfo->CurrentScore += scoreInfo->ChainBonus;	//スコアを加算
					ScorePosX = 1080;	//スコア数字X座標を設定
					GetScoreIndex = scoreInfo->ChainBonus - 1;	//スコア数字の添え字を設定
					if (GetScoreIndex >= 4)
					{
						GetScoreIndex = 4;
					}
					scoreInfo->ChainBonus++;	//ボーナスを加算
					isGetScoreDraw = true;	//スコア数字の描画フラグを立てる
					red->isGoal = true;	//ゴール到達フラグを立てる
					red->isDraw = false;	//描画フラグを折る
				}
			}
		}		
	}
}

SlimeInfo* GetSlimeInfo()	//スライム情報取得
{
	return greenslimeInfo;
	return redslimeInfo;
}