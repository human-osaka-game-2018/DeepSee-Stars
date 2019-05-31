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
		JudgeMoveEnemy();
		IsPlayerTarget();

		JudgeMissionStart();
		JudgeGameClear();

		m_pStage->Update();
		m_pPlayer->Update();
		m_pEnemies->Update();
	}

	void World::Render()
	{
		m_pStage->Render();
		m_pPlayer->Render();
		m_pEnemies->Render();
		RenderingPriority();
	}

	void World::ObjectCollision()
	{
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

		JudgeDirectionAvatarCreate();

		GimmickCollision();
	}

	void World::JudgePlayerMove()
	{
		Movements playerDirection;

		for (int i = 0;i < 4;i++)
		{
			for (auto& stagePos : m_pStage->GetblockCellPos())
			{
				if (stagePos->Gettype() == FLOOR) continue;
				if (stagePos->Gettype() == PLAYER_RECOVERY_OBJECT) continue;
				if (stagePos->Gettype() == SEAWEED) continue;
				if (stagePos->Gettype() == MISSION_ITEM) continue;
				if (stagePos->Gettype() == GAMECLEARZONE) continue;
				
				if (!m_pPlayer->GetStartMissionGet4Items())
				{
					if (stagePos->Gettype() == MISSIONSTART_GET4ITEMS) continue;
				}

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


	void World::JudgeDirectionAvatarCreate()
	{
		Movements DirectionAvatarCreate;

		for (int i = 0;i < 4;i++)
		{
			for (auto& stagePos : m_pStage->GetblockCellPos())
			{
				if (stagePos->Gettype() == FLOOR) continue;
				if (stagePos->Gettype() == PLAYER_RECOVERY_OBJECT) continue;
				if (stagePos->Gettype() == SEAWEED) continue;
				if (stagePos->Gettype() == MISSION_ITEM) continue;
				if (stagePos->Gettype() == GAMECLEARZONE) continue;
				if (stagePos->Gettype() == MISSIONSTART_GET4ITEMS) continue;

				if ((stagePos->Getcenter().x != m_PlayerGirthCenter[i].x) || (stagePos->Getcenter().y != m_PlayerGirthCenter[i].y)) continue;

				switch (i)
				{
				case LEFT:
					DirectionAvatarCreate.CanMoveLeft = false;
					break;
				case RIGHT:
					DirectionAvatarCreate.CanMoveRight = false;
					break;
				case UP:
					DirectionAvatarCreate.CanMoveUp = false;
					break;
				case DOWN:
					DirectionAvatarCreate.CanMoveDown = false;
					break;
				}
			}
		}
		m_pPlayer->SetDirectionAvatarCreate(DirectionAvatarCreate);
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

			D3DXVECTOR2 unitVec(0.f, 0.f);
			
			switch(enemy->GetDirection())
			{
			case LEFT:	unitVec.x = -1.0f; break;
			case RIGHT: unitVec.x =  1.0f; break;
			case UP:    unitVec.y = -1.0f; break;
			case DOWN:  unitVec.y =  1.0f; break;
			}
			
			//視野角(degree)
			float viewAngle = D3DXToDegree(acos(D3DXVec2Dot(&distance, &unitVec) / length));			
							
							//軸からの角度
			if (viewAngle > (m_viewAngleMax * 0.5f)) continue;

			auto CanFind = [&]()->bool
			{
				//確率(％)
				int probability = 100;

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
		for (auto& enemy : m_pEnemies->GetEnemies())
		{
			D3DXVECTOR2 predictedDest = enemy->GetDestination();
		
			D3DXVECTOR2 sizeDIff = D3DXVECTOR2(0.0f, 0.0f);

			auto GetSign = [](float val)->int
			{
				return (val >= 0) ? +1 : -1;
			};

			if (enemy->GetTranslationData().m_movement.x != 0.0f)
			{
				sizeDIff.x = -GetSign(enemy->GetTranslationData().m_movement.x) * 0.5f * m_CellSize;
			}

			if (enemy->GetTranslationData().m_movement.y != 0.0f)
			{
				sizeDIff.y = -GetSign(enemy->GetTranslationData().m_movement.y) * 0.5f * m_CellSize;
			}

			switch (m_pStage->ConvertIntoType(predictedDest - sizeDIff))
			{
			case WHITE_BLOCK:
			case BLACK_BLOCK:
			case HIDE_BLOCK:
			case SEAWEED:
				enemy->SetCanMove(false);
				break;

			default:
				enemy->SetCanMove(true);
			}

			enemy->MoveDestIfCanMove();
		}
	}

	void World::GimmickCollision()
	{
		for (auto& stagePos : m_pStage->GetblockCellPos())
		{
			if ((stagePos->Getcenter().x != playerCenterBuf.x) || (stagePos->Getcenter().y != playerCenterBuf.y)) continue;

			switch (stagePos->Gettype())
			{
			case PLAYER_RECOVERY_OBJECT:
				m_pPlayer->SetLife(m_pPlayer->GetLife() + 1);
				stagePos->Settype(FLOOR);
				break;
			case SEAWEED:
				m_pPlayer->SetInTheSeaWeed(true);
				break;
			case MISSION_ITEM:
				m_pPlayer->SetRetentionMissionItem(m_pPlayer->GetRetentionMissionItem() + 1);
				stagePos->Settype(FLOOR);
				break;
			}
			if (stagePos->Gettype() != SEAWEED)
			{
				m_pPlayer->SetInTheSeaWeed(false);
			}
		}
	}

	void World::RenderingPriority()
	{
		for (auto& stagePos : m_pStage->GetblockCellPos())
		{
			if (stagePos->Gettype() != SEAWEED) continue;
			D3DXVECTOR2 pos = { stagePos->Getcenter().x + m_distanceToOrigin.x , stagePos->Getcenter().y + m_distanceToOrigin.y - m_CellSize / 4 };
			D3DXVECTOR2 scale = { m_CellSize / 2 ,m_CellSize / 2 };

			m_vertices.SetPos(pos);
			m_vertices.SetScale(scale);
			m_rGameBaseMaker.Render(m_vertices, m_rGameBaseMaker.GetTex(_T("SeaWeed")));
		}
	}

	void World::JudgeMissionStart()
	{
		switch (GetCurrentPosBlock())
		{
		case MISSIONSTART_GET4ITEMS:
			m_pPlayer->SetMissionDirection(m_pPlayer->GetPrevDirection());
			m_pPlayer->SetStartMissionGet4Items(true);
			break;
		}
		FinishMission();
	}

	void World::FinishMission()
	{
		if (m_pPlayer->GetStartMissionGet4Items())
		{
			if (m_pPlayer->GetRetentionMissionItem() == 4)
			{
				m_pPlayer->SetStartMissionGet4Items(false);
			}
		}
	}

	void World::JudgeGameClear()
	{
		switch (GetCurrentPosBlock())
		{
		case GAMECLEARZONE:
			SceneManager & rSceneManager = SceneManager::GetInstance();
			rSceneManager.SetNextScene(SceneManager::SCENE_ID::RESULT);
			break;
		}
	}

	TYPE World::GetCurrentPosBlock()
	{
		for (auto& stagePos : m_pStage->GetblockCellPos())
		{
			if ((stagePos->Getcenter().x != playerCenterBuf.x) || (stagePos->Getcenter().y != playerCenterBuf.y)) continue;

			return stagePos->Gettype();
		}
		return ERRORTYPE;
	}
}
