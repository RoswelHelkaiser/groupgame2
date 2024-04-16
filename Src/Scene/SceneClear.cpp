#include "DxLib.h"
#include "Scene.h"
#include "SceneClear.h"
#include "../Score/Score.h"

int ClearImage;	//�N���A�w�i�摜�n���h��

int CursorImage;	//���摜�n���h��

int CursorPosX;		//���摜Y���W

bool isContinue;	//�R���e�j���[�t���O

bool isBackTitle;	//�^�C�g���t���O

int Clear_BGM;		//BGM�n���h��

void InitClear()	//�N���A������
{
	ClearImage = LoadGraph(BACK_CLEAR_PATH);	//�N���A�w�i�摜�ǂݍ���

	CursorImage = LoadGraph(CURSOR_PATH);	//���摜�ǂݍ���

	LoadScore(NUMBER_0);	//0�ǂݍ���
	LoadScore(NUMBER_1);	//1�ǂݍ���
	LoadScore(NUMBER_2);	//2�ǂݍ���
	LoadScore(NUMBER_3);	//3�ǂݍ���
	LoadScore(NUMBER_4);	//4�ǂݍ���
	LoadScore(NUMBER_5);	//5�ǂݍ���
	LoadScore(NUMBER_6);	//6�ǂݍ���
	LoadScore(NUMBER_7);	//7�ǂݍ���
	LoadScore(NUMBER_8);	//8�ǂݍ���
	LoadScore(NUMBER_9);	//9�ǂݍ���

	CursorPosX = 150;	//���̏���Y���W��ݒ�

	isContinue = false;		//�R���e�j���[�t���O��܂�

	isBackTitle = false;	//�^�C�g���t���O��܂�

	Clear_BGM = LoadSoundMem(CLEAR_BGM_PATH);	//BGM�ǂݍ���

	ChangeVolumeSoundMem(255 * 50 / 100, Clear_BGM);	//BGM�̉��ʂ�50%�ɂ���

	PlaySoundMem(Clear_BGM, DX_PLAYTYPE_LOOP, true);	//BGM�Đ�

	g_CurrentSceneID = SCENE_ID_LOOP_CLEAR;	//�N���A���[�v�ֈړ�
}

void StepClear()	//�N���A�ʏ폈��
{
	if (IsKeyPush(KEY_INPUT_A) || IsKeyPush(KEY_INPUT_LEFT))	//A�L�[�܂��͍����L�[�������ꂽ��
	{
		if (CursorPosX == 650)	//�u�����������ȁv�ׂ̗Ȃ�
		{
			CursorPosX = 150;	//�u���������I�v�ׂ̗Ɉړ�����
		}
	}

	else if (IsKeyPush(KEY_INPUT_D) || IsKeyPush(KEY_INPUT_RIGHT))	//D�L�[�܂��͉E���L�[�������ꂽ��
	{
		if (CursorPosX == 150)	//�u���������I�v�ׂ̗Ȃ�
		{
			CursorPosX = 650;	//�u�����������ȁv�ׂ̗Ɉړ�����
		}
	}

	if (IsKeyPush(KEY_INPUT_RETURN))	//�G���^�[�L�[��������
	{
		if (CursorPosX == 150)	//�u���������I�v�ׂ̗Ȃ�
		{
			isContinue = true;	//�R���e�j���[�t���O�𗧂Ă�
		}

		else if (CursorPosX == 650)	//�u�����������ȁv�ׂ̗Ȃ�
		{
			isBackTitle = true;	//�^�C�g���t���O��܂�
		}

		g_CurrentSceneID = SCENE_ID_FIN_CLEAR;	//�N���A�㏈���ֈړ�
	}
}

void DrawClear()	//�N���A�`�揈��
{
	DrawGraph(0, 0, ClearImage, true);	//�N���A�w�i�摜�`��

	DrawRotaGraph(CursorPosX, 625, 0.5f, 0.0f, CursorImage, true);	//���摜�`��

	ScoreInfo* scoreInfo = GetScoreInfo();	//�X�R�A���擾
	int Score = scoreInfo->CurrentScore;	//�X�R�A�����u���ϐ��ɑ��
	int count = 0;	//�J�E���g�p�ϐ�
	while(Score > 0)	//�X�R�A��0���傫���Ȃ�
	{
		int num = Score % 10;	//�����̓Y���������߂�
		Score /= 10;	//�X�R�A��10�Ŋ���
		DrawGraph(665 - count * 50, 360, scoreInfo->ScoreHandle[num], true);
		count++;	//�J�E���g�𑝂₷
	}
}

void FinClear()	//�N���A�㏈��
{
	ScoreInfo* scoreInfo = GetScoreInfo();	//�X�R�A���擾

	DeleteGraph(ClearImage);	//�N���A�w�i�摜�j��

	DeleteGraph(CursorImage);	//���摜�j��

	StopSoundMem(Clear_BGM);	//BGM��~

	DeleteSoundMem(Clear_BGM);	//BGM�j��

	for (int i = 0; i < NUMBER_NUM; i++)
	{
		DeleteGraph(scoreInfo->ScoreHandle[i]);	//�����摜�j��
	}

	if (isContinue)	//�R���e�j���[�t���O��true�Ȃ�
	{
		g_CurrentSceneID = SCENE_ID_INIT_PLAY;	//�v���C�V�[���ɖ߂�
	}

	else if (isBackTitle)	//�^�C�g���t���O��true�Ȃ�
	{
		g_CurrentSceneID = SCENE_ID_INIT_TITLE;	//�^�C�g���V�[���ɖ߂�
	}
}