#include "DxLib.h"
#include "Scene.h"
#include "SceneClear.h"

int ClearImage;	//�N���A�w�i�摜�n���h��

int ResultImage;	//���U���g�����摜�n���h��

int TextImage;	//�u�܂����H�v�摜�n���h��

int ContinueImage;	//�u���������I�v�摜�n���h��

int BackTitleImage;	//�u�����������ȁv�摜�n���h��

int CursorImage;	//���摜�n���h��

int CursorPosY;		//���摜Y���W

bool isContinue;	//�R���e�j���[�t���O

bool isBackTitle;	//�^�C�g���t���O

void InitClear()	//�N���A������
{
	ClearImage = LoadGraph(BACK_CLEAR_PATH);	//�N���A�w�i�摜�ǂݍ���

	ResultImage = LoadGraph(RESULT_PATH);	//���U���g�����摜�ǂݍ���

	TextImage = LoadGraph(TEXT_PATH);	//�u�܂����H�v�摜�ǂݍ���

	ContinueImage = LoadGraph(CONTINUE_PATH);	//�u���������I�v�摜�ǂݍ���

	BackTitleImage = LoadGraph(BACK_TITLE_PATH);	//�u�����������ȁv�摜�ǂݍ���

	CursorImage = LoadGraph(CURSOR_PATH);	//���摜�ǂݍ���

	CursorPosY = 500;	//���̏���Y���W��ݒ�

	isContinue = false;		//�R���e�j���[�t���O��܂�

	isBackTitle = false;	//�^�C�g���t���O��܂�

	g_CurrentSceneID = SCENE_ID_LOOP_CLEAR;	//�N���A���[�v�ֈړ�
}

void StepClear()	//�N���A�ʏ폈��
{
	if (IsKeyPush(KEY_INPUT_W) || IsKeyPush(KEY_INPUT_UP))	//W�L�[�܂��͏���L�[�������ꂽ��
	{
		if (CursorPosY == 600)	//�u�����������ȁv�ׂ̗Ȃ�
		{
			CursorPosY = 500;	//�u���������I�v�ׂ̗Ɉړ�����
		}
	}

	else if (IsKeyPush(KEY_INPUT_S) || IsKeyPush(KEY_INPUT_DOWN))	//S�L�[�܂��͉����L�[�������ꂽ��
	{
		if (CursorPosY == 500)	//�u���������I�v�ׂ̗Ȃ�
		{
			CursorPosY = 600;	//�u�����������ȁv�ׂ̗Ɉړ�����
		}
	}

	if (IsKeyPush(KEY_INPUT_RETURN))	//�G���^�[�L�[��������
	{
		if (CursorPosY == 500)	//�u���������I�v�ׂ̗Ȃ�
		{
			isContinue = true;	//�R���e�j���[�t���O�𗧂Ă�
		}

		else if (CursorPosY == 600)	//�u�����������ȁv�ׂ̗Ȃ�
		{
			isBackTitle = true;	//�^�C�g���t���O��܂�
		}

		g_CurrentSceneID = SCENE_ID_FIN_CLEAR;	//�N���A�㏈���ֈړ�
	}
}

void DrawClear()	//�N���A�`�揈��
{
	DrawGraph(0, 0, ClearImage, true);	//�N���A�w�i�摜�`��

	DrawRotaGraph(640, 100, 1.0f, 0.0f, ResultImage, true);	//���U���g�����摜�`��

	DrawRotaGraph(640, 350, 0.5f, 0.0f, TextImage, true);	//�u�܂����H�v�摜�`��

	DrawRotaGraph(640, 500, 1.0f, 0.0f, ContinueImage, true);	//�u���������I�v�摜�`��

	DrawRotaGraph(640, 600, 1.0f, 0.0f, BackTitleImage, true);	//�u�����������ȁv�摜�`��

	DrawRotaGraph(450, CursorPosY, 1.0f, 0.0f, CursorImage, true);	//���摜�`��
}

void FinClear()	//�N���A�㏈��
{
	DeleteGraph(ClearImage);	//�N���A�w�i�摜�j��

	DeleteGraph(ResultImage);	//���U���g�����摜�j��

	DeleteGraph(TextImage);		//�u�܂����H�v�摜�j��

	DeleteGraph(ContinueImage);	//�u���������I�v�摜�j��

	DeleteGraph(BackTitleImage);	//�u�����������ȁv�摜�j��

	DeleteGraph(CursorImage);	//���摜�j��

	if (isContinue)	//�R���e�j���[�t���O��true�Ȃ�
	{
		g_CurrentSceneID = SCENE_ID_INIT_PLAY;	//�v���C�V�[���ɖ߂�
	}

	else if (isBackTitle)	//�^�C�g���t���O��true�Ȃ�
	{
		g_CurrentSceneID = SCENE_ID_INIT_TITLE;	//�^�C�g���V�[���ɖ߂�
	}
}