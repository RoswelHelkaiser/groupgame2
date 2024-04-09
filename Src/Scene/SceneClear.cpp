#include "DxLib.h"
#include "Scene.h"
#include "SceneClear.h"

//クリア背景画像ハンドル
int ClearImage = 0;

//リザルト文字画像ハンドル
int ResultImage = 0;

//クリア初期化
void InitClear()
{
	//クリア背景画像読み込み
	ClearImage = LoadGraph(BACK_CLEAR);

	//リザルト文字画像読み込み
	ResultImage = LoadGraph(RESULT_PATH);

	//クリアループへ移動
	g_CurrentSceneID = SCENE_ID_LOOP_CLEAR;
}

//クリア通常処理
void StepClear()
{
	//エンターキーでクリア後処理へ移動
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		g_CurrentSceneID = SCENE_ID_FIN_CLEAR;
	}
}

//クリア描画処理
void DrawClear()
{
	//クリア背景画像描画
	DrawGraph(0, 0, ClearImage, true);

	//リザルト文字画像読み込み
	DrawRotaGraph(640, 220, 1.0f, 0.0f, ResultImage, true);
}

//クリア後処理
void FinClear()
{
	//クリア背景画像破棄
	DeleteGraph(ClearImage);

	//リザルト文字画像読み込み
	DeleteGraph(ResultImage);

	//タイトルに戻るようにする
	g_CurrentSceneID = SCENE_ID_INIT_TITLE;
}