#ifndef WORLD_H
#define WORLD_H

#include "../Player/Player.h"
#include"../Stage/Stage.h"
#include "../Camera/Camera.h"
#include "GameObject.h"

namespace deepseestars
{

	class World : public GameObject
	{
	public:
		World() :
			GameObject(_T("Logo"), _T("2DTexture/Title/TitleLogo.png"))
		{
			Init();
			m_pCamera = new Camera(m_playerPos);
			m_differencetoStartingPoint = m_pCamera->GetUpperLeftWithTheDifference();
			m_pPlayer = new Player(m_differencetoStartingPoint);
			m_pStage = new Stage(m_differencetoStartingPoint);
		}

		~World()
		{
			delete m_pStage;
			delete m_pPlayer;
			delete m_pCamera;
		}

		void Init()
		{
			m_PlayerDirection.IsLeft = true;
			m_PlayerDirection.IsRight = true;
			m_PlayerDirection.IsUp = true;
			m_PlayerDirection.IsDown = true;

			m_PlayerAction.IsHide = false;
			m_PlayerAction.IsAutotomy = false;
			m_PlayerAction.IsAvatar = false;
		}

		void Update();

		void Render();

		void Release()
		{
			m_rGameBaseMaker.ReleaseAllTex();
		}

		void ObjectCollision();
		void m_CanPlayerMoveJudg();
		void CanPlayerActionJudg();


	private:
		D3DXVECTOR2 m_differencetoStartingPoint;
		D3DXVECTOR2 m_playerPos;

		Camera* m_pCamera;
		Player* m_pPlayer;
		Stage*  m_pStage ;

		D3DXVECTOR2 m_PlayerGirthCenterPos[4];

		DIRECTION m_PlayerDirection;
		ACTION m_PlayerAction;
		float m_WorldScrollX = 0.f;
		float m_WorldScrollY = 0.f;

		const float m_SquaresSize = 100.f;
	};
}

#endif // WORLD_H
