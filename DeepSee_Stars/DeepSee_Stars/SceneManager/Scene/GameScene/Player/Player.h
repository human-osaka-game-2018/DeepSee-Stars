#ifndef PLAYER_H
#define PLAYER_H

#include "../Enum/Direction.h"
#include "../Player/Action/Autotomy/AutotomyAction.h"
#include "../Player/Action/Avatar/AvatarAction.h"
#include "GameObject.h"

namespace deepseestars
{
	struct Movements
	{
		bool CanMoveLeft = true;
		bool CanMoveRight = true;
		bool CanMoveUp = true;
		bool CanMoveDown = true;

		void Freeze()
		{
			CanMoveLeft = false;
			CanMoveRight = false;
			CanMoveUp = false;
			CanMoveDown = false;
		}
	};

	struct Action
	{
		bool CanHide;
		bool CanAutotomy;
		bool CanAvatar;
	};

	class Player : public GameObject
	{
	public:
		Player(const D3DXVECTOR2& distanceToOrigin, const float& squaresSize):
			GameObject(_T("Player"), _T("2DTexture/Game/Player.png")), m_distanceToOrigin(distanceToOrigin), m_CellSize(squaresSize)
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

			m_center = { (m_CellSize * m_row) + (m_CellSize / 2) ,(m_CellSize * m_colunm) + (m_CellSize / 2) };
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

		void SetCanMoveDirection(Movements canMove)
		{
			m_movements = canMove;
		}

		void SetCanAction(Action canAction)
		{
			m_action = canAction;
		}

		bool GetIsHideState()
		{
			return m_isHideState;
		}

	private:
		const float& m_CellSize;
		const D3DXVECTOR2& m_distanceToOrigin;
		std::vector<BaseAction*> m_paction;

		const float m_TextureSizeX = 50.f;
		const float m_TextureSizeY = 50.f;
		const float m_MoveSpeed = 10.f;
	

		int m_Life;

		Movements m_movements;
		Action m_action;
		bool m_isAutotomyState;

	
		D3DXVECTOR2 m_center;
		D3DXVECTOR2 m_centerBuf;
		float m_variationValue = 0.f;
		Direction m_direction;
		bool m_canDirectionInput;
		bool m_isHideState;

		//キャラのスタート位置Stage読み込みの際スタート位置の番号の数字を渡す
		int m_row = 14;
		int m_colunm = 8;
		//

		void UpdateAction();
		void Action();
		void Hide();
		void Autotomy();
		void Avatar();
		void CheckDirectionStatus();
		void Move();
	};
}
#endif // PLAYER_H
