#include "DxLib.h"
#include "Scene.h"
#include "SceneClear.h"

//�N���A�w�i�摜�n���h��
int ClearImage = 0;

//���U���g�����摜�n���h��
int ResultImage = 0;

//�N���A������
void InitClear()
{
	//�N���A�w�i�摜�ǂݍ���
	ClearImage = LoadGraph(BACK_CLEAR);

	//���U���g�����摜�ǂݍ���
	ResultImage = LoadGraph(RESULT_PATH);

	//�N���A���[�v�ֈړ�
	g_CurrentSceneID = SCENE_ID_LOOP_CLEAR;
}

//�N���A�ʏ폈��
void StepClear()
{
	//�G���^�[�L�[�ŃN���A�㏈���ֈړ�
	if (IsKeyPush(KEY_INPUT_RETURN))
	{
		g_CurrentSceneID = SCENE_ID_FIN_CLEAR;
	}
}

//�N���A�`�揈��
void DrawClear()
{
	//�N���A�w�i�摜�`��
	DrawGraph(0, 0, ClearImage, true);

	//���U���g�����摜�ǂݍ���
	DrawRotaGraph(640, 220, 1.0f, 0.0f, ResultImage, true);
}

//�N���A�㏈��
void FinClear()
{
	//�N���A�w�i�摜�j��
	DeleteGraph(ClearImage);

	//���U���g�����摜�ǂݍ���
	DeleteGraph(ResultImage);

	//�^�C�g���ɖ߂�悤�ɂ���
	g_CurrentSceneID = SCENE_ID_INIT_TITLE;
}