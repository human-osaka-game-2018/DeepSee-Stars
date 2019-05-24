#include "World.h"

#include <math.h>

namespace deepseestars
{
	void World::Update()
	{
		m_distanceToOrigin = m_pCamera->GetDistanceToOrigin();
		m_playerCenterPos = m_pPlayer->GetCenterPos();
		m_pCamera->SetIsPlayerHide(m_pPlayer->GetIsHideState());
		
		m_pCamera->Update();

		ObjectCollision();
		JudgePlayerAction();
		m_pStage->Update();
		m_pPlayer->Update();
	}

	void World::Render()
	{
		m_pStage->Render();
		m_pPlayer->Render();
	}

	void World::ObjectCollision()
	{
		D3DXVECTOR2 playerCenterBuf;
		playerCenterBuf = m_pPlayer->GetCenterPos();
		if (m_pPlayer->GetIsHideState())
		{
			playerCenterBuf.y = playerCenterBuf.y + m_CellSize;
		}
		m_pPlayer->SetCenterPos(playerCenterBuf);

		//LEFT
		m_PlayerGirthCenter[LEFT] = { m_pPlayer->GetCenterPos().x - m_CellSize,m_pPlayer->GetCenterPos().y };
		//RIGHT
		m_PlayerGirthCenter[RIGHT] = { m_pPlayer->GetCenterPos().x + m_CellSize,m_pPlayer->GetCenterPos().y };
		//UP
		m_PlayerGirthCenter[UP] = { m_pPlayer->GetCenterPos().x,m_pPlayer->GetCenterPos().y - m_CellSize };
		//DOWN
		m_PlayerGirthCenter[DOWN] = { m_pPlayer->GetCenterPos().x,m_pPlayer->GetCenterPos().y + m_CellSize };

		JudgePlayerMove();
	}

	void World::JudgePlayerMove()
	{
		Movements playerDirection;

		for (int i = 0;i <= DOWN;i++)
		{
			for (auto& stagePos : m_pStage->GetblockCellPos())
			{
				if (stagePos->Gettype() == 0) continue;
				if ((stagePos->Getcenter().x != m_PlayerGirthCenter[i].x) || (stagePos->Getcenter().y != m_PlayerGirthCenter[i].y)) continue;
				switch (i)
				{
				case LEFT:
					playerDirection.CanMoveLeft = false;
					break;
				case RIGHT:
					playerDirection.CanMoveRight = false;
					break;
				case UP:
					playerDirection.CanMoveUp = false;
					break;
				case DOWN:
					playerDirection.CanMoveDown = false;
					break;
				}
			}
		}
		if (m_pCamera->GetIsCenterReset())
		{
			playerDirection.Freeze();
		}
		m_pPlayer->SetCanMoveDirection(playerDirection);
	}

	void World::JudgePlayerAction()
	{
		m_PlayerAction.CanHide = false;
		m_PlayerAction.CanAutotomy = false;
		m_PlayerAction.CanAvatar = false;

		for (auto& stageInfo : m_pStage->GetblockCellPos())
		{
			if ((stageInfo->Getcenter().x != m_PlayerGirthCenter[2].x) || (stageInfo->Getcenter().y != m_PlayerGirthCenter[2].y)) continue;
			if (stageInfo->Gettype() != HIDE_BLOCK) continue;
			m_PlayerAction.CanHide = true;
		}
		m_PlayerAction.CanAvatar = true;
		m_PlayerAction.CanAutotomy = true;
		m_pPlayer->SetCanAction(m_PlayerAction);
	}

	void World::IsPlayerTarget()
	{
		D3DXVECTOR2 distance;
		float length;
		const float visibilityLength[Visibility::DANGER + 1] =
		{
			m_CellSize * 5.f,
			m_CellSize * 3.f,
			m_CellSize
		};
		
		for (auto& enemy : m_pEnemies->GetEnemies())
		{
			distance = m_pPlayer->GetCenterPos() - enemy->GetTranslationData().m_pos;
			length = D3DXVec2Length(&distance);

			if (length > visibilityLength[enemy->GetVisibility()]) continue;
			
			D3DXVECTOR2 unitVec;
			
			switch(enemy->GetDirection())
			{
			case LEFT:	unitVec.x += 1.0f; break;
			case RIGHT: unitVec.x -= 1.0f; break;
			case UP:    unitVec.y -= 1.0f; break;
			case DOWN:  unitVec.y += 1.0f; break;
			}
			
			//視野角(degree)
			float viewAngle = 0;
			viewAngle = D3DXToDegree(acos(D3DXVec2Dot(&distance, &unitVec) / length));
							
							//軸からの角度
			if (viewAngle > (m_viewAngleMax * 0.5f)) continue;

			auto CanFind = [&]()->bool
			{
				//確率(％)
				int probability = 0;

				//見つかる確率の処理を書く
				//後日変更する予定

				bool canFind = probability > rand() % 100;

				return canFind;
			};
			
			enemy->SetExistsPlayer(CanFind());
		}
	}

	void World::JudgeMoveEnemy()
	{
		D3DXVECTOR2 enemyPos;
		D3DXVECTOR2 cameraUpperLeftPos = m_pCamera->GetUpperLeftPos();
		D3DXVECTOR2 cameraLowerRight = m_pCamera->GetLowerRightPos();

		auto ExistsInCamera = [&]()->bool
		{
			bool ExistsCameraRangeX = (cameraUpperLeftPos.x < enemyPos.x) && (enemyPos.x < cameraLowerRight.x);
			bool ExistsCameraRangeY = (cameraUpperLeftPos.y < enemyPos.y) && (enemyPos.y < cameraLowerRight.y);

			if (ExistsCameraRangeX && ExistsCameraRangeY) return true;

			return false;
		};

		for (auto& enemy : m_pEnemies->GetEnemies())
		{
			enemyPos = enemy->GetTranslationData().m_pos;

			if (!ExistsInCamera()) continue;

			switch (enemy->GetDirection())
			{
			case LEFT:	m_enemyAroundCellPos.x = enemyPos.x - m_CellSize; break;
			case RIGHT: m_enemyAroundCellPos.x = enemyPos.x + m_CellSize; break;
			case UP:    m_enemyAroundCellPos.y = enemyPos.y - m_CellSize; break;
			case DOWN:  m_enemyAroundCellPos.y = enemyPos.y + m_CellSize; break;
			}

			for (auto& blockCell : m_pStage->GetblockCellPos())
			{
				if (blockCell->Gettype() == FLOOR) continue;
				
				bool canMove = blockCell->Getcenter() == m_enemyAroundCellPos;
				enemy->SetCanMove(canMove);
			}
		}
	}
}
