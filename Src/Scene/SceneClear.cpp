#include "DxLib.h"
#include "Scene.h"
#include "SceneClear.h"

int ClearImage;		//クリア背景画像ハンドル

int ResultImage;	//リザルト文字画像ハンドル

int TextImage;		//「まだやる？」画像ハンドル

int ContinueImage;	//「もっかい！」画像ハンドル

int BackTitleImage;	//「もういいかな。」画像ハンドル

void InitClear()	//クリア初期化
{
	ClearImage = LoadGraph(BACK_CLEAR);		//クリア背景画像読み込み
	
	ResultImage = LoadGraph(RESULT_PATH);	//リザルト文字画像読み込み

	TextImage = LoadGraph(TEXT_PATH);		//「まだやる？」画像読み込み

	ContinueImage = LoadGraph(CONTINUE_PATH) ;	//「もっかい！」画像読み込み

	BackTitleImage = LoadGraph(BACK_TITLE_PATH);//「もういいかな。」画像読み込み

	g_CurrentSceneID = SCENE_ID_LOOP_CLEAR;	//クリアループへ移動
}

//クリア通常処理
void StepClear()
{
	if (IsKeyPush(KEY_INPUT_RETURN))	//エンターキーを押すと
	{
		g_CurrentSceneID = SCENE_ID_FIN_CLEAR;	//クリア後処理へ移動
	}
}

void DrawClear()	//クリア描画処理
{
	DrawGraph(0, 0, ClearImage, true);	//クリア背景画像描画

	DrawRotaGraph(640, 100, 1.0f, 0.0f, ResultImage, true);	//リザルト文字画像描画

	DrawRotaGraph(640, 300, 1.0f, 0.0f, TextImage, true);	//「まだやる？」画像描画

	DrawRotaGraph(640, 450, 1.0f, 0.0f, ContinueImage, true);	//「もっかい！」画像描画

	DrawRotaGraph(660, 600, 1.0f, 0.0f, BackTitleImage, true);	//「もういいかな。」画像描画
}

void FinClear()	//クリア後処理
{
	DeleteGraph(ClearImage);	//クリア背景画像破棄

	DeleteGraph(ResultImage);	//リザルト文字画像破棄

	DeleteGraph(TextImage);		//「まだやる？」画像破棄

	DeleteGraph(ContinueImage);	//「もっかい！」画像破棄

	DeleteGraph(BackTitleImage);	//「もういいかな。」画像破棄

	g_CurrentSceneID = SCENE_ID_INIT_TITLE;	//タイトルシーンに戻る
}