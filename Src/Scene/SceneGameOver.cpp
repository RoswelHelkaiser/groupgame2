#include "DxLib.h"
#include "Scene.h"
#include "SceneGameOver.h"

void InitGameOver()	//�Q�[���I�[�o�[������
{
	g_CurrentSceneID = SCENE_ID_LOOP_GAMEOVER;	//�Q�[���I�[�o�[���[�v�ֈړ�
}

void StepGameOver()	//�Q�[���I�[�o�[�ʏ폈��
{
	if (IsKeyPush(KEY_INPUT_RETURN))	//�G���^�[�L�[��������
	{
		g_CurrentSceneID = SCENE_ID_FIN_GAMEOVER;	//�Q�[���I�[�o�[�㏈���ֈړ�
	}
}

void DrawGameOver()	//�Q�[���I�[�o�[�`�揈��
{

}

void FinGameOver()	//�Q�[���I�[�o�[�㏈��
{
	if (IsKeyPush(KEY_INPUT_RETURN))	//�G���^�[�L�[��������
	{
		g_CurrentSceneID = SCENE_ID_INIT_TITLE;	//�^�C�g���V�[���ɖ߂�
	}
}