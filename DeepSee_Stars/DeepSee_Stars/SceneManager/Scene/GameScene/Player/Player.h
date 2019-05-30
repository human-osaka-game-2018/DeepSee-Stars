#ifndef PLAYER_H
#define PLAYER_H

#include "../Enum/Direction.h"
#include "../Player/Action/Autotomy/AutotomyObject.h"
#include "../Player/Action/Avatar/AvatarObject.h"
#include "../../GameBaseMaker/TextureUV/TextureUV.h"
#include "../Player/UI/PlayerLife.h"
#include "../Player/UI/SafetyLevel.h"
#include "../Player/UI/RetentionMissionItem.h"
#include "Mission\Mission.h"
#include "GameObject.h"
#include "DirectionID.h"

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
		Player(const D3DXVECTOR2& distanceToOrigin, const float& squaresSize, const int& startPosRow, const int& startPosColunm):
			GameObject(), m_distanceToOrigin(distanceToOrigin), m_cellSize(squaresSize), m_startPosRow(startPosRow), m_startPosColunm(startPosColunm)
		{
			Init();
			m_pplayerLife = new PlayerLife();
			m_psafetyLevel = new SafetyLevel(m_safetyLevel, m_direction, m_isHideState, m_inTheSeaWeed);
			m_pretentionMissionItem = new RetentionMissionItem(m_retentionMissionItem);
			m_pmission = new Mission();
		}
		
		~Player()
		{
			Release();
			for (auto& actionObject : m_paction)
			{
				delete actionObject;
				actionObject = nullptr;
			}
			delete m_pplayerLife;
			m_pplayerLife = nullptr;
			delete m_psafetyLevel;
			m_psafetyLevel = nullptr;
		}

		void Init();

		void Update();

		void Render();

		void Release() 
		{
			m_rGameBaseMaker.ReleaseAllTex();
		}

		void GameOverandClearConfirmation();
		void Move();

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
			return m_pplayerLife->GetLife();
		}
		void SetLife(int life)
		{
			m_pplayerLife->SetLife(life);
		}

		int GetSafetyLevel()
		{
			return m_safetyLevel;
		}

		int GetRetentionMissionItem()
		{
			return m_retentionMissionItem;
		}
		void SetRetentionMissionItem(int retentionMissionItem)
		{
			m_retentionMissionItem = retentionMissionItem;
		}

		bool GetInTheSeaWeed()
		{
			return m_inTheSeaWeed;
		}
		void SetInTheSeaWeed(bool inTheSeaWeed)
		{
			m_inTheSeaWeed = inTheSeaWeed;
		}

		Direction GetDirection()
		{
			return m_direction;
		}
		void SetDirection(Direction direction)
		{
			m_direction = direction;
		}

		Direction GetMissionDirection()
		{
			return m_missionDirection;
		}
		void SetMissionDirection(Direction missionDirection)
		{
			m_missionDirection = missionDirection;
		}

		Direction GetPrevDirection()
		{
			return m_prevDirection;
		}

		bool GetStartMissionGet4Items()
		{
			return m_pmission->GetStartMissionGet4Items();
		}
		void SetStartMissionGet4Items(bool startMissionGet4Items)
		{
			m_pmission->SetStartMissionGet4Items(startMissionGet4Items);
		}
	private:
		const TCHAR* m_playerTextureKey[10] =
		{
			_T("PlayerLeft"),
			_T("PlayerRight"),
			_T("PlayerDown"),
			_T("ReadyAction"),
			_T("Hide"),
			_T("Autotomy"),
			_T("Avatar1"),
			_T("Avatar2"),
			_T("Avatar3"),
			_T("Avatar4"),
		};
		const TCHAR* m_playerTextureName[10] =
		{
			_T("2DTexture/Game/Player/PlayerLeft.png"),
			_T("2DTexture/Game/Player/PlayerRight.png"),
			_T("2DTexture/Game/Player/PlayerDown.png"),
			_T("2DTexture/Game/Player/PlayerReadyAction.png"),
			_T("2DTexture/Game/Player/PlayerHide.png"),
			_T("2DTexture/Game/Player/PlayerAutotomy.png"),
			_T("2DTexture/Game/Player/PlayerAvatar1.png"),
			_T("2DTexture/Game/Player/PlayerAvatar2.png"),
			_T("2DTexture/Game/Player/PlayerAvatar3.png"),
			_T("2DTexture/Game/Player/PlayerAvatar4.png"),
		};

		PlayerLife * m_pplayerLife;
		SafetyLevel* m_psafetyLevel;
		RetentionMissionItem* m_pretentionMissionItem;
		Mission* m_pmission;

		const float& m_cellSize;
		const D3DXVECTOR2& m_distanceToOrigin;
		std::vector<BaseActionObject*> m_paction;

		const float m_textureSizeX = 50.f;
		const float m_textureSizeY = 50.f;
		const float m_moveSpeed = 5.f;

		int m_safetyLevel;
		int m_retentionMissionItem;

		Movements m_movements;
		Action m_action;
		bool m_isAutotomyState;
		bool m_isAutotomyAnimation;

		D3DXVECTOR2 m_center;
		D3DXVECTOR2 m_centerBuf;
		float m_variationValue;
		Direction m_direction;
		Direction m_prevDirection;
		Direction m_missionDirection;
		bool m_canDirectionInput;
		bool m_isHideState;
		bool m_inTheSeaWeed;

		//キャラのスタート位置Stage読み込みの際スタート位置の番号の数字を渡す
		const int m_startPosRow;
		const int m_startPosColunm;

		void UpdateAction();
		void Action();
		void Hide();
		void Autotomy();
		void Avatar();
		void CheckDirectionStatus();
	};
}
#endif // PLAYER_H
