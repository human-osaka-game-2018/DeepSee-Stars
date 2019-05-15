#include "World.h"

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

		for (int i = 0;i < 4;i++)
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
		m_PlayerAction.IsHide = false;
		m_PlayerAction.IsAutotomy = false;
		m_PlayerAction.IsAvatar = false;

		for (auto& stageInfo : m_pStage->GetblockCellPos())
		{
			if ((stageInfo->Getcenter().x != m_PlayerGirthCenter[2].x) || (stageInfo->Getcenter().y != m_PlayerGirthCenter[2].y)) continue;
			if (stageInfo->Gettype() != HIDE_BLOCK) continue;
			m_PlayerAction.IsHide = true;
		}
		m_PlayerAction.IsAvatar = true;
		m_PlayerAction.IsAutotomy = true;
		m_pPlayer->SetCanAction(m_PlayerAction);
	}
}
