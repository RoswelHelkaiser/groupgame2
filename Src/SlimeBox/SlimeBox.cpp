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
		box->PosX = i * 1000.0f + 140.0f;
		box->PosY = 360.0f;
	}
}

void DrawBox()	//���`�揈��
{
	BoxInfo* box = boxInfo;	//�����擾
	for (int i = 0; i < BOX_NUM; i++, box++)
	{
		for (int j = 0; j < BOX_NUM; j++)
		{
			DrawRotaGraph((int)box->PosX, (int)box->PosY, 1.0f, 0.0f, box->BoxHandle[j], true);	//���摜�`��
		}
	}
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
