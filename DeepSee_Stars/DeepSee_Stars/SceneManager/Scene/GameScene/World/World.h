#ifndef WORLD_H
#define WORLD_H

#include "../Player/Player.h"
#include"../Stage/Stage.h"
#include "../Camera/Camera.h"
#include "../Enemies/Enemies.h"
#include "GameObject.h"
#include "../../SceneManager/SceneManager.h"

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
			m_pStage = new Stage(m_distanceToOrigin, m_CellSize);
			m_pEnemies = new Enemies(m_distanceToOrigin, m_playerCenterPos, m_CellSize);
			m_playerStartPosRow = m_pStage->GetPlayerStartPosRow();
			m_playerStartPosColunm = m_pStage->GetPlayerStartPosColunm();
			m_pPlayer = new Player(m_distanceToOrigin, m_CellSize, m_playerStartPosRow, m_playerStartPosColunm);
			}

		~World()
		{
			Release();
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

		void Release(){}

	private:
		void JudgeMoveEnemy();
		void IsPlayerTarget();

		D3DXVECTOR2 m_distanceToOrigin;
		D3DXVECTOR2 m_playerCenterPos;

		Camera*  m_pCamera;
		Player*  m_pPlayer;
		Stage*   m_pStage ;
		Enemies* m_pEnemies;

		D3DXVECTOR2 playerCenterBuf;
		D3DXVECTOR2 m_PlayerGirthCenter[4];
		D3DXVECTOR2 m_enemyAroundCellPos;

		const float m_CellSize = 50.f;

		Action m_PlayerAction;
		float m_WorldScrollX = 0.f;
		float m_WorldScrollY = 0.f;
		int m_playerStartPosRow;
		int m_playerStartPosColunm;

		const float m_viewAngleMax = 90.f;
		const float m_CellSize = 50.f;

		void ObjectCollision();
		void JudgePlayerMove();
		void JudgePlayerAction();
		void RenderingPriority();
		void GimmickCollision();
		void JudgeMissionStart();
		void FinishMission();
		void JudgeGameClear();
		TYPE GetCurrentPosBlock();
	};
}

#endif // WORLD_H
