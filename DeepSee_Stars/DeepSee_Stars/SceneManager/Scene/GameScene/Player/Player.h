#ifndef PLAYER_H
#define PLAYER_H

#include "../Enum/Direction.h"
#include "../Player/Action/Autotomy/AutotomyObject.h"
#include "../Player/Action/Avatar/AvatarObject.h"
#include "../../GameBaseMaker/TextureUV/TextureUV.h"
#include "../Player/UI/PlayerLife.h"
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
			GameObject(), m_distanceToOrigin(distanceToOrigin), m_cellSize(squaresSize)
		{
			Init();
		}
		
		~Player();

		void Init();

		void Update();

		void Render();

		void Release() 
		{
			m_rGameBaseMaker.ReleaseAllTex();
		}

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

		int GetLife()
		{
			return m_life;
		}

		void SetLife(int life)
		{
			m_life = life;
		}

	private:
		const TCHAR* m_playerTextureKey[9] =
		{
			_T("PlayerLeft"),
			_T("PlayerRight"),
			_T("ReadyAction"),
			_T("Hide"),
			_T("Autotomy"),
			_T("Avatar1"),
			_T("Avatar2"),
			_T("Avatar3"),
			_T("Avatar4"),
		};
		const TCHAR* m_playerTextureName[9] =
		{
			_T("2DTexture/Game/Player/PlayerLeft.png"),
			_T("2DTexture/Game/Player/PlayerRight.png"),
			_T("2DTexture/Game/Player/PlayerReadyAction.png"),
			_T("2DTexture/Game/Player/PlayerHide.png"),
			_T("2DTexture/Game/Player/PlayerAutotomy.png"),
			_T("2DTexture/Game/Player/PlayerAvatar1.png"),
			_T("2DTexture/Game/Player/PlayerAvatar2.png"),
			_T("2DTexture/Game/Player/PlayerAvatar3.png"),
			_T("2DTexture/Game/Player/PlayerAvatar4.png"),
		};

		const float& m_cellSize;
		const D3DXVECTOR2& m_distanceToOrigin;
		std::vector<BaseActionObject*> m_paction;
		AutotomyAction* m_pautotomyAction;
		AvatarAction* m_pavatarAction;
		PlayerLife* m_pplayerLife;

		const float m_textureSizeX = 50.f;
		const float m_textureSizeY = 50.f;
		const float m_moveSpeed = 10.f;
	

		int m_life;

		Movements m_movements;
		Action m_action;
		bool m_isAutotomyState;
		bool m_isAutotomyAnimation;

	
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
		void StatusManagement();
		void Action();
		void Hide();
		void Autotomy();
		void Avatar();
		void CheckDirectionStatus();
		void Move();
	};
}
#endif // PLAYER_H
