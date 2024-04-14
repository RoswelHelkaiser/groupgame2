#pragma once

#define MAX_BONUS	(5)	//�{�[�i�X�̍ő�l
#define MINUS_NUM	(3)	//���_������

enum NUMBER_IMAGE	//�����̎��
{
	NUMBER_0 = 0,	//0
	NUMBER_1,		//1
	NUMBER_2,		//2
	NUMBER_3,		//3
	NUMBER_4,		//4
	NUMBER_5,		//5
	NUMBER_6,		//6
	NUMBER_7,		//7
	NUMBER_8,		//8
	NUMBER_9,		//9

	NUMBER_NUM,
};

const char NumberImage_Path[NUMBER_NUM][100] =
{
	"Data/PlayImage/Text/0.png",	//0
	"Data/PlayImage/Text/1.png",	//1
	"Data/PlayImage/Text/2.png",	//2
	"Data/PlayImage/Text/3.png",	//3
	"Data/PlayImage/Text/4.png",	//4
	"Data/PlayImage/Text/5.png",	//5
	"Data/PlayImage/Text/6.png",	//6
	"Data/PlayImage/Text/7.png",	//7
	"Data/PlayImage/Text/8.png",	//8
	"Data/PlayImage/Text/9.png",	//9
};

struct ScoreInfo	//�X�R�A���\����
{
	int ScoreHandle[NUMBER_NUM];	//�����摜�n���h��
	int CurrentScore;	//���݂̃X�R�A
	int ChainBonus;		//�A�������{�[�i�X
	int Minus;			//���_�X�R�A
};

void InitScore();	//�X�R�A�̏�����

void DrawScore();	//�X�R�A�`�揈��

void FinScore();	//�X�R�A�㏈��

void LoadScore(NUMBER_IMAGE type);	//�����摜�ǂݍ���

ScoreInfo* GetScoreInfo();	//�X�R�A���擾

