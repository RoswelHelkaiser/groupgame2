#include "DxLib.h"
#include "Scene.h"
#include "SceneTitle.h"

int BackImage;	//タイトル背景画像ハンドル

int TitleImage;	//タイトル文字画像ハンドル

int StartImage;	//スタート文字画像ハンドル

void InitTitle()	//タイトル初期化
{
	BackImage = LoadGraph(BACK_PATH);	//タイトル背景画像読み込み

	TitleImage = LoadGraph(TITLE_PATH);	//タイトル文字画像読み込み

	StartImage = LoadGraph(START_PATH);	//スタート文字画像読み込み

	g_CurrentSceneID = SCENE_ID_LOOP_TITLE;	//タイトルループへ移動
}

void StepTitle()	//タイトル通常処理
{
	if (IsKeyPush(KEY_INPUT_RETURN))	//Enterキーが押されたら
	{
		g_CurrentSceneID = SCENE_ID_FIN_TITLE;	//タイトル後処理へ移動
	}
}

void DrawTitle()	//タイトル描画処理
{
	DrawGraph(0, 0, BackImage, true);	//タイトル背景画像描画

	DrawRotaGraph(640, 200, 1.0f, 0.0f, TitleImage, true);	//タイトル文字画像描画

	DrawRotaGraph(640, 600, 1.0f, 0.0f, StartImage, true);	//スタート文字画像描画
}

//タイトル後処理
void FinTitle()
{
	DeleteGraph(BackImage);	//タイトル背景画像破棄

	g_CurrentSceneID = SCENE_ID_INIT_PLAY;	//プレイシーンへ移動
}
