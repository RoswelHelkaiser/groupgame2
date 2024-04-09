#include "DxLib.h"
#include "Scene.h"
#include "SceneGameOver.h"

//ゲームオーバー初期化
void InitGameOver()
{
	//ゲームオーバーループへ移動
	g_CurrentSceneID = SCENE_ID_LOOP_GAMEOVER;
}

//ゲームオーバー通常処理
void StepGameOver()
{
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		g_CurrentSceneID = SCENE_ID_FIN_GAMEOVER;
	}
}

//ゲームオーバー描画処理
void DrawGameOver()
{

}

//ゲームオーバー後処理
void FinGameOver()
{
	//エンターキーで
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		//プレイシーンに戻る
		g_CurrentSceneID = SCENE_ID_INIT_PLAY;
	}
}