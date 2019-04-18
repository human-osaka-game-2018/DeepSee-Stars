#include "Object.h"
#include "CustomVertex.h"
#include "Stage.h"
#include"DirectionID.h"
#include"StageScroll.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player : public Object
{
public:
	Player();
	~Player();
	void Init();
	void Update();
	void Render();
	void GameOverandClearConfirmation();

	//////////////////////////移動関係////////////////////
	//移動
	void Movement();
	//向きの状態を確認
	void DirectionStatusCheck();
	//向いている方向には動けるか確認
	bool CanMoveInputDirection();
	//RowとColumnを移動させる
	void RowandColunmMove(int direction);
	//キャラの動き
	void Motion();
	//方向状態の動き
	void DirectionStatusMotion();
	//方向の入力できるか？
	bool m_CanDirectionInput;
	//方向の入力信号除去時間
	int m_DirectionInputSignalRejectionTime;
	//方向の入力信号除去時間の最大値
	int m_DirectionInputSignalRejectionMaxTime;
	//左足と右足の切替
	bool m_JudgmentofFootWalk;
	////////////////////////////////////////////////////

	//方向状態
	int m_Direction;

private:
	DirectX* m_pDirectX;
	CollsionManager* m_pCollsionManager;
	StageScroll* m_pStageScroll;
	CustomVertex m_Player[4];
	int m_Colunm;
	int m_Row;
	const float m_TextureSizeX = 64.f;
	const float m_TextureSizeY = 128.f;
	const float m_SquaresSize = 64.f;

	void tuOperation(int direction);
	void tvOperation(int direction);
};
#endif // PLAYER_H
