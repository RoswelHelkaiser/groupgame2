#include "DxLib.h"
#include "../Common.h"
#include "../Effect/Effect.h"
#include "../Input/Input.h"
#include "Scene.h"
#include "ScenePlay.h"

//�t���[���J�E���g�p�ϐ�
int FrameCount;

//���[�v�J�E���g�p�ϐ�
int LoopCount;

//��������
int TimeLimit;

//�������Ԃ����炷�t���O
bool isMinusTime;

//�N���A�V�[���ɐi�ރt���O
bool isNextClear;

//�v���C�V�[��������
void InitPlay()
{
	//�t���[���J�E���g�����Z�b�g
	FrameCount = 0;

	//���[�v�J�E���g�����Z�b�g
	LoopCount = 0;

	//�������Ԃ����Z�b�g
	TimeLimit = 30;

	//�������Ԍ����t���O��܂�
	isMinusTime = false;

	//�N���A�V�[���ɐi�ރt���O��܂�
	isNextClear = false;

	//�v���C�V�[�����[�v��
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}

//�v���C�V�[���ʏ폈��
void StepPlay()
{
	//�������Ԃ��c���Ă�����
	if (TimeLimit > 0)
	{
		//���[�v�J�E���g��2��菬�����Ȃ�
		if (LoopCount < 2)
		{
			//�t���[���J�E���g�𑝂₷
			FrameCount++;

			//�t���[���J�E���g�����̒l�𒴂�����
			if (FrameCount > FRAME_RATE / 2)
			{
				LoopCount++;	//���[�v�J�E���g�𑝂₷
				FrameCount = 0;	//�t���[���J�E���g�����Z�b�g
			}
		}

		//���[�v�J�E���g��2�ȏ�ɂȂ�����
		else if (LoopCount >= 2)
		{
			//�������Ԍ����t���O�𗧂Ă�
			isMinusTime = true;
		}

		//�������Ԍ����t���O��true�Ȃ�
		if (isMinusTime)
		{
			TimeLimit--;	//�������Ԃ����炷
			LoopCount = 0;	//���[�v�J�E���g�����Z�b�g
			isMinusTime = false;	//�������Ԍ����t���O��܂�
		}
	}

	//�������Ԃ��Ȃ��Ȃ�����
	if (TimeLimit <= 0)
	{
		//���[�v�J�E���g��4��菬�����Ȃ�
		if (LoopCount < 4)
		{
			//�t���[���J�E���g�𑝂₷
			FrameCount++;

			//�t���[���J�E���g�����̒l�𒴂�����
			if (FrameCount > FRAME_RATE / 2)
			{
				LoopCount++;	//���[�v�J�E���g�𑝂₷
				FrameCount = 0;	//�t���[���J�E���g�����Z�b�g
			}
		}

		//���[�v�J�E���g��4�ȏ�ɂȂ�����
		else if (LoopCount >= 4)
		{
			//�N���A�V�[���ɐi�ރt���O�𗧂Ă�
			isNextClear = true;
		}

		//�N���A�V�[���ɐi�ރt���O��true�Ȃ�
		if (isNextClear)
		{
			//�v���C�V�[���㏈���ֈړ�
			g_CurrentSceneID = SCENE_ID_FIN_PLAY;
		}
	}
}

//�v���C�V�[���`�揈��
void DrawPlay()
{
	//�������ԕ`��
	DrawFormatString(600, 60, GetColor(255, 255, 255), "Time:%d", TimeLimit);
}

//�v���C�V�[���㏈��
void FinPlay()
{
	//�N���A�V�[���ֈړ�
	g_CurrentSceneID = SCENE_ID_INIT_CLEAR;
}
