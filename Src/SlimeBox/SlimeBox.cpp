#include "DxLib.h"
#include "SlimeBox.h"

BoxInfo boxInfo[BOX_NUM] = { 0 };	//箱情報構造体の宣言

void InitBox()	//箱の初期化
{
	BoxInfo* box = boxInfo;	//箱情報取得
	for (int i = 0; i < BOX_NUM; i++, box++)
	{
		box->BoxHandle[0] = LoadGraph(GREEN_BOX_PATH);	//緑の箱画像読み込み
		box->BoxHandle[1] = LoadGraph(RED_BOX_PATH);	//赤の箱画像読み込み
		box->PosY = 500.0f;
	}
	boxInfo[0].PosX = 200.0f;	//緑の箱のX座標をセット
	boxInfo[1].PosX = 1080.0f;	//赤の箱のX座標をセット
}

void DrawBox()	//箱描画処理
{
	BoxInfo* box = boxInfo;	//箱情報取得
	DrawRotaGraph((int)boxInfo[0].PosX, (int)boxInfo[0].PosY, 0.75f, 0.0f, boxInfo[0].BoxHandle[0], true);	//緑の箱画像描画
	DrawRotaGraph((int)boxInfo[1].PosX, (int)boxInfo[1].PosY, 0.75f, 0.0f, boxInfo[1].BoxHandle[1], true);	//緑の箱画像描画
}

void FinBox()	//箱後処理
{
	BoxInfo* box = boxInfo;	//箱情報取得
	for (int i = 0; i < BOX_NUM; i++, box++)
	{
		for (int j = 0; j < BOX_NUM; j++)
		{
			DeleteGraph(box->BoxHandle[j]);	//箱画像破棄
		}
	}
}

BoxInfo* GetBoxInfo()	//箱情報取得
{
	return boxInfo;
}
