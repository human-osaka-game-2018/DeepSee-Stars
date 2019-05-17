#ifndef PLAYER_H
#define PLAYER_H

#include "../Enum/Direction.h"
#include "../Player/Action/Autotomy/AutotomyObject.h"
#include "../../GameBaseMaker/TextureUV/TextureUV.h"
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
			GameObject(), m_distanceToOrigin(distanceToOrigin), m_CellSize(squaresSize)
		{
			Init();
		}
		
		~Player();

		void Init()
		{
			gamebasemaker::TextureUV autotomy(D3DXVECTOR2(0.0f,0.0f), D3DXVECTOR2(1024.f, 150.f), D3DXVECTOR2(150.f, 150.f));
			m_vertices.SetTextureUV(autotomy);

			for (int i = 0;i <= 8;i++)
			{
				m_rGameBaseMaker.CreateTex(m_playerTextureKey[i], m_playerTextureName[i]);
			}

			m_vertices.SetImageSize(D3DXVECTOR2(150.f, 150.f));
			m_vertices.ClippingImage(D3DXVECTOR2(0.f, 0.f), D3DXVECTOR2(150.f, 150.f));

			m_pTextureKey = m_playerTextureKey[2];
			m_life = 5;
			m_row = 14;
			m_colunm = 8;

			m_canDirectionInput = true;
			m_isHideState = false;
			m_isAutotomyState = true;

			m_center = { (m_CellSize * m_row) + (m_CellSize / 2) ,(m_CellSize * m_colunm) + (m_CellSize / 2) };
		}


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

		const float& m_CellSize;
		const D3DXVECTOR2& m_distanceToOrigin;
		std::vector<BaseActionObject*> m_paction;

		const float m_TextureSizeX = 50.f;
		const float m_TextureSizeY = 50.f;
		const float m_MoveSpeed = 10.f;
	

		int m_life;

		Movements m_movements;
		Action m_action;
		bool m_isAutotomyState;
		bool m_isAutotomyAnimation = false;

	
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
