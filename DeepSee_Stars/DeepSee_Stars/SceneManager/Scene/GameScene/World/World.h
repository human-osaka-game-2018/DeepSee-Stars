#ifndef WORLD_H
#define WORLD_H

#include "../Player/Player.h"
#include"../Stage/Stage.h"
#include "../Camera/Camera.h"
#include "../Enemies/Enemies.h"
#include "GameObject.h"

namespace deepseestars
{
	class World : public GameObject
	{
	public:
		World() :
			GameObject()
		{
			Init();
			m_pCamera = new Camera(m_playerCenterPos, m_CellSize);
			m_distanceToOrigin = m_pCamera->GetDistanceToOrigin();
			m_pPlayer = new Player(m_distanceToOrigin, m_CellSize);
			m_pStage = new Stage(m_distanceToOrigin, m_CellSize);
			m_pEnemies = new Enemies(m_distanceToOrigin, m_playerCenterPos, m_CellSize);
		}

		~World()
		{
			delete m_pStage;
			m_pStage = nullptr;

			delete m_pPlayer;
			m_pPlayer = nullptr;

			delete m_pCamera;
			m_pCamera = nullptr;

			delete m_pEnemies;
			m_pEnemies = nullptr;
		}

		void Init()
		{
			m_PlayerAction.CanHide = false;
			m_PlayerAction.CanAutotomy = false;
			m_PlayerAction.CanAvatar = false;
		}

		void Update();

		void Render();

		void Release()
		{
			m_rGameBaseMaker.ReleaseAllTex();
		}

		void ObjectCollision();
		void JudgePlayerMove();
		void JudgePlayerAction();

	private:
		void JudgeMoveEnemy();
		void IsPlayerTarget();

		D3DXVECTOR2 m_distanceToOrigin;
		D3DXVECTOR2 m_playerCenterPos;

		Camera*  m_pCamera;
		Player*  m_pPlayer;
		Stage*   m_pStage ;
		Enemies* m_pEnemies;

		D3DXVECTOR2 m_PlayerGirthCenter[4];
		D3DXVECTOR2 m_enemyAroundCellPos;

		Action m_PlayerAction;
		float m_WorldScrollX = 0.f;
		float m_WorldScrollY = 0.f;
		
		const float m_viewAngleMax = 90.f;
		const float m_CellSize = 50.f;
	};
}

#endif // WORLD_H
