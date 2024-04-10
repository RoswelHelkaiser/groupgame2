#pragma once

#define BACK_CLEAR		("Data/ClearImage/BgClear.png")		//クリアの背景画像のパス
#define RESULT_PATH		("Data/ClearImage/Result.png")		//リザルト文字のパス
#define TEXT_PATH		("Data/ClearImage/Text.png")		//「まだやる？」のパス
#define CONTINUE_PATH	("Data/ClearImage/Continue.png")	//「もっかい！」のパス
#define BACK_TITLE_PATH	("Data/ClearImage/BackTitle.png")	//「もういいかな。」のパス	

void InitClear();	//クリア初期化

void StepClear();	//クリア通常処理

void DrawClear();	//クリア描画処理

void FinClear();	//クリア後処理