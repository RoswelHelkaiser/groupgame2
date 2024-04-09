#include "DxLib.h"
#include "Scene.h"
#include "SceneTitle.h"

//タイトル背景画像ハンドル
int BackImage = 0;

//タイトル初期化
void InitTitle()
{
	//タイトル背景画像読み込み
	BackImage = LoadGraph(BACK_PATH);

	//タイトルループへ移動
	g_CurrentSceneID = SCENE_ID_LOOP_TITLE;
}

//タイトル通常処理
void StepTitle()
{
	//Enterキーが押されたら
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		//タイトル後処理へ移動
		g_CurrentSceneID = SCENE_ID_FIN_TITLE;
	}
}

//タイトル描画処理
void DrawTitle()
{
	//タイトル背景画像描画
	DrawGraph(0, 0, BackImage, true);
}

//タイトル後処理
void FinTitle()
{
	//タイトル背景画像破棄
	DeleteGraph(BackImage);

	//タイトルの後はプレイへ移動
	g_CurrentSceneID = SCENE_ID_INIT_PLAY;
}
