#include "DxLib.h"
#include "../Common.h"
#include "Slime.h"

SlimeInfo slimeInfo[SLIME_NUM] = { 0 }; //�X���C�����\���̂̐錾

int HandleIndex;	//�摜�n���h���Y�����p�ϐ�

int FrameNum;	//�t���[���J�E���g�p�ϐ�

int Waiting;		//���[�v�J�E���g�p�ϐ�

void InitSlime()	//�X���C���̏�����
{
	SlimeInfo* slime = slimeInfo;	//�X���C�����擾
	for (int i = 0; i < SLIME_NUM; i++, slime++)
	{
		slime->ImageHandle[0] = LoadGraph(SLIME_GREEN_PATH);	//�X���C��(��)�摜�ǂݍ���
		slime->ImageHandle[1] = LoadGraph(SLIME_RED_PATH);	//�X���C��(��)�摜�ǂݍ���
		slime->KindIndex = 0;	//�Y���������Z�b�g
		slime->PosX = 640.0f;	//����X���W��ݒ�
		slime->PosY = 360.0f;	//����Y���W��ݒ�
		slime->isDraw = false;	//�`��t���O��܂�
	}

	HandleIndex = 0;	//�Y������0�Ƀ��Z�b�g

	FrameNum = 0;	//�t���[���J�E���g�����Z�b�g

	Waiting = 0;		//���[�v�J�E���g�����Z�b�g
}

void StepSlime()	//�X���C���ʏ폈��
{
	SlimeInfo* slime = slimeInfo;	//�X���C�����擾
}

void DrawSlime()	//�X���C���`�揈��
{
	SlimeInfo* slime = slimeInfo;	//�X���C�����擾
	for (int i = 0; i < SLIME_NUM; i++, slime++)
	{
		if (slime->isDraw)	//�`��t���O��true�Ȃ�
		{
			DrawRotaGraph((int)slime->PosX, (int)slime->PosY,
						  1.0f, 0.0f, slime->ImageHandle[slime->KindIndex], true);	//�X���C���摜�`��
		}
	}
}

void FinSlime()		//�X���C���㏈��
{
	SlimeInfo* slime = slimeInfo;	//�X���C�����擾
	for (int i = 0; i < SLIME_NUM; i++, slime++)
	{
		for (int j = 0; j < SLIME_KIND; j++)
		{
			DeleteGraph(slime->ImageHandle[j]);	//�X���C���摜�j��
		}
	}
}

void SpornSlime()	//�X���C���X�|�[������
{
	slimeInfo[HandleIndex].KindIndex = GetRand(1);			//�X���C���̎�ނ������_���Ɍ��߂�
	slimeInfo[HandleIndex].PosX = GetRand(600) + 328.0f;	//X���W�������_���ɃZ�b�g
	slimeInfo[HandleIndex].PosY = GetRand(400) + 200.0f;
	slimeInfo[HandleIndex].isDraw = true;	//�`��t���O�𗧂Ă�
	HandleIndex++;	//���̃X���C���ɂ���
}

SlimeInfo* GetSlimeInfo()	//�X���C�����擾
{
	return slimeInfo;
}