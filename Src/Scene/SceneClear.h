#pragma once

#define BACK_CLEAR	("Data/ClearImage/BgClear.png")	//クリアの背景画像のパス
#define RESULT_PATH	("Data/ClearImage/Result.png")	//リザルト文字のパス

//クリア初期化
void InitClear();

//クリア通常処理
void StepClear();

//クリア描画処理
void DrawClear();

//クリア後処理
void FinClear();