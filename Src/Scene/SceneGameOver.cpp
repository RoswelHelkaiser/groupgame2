#include "DxLib.h"
#include "Scene.h"
#include "SceneGameOver.h"

void InitGameOver()	//ゲームオーバー初期化
{
	g_CurrentSceneID = SCENE_ID_LOOP_GAMEOVER;	//ゲームオーバーループへ移動
}

void StepGameOver()	//ゲームオーバー通常処理
{
	if (IsKeyPush(KEY_INPUT_RETURN))	//エンターキーを押すと
	{
		g_CurrentSceneID = SCENE_ID_FIN_GAMEOVER;	//ゲームオーバー後処理へ移動
	}
}

void DrawGameOver()	//ゲームオーバー描画処理
{

}

void FinGameOver()	//ゲームオーバー後処理
{
	if (IsKeyPush(KEY_INPUT_RETURN))	//エンターキーを押すと
	{
		g_CurrentSceneID = SCENE_ID_INIT_TITLE;	//タイトルシーンに戻る
	}
}