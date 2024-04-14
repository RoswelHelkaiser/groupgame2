#include "DxLib.h"
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
		green->PosY = 360.0f;	//����Y���W��ݒ�
		green->isDraw = false;	//�`��t���O��܂�
		green->AnimeFrame = 0;	//�A�j���t���[�������Z�b�g
		green->isGoal = false;	//�S�[�����B�t���O��܂�
	}

	for (int i = 0; i < SLIME_NUM; i++, red++)
	{
		red->KindIndex = 0;		//�Y���������Z�b�g
		red->PosX = 640.0f;		//����X���W��ݒ�
		red->PosY = 360.0f;		//����Y���W��ݒ�
		red->isDraw = false;	//�`��t���O��܂�
		red->AnimeFrame = 0;	//�A�j���t���[�������Z�b�g
		red->isGoal = false;	//�S�[�����B�t���O��܂�
	}

	HandleIndex = 0;	//�Y������0�Ƀ��Z�b�g

	ColorType = 0;	//0�Ȃ��,1�Ȃ��
}

void StepSlime()	//�X���C���ʏ폈��
{
	SlimeInfo* green = greenslimeInfo;	//�X���C��(��)���擾
	SlimeInfo* red = redslimeInfo;	//�X���C��(��)���擾

	ChangeSlime(); //�X���C���̃A�j���[�V��������
	GetMousePoint(&MouseX, &MouseY);	//�}�E�X�J�[�\���̈ʒu���擾

	for (int i = 0; i < SLIME_NUM; i++, green++)
	{
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)	//�}�E�X�̍��{�^����������Ă���Ȃ�
		{
			if (green->PosX - 45.0f < MouseX && MouseX < green->PosX + 45.0f)	//X�������ŃJ�[�\�����X���C���Ɠ������Ă���Ȃ�
			{
				if (green->PosY - 45.0f < MouseY && MouseY < green->PosY + 45.0f)	//Y�������ŃJ�[�\�����X���C���Ɠ������Ă���Ȃ�
				{
					green->PosX = (float)MouseX;	//X���W���J�[�\���ɍ��킹��
					green->PosY = (float)MouseY;	//Y���W���J�[�\���ɍ��킹��
				}
			}
		}
	}

	for (int i = 0; i < SLIME_NUM; i++, red++)
	{
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)	//�}�E�X�̍��{�^����������Ă���Ȃ�
		{
			if (red->PosX - 45.0f < MouseX && MouseX < red->PosX + 45.0f)	//X�������ŃJ�[�\�����X���C���Ɠ������Ă���Ȃ�
			{
				if (red->PosY - 45.0f < MouseY && MouseY < red->PosY + 45.0f)	//Y�������ŃJ�[�\�����X���C���Ɠ������Ă���Ȃ�
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
			greenslimeInfo[HandleIndex].PosX = GetRand(400) + 400.0f;	//X���W�������_���ɃZ�b�g
			greenslimeInfo[HandleIndex].PosY = GetRand(400) + 200.0f;	//Y���W�������_���ɃZ�b�g
			greenslimeInfo[HandleIndex].isDraw = true;	//�`��t���O�𗧂Ă�
		}
		break;

		case 1:	//�ԂȂ�
		{
			redslimeInfo[HandleIndex].PosX = GetRand(400) + 400.0f;	//X���W�������_���ɃZ�b�g
			redslimeInfo[HandleIndex].PosY = GetRand(400) + 200.0f;	//Y���W�������_���ɃZ�b�g
			redslimeInfo[HandleIndex].isDraw = true;	//�`��t���O�𗧂Ă�
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

void JudgeSlime()	//�d�����������Ă��邩���f
{
	BoxInfo* boxInfo = GetBoxInfo();	//�����擾
	ScoreInfo* scoreInfo = GetScoreInfo();	//�X�R�A���擾
	switch (ColorType)	//�F�ŏꍇ����
	{
		case 0:	//�΂Ȃ�
		{
			SlimeInfo* green = greenslimeInfo;	//�X���C��(��)���擾
			for (int i = 0; i < SLIME_NUM; i++, green++)
			{
				if ((GetMouseInput() & MOUSE_INPUT_LEFT) == 0)	//�}�E�X�̍��{�^���������ꂽ��
				{
					if (green->PosX < boxInfo[0].PosX - 200.0f && boxInfo[0].PosX + 200.0f < green->PosX)	//X�������ɗ΂̔��ƃX���C��(��)���������Ă���Ȃ�
					{
						if (green->PosY < boxInfo[0].PosY - 150.0f && boxInfo[0].PosX + 200.0f < green->PosY)	//Y�������ɗ΂̔��ƃX���C��(��)���������Ă���Ȃ�
						{
							scoreInfo->CurrentScore += scoreInfo->ChainBonus;	//�X�R�A�����Z
							scoreInfo->ChainBonus++;	//�{�[�i�X�����Z
							green->isGoal = true;	//�S�[�����B�t���O�𗧂Ă�
							green->isDraw = false;	//�`��t���O��܂�
						}
					}
					else if (green->PosX < boxInfo[1].PosX - 200.0f && boxInfo[1].PosX + 200.0f < green->PosX)	//X�������ɐԂ̔��ƃX���C��(��)���������Ă���Ȃ�
					{
						if (green->PosY < boxInfo[1].PosY - 150.0f && boxInfo[1].PosX + 200.0f < green->PosY)	//Y�������ɐԂ̔��ƃX���C��(��)���������Ă���Ȃ�
						{
							scoreInfo->CurrentScore -= scoreInfo->Minus;	//�X�R�A�����Z
							green->isGoal = true;	//�S�[�����B�t���O�𗧂Ă�
							green->isDraw = false;	//�`��t���O��܂�
						}
					}
				}
			}
		}
		break;

		case 1:	//�ԂȂ�
		{
			SlimeInfo* red = redslimeInfo;	//�X���C��(��)���擾
			for (int i = 0; i < SLIME_NUM; i++, red++)
			{
				if ((GetMouseInput() & MOUSE_INPUT_LEFT) == 0)	//�}�E�X�̍��{�^���������ꂽ��
				{
					if (red->PosX < boxInfo[0].PosX - 200.0f && boxInfo[0].PosX + 200.0f < red->PosX)	//X�������ɗ΂̔��ƃX���C��(��)���������Ă���Ȃ�
					{
						if (red->PosY < boxInfo[0].PosY - 150.0f && boxInfo[0].PosX + 200.0f < red->PosY)	//Y�������ɗ΂̔��ƃX���C��(��)���������Ă���Ȃ�
						{
							scoreInfo->CurrentScore -= scoreInfo->Minus;	//�X�R�A�����Z
							red->isGoal = true;	//�S�[�����B�t���O�𗧂Ă�
							red->isDraw = false;	//�`��t���O��܂�
						}
					}
					else if (red->PosX < boxInfo[1].PosX - 200.0f && boxInfo[1].PosX + 200.0f < red->PosX)	//X�������ɐԂ̔��ƃX���C��(��)���������Ă���Ȃ�
					{
						if (red->PosY < boxInfo[1].PosY - 150.0f && boxInfo[1].PosX + 200.0f < red->PosY)	//Y�������ɐԂ̔��ƃX���C��(��)���������Ă���Ȃ�
						{
							scoreInfo->CurrentScore += scoreInfo->ChainBonus;	//�X�R�A�����Z
							scoreInfo->ChainBonus++;	//�{�[�i�X�����Z
							red->isGoal = true;	//�S�[�����B�t���O�𗧂Ă�
							red->isDraw = false;	//�`��t���O��܂�
						}
					}
				}
			}
		}
		break;
	}
}

SlimeInfo* GetSlimeInfo()	//�X���C�����擾
{
	return greenslimeInfo;
	return redslimeInfo;
}