#include "DxLib.h"
#include "Scene.h"
#include "SceneClear.h"

int ClearImage;		//�N���A�w�i�摜�n���h��

int ResultImage;	//���U���g�����摜�n���h��

int TextImage;		//�u�܂����H�v�摜�n���h��

int ContinueImage;	//�u���������I�v�摜�n���h��

int BackTitleImage;	//�u�����������ȁB�v�摜�n���h��

void InitClear()	//�N���A������
{
	ClearImage = LoadGraph(BACK_CLEAR);		//�N���A�w�i�摜�ǂݍ���
	
	ResultImage = LoadGraph(RESULT_PATH);	//���U���g�����摜�ǂݍ���

	TextImage = LoadGraph(TEXT_PATH);		//�u�܂����H�v�摜�ǂݍ���

	ContinueImage = LoadGraph(CONTINUE_PATH) ;	//�u���������I�v�摜�ǂݍ���

	BackTitleImage = LoadGraph(BACK_TITLE_PATH);//�u�����������ȁB�v�摜�ǂݍ���

	g_CurrentSceneID = SCENE_ID_LOOP_CLEAR;	//�N���A���[�v�ֈړ�
}

//�N���A�ʏ폈��
void StepClear()
{
	if (IsKeyPush(KEY_INPUT_RETURN))	//�G���^�[�L�[��������
	{
		g_CurrentSceneID = SCENE_ID_FIN_CLEAR;	//�N���A�㏈���ֈړ�
	}
}

void DrawClear()	//�N���A�`�揈��
{
	DrawGraph(0, 0, ClearImage, true);	//�N���A�w�i�摜�`��

	DrawRotaGraph(640, 100, 1.0f, 0.0f, ResultImage, true);	//���U���g�����摜�`��

	DrawRotaGraph(640, 300, 1.0f, 0.0f, TextImage, true);	//�u�܂����H�v�摜�`��

	DrawRotaGraph(640, 450, 1.0f, 0.0f, ContinueImage, true);	//�u���������I�v�摜�`��

	DrawRotaGraph(660, 600, 1.0f, 0.0f, BackTitleImage, true);	//�u�����������ȁB�v�摜�`��
}

void FinClear()	//�N���A�㏈��
{
	DeleteGraph(ClearImage);	//�N���A�w�i�摜�j��

	DeleteGraph(ResultImage);	//���U���g�����摜�j��

	DeleteGraph(TextImage);		//�u�܂����H�v�摜�j��

	DeleteGraph(ContinueImage);	//�u���������I�v�摜�j��

	DeleteGraph(BackTitleImage);	//�u�����������ȁB�v�摜�j��

	g_CurrentSceneID = SCENE_ID_INIT_TITLE;	//�^�C�g���V�[���ɖ߂�
}