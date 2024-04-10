#include "DxLib.h"
#include "../Common.h"
#include "Slime.h"

SlimeInfo slimeInfo[SLIME_NUM][SLIME_KIND] = { 0 }; //�X���C�����\���̂̐錾

int HandleIndex;	//�摜�n���h���Y�����p�ϐ�

int KindIndex;		//�X���C���̎�ޗp�ϐ�

int FrameNum;	//�t���[���J�E���g�p�ϐ�

int Wating;		//���[�v�J�E���g�p�ϐ�

void InitSlime()	//�X���C���̏�����
{
	for (int i = 0; i < SLIME_NUM; i++)
	{
		for (int j = 0; j < SLIME_KIND; j++)
		{
			slimeInfo[i][0].ImageHandle = LoadGraph(SLIME_GREEN_PATH);	//�X���C��(��)�摜�ǂݍ���
			slimeInfo[i][1].ImageHandle = LoadGraph(SLIME_RED_PATH);	//�X���C��(��)�摜�ǂݍ���
			slimeInfo[i][j].PosX = 640.0f;		//����X���W��ݒ�
			slimeInfo[i][j].PosY = 360.0f;		//����Y���W��ݒ�
			slimeInfo[i][j].isDraw = false;		//�`��t���O��܂�
		}
	}

	HandleIndex = 0;	//�Y������0�Ƀ��Z�b�g

	KindIndex = 0;	//�X���C��(��)�������ݒ�

	FrameNum = 0;	//�t���[���J�E���g�����Z�b�g

	Wating = 0;		//���[�v�J�E���g�����Z�b�g
}

void StepSlime()	//�X���C���ʏ폈��
{
	//if (Wating < 1)	//���[�v�J�E���g��1��菬�����Ȃ�
	//{
	//	FrameNum++;	//�t���[���J�E���g�𑝂₷

	//	if (FrameNum > FRAME_RATE)	//�t���[���J�E���g�����̒l�𒴂�����
	//	{
	//		Wating++;	//���[�v�J�E���g�𑝂₷
	//		FrameNum = 0;	//�t���[���J�E���g�����Z�b�g
	//	}
	//}

	//else if (Wating >= 1)	//���[�v�J�E���g��1�ȏ�ɂȂ�����
	//{
	//}
}

void DrawSlime()	//�X���C���`�揈��
{
	if (slimeInfo[HandleIndex][KindIndex].isDraw)	//�`��t���O��true�Ȃ�
	{
		DrawRotaGraph((int)slimeInfo[HandleIndex][KindIndex].PosX,
					  (int)slimeInfo[HandleIndex][KindIndex].PosY,
					  1.0f, 0.0f, slimeInfo[HandleIndex][KindIndex].ImageHandle, true);	//�X���C���摜�`��
	}
}

void FinSlime()		//�X���C���㏈��
{
	for (int i = 0; i < SLIME_NUM; i++)
	{
		for (int j = 0; j < SLIME_KIND; j++)
		{
			DeleteGraph(slimeInfo[i][j].ImageHandle);	//�X���C���摜�j��
		}
	}
}

void SpornSlime()	//�X���C���X�|�[������
{
	GetRand(1);		//�X���C���̎�ނ������_���Ɍ��߂�
	slimeInfo[HandleIndex][KindIndex].isDraw = true;	//�`��t���O�𗧂Ă�
	HandleIndex++;	//���̃X���C���ɂ���
}