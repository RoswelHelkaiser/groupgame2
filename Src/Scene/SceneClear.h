#pragma once

#define BACK_CLEAR		("Data/ClearImage/BgClear.png")		//�N���A�̔w�i�摜�̃p�X
#define RESULT_PATH		("Data/ClearImage/Result.png")		//���U���g�����̃p�X
#define TEXT_PATH		("Data/ClearImage/Text.png")		//�u�܂����H�v�̃p�X
#define CONTINUE_PATH	("Data/ClearImage/Continue.png")	//�u���������I�v�̃p�X
#define BACK_TITLE_PATH	("Data/ClearImage/BackTitle.png")	//�u�����������ȁB�v�̃p�X	

void InitClear();	//�N���A������

void StepClear();	//�N���A�ʏ폈��

void DrawClear();	//�N���A�`�揈��

void FinClear();	//�N���A�㏈��