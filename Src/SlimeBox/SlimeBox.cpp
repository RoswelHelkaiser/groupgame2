#include "DxLib.h"
#include "SlimeBox.h"

BoxInfo boxInfo[BOX_NUM] = { 0 };	//” î•ñ\‘¢‘Ì‚ÌéŒ¾

void InitBox()	//” ‚Ì‰Šú‰»
{
	BoxInfo* box = boxInfo;	//” î•ñŽæ“¾
	for (int i = 0; i < BOX_NUM; i++, box++)
	{
		box->BoxHandle[0] = LoadGraph(GREEN_BOX_PATH);	//—Î‚Ì” ‰æ‘œ“Ç‚Ýž‚Ý
		box->BoxHandle[1] = LoadGraph(RED_BOX_PATH);	//Ô‚Ì” ‰æ‘œ“Ç‚Ýž‚Ý
		box->PosX = i * 1000.0f + 140.0f;
		box->PosY = 360.0f;
	}
}

void DrawBox()	//” •`‰æˆ—
{
	BoxInfo* box = boxInfo;	//” î•ñŽæ“¾
	for (int i = 0; i < BOX_NUM; i++, box++)
	{
		for (int j = 0; j < BOX_NUM; j++)
		{
			DrawRotaGraph((int)box->PosX, (int)box->PosY, 1.0f, 0.0f, box->BoxHandle[j], true);	//” ‰æ‘œ•`‰æ
		}
	}
}

void FinBox()	//” Œãˆ—
{
	BoxInfo* box = boxInfo;	//” î•ñŽæ“¾
	for (int i = 0; i < BOX_NUM; i++, box++)
	{
		for (int j = 0; j < BOX_NUM; j++)
		{
			DeleteGraph(box->BoxHandle[j]);	//” ‰æ‘œ”jŠü
		}
	}
}

BoxInfo* GetBoxInfo()	//” î•ñŽæ“¾
{
	return boxInfo;
}
