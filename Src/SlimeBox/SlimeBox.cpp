#include "DxLib.h"
#include "SlimeBox.h"

BoxInfo boxInfo[BOX_NUM] = { 0 };	//�����\���̂̐錾

void InitBox()	//���̏�����
{
	BoxInfo* box = boxInfo;	//�����擾
	for (int i = 0; i < BOX_NUM; i++, box++)
	{
		box->BoxHandle[0] = LoadGraph(GREEN_BOX_PATH);	//�΂̔��摜�ǂݍ���
		box->BoxHandle[1] = LoadGraph(RED_BOX_PATH);	//�Ԃ̔��摜�ǂݍ���
		box->PosY = 500.0f;
	}
	boxInfo[0].PosX = 200.0f;	//�΂̔���X���W���Z�b�g
	boxInfo[1].PosX = 1080.0f;	//�Ԃ̔���X���W���Z�b�g
}

void DrawBox()	//���`�揈��
{
	BoxInfo* box = boxInfo;	//�����擾
	DrawRotaGraph((int)boxInfo[0].PosX, (int)boxInfo[0].PosY, 0.75f, 0.0f, boxInfo[0].BoxHandle[0], true);	//�΂̔��摜�`��
	DrawRotaGraph((int)boxInfo[1].PosX, (int)boxInfo[1].PosY, 0.75f, 0.0f, boxInfo[1].BoxHandle[1], true);	//�΂̔��摜�`��
}

void FinBox()	//���㏈��
{
	BoxInfo* box = boxInfo;	//�����擾
	for (int i = 0; i < BOX_NUM; i++, box++)
	{
		for (int j = 0; j < BOX_NUM; j++)
		{
			DeleteGraph(box->BoxHandle[j]);	//���摜�j��
		}
	}
}

BoxInfo* GetBoxInfo()	//�����擾
{
	return boxInfo;
}
