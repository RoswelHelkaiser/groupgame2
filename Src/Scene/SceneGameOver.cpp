#include "DxLib.h"
#include "Scene.h"
#include "SceneGameOver.h"

//�Q�[���I�[�o�[������
void InitGameOver()
{
	//�Q�[���I�[�o�[���[�v�ֈړ�
	g_CurrentSceneID = SCENE_ID_LOOP_GAMEOVER;
}

//�Q�[���I�[�o�[�ʏ폈��
void StepGameOver()
{
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		g_CurrentSceneID = SCENE_ID_FIN_GAMEOVER;
	}
}

//�Q�[���I�[�o�[�`�揈��
void DrawGameOver()
{

}

//�Q�[���I�[�o�[�㏈��
void FinGameOver()
{
	//�G���^�[�L�[��
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		//�v���C�V�[���ɖ߂�
		g_CurrentSceneID = SCENE_ID_INIT_PLAY;
	}
}