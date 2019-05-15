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

	struct CanMoveDirection
	{
		bool IsLeft;
		bool IsRight;
		bool IsUp;
		bool IsDown;
	};

	struct CanAction
	{
		bool IsHide;
		bool IsAutotomy;
		bool IsAvatar;
	};

	class Player : public GameObject
	{
	public:
		Player(const D3DXVECTOR2& distanceToOrigin, const float& squaresSize):
			GameObject(_T("Player"), _T("2DTexture/Game/Player.png")), m_distanceToOrigin(distanceToOrigin), m_squaresSize(squaresSize)
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
			m_isAutotomyState = true;

			m_center = { (m_squaresSize * m_row) + (m_squaresSize / 2) ,(m_squaresSize * m_colunm) + (m_squaresSize / 2) };
		}


		void Update();

		void Render();

		void Release() {}

		void GameOverandClearConfirmation();


		D3DXVECTOR2 GetCenterPos()
		{
			return m_center;
		}
		void SetCenterPos(D3DXVECTOR2 centerPos)
		{
			m_center = centerPos;
		}

		void SetCanMoveDirection(CanMoveDirection canMove)
		{
			m_canMoveDirection = canMove;
		}

		void SetCanAction(CanAction canAction)
		{
			m_canAction = canAction;
		}

		bool GetIsHideState()
		{
			return m_isHideState;
		}

	private:
		const float& m_squaresSize;
		const D3DXVECTOR2& m_distanceToOrigin;
		std::vector<BaseAction*> m_paction;

		const float m_TextureSizeX = 50.f;
		const float m_TextureSizeY = 50.f;
		const float m_MoveSpeed = 10.f;
	
		//CustomVertex m_Player[4];

		int m_Life;

		CanMoveDirection m_canMoveDirection;
		CanAction m_canAction;
		bool m_isAutotomyState;

	
		D3DXVECTOR2 m_center;
		D3DXVECTOR2 m_centerBuf;
		D3DXVECTOR2 m_prevPlayerCenter;
		int m_direction;
		bool m_canDirectionInput;
		bool m_isHideState;

		//キャラのスタート位置Stage読み込みの際スタート位置の番号の数字を渡す
		int m_row = 14;
		int m_colunm = 8;
		//

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
