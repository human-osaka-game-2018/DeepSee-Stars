#include "World.h"

World::World()
{
	m_pStage = new Stage();
	m_pPlayer = new Player();
	m_pCamera = new Camera();
	Init();
}

World::~World()
{
	delete m_pStage;
	delete m_pPlayer;
	delete m_pCamera;
}

void World::Init()
{
	m_CanPlayerDirection.IsLeft = true;
	m_CanPlayerDirection.IsRight = true;
	m_CanPlayerDirection.IsUp = true;
	m_CanPlayerDirection.IsDown = true;

	m_CanPlayerAction.IsHide = false;
	m_CanPlayerAction.IsAutotomy = false;
	m_CanPlayerAction.IsAvatar = false;
}

void World::Update()
{
	if (m_pPlayer->GetIsHideState())
	{
		D3DXVECTOR2 playerHideStateCamera(0.f,0.f);
		playerHideStateCamera.y = m_SquaresSize;
		m_pCamera->Operation(m_pPlayer->GetCenterPos() + playerHideStateCamera);
	}
	if (!m_pPlayer->GetIsHideState())
	{
		m_pCamera->Operation(m_pPlayer->GetCenterPos());
	}

	ObjectCollision();
	CanPlayerAction();
	m_pStage->Update();
	m_pPlayer->Update();
}

void World::Render()
{
	m_pStage->Render(m_pCamera->GetUpperLeftWithTheDifference());
	m_pPlayer->Render(m_pCamera->GetUpperLeftWithTheDifference());
}

void World::ObjectCollision()
{
	D3DXVECTOR2 playerCenterBuf;
	playerCenterBuf.x = m_pPlayer->GetPlayer()[0].x + m_SquaresSize / 2;
	playerCenterBuf.y = m_pPlayer->GetPlayer()[0].y + m_SquaresSize + m_SquaresSize / 2;
	m_pPlayer->SetCenterPos(playerCenterBuf);

	//LEFT
	m_PlayerGirthCenterPos[0] = { m_pPlayer->GetCenterPos().x - m_SquaresSize,m_pPlayer->GetCenterPos().y };
	//RIGHT
	m_PlayerGirthCenterPos[1] = { m_pPlayer->GetCenterPos().x + m_SquaresSize,m_pPlayer->GetCenterPos().y };
	//UP
	m_PlayerGirthCenterPos[2] = { m_pPlayer->GetCenterPos().x,m_pPlayer->GetCenterPos().y - m_SquaresSize };
	//DOWN
	m_PlayerGirthCenterPos[3] = { m_pPlayer->GetCenterPos().x,m_pPlayer->GetCenterPos().y + m_SquaresSize };


	m_CanPlayerDirection.IsLeft = true;
	m_CanPlayerDirection.IsRight = true;
	m_CanPlayerDirection.IsUp = true;
	m_CanPlayerDirection.IsDown = true;

	for (int i = 0;i < 4;i++)
	{
		for (auto& stagePos : m_pStage->m_StagiesPos)
		{
			if ((stagePos.x != m_PlayerGirthCenterPos[i].x) || (stagePos.y != m_PlayerGirthCenterPos[i].y)) continue;
			if (i == 0)
			{
				m_CanPlayerDirection.IsLeft = false;
			}
			if (i == 1)
			{
				m_CanPlayerDirection.IsRight = false;
			}
			if (i == 2)
			{
				m_CanPlayerDirection.IsUp = false;
			}
			if (i == 3)
			{
				m_CanPlayerDirection.IsDown = false;
			}
		}
	}
	m_pPlayer->SetCanMoveDirection(m_CanPlayerDirection);
}

void World::CanPlayerAction()
{
	m_CanPlayerAction.IsHide = false;
	m_CanPlayerAction.IsAutotomy = false;
	m_CanPlayerAction.IsAvatar = false;

	for (auto& stageInfo : m_pStage->m_BlockCellPos)
	{
		if ((stageInfo->m_BlockCenterPos.x != m_PlayerGirthCenterPos[2].x) || (stageInfo->m_BlockCenterPos.y != m_PlayerGirthCenterPos[2].y)) continue;
		if (stageInfo->m_BlockType != HIDEBLOCK) continue;
		m_CanPlayerAction.IsHide = true;
	}
	m_CanPlayerAction.IsAvatar = true;
	m_CanPlayerAction.IsAutotomy = true;
	m_pPlayer->SetCanAction(m_CanPlayerAction);
}
