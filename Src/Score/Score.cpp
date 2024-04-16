#include "DxLib.h"
#include "Score.h"

ScoreInfo scoreInfo = { 0 };	//�X�R�A���\���̂̐錾

void InitScore()	//�X�R�A������
{
	LoadScore(NUMBER_0);	//0�ǂݍ���
	LoadScore(NUMBER_1);	//1�ǂݍ���
	LoadScore(NUMBER_2);	//2�ǂݍ���
	LoadScore(NUMBER_3);	//3�ǂݍ���
	LoadScore(NUMBER_4);	//4�ǂݍ���
	LoadScore(NUMBER_5);	//5�ǂݍ���
	LoadScore(NUMBER_6);	//6�ǂݍ���
	LoadScore(NUMBER_7);	//7�ǂݍ���
	LoadScore(NUMBER_8);	//8�ǂݍ���
	LoadScore(NUMBER_9);	//9�ǂݍ���
	scoreInfo.CurrentScore = 0;	//���݂̃X�R�A
	scoreInfo.ChainBonus = 1;		//�A�������{�[�i�X
	scoreInfo.Minus = MINUS_NUM;	//���_�X�R�A
}

void StepScore()	//�X�R�A�ʏ폈��
{
	if (scoreInfo.ChainBonus >= MAX_BONUS)	//�{�[�i�X���_���ő�l�𒴂�����
	{
		scoreInfo.ChainBonus = MAX_BONUS;	//�{�[�i�X���_���ő�l�ɂ���
	}
}

void DrawScore()	//�X�R�A�`�揈��
{
	DrawFormatString(600, 90, GetColor(255, 255, 255), "Score:%d", scoreInfo.CurrentScore);
}

void FinScore()		//�X�R�A�㏈��
{
	for (int i = 0; i < NUMBER_NUM; i++)
	{
		DeleteGraph(scoreInfo.ScoreHandle[i]);	//�����摜�j��
	}
}

void LoadScore(NUMBER_IMAGE type)	//�����摜�ǂݍ���
{
	scoreInfo.ScoreHandle[type] = LoadGraph(NumberImage_Path[type]);
}

ScoreInfo* GetScoreInfo()	//�X�R�A���擾
{
	return &scoreInfo;
}
