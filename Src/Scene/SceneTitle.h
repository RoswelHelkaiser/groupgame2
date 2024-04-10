#pragma once

#define BACK_PATH	("Data/TitleImage/BgTitle.png")		//タイトルの背景画像のパス
#define TITLE_PATH	("Data/TitleImage/TitleText.png")	//タイトル文字画像のパス
#define START_PATH	("Data/TitleImage/Start.png")		//スタート文字画像のパス

void InitTitle();	//タイトル初期化

void StepTitle();	//タイトル通常処理

void DrawTitle();	//タイトル描画処理

void FinTitle();	//タイトル後処理
