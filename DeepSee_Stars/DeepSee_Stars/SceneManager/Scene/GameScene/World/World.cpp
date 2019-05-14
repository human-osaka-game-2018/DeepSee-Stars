#include "World.h"

namespace deepseestars
{

	void World::Update()
	{
		m_differencetoStartingPoint = m_pCamera->GetUpperLeftWithTheDifference();
		m_playerPos = m_pPlayer->GetCenterPos();

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
		m_PlayerGirthCenterPos[LEFT] = { m_pPlayer->GetCenterPos().x - m_SquaresSize,m_pPlayer->GetCenterPos().y };
		//RIGHT
		m_PlayerGirthCenterPos[RIGHT] = { m_pPlayer->GetCenterPos().x + m_SquaresSize,m_pPlayer->GetCenterPos().y };
		//UP
		m_PlayerGirthCenterPos[UP] = { m_pPlayer->GetCenterPos().x,m_pPlayer->GetCenterPos().y - m_SquaresSize };
		//DOWN
		m_PlayerGirthCenterPos[DOWN] = { m_pPlayer->GetCenterPos().x,m_pPlayer->GetCenterPos().y + m_SquaresSize };

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
			for (auto& stagePos : m_pStage->m_blockCellPos)
			{
				if (stagePos->m_blockType == 4)
				{

				}
				if (stagePos->m_blockType == 0) continue;
				if ((stagePos->m_blockCenterPos.x != m_PlayerGirthCenterPos[i].x) || (stagePos->m_blockCenterPos.y != m_PlayerGirthCenterPos[i].y)) continue;
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
		if (m_pCamera->GetIsKeyOperation())
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

		for (auto& stageInfo : m_pStage->m_blockCellPos)
		{
			if ((stageInfo->m_blockCenterPos.x != m_PlayerGirthCenterPos[2].x) || (stageInfo->m_blockCenterPos.y != m_PlayerGirthCenterPos[2].y)) continue;
			if (stageInfo->m_blockType != HIDE_BLOCK) continue;
			m_PlayerAction.IsHide = true;
		}
		m_PlayerAction.IsAvatar = true;
		m_PlayerAction.IsAutotomy = true;
		m_pPlayer->SetCanAction(m_PlayerAction);
	}
}
