#pragma once

#define SLIME_GREEN_PATH	("Data/PlayImage/Slime/SlimeGreen.png")	//�X���C��(��)�̃p�X
#define SLIME_RED_PATH		("Data/PlayImage/Slime/SlimeRed.png")	//�X���C��(��)�̃p�X
#define SLIME_NUM	(175)	//�X���C���̃X�|�[����
#define SLIME_KIND	(2)		//�X���C���̎��

struct SlimeInfo	//�X���C�����\����
{
	int ImageHandle[SLIME_KIND];	//�摜�n���h��
	int KindIndex;		//�X���C���̎�ޗp�ϐ�
	float PosX, PosY;	//X���W,Y���W
	bool isDraw;		//�`��t���O
};

void InitSlime();	//�X���C���̏�����

void StepSlime();	//�X���C���ʏ폈��

void DrawSlime();	//�X���C���`�揈��

void FinSlime();	//�X���C���㏈��

void SpornSlime();	//�X���C���X�|�[������

SlimeInfo* GetSlimeInfo();	//�X���C�����擾
