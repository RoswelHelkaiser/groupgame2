#include "DxLib.h"
#include "Score.h"

ScoreInfo scoreInfo = { 0 };	//�X�R�A���\���̂̐錾

void InitScore()	//�X�R�A������
{
	//LoadScore(NUMBER_0);	//0�ǂݍ���
	//LoadScore(NUMBER_1);	//1�ǂݍ���
	//LoadScore(NUMBER_2);	//2�ǂݍ���
	//LoadScore(NUMBER_3);	//3�ǂݍ���
	//LoadScore(NUMBER_4);	//4�ǂݍ���
	//LoadScore(NUMBER_5);	//5�ǂݍ���
	//LoadScore(NUMBER_6);	//6�ǂݍ���
	//LoadScore(NUMBER_7);	//7�ǂݍ���
	//LoadScore(NUMBER_8);	//8�ǂݍ���
	//LoadScore(NUMBER_9);	//9�ǂݍ���
	scoreInfo.CurrentScore = 0;	//���݂̃X�R�A
	scoreInfo.ChainBonus = 0;		//�A�������{�[�i�X
	scoreInfo.Minus = MINUS_NUM;	//���_�X�R�A
}

void DrawScore()	//�X�R�A�`�揈��
{
	int Score = scoreInfo.CurrentScore;	//�X�R�A�����u���ϐ��ɑ��
	int count = 0;	//�J�E���g�p�ϐ�
	//while(Score > 0)	//�X�R�A��0���傫���Ȃ�
	//{
		int num = Score % 10;	//�����̓Y���������߂�
		Score /= 10;	//�X�R�A��10�Ŋ���
		DrawGraph(450 - count * 10, 0, scoreInfo.ScoreHandle[num], true);
		count++;	//�J�E���g�𑝂₷
	//}

		DrawFormatString(0, 0, GetColor(255, 255, 255), "%d", scoreInfo.CurrentScore);
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
