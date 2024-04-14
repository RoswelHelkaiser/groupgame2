#pragma once

#define BACK_CLEAR_PATH	("Data/ClearImage/BgClear.png")		//クリアの背景画像のパス
#define RESULT_PATH		("Data/ClearImage/Result.png")		//リザルト文字のパス
#define TEXT_PATH		("Data/ClearImage/Text.png")		//「まだやる？」画像のパス
#define CONTINUE_PATH	("Data/ClearImage/Continue.png")	//「もっかい！」画像のパス
#define BACK_TITLE_PATH	("Data/ClearImage/BackTitle.png")	//「もういいかな」画像のパス
#define CURSOR_PATH		("Data/ClearImage/Cursor.png")		//矢印画像のパス

void InitClear();	//クリア初期化

void StepClear();	//クリア通常処理

void DrawClear();	//クリア描画処理

void FinClear();	//クリア後処理