#include "DxLib.h"
#include "Scene.h"
#include "SceneClear.h"

int ClearImage;	//クリア背景画像ハンドル

int ResultImage;	//リザルト文字画像ハンドル

int TextImage;	//「まだやる？」画像ハンドル

int ContinueImage;	//「もっかい！」画像ハンドル

int BackTitleImage;	//「もういいかな」画像ハンドル

int CursorImage;	//矢印画像ハンドル

int CursorPosY;		//矢印画像Y座標

bool isContinue;	//コンテニューフラグ

bool isBackTitle;	//タイトルフラグ

void InitClear()	//クリア初期化
{
	ClearImage = LoadGraph(BACK_CLEAR_PATH);	//クリア背景画像読み込み

	ResultImage = LoadGraph(RESULT_PATH);	//リザルト文字画像読み込み

	TextImage = LoadGraph(TEXT_PATH);	//「まだやる？」画像読み込み

	ContinueImage = LoadGraph(CONTINUE_PATH);	//「もっかい！」画像読み込み

	BackTitleImage = LoadGraph(BACK_TITLE_PATH);	//「もういいかな」画像読み込み

	CursorImage = LoadGraph(CURSOR_PATH);	//矢印画像読み込み

	CursorPosY = 500;	//矢印の初期Y座標を設定

	isContinue = false;		//コンテニューフラグを折る

	isBackTitle = false;	//タイトルフラグを折る

	g_CurrentSceneID = SCENE_ID_LOOP_CLEAR;	//クリアループへ移動
}

void StepClear()	//クリア通常処理
{
	if (IsKeyPush(KEY_INPUT_W) || IsKeyPush(KEY_INPUT_UP))	//Wキーまたは上矢印キーが押されたら
	{
		if (CursorPosY == 600)	//「もういいかな」の隣なら
		{
			CursorPosY = 500;	//「もっかい！」の隣に移動する
		}
	}

	else if (IsKeyPush(KEY_INPUT_S) || IsKeyPush(KEY_INPUT_DOWN))	//Sキーまたは下矢印キーが押されたら
	{
		if (CursorPosY == 500)	//「もっかい！」の隣なら
		{
			CursorPosY = 600;	//「もういいかな」の隣に移動する
		}
	}

	if (IsKeyPush(KEY_INPUT_RETURN))	//エンターキーを押すと
	{
		if (CursorPosY == 500)	//「もっかい！」の隣なら
		{
			isContinue = true;	//コンテニューフラグを立てる
		}

		else if (CursorPosY == 600)	//「もういいかな」の隣なら
		{
			isBackTitle = true;	//タイトルフラグを折る
		}

		g_CurrentSceneID = SCENE_ID_FIN_CLEAR;	//クリア後処理へ移動
	}
}

void DrawClear()	//クリア描画処理
{
	DrawGraph(0, 0, ClearImage, true);	//クリア背景画像描画

	DrawRotaGraph(640, 100, 1.0f, 0.0f, ResultImage, true);	//リザルト文字画像描画

	DrawRotaGraph(640, 350, 0.5f, 0.0f, TextImage, true);	//「まだやる？」画像描画

	DrawRotaGraph(640, 500, 1.0f, 0.0f, ContinueImage, true);	//「もっかい！」画像描画

	DrawRotaGraph(640, 600, 1.0f, 0.0f, BackTitleImage, true);	//「もういいかな」画像描画

	DrawRotaGraph(450, CursorPosY, 1.0f, 0.0f, CursorImage, true);	//矢印画像描画
}

void FinClear()	//クリア後処理
{
	DeleteGraph(ClearImage);	//クリア背景画像破棄

	DeleteGraph(ResultImage);	//リザルト文字画像破棄

	DeleteGraph(TextImage);		//「まだやる？」画像破棄

	DeleteGraph(ContinueImage);	//「もっかい！」画像破棄

	DeleteGraph(BackTitleImage);	//「もういいかな」画像破棄

	DeleteGraph(CursorImage);	//矢印画像破棄

	if (isContinue)	//コンテニューフラグがtrueなら
	{
		g_CurrentSceneID = SCENE_ID_INIT_PLAY;	//プレイシーンに戻る
	}

	else if (isBackTitle)	//タイトルフラグがtrueなら
	{
		g_CurrentSceneID = SCENE_ID_INIT_TITLE;	//タイトルシーンに戻る
	}
}