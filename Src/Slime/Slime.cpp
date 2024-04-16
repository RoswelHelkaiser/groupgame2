#include "DxLib.h"
#include "../Collision/Collision.h"
#include "../Common.h"
#include "../Input/Input.h"
#include "Slime.h"
#include "../SlimeBox/SlimeBox.h"
#include "../Score/Score.h"

SlimeInfo greenslimeInfo[SLIME_NUM] = { 0 }; //�X���C��(��)���\���̂̐錾

SlimeInfo redslimeInfo[SLIME_NUM] = { 0 }; //�X���C��(��)���\���̂̐錾

int HandleIndex;	//�摜�n���h���Y�����p�ϐ�

int ColorType;	//�X���C���̐F

int MouseX, MouseY;	//�}�E�X�J�[�\����X���W,Y���W

int ScorePosX,ScorePosY;	//�X�R�A����Y���W

int CountFrame;		//�t���[���J�E���g�p�ϐ�

int GetScoreHandle[6];	//�X�R�A�����摜�n���h��

int GetScoreIndex;	//�X�R�A�����Y�����p�ϐ�

bool isGetScoreDraw;	//�X�R�A�����`��t���O

int SoundHandle[2];	//���ʉ��n���h��

void InitSlime()	//�X���C���̏�����
{
	SlimeInfo* green = greenslimeInfo;	//�X���C��(��)���擾
	SlimeInfo* red = redslimeInfo;	//�X���C��(��)���擾

	//�X���C��(��)�摜�ǂݍ���
	LoadGreenSlime(GREEN_SLIME_1);	//Green_Slime1
	LoadGreenSlime(GREEN_SLIME_2);	//Green_Slime2
	LoadGreenSlime(GREEN_SLIME_3);	//Green_Slime3
	LoadGreenSlime(GREEN_SLIME_4);	//Green_Slime4
	LoadGreenSlime(GREEN_SLIME_5);	//Green_Slime5

	//�X���C��(��)�摜�ǂݍ���
	LoadRedSlime(RED_SLIME_1);	//Red_Slime1
	LoadRedSlime(RED_SLIME_2);	//Red_Slime2
	LoadRedSlime(RED_SLIME_3);	//Red_Slime3
	LoadRedSlime(RED_SLIME_4);	//Red_Slime4
	LoadRedSlime(RED_SLIME_5);	//Red_Slime5

	for (int i = 0; i < SLIME_NUM; i++, green++)
	{
		green->KindIndex = 0;	//�Y���������Z�b�g
		green->PosX = 640.0f;	//����X���W��ݒ�
		green->PosY = 150.0f;	//����Y���W��ݒ�
		green->isDraw = false;	//�`��t���O��܂�
		green->AnimeFrame = 0;	//�A�j���t���[�������Z�b�g
		green->isGoal = false;	//�S�[�����B�t���O��܂�
	}

	for (int i = 0; i < SLIME_NUM; i++, red++)
	{
		red->KindIndex = 0;		//�Y���������Z�b�g
		red->PosX = 640.0f;		//����X���W��ݒ�
		red->PosY = 150.0f;		//����Y���W��ݒ�
		red->isDraw = false;	//�`��t���O��܂�
		red->AnimeFrame = 0;	//�A�j���t���[�������Z�b�g
		red->isGoal = false;	//�S�[�����B�t���O��܂�
	}

	HandleIndex = 0;	//�Y������0�Ƀ��Z�b�g

	ColorType = 0;	//0�Ȃ��,1�Ȃ��

	GetScoreHandle[0] = LoadGraph(PLUS_1_PATH);	 //�u+1�v�摜�ǂݍ���
	GetScoreHandle[1] = LoadGraph(PLUS_2_PATH);	 //�u+2�v�摜�ǂݍ���
	GetScoreHandle[2] = LoadGraph(PLUS_3_PATH);	 //�u+3�v�摜�ǂݍ���
	GetScoreHandle[3] = LoadGraph(PLUS_4_PATH);	 //�u+4�v�摜�ǂݍ���
	GetScoreHandle[4] = LoadGraph(PLUS_5_PATH);	 //�u+5�v�摜�ǂݍ���
	GetScoreHandle[5] = LoadGraph(MINUS_3_PATH); //�u-3�v�摜�ǂݍ���

	ScorePosX = 0;		//X���W��ݒ�
	ScorePosY = 450;	//Y���W��ݒ�

	SoundHandle[0] = LoadSoundMem(CORRECT_SOUND_PATH);	//�������ʉ��ǂݍ���
	SoundHandle[1] = LoadSoundMem(WRONG_SOUND_PATH);	//�s�������ʉ��ǂݍ���
}

void StepSlime()	//�X���C���ʏ폈��
{
	SlimeInfo* green = greenslimeInfo;	//�X���C��(��)���擾
	SlimeInfo* red = redslimeInfo;	//�X���C��(��)���擾

	ChangeSlime(); //�X���C���̃A�j���[�V��������
	GetMousePoint(&MouseX, &MouseY);	//�}�E�X�J�[�\���̈ʒu���擾

	for (int i = 0; i < SLIME_NUM; i++, green++)
	{
		green->PosY += SLIME_SPEED;	//Y���W�����ɓ�����

		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)	//�}�E�X�̍��{�^����������Ă���Ȃ�
		{
			if (green->PosX - 50.0f < MouseX && MouseX < green->PosX + 50.0f)	//X�������ŃJ�[�\�����X���C���Ɠ������Ă���Ȃ�
			{
				if (green->PosY - 50.0f < MouseY && MouseY < green->PosY + 50.0f)	//Y�������ŃJ�[�\�����X���C���Ɠ������Ă���Ȃ�
				{
					green->PosX = (float)MouseX;	//X���W���J�[�\���ɍ��킹��
					green->PosY = (float)MouseY;	//Y���W���J�[�\���ɍ��킹��
				}
			}
		}
	}
	

	for (int i = 0; i < SLIME_NUM; i++, red++)
	{
		red->PosY += SLIME_SPEED;	//Y���W�����ɓ�����

		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)	//�}�E�X�̍��{�^����������Ă���Ȃ�
		{
			if (red->PosX - 50.0f < MouseX && MouseX < red->PosX + 50.0f)	//X�������ŃJ�[�\�����X���C���Ɠ������Ă���Ȃ�
			{
				if (red->PosY - 50.0f < MouseY && MouseY < red->PosY + 50.0f)	//Y�������ŃJ�[�\�����X���C���Ɠ������Ă���Ȃ�
				{
					red->PosX = (float)MouseX;	//X���W���J�[�\���ɍ��킹��
					red->PosY = (float)MouseY;	//Y���W���J�[�\���ɍ��킹��
				}
			}
		}
	}
}

void DrawSlime()	//�X���C���`�揈��
{
	SlimeInfo* green = greenslimeInfo;	//�X���C��(��)���擾
	for (int i = 0; i < SLIME_NUM; i++, green++)
	{
		if (green->isDraw)	//�`��t���O��true�Ȃ�
		{
			DrawRotaGraph((int)green->PosX, (int)green->PosY,
						  1.0f, 0.0f, greenslimeInfo[HandleIndex].ImageHandle[green->KindIndex], true);	//�X���C���摜�`��
		}
	}

	SlimeInfo* red = redslimeInfo;	//�X���C��(��)���擾
	for (int i = 0; i < SLIME_NUM; i++, red++)
	{
		if (red->isDraw)	//�`��t���O��true�Ȃ�
		{
			DrawRotaGraph((int)red->PosX, (int)red->PosY,
						  1.0f, 0.0f, redslimeInfo[HandleIndex].ImageHandle[red->KindIndex], true);	//�X���C���摜�`��
		}
	}

	if (isGetScoreDraw)	//�X�R�A�����`��t���O��true�Ȃ�
	{
		DrawRotaGraph(ScorePosX, ScorePosY, 1.0f, 0.0f, GetScoreHandle[GetScoreIndex], true);	//�X�R�A�����`��
		ScorePosY -= 5;	//Y���W����Ɉړ�
		CountFrame++;	//�t���[���J�E���g�𑝂₷
	}

	if (CountFrame >= FRAME_RATE / 2)	//�t���[���J�E���g�����̒l�ɒB������
	{
		isGetScoreDraw = false;	//�X�R�A�����`��t���O��܂�
		ScorePosY = 450;	//Y���W�����ɖ߂�
		CountFrame = 0;	//�t���[���J�E���g�����Z�b�g
	}

	DrawFormatString(0, 0, GetColor(255, 255, 255), "%d", ColorType);
}

void FinSlime()		//�X���C���㏈��
{
	SlimeInfo* green = greenslimeInfo;	//�X���C��(��)���擾
	for (int i = 0; i < SLIME_NUM; i++, green++)
	{
		for (int j = 0; j < SLIME_KIND; j++)
		{
			DeleteGraph(green->ImageHandle[j]);	//�X���C��(��)�摜�j��
		}
	}

	SlimeInfo* red = redslimeInfo;	//�X���C��(��)���擾
	for (int i = 0; i < SLIME_NUM; i++, red++)
	{
		for (int j = 0; j < SLIME_KIND; j++)
		{
			DeleteGraph(red->ImageHandle[j]);	//�X���C��(��)�摜�j��
		}
	}

	for (int i = 0; i < 6; i++)
	{
		DeleteGraph(GetScoreHandle[i]);	//�X�R�A�����摜�j��
	}

	for (int i = 0; i < 2; i++)
	{
		DeleteSoundMem(SoundHandle[i]);	//���ʉ��j��
	}
}

void LoadGreenSlime(GREEN_SLIME_IMAGE type)	//�X���C��(��)�摜�ǂݍ���
{
	SlimeInfo* green = greenslimeInfo;	//�X���C��(��)���擾
	for (int i = 0; i < SLIME_NUM; i++, green++)
	{
		green->ImageHandle[type] = LoadGraph(GreenSlimeImage_Path[type]);
	}
}

void LoadRedSlime(RED_SLIME_IMAGE type)	//�X���C��(��)�摜�ǂݍ���
{
	SlimeInfo* red = redslimeInfo;	//�X���C��(��)���擾
	for (int i = 0; i < SLIME_NUM; i++, red++)
	{
		red->ImageHandle[type] = LoadGraph(RedSlimeImage_Path[type]);
	}
}

void SpornSlime()	//�X���C���X�|�[������
{
	ColorType = GetRand(1);	//0��1���擾
	switch (ColorType)	//�F�ŏꍇ����
	{
		case 0:	//�΂Ȃ�
		{
			greenslimeInfo[HandleIndex].PosX = GetRand(200) + 500.0f;	//X���W�������_���ɃZ�b�g
			greenslimeInfo[HandleIndex].PosY = 150.0f;	//Y���W���Z�b�g
			greenslimeInfo[HandleIndex].isDraw = true;	//�`��t���O�𗧂Ă�
			redslimeInfo[HandleIndex].isDraw = false;	//�`��t���O��܂�
		}
		break;

		case 1:	//�ԂȂ�
		{
			redslimeInfo[HandleIndex].PosX = GetRand(200) + 500.0f;	//X���W�������_���ɃZ�b�g
			redslimeInfo[HandleIndex].PosY = 150.0f;	//Y���W���Z�b�g
			redslimeInfo[HandleIndex].isDraw = true;	//�`��t���O�𗧂Ă�
			greenslimeInfo[HandleIndex].isDraw = false;	//�`��t���O��܂�
		}
		break;
	}

	HandleIndex++;	//���̃X���C���ɂ���
}

void ChangeSlime()	//�X���C���̃A�j���[�V��������
{
	SlimeInfo* green = greenslimeInfo;	//�X���C��(��)���擾
	for (int i = 0; i < SLIME_NUM; i++, green++)
	{
		green->AnimeFrame++;	//�Đ����Ԃ��J�E���g
		if (green->AnimeFrame >= FRAME_RATE / 2)	//���̎��ԂɒB������
		{
			green->AnimeFrame = 0;	//�Đ����Ԃ����Z�b�g

			if (green->KindIndex == 4)	//�Ō�̉摜�Ȃ�
			{
				green->KindIndex = 0;	//�ŏ��̉摜�ɂ���
			}
			else	//�Ō�̉摜�łȂ��Ȃ�
			{
				green->KindIndex++;		//���̉摜�ɐ؂�ւ���
			}
		}
	}

	SlimeInfo* red = redslimeInfo;	//�X���C��(��)���擾
	for (int i = 0; i < SLIME_NUM; i++, red++)
	{
		red->AnimeFrame++;	//�Đ����Ԃ��J�E���g
		if (red->AnimeFrame >= FRAME_RATE / 2)	//���̎��ԂɒB������
		{
			red->AnimeFrame = 0;	//�Đ����Ԃ����Z�b�g

			if (red->KindIndex == 4)	//�Ō�̉摜�Ȃ�
			{
				red->KindIndex = 0;	//�ŏ��̉摜�ɂ���
			}
			else	//�Ō�̉摜�łȂ��Ȃ�
			{
				red->KindIndex++;		//���̉摜�ɐ؂�ւ���
			}
		}
	}
}

void JudgeGreenSlime()	//�X���C��(��)�̎d�����������Ă��邩���f
{
	BoxInfo* boxInfo = GetBoxInfo();	//�����擾
	ScoreInfo* scoreInfo = GetScoreInfo();	//�X�R�A���擾
	SlimeInfo* green = greenslimeInfo;	//�X���C��(��)���擾
	SlimeInfo* red = redslimeInfo;	//�X���C��(��)���擾
	for (int i = 0; i < SLIME_NUM; i++, green++)
	{		
		//�~�`�̓����蔻��p�f�[�^��p��
		float Ax = green->PosX;
		float Ay = green->PosY;
		int Ar = 32;

		float Bx = boxInfo[0].PosX;
		float By = boxInfo[0].PosY;
		float B2x = boxInfo[1].PosX;
		float B2y = boxInfo[1].PosY;
		int Br = 200;

		if (IsHitCircle((int)Ax, (int)Ay, Ar, (int)Bx, (int)By, Br))	//�΂̔��ƃX���C��(��)���������Ă���Ȃ�
		{
			if (!green->isGoal)	//�S�[�����B�t���O��false�Ȃ�
			{
				if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)	//�}�E�X�̍��{�^����������Ă���Ȃ�
				{
					PlaySoundMem(SoundHandle[0], DX_PLAYTYPE_BACK, true);	//�������ʉ��Đ�
					scoreInfo->CurrentScore += scoreInfo->ChainBonus;	//�X�R�A�����Z
					ScorePosX = 200;	//�X�R�A����X���W��ݒ�
					GetScoreIndex = scoreInfo->ChainBonus - 1;	//�X�R�A�����̓Y������ݒ�
					if (GetScoreIndex >= 4)
					{
						GetScoreIndex = 4;
					}
					scoreInfo->ChainBonus++;	//�{�[�i�X�����Z
					isGetScoreDraw = true;	//�X�R�A�����̕`��t���O�𗧂Ă�
					green->isGoal = true;	//�S�[�����B�t���O�𗧂Ă�
					green->isDraw = false;	//�`��t���O��܂�
				}
			}
		}

		else if (IsHitCircle((int)Ax, (int)Ay, Ar, (int)B2x, (int)B2y, Br))	//�Ԃ̔��ƃX���C��(��)���������Ă���Ȃ�
		{
			if (!green->isGoal)	//�S�[�����B�t���O��false�Ȃ�
			{
				if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)	//�}�E�X�̍��{�^����������Ă���Ȃ�
				{
					PlaySoundMem(SoundHandle[1], DX_PLAYTYPE_BACK, true);	//�s�������ʉ��Đ�
					scoreInfo->CurrentScore -= scoreInfo->Minus;	//�X�R�A�����Z
					scoreInfo->ChainBonus = 1;	//�{�[�i�X�����Z�b�g	
					ScorePosX = 1080;	//�X�R�A����X���W��ݒ�
					GetScoreIndex = 5;		//�X�R�A�����̓Y������ݒ�
					isGetScoreDraw = true;	//�X�R�A�����̕`��t���O�𗧂Ă�
					green->isGoal = true;	//�S�[�����B�t���O�𗧂Ă�
					green->isDraw = false;	//�`��t���O��܂�
				}
			}
		}
	}	
}

void JudgeRedSlime()	//�X���C��(��)�̎d�����������Ă��邩���f
{
	BoxInfo* boxInfo = GetBoxInfo();	//�����擾
	ScoreInfo* scoreInfo = GetScoreInfo();	//�X�R�A���擾
	SlimeInfo* red = redslimeInfo;	//�X���C��(��)���擾
	SlimeInfo* green = greenslimeInfo;	//�X���C��(��)���擾
	for (int i = 0; i < SLIME_NUM; i++, red++)
	{	
		//�~�`�̓����蔻��p�f�[�^��p��
		float Ax = red->PosX;
		float Ay = red->PosY;
		int Ar = 32;

		float Bx = boxInfo[0].PosX;
		float By = boxInfo[0].PosY;
		float B2x = boxInfo[1].PosX;
		float B2y = boxInfo[1].PosY;
		int Br = 200;

		if (IsHitCircle((int)Ax, (int)Ay, Ar, (int)Bx, (int)By, Br))	//�΂̔��ƃX���C��(��)���������Ă���Ȃ�
		{
			if (!red->isGoal)	//�S�[�����B�t���O��false�Ȃ�
			{
				if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)	//�}�E�X�̍��{�^����������Ă���Ȃ�
				{
					PlaySoundMem(SoundHandle[1], DX_PLAYTYPE_BACK, true);	//�s�������ʉ��Đ�
					scoreInfo->CurrentScore -= scoreInfo->Minus;	//�X�R�A�����Z
					scoreInfo->ChainBonus = 1;	//�{�[�i�X�����Z�b�g
					ScorePosX = 200;	//�X�R�A����X���W��ݒ�
					GetScoreIndex = 5;		//�X�R�A�����̓Y������ݒ�
					isGetScoreDraw = true;	//�X�R�A�����̕`��t���O�𗧂Ă�
					red->isGoal = true;	//�S�[�����B�t���O�𗧂Ă�
					red->isDraw = false;	//�`��t���O��܂�
				}
			}
		}

		else if (IsHitCircle((int)Ax, (int)Ay, Ar, (int)B2x, (int)B2y, Br))	//�Ԃ̔��ƃX���C��(��)���������Ă���Ȃ�
		{
			if (!red->isGoal)	//�S�[�����B�t���O��false�Ȃ�
			{
				if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)	//�}�E�X�̍��{�^����������Ă���Ȃ�
				{
					PlaySoundMem(SoundHandle[0], DX_PLAYTYPE_BACK, true);	//�������ʉ��Đ�
					scoreInfo->CurrentScore += scoreInfo->ChainBonus;	//�X�R�A�����Z
					ScorePosX = 1080;	//�X�R�A����X���W��ݒ�
					GetScoreIndex = scoreInfo->ChainBonus - 1;	//�X�R�A�����̓Y������ݒ�
					if (GetScoreIndex >= 4)
					{
						GetScoreIndex = 4;
					}
					scoreInfo->ChainBonus++;	//�{�[�i�X�����Z
					isGetScoreDraw = true;	//�X�R�A�����̕`��t���O�𗧂Ă�
					red->isGoal = true;	//�S�[�����B�t���O�𗧂Ă�
					red->isDraw = false;	//�`��t���O��܂�
				}
			}
		}		
	}
}

SlimeInfo* GetSlimeInfo()	//�X���C�����擾
{
	return greenslimeInfo;
	return redslimeInfo;
}