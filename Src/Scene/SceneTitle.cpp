#include "DxLib.h"
#include "Scene.h"
#include "SceneTitle.h"

int BackImage;	//�^�C�g���w�i�摜�n���h��

int Start_BGM;	//BGM�n���h��

void InitTitle()	//�^�C�g��������
{
	BackImage = LoadGraph(BACK_PATH);	//�^�C�g���w�i�摜�ǂݍ���

	Start_BGM = LoadSoundMem(START_BGM_PATH);	//BGM�ǂݍ���

	ChangeVolumeSoundMem(255 * 50 / 100, Start_BGM);	//BGM�̉��ʂ�50%�ɂ���

	PlaySoundMem(Start_BGM, DX_PLAYTYPE_LOOP, true);	//BGM�Đ�

	g_CurrentSceneID = SCENE_ID_LOOP_TITLE;	//�^�C�g�����[�v�ֈړ�
}

void StepTitle()	//�^�C�g���ʏ폈��
{
	if (IsKeyPush(KEY_INPUT_RETURN))	//Enter�L�[�������ꂽ��
	{
		g_CurrentSceneID = SCENE_ID_FIN_TITLE;	//�^�C�g���㏈���ֈړ�
	}
}

void DrawTitle()	//�^�C�g���`�揈��
{
	DrawGraph(0, 0, BackImage, true);	//�^�C�g���w�i�摜�`��
}

//�^�C�g���㏈��
void FinTitle()
{
	DeleteGraph(BackImage);	//�^�C�g���w�i�摜�j��

	StopSoundMem(Start_BGM);	//BGM��~

	DeleteSoundMem(Start_BGM);	//BGM�j��

	g_CurrentSceneID = SCENE_ID_INIT_PLAY;	//�v���C�V�[���ֈړ�
}
