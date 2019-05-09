﻿#ifndef PLAYER_H
#define PLAYER_H

#include "Object.h"
#include "CustomVertex.h"
#include"DirectionID.h"
#include "AutotomyAction.h"
#include "AvatarAction.h"

struct DIRECTION
{
	bool IsLeft;
	bool IsRight;
	bool IsUp;
	bool IsDown;
};

struct ACTION
{
	bool IsHide;
	bool IsAutotomy;
	bool IsAvatar;
};

class Player
{
public:
	Player();
	~Player();
	void Init();
	void Update();
	void Render(D3DXVECTOR2 drawArea);
	void GameOverandClearConfirmation();

	CustomVertex* GetPlayer()
	{
		return m_Player;
	}

	D3DXVECTOR2 GetCenterPos()
	{
		return m_CenterPos;
	}
	void SetCenterPos(D3DXVECTOR2 centerPos)
	{
		m_CenterPos = centerPos;
	}

	void SetCanMoveDirection(DIRECTION canMove)
	{
		m_CanMoveDirection = canMove;
	}

	void SetCanAction(ACTION canAction)
	{
		m_CanAction = canAction;
	}

	bool GetIsHideState()
	{
		return m_IsHideState;
	}
private:
	DirectX * m_pDirectX;
	std::vector<BaseAction*> m_pAction;

	const float m_TextureSizeX = 100.f;
	const float m_TextureSizeY = 100.f;
	const float m_SquaresSize = 100.f;
	const float m_MoveSpeed = 10.f;
	D3DXVECTOR2 m_DrawArea;
	CustomVertex m_Player[4];

	int m_Life;
	CustomVertex m_LifeUI[4];

	CustomVertex m_Avatar[4];
	DIRECTION m_CanMoveDirection;
	ACTION m_CanAction;
	bool m_OnAutotomy;

	D3DXVECTOR2 m_CenterPos;
	D3DXVECTOR2 m_CenterPosBuf;
	D3DXVECTOR2 m_PrevPlayerCenterPos;
	int m_Direction;
	//方向の入力できるか？
	bool m_CanDirectionInput;
	bool m_IsHideState;

	void Movement();
	void Action();
	void Hide();
	void Autotomy();
	void Avatar();
	void DirectionStatusCheck();
	void DirectionStatusMotion();
	void tuOperation(int direction);
	void tvOperation(int direction);
};
#endif // PLAYER_H
