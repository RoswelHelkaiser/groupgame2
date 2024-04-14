#include "DxLib.h"
#include "../Common.h"
#include "../Effect/Effect.h"
#include "../Input/Input.h"
#include "Scene.h"
#include "ScenePlay.h"
#include "../Slime/Slime.h"
#include "../SlimeBox/SlimeBox.h"
#include "../Score/Score.h"

int BackPlayImage;	//�v���C�w�i�摜�n���h��

Text text;		//�����N���X�̐錾

int FrameCount;	//�t���[���J�E���g�p�ϐ�

int LoopCount;	//���[�v�J�E���g�p�ϐ�

int TimeLimit;	//��������

bool isMinusTime;	//�������Ԃ����炷�t���O

bool isNextClear;	//�N���A�V�[���ɐi�ރt���O

void InitPlay()	//�v���C�V�[��������
{
	BackPlayImage = LoadGraph(BACK_PLAY_PATH);	//�v���C�w�i�摜�ǂݍ���

	text.InitText();	//�����̏�����

	InitSlime();	//�X���C���̏�����

	InitBox();	//���̏�����

	InitScore();	//�X�R�A�̏�����

	FrameCount = 0;		//�t���[���J�E���g�����Z�b�g

	LoopCount = 0;		//���[�v�J�E���g�����Z�b�g

	TimeLimit = TIME_MAX_NUM;	//�������Ԃ����Z�b�g

	isMinusTime = false;	//�������Ԍ����t���O��܂�

	isNextClear = false;	//�N���A�V�[���ɐi�ރt���O��܂�

	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;	//�v���C�V�[�����[�v��
}

void StepPlay()	//�v���C�V�[���ʏ폈��
{
	text.StepText();	//�����ʏ폈��

	if (text.isStart)	//�Q�[����i�܂���t���O��true�Ȃ�
	{
		StepSlime();	//�X���C���ʏ폈��

		if (TimeLimit > 0)	//�������Ԃ��c���Ă�����
		{
			if (LoopCount < 1)	//���[�v�J�E���g��1��菬�����Ȃ�
			{
				FrameCount++;	//�t���[���J�E���g�𑝂₷

				if (FrameCount > FRAME_RATE)	//�t���[���J�E���g�����̒l�𒴂�����
				{
					LoopCount++;	//���[�v�J�E���g�𑝂₷
					FrameCount = 0;	//�t���[���J�E���g�����Z�b�g
				}
			}

			else if (LoopCount >= 1)	//���[�v�J�E���g��1�ȏ�ɂȂ�����
			{
				isMinusTime = true;		//�������Ԍ����t���O�𗧂Ă�
			}

			if (isMinusTime)	//�������Ԍ����t���O��true�Ȃ�
			{
				if (48 <= TimeLimit)	//�������Ԃ�48�b�ȏ�Ȃ�
				{
					//�X���C����1�C�X�|�[��
					SpornSlime();	//�X���C���X�|�[������
				}
				else if (36 <= TimeLimit && TimeLimit <= 47)	//�������Ԃ�36�b�ȏ�47�b�ȉ��Ȃ�
				{
					//�X���C����2�C�X�|�[��
					SpornSlime();	//�X���C���X�|�[������
					SpornSlime();	//�X���C���X�|�[������
				}
				else if (24 <= TimeLimit && TimeLimit <= 35)	//�������Ԃ�24�b�ȏ�35�b�ȉ��Ȃ�
				{
					//�X���C����3�C�X�|�[��
					SpornSlime();	//�X���C���X�|�[������
					SpornSlime();	//�X���C���X�|�[������
					SpornSlime();	//�X���C���X�|�[������
				}
				else if (12 <= TimeLimit && TimeLimit <= 23)	//�������Ԃ�12�b�ȏ�23�b�ȉ��Ȃ�
				{
					//�X���C����4�C�X�|�[��
					SpornSlime();	//�X���C���X�|�[������
					SpornSlime();	//�X���C���X�|�[������
					SpornSlime();	//�X���C���X�|�[������
					SpornSlime();	//�X���C���X�|�[������
				}
				else if (1 <= TimeLimit && TimeLimit <= 11)		//�������Ԃ�1�b�ȏ�11�b�ȉ��Ȃ�
				{
					//�X���C����5�C�X�|�[��
					SpornSlime();	//�X���C���X�|�[������
					SpornSlime();	//�X���C���X�|�[������
					SpornSlime();	//�X���C���X�|�[������
					SpornSlime();	//�X���C���X�|�[������
					SpornSlime();	//�X���C���X�|�[������
				}

				TimeLimit--;	//�������Ԃ����炷
				LoopCount = 0;	//���[�v�J�E���g�����Z�b�g
				isMinusTime = false;	//�������Ԍ����t���O��܂�
			}
		}
	}	

	if (TimeLimit <= 0)	//�������Ԃ��Ȃ��Ȃ�����
	{
		text.HandleIndex = 2;	//�uFinish!�v�ɂ���
		text.isDraw = true;		//�`��t���O�𗧂Ă�
		text.Size = 3.0f;		//�傫����3�{�ɂ���

		if (LoopCount < 2)	//���[�v�J�E���g��2��菬�����Ȃ�
		{
			FrameCount++;	//�t���[���J�E���g�𑝂₷

			if (FrameCount > FRAME_RATE)	//�t���[���J�E���g�����̒l�𒴂�����
			{
				LoopCount++;	//���[�v�J�E���g�𑝂₷
				FrameCount = 0;	//�t���[���J�E���g�����Z�b�g
			}
		}

		else if (LoopCount >= 2)	//���[�v�J�E���g��2�ȏ�ɂȂ�����
		{
			isNextClear = true;		//�N���A�V�[���ɐi�ރt���O�𗧂Ă�
		}

		if (isNextClear)	//�N���A�V�[���ɐi�ރt���O��true�Ȃ�
		{
			g_CurrentSceneID = SCENE_ID_FIN_PLAY;	//�v���C�V�[���㏈���ֈړ�
		}
	}
}

void DrawPlay()	//�v���C�V�[���`�揈��
{
	DrawGraph(0, 0, BackPlayImage, true);	//�v���C�w�i�摜�`��

	DrawBox();	//���`�揈��

	DrawSlime();	//�X���C���`�揈��

	text.DrawTextImage();	//�����`�揈��

	DrawScore();	//�X�R�A�`�揈��

	DrawFormatString(600, 60, GetColor(255, 255, 255), "Time:%d", TimeLimit);	//�������ԕ`�揈��
}

//�v���C�V�[���㏈��
void FinPlay()
{
	DeleteGraph(BackPlayImage);	//�v���C�w�i�摜�j��

	text.FinText();	//�����㏈��

	FinSlime();	//�X���C���㏈��

	FinBox();	//���㏈��

	FinScore();	//�X�R�A�㏈��

	g_CurrentSceneID = SCENE_ID_INIT_CLEAR;	//�N���A�V�[���ֈړ�
}
