#pragma once

#define GREEN_BOX_PATH	("Data/PlayImage/Slime/GreenSlimeBox.png")	//�΂̔��摜�̃p�X
#define RED_BOX_PATH	("Data/PlayImage/Slime/RedSlimeBox.png")	//�Ԃ̔��摜�̃p�X

#define BOX_NUM	(2)	//���̐�

struct BoxInfo //�����\����
{
	int BoxHandle[BOX_NUM];	//�摜�n���h��
	float PosX, PosY;		//X���W,Y���W
};

void InitBox();	//���̏�����

void DrawBox();	//���`�揈��

void FinBox();	//���㏈��

BoxInfo* GetBoxInfo();	//�����擾
