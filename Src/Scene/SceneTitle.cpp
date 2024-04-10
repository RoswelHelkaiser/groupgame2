#include "DxLib.h"
#include "Scene.h"
#include "SceneTitle.h"

int BackImage;	//�^�C�g���w�i�摜�n���h��

int TitleImage;	//�^�C�g�������摜�n���h��

int StartImage;	//�X�^�[�g�����摜�n���h��

void InitTitle()	//�^�C�g��������
{
	BackImage = LoadGraph(BACK_PATH);	//�^�C�g���w�i�摜�ǂݍ���

	TitleImage = LoadGraph(TITLE_PATH);	//�^�C�g�������摜�ǂݍ���

	StartImage = LoadGraph(START_PATH);	//�X�^�[�g�����摜�ǂݍ���

	g_CurrentSceneID = SCENE_ID_LOOP_TITLE;	//�^�C�g�����[�v�ֈړ�
}

void StepTitle()	//�^�C�g���ʏ폈��
{
	if (IsKeyPush(KEY_INPUT_RETURN))	//Enter�L�[�������ꂽ��
	{
		g_CurrentSceneID = SCENE_ID_FIN_TITLE;	//�^�C�g���㏈���ֈړ�
	}
}

void DrawTitle()	//�^�C�g���`�揈��
{
	DrawGraph(0, 0, BackImage, true);	//�^�C�g���w�i�摜�`��

	DrawRotaGraph(640, 200, 1.0f, 0.0f, TitleImage, true);	//�^�C�g�������摜�`��

	DrawRotaGraph(640, 600, 1.0f, 0.0f, StartImage, true);	//�X�^�[�g�����摜�`��
}

//�^�C�g���㏈��
void FinTitle()
{
	DeleteGraph(BackImage);	//�^�C�g���w�i�摜�j��

	g_CurrentSceneID = SCENE_ID_INIT_PLAY;	//�v���C�V�[���ֈړ�
}
