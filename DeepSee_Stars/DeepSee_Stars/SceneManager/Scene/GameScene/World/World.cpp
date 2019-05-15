#include "World.h"

namespace deepseestars
{

	void World::Update()
	{
		m_distanceToOrigin = m_pCamera->GetdistanceToOrigin();
		m_playerCenterPos = m_pPlayer->GetCenterPos();

		if (m_pPlayer->GetIsHideState())
		{
			m_pCamera->SetIsPlayerHide(true);
		}
		if (!m_pPlayer->GetIsHideState())
		{
			m_pCamera->SetIsPlayerHide(false);
		}
		m_pCamera->Update();

		ObjectCollision();
		CanPlayerActionJudg();
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
			playerCenterBuf.y = playerCenterBuf.y + m_SquaresSize;
		}
		m_pPlayer->SetCenterPos(playerCenterBuf);

		//LEFT
		m_PlayerGirthCenter[LEFT] = { m_pPlayer->GetCenterPos().x - m_SquaresSize,m_pPlayer->GetCenterPos().y };
		//RIGHT
		m_PlayerGirthCenter[RIGHT] = { m_pPlayer->GetCenterPos().x + m_SquaresSize,m_pPlayer->GetCenterPos().y };
		//UP
		m_PlayerGirthCenter[UP] = { m_pPlayer->GetCenterPos().x,m_pPlayer->GetCenterPos().y - m_SquaresSize };
		//DOWN
		m_PlayerGirthCenter[DOWN] = { m_pPlayer->GetCenterPos().x,m_pPlayer->GetCenterPos().y + m_SquaresSize };

		m_CanPlayerMoveJudg();
	}

	void World::m_CanPlayerMoveJudg()
	{
		m_PlayerDirection.IsLeft = true;
		m_PlayerDirection.IsRight = true;
		m_PlayerDirection.IsUp = true;
		m_PlayerDirection.IsDown = true;

		for (int i = 0;i < 4;i++)
		{
			for (auto& stagePos : m_pStage->GetblockCellPos())
			{
				if (stagePos->Gettype() == 0) continue;
				if ((stagePos->Getcenter().x != m_PlayerGirthCenter[i].x) || (stagePos->Getcenter().y != m_PlayerGirthCenter[i].y)) continue;
				if (i == LEFT)
				{
					m_PlayerDirection.IsLeft = false;
				}
				if (i == RIGHT)
				{
					m_PlayerDirection.IsRight = false;
				}
				if (i == UP)
				{
					m_PlayerDirection.IsUp = false;
				}
				if (i == DOWN)
				{
					m_PlayerDirection.IsDown = false;
				}
			}
		}
		if (m_pCamera->GetIsCenterReset())
		{
			m_PlayerDirection.IsLeft = false;
			m_PlayerDirection.IsRight = false;
			m_PlayerDirection.IsUp = false;
			m_PlayerDirection.IsDown = false;
		}
		m_pPlayer->SetCanMoveDirection(m_PlayerDirection);
	}

	void World::CanPlayerActionJudg()
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
