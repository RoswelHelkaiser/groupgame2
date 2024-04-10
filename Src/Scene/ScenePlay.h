#pragma once

#define TIME_MAX_NUM	(60)	//制限時間のマックス

#define READY_PATH	("Data/PlayImage/Text/Ready.png")	//「Ready?」のパス
#define GO_PATH		("Data/PlayImage/Text/Go.png")		//「Go!」のパス
#define FINISH_PATH	("Data/PlayImage/Text/Finish.png")	//「Finish!」のパス
#define TEXT_NUM	(3)	//文字の数

#define SLIME_PATH	("Data/PlayImage/Slime.png")		//スライム(緑)のパス
#define SLIME_NUM	(175)	//スライムの数

//文字クラス
class Text
{
	public:	//メンバ変数一覧
		int TextHandle[TEXT_NUM];	//画像ハンドル
		int HandleIndex;	//画像ハンドル添え字用変数
		float PosX, PosY;	//X座標,Y座標
		float Size;			//画像の拡大率
		bool isDraw;		//描画フラグ
		int Frame;			//フレームカウント用変数
		int  Loop;			//ループカウント用変数
		bool isStart;		//ゲームをスタートさせるフラグ

	public:	//メソッド一覧
		Text()	//コンストラクタ(全ての情報を初期化)
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

		void InitText()	//文字の初期化
		{
			TextHandle[0] = LoadGraph(READY_PATH);	//「Ready?」読み込み
			TextHandle[1] = LoadGraph(GO_PATH);		//「Go!」読み込み
			TextHandle[2] = LoadGraph(FINISH_PATH);	//「Finish!」読み込み
			HandleIndex = 0;	//最初は「Ready?」が表示される
			PosX = 640.0f;		//X座標を画面の中心に
			PosY = 360.0f;		//Y座標を画面の中心に
			Size = 1.0f;		//サイズは等倍
			isDraw = true;		//描画フラグを立てる
			Frame = 0;			//フレームカウントをリセット
			Loop = 0;			//ループカウントをリセット
			isStart = false;	//制限時間を進ませない
		}

		void StepText()	//文字通常処理
		{
			Size += 0.02f;	//少しずつ画像を大きくする

			if (Loop < 2)	//ループカウントが2より小さいなら
			{
				Frame++;	//フレームカウントを増やす

				if (Frame > FRAME_RATE)	//フレームカウントが一定の値を超えたら
				{
					Loop++;		//ループカウントを増やす
					Frame = 0;	//フレームカウントをリセット
				}
			}

			else if (Loop >= 2)	//ループカウントが2以上になったら
			{
				Size = 1.0f;	//大きさを等倍に戻す

				if (HandleIndex == 0)	//「Ready?」なら
				{
					HandleIndex = 1;	//「Go!」にする
					Loop = 0;
				}

				else if (HandleIndex == 1)	//「Go!」なら
				{
					isDraw = false;	//描画フラグを折る
					isStart = true;	//制限時間を進ませる
				}
			}
		}

		void DrawTextImage()	//文字描画処理
		{
			if (isDraw)	//描画フラグがtrueなら
			{
				DrawRotaGraph((int)PosX, (int)PosY, (double)Size, 0.0f, TextHandle[HandleIndex], true);
			}
		}

		void FinText()	//文字後処理
		{
			for (int i = 0; i < TEXT_NUM; i++)
			{
				DeleteGraph(TextHandle[i]);	//画像破棄
			}
		}
};

//スライムクラス
class Slime
{
public:	//メンバ変数一覧
	int ImageHandle[SLIME_NUM];	//画像ハンドル
		float PosX, PosY;		//X座標,Y座標
		bool isDraw;			//描画フラグ
		int FrameNum;			//フレームカウント用変数
		int Wating;				//スポーン間隔用変数

	public:	//メソッド一覧
		Slime()	//コンストラクタ(全ての情報を初期化)
		{
			for (int i = 0; i < SLIME_NUM; i++)
			{
				ImageHandle[i] = 0;
			}
			PosX = 0.0f;
			PosY = 0.0f;
			isDraw = false;
		}

		void InitSlime()	//スライムの初期化
		{
			for (int i = 0; i < SLIME_NUM; i++)
			{
				ImageHandle[i] = LoadGraph(SLIME_PATH);	//スライム画像読み込み
			}
			PosX = 640.0f;	//初期X座標を設定
			PosY = 360.0f;	//初期Y座標を設定
			isDraw = false;	//描画フラグを折る
		}

		void StepSlime()	//スライム通常処理
		{

		}

		void DrawSlime()	//スライム描画処理
		{
			if (isDraw)	//描画フラグがtrueなら
			{
				for (int i = 0; i < SLIME_NUM; i++)
				{
					DrawRotaGraph((int)PosX, (int)PosY, 1.0f, 0.0f, ImageHandle[i], true);	//スライム画像描画
				}
			}
		}

		void FinSlime()		//スライム後処理
		{
			for (int i = 0; i < SLIME_NUM; i++)
			{
				DeleteGraph(ImageHandle[i]);	//スライム画像破棄
			}
		}
};

void InitPlay();	//プレイシーン初期化

void StepPlay();	//プレイシーン通常処理

void DrawPlay();	//プレイシーン描画処理

void FinPlay();		//プレイシーン後処理
