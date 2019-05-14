#ifndef PLAYER_H
#define PLAYER_H

#include "../Player/Action/Autotomy/AutotomyAction.h"
#include "../Player/Action/Avatar/AvatarAction.h"
#include "GameObject.h"

namespace deepseestars
{
	enum Direction
	{
		LEFT,
		RIGHT,
		UP,
		DOWN,
		STAYING,
	};

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

	class Player : public GameObject
	{
	public:
		Player(const D3DXVECTOR2& differencetoStartingPoint):
			GameObject(_T("Player"), _T("2DTexture/Game/Player.png")), m_differencetoStartingPoint(differencetoStartingPoint)
		{
			Init();
		}
		
		~Player();

		void Init()
		{
			m_rGameBaseMaker.CreateTex(m_pTextureKey, m_pFileName);

			m_Life = 5;
			m_row = 14;
			m_colunm = 8;

			m_canDirectionInput = true;
			m_isHideState = false;
			m_isAutotomy = true;

			m_centerPos = { (m_SquaresSize * m_row) + (m_SquaresSize / 2) ,(m_SquaresSize * m_colunm) + (m_SquaresSize / 2) };
		}


		void Update();

		void Render();

		void Release() {}

		void GameOverandClearConfirmation();

		//CustomVertex* GetPlayer()
		//{
		//	return m_Player;
		//}

		D3DXVECTOR2 GetCenterPos()
		{
			return m_centerPos;
		}
		void SetCenterPos(D3DXVECTOR2 centerPos)
		{
			m_centerPos = centerPos;
		}

		void SetCanMoveDirection(DIRECTION canMove)
		{
			m_canMoveDirection = canMove;
		}

		void SetCanAction(ACTION canAction)
		{
			m_canAction = canAction;
		}

		bool GetIsHideState()
		{
			return m_isHideState;
		}

		int m_row = 14;
		int m_colunm = 8;
	private:
		const D3DXVECTOR2& m_differencetoStartingPoint;
		std::vector<BaseAction*> m_paction;

		const float m_TextureSizeX = 50.f;
		const float m_TextureSizeY = 50.f;
		const float m_SquaresSize = 50.f;
		const float m_MoveSpeed = 10.f;
	
		//CustomVertex m_Player[4];

		int m_Life;

		DIRECTION m_canMoveDirection;
		ACTION m_canAction;
		bool m_isAutotomy;

	
		D3DXVECTOR2 m_centerPos;
		D3DXVECTOR2 m_centerPosBuf;
		D3DXVECTOR2 m_prevPlayerCenterPos;
		int m_direction;
		//方向の入力できるか？
		bool m_canDirectionInput;
		bool m_isHideState;

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
}
#endif // PLAYER_H
