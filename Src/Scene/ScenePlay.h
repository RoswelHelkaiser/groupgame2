#pragma once

#define TIME_MAX_NUM	(10)	//�������Ԃ̃}�b�N�X

#define READY_PATH	("Data/PlayImage/Text/Ready.png")	//�uReady?�v�̃p�X
#define GO_PATH		("Data/PlayImage/Text/Go.png")		//�uGo!�v�̃p�X
#define FINISH_PATH	("Data/PlayImage/Text/Finish.png")	//�uFinish!�v�̃p�X
#define TEXT_NUM	(3)	//�����̐�

//�����N���X
class Text
{
	public:	//�����o�ϐ��ꗗ
		int TextHandle[TEXT_NUM];	//�摜�n���h��
		int HandleIndex;	//�摜�n���h���Y�����p�ϐ�
		float PosX, PosY;	//X���W,Y���W
		float Size;			//�摜�̊g�嗦
		bool isDraw;		//�`��t���O
		int Frame;			//�t���[���J�E���g�p�ϐ�
		int  Loop;			//���[�v�J�E���g�p�ϐ�
		bool isStart;		//�Q�[�����X�^�[�g������t���O

	public:	//���\�b�h�ꗗ
		Text()	//�R���X�g���N�^(�S�Ă̏���������)
		{
			for (int i = 0; i < TEXT_NUM; i++)
			{
				TextHandle[i] = 0;
			}
			HandleIndex = 0;
			PosX = 0.0f;
			PosY = 0.0f;
			Size = 0.0f;
			isDraw = false;
			Frame = 0;
			Loop = 0;
			isStart = false;
		}

		void InitText()	//�����̏�����
		{
			TextHandle[0] = LoadGraph(READY_PATH);	//�uReady?�v�ǂݍ���
			TextHandle[1] = LoadGraph(GO_PATH);		//�uGo!�v�ǂݍ���
			TextHandle[2] = LoadGraph(FINISH_PATH);	//�uFinish!�v�ǂݍ���
			HandleIndex = 0;	//�ŏ��́uReady?�v���\�������
			PosX = 640.0f;		//X���W����ʂ̒��S��
			PosY = 360.0f;		//Y���W����ʂ̒��S��
			Size = 1.0f;		//�T�C�Y�͓��{
			isDraw = true;		//�`��t���O�𗧂Ă�
			Frame = 0;			//�t���[���J�E���g�����Z�b�g
			Loop = 0;			//���[�v�J�E���g�����Z�b�g
			isStart = false;	//�������Ԃ�i�܂��Ȃ�
		}

		void StepText()	//�����ʏ폈��
		{
			Size += 0.02f;	//�������摜��傫������

			if (Loop < 2)	//���[�v�J�E���g��2��菬�����Ȃ�
			{
				Frame++;	//�t���[���J�E���g�𑝂₷

				if (Frame > FRAME_RATE)	//�t���[���J�E���g�����̒l�𒴂�����
				{
					Loop++;		//���[�v�J�E���g�𑝂₷
					Frame = 0;	//�t���[���J�E���g�����Z�b�g
				}
			}

			else if (Loop >= 2)	//���[�v�J�E���g��2�ȏ�ɂȂ�����
			{
				Size = 1.0f;	//�傫���𓙔{�ɖ߂�

				if (HandleIndex == 0)	//�uReady?�v�Ȃ�
				{
					HandleIndex = 1;	//�uGo!�v�ɂ���
					Loop = 0;
				}

				else if (HandleIndex == 1)	//�uGo!�v�Ȃ�
				{
					isDraw = false;	//�`��t���O��܂�
					isStart = true;	//�������Ԃ�i�܂���
				}
			}
		}

		void DrawTextImage()	//�����`�揈��
		{
			if (isDraw)	//�`��t���O��true�Ȃ�
			{
				DrawRotaGraph((int)PosX, (int)PosY, (double)Size, 0.0f, TextHandle[HandleIndex], true);
			}
		}

		void FinText()	//�����㏈��
		{
			for (int i = 0; i < TEXT_NUM; i++)
			{
				DeleteGraph(TextHandle[i]);	//�摜�j��
			}
		}
};

void InitPlay();	//�v���C�V�[��������

void StepPlay();	//�v���C�V�[���ʏ폈��

void DrawPlay();	//�v���C�V�[���`�揈��

void FinPlay();		//�v���C�V�[���㏈��
