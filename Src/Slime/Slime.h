#pragma once

#define SLIME_NUM	(175)	//�X���C���̃X�|�[����
#define SLIME_KIND	(2)		//�X���C���̎��
#define SLIME_SPEED	(1.5f)	//�X���C���̈ړ��X�s�[�h

#define PLUS_1_PATH	 ("Data/PlayImage/Text/+1.png")	//�u+1�v�摜�̃p�X
#define PLUS_2_PATH	 ("Data/PlayImage/Text/+2.png")	//�u+2�v�摜�̃p�X
#define PLUS_3_PATH	 ("Data/PlayImage/Text/+3.png")	//�u+3�v�摜�̃p�X
#define PLUS_4_PATH	 ("Data/PlayImage/Text/+4.png")	//�u+4�v�摜�̃p�X
#define PLUS_5_PATH	 ("Data/PlayImage/Text/+5.png")	//�u+5�v�摜�̃p�X
#define MINUS_3_PATH ("Data/PlayImage/Text/-3.png")	//�u-3�v�摜�̃p�X

#define CORRECT_SOUND_PATH	("Data/Sound/SE/Correct.wav")	//�������ʉ��̃p�X
#define WRONG_SOUND_PATH	("Data/Sound/SE/Wrong.wav")		//�s�������ʉ��̃p�X

enum GREEN_SLIME_IMAGE	//�X���C��(��)�摜�̎��
{
	GREEN_SLIME_1 = 0,	//Green_Slime1
	GREEN_SLIME_2 ,		//Green_Slime2
	GREEN_SLIME_3 ,		//Green_Slime3
	GREEN_SLIME_4 ,		//Green_Slime4
	GREEN_SLIME_5 ,		//Green_Slime5

	GREEN_SLIME_NUM,
};

enum RED_SLIME_IMAGE	//�X���C��(��)�摜�̎��
{
	RED_SLIME_1 = 0,	//Red_Slime1
	RED_SLIME_2,		//Red_Slime2
	RED_SLIME_3,		//Red_Slime3
	RED_SLIME_4,		//Red_Slime4
	RED_SLIME_5,		//Red_Slime5

	RED_SLIME_NUM,
};

const char GreenSlimeImage_Path[GREEN_SLIME_NUM][100] =	//�X���C��(��)�摜�̃p�X
{
	"Data/PlayImage/Slime/Green_Slime1.png",	//Green_Slime1
	"Data/PlayImage/Slime/Green_Slime2.png",	//Green_Slime2
	"Data/PlayImage/Slime/Green_Slime3.png",	//Green_Slime3
	"Data/PlayImage/Slime/Green_Slime4.png",	//Green_Slime4
	"Data/PlayImage/Slime/Green_Slime5.png",	//Green_Slime5
};

const char RedSlimeImage_Path[RED_SLIME_NUM][100] =	//�X���C��(��)�摜�̃p�X
{
	"Data/PlayImage/Slime/Red_Slime1.png",	//Green_Slime1
	"Data/PlayImage/Slime/Red_Slime2.png",	//Green_Slime2
	"Data/PlayImage/Slime/Red_Slime3.png",	//Green_Slime3
	"Data/PlayImage/Slime/Red_Slime4.png",	//Green_Slime4
	"Data/PlayImage/Slime/Red_Slime5.png",	//Green_Slime5
};

struct SlimeInfo	//�X���C�����\����
{
	int ImageHandle[10];	//�摜�n���h��
	int KindIndex;		//�X���C���̎�ޗp�ϐ�
	float PosX, PosY;	//X���W,Y���W
	bool isDraw;		//�`��t���O
	int AnimeFrame;		//�A�j���[�V�����p�ϐ�
	bool isGoal;		//�S�[�����B�t���O
};

void InitSlime();	//�X���C���̏�����

void StepSlime();	//�X���C���ʏ폈��

void DrawSlime();	//�X���C���`�揈��

void FinSlime();	//�X���C���㏈��

void LoadGreenSlime(GREEN_SLIME_IMAGE type);	//�X���C��(��)�摜�ǂݍ���

void LoadRedSlime(RED_SLIME_IMAGE type);	//�X���C��(��)�摜�ǂݍ���

void SpornSlime();	//�X���C���X�|�[������

void ChangeSlime();	//�X���C���̃A�j���[�V��������

void JudgeGreenSlime();	//�X���C��(��)�̎d�����������Ă��邩���f

void JudgeRedSlime();	//�X���C��(��)�̎d�����������Ă��邩���f

SlimeInfo* GetSlimeInfo();	//�X���C�����擾
