#include "Player.h"


Player::Player()
{
	m_pDirectX = DirectX::GetInstance();
	m_pCollsionManager = CollsionManager::GetInstance();
	m_pStageScroll = StageScroll::GetInstance();
	Init();

	m_pCollsionManager->SetPlayerPos(&m_Colunm, &m_Row);
	m_pStageScroll->SetPlayerPos(&m_Colunm, &m_Row);
}

Player::~Player()
{

}

void Player::Init()
{
	m_pDirectX->InitVertex(m_Player);
	m_pDirectX->InitRectangleCustomVertex(m_Player,96,128, m_TextureSizeX, m_TextureSizeY);

	m_CanDirectionInput = true;
	m_DirectionInputSignalRejectionTime = 0;
	m_DirectionInputSignalRejectionMaxTime = 20;
	m_Direction = STAYING;
	m_JudgmentofFootWalk = true;

	float centerStandingPositionRow = (m_TextureSizeX + (m_SquaresSize / 2)) / 2;
	float centerStandingPositionColunm = (m_TextureSizeY / 2) + (m_SquaresSize /2);

	m_Row = static_cast<int>((m_Player[0].x + centerStandingPositionRow)) / static_cast<int>(m_SquaresSize);
	m_Colunm = static_cast<int>((m_Player[0].y + centerStandingPositionColunm)) / static_cast<int>(m_SquaresSize);
	 
	for (int i = 0;i < 4;i++)
	{
		if (i == 0 || i == 3) m_Player[i].tu = static_cast<float>(0.0833) * 1;
		if (i == 1 || i == 2) m_Player[i].tu = static_cast<float>(0.0833) * 2;
		if (i == 0 || i == 1) m_Player[i].tv =  static_cast<float>(0.128) * 2;
		if (i == 2 || i == 3) m_Player[i].tv =  static_cast<float>(0.128) * 3;
	}
}

void Player::Update()
{
	Movement();
	GameOverandClearConfirmation();
}

void Player::Render()
{
	m_pDirectX->DrawTexture("GAME_PLAYER_TEX", m_Player);
}

bool Player::CanMoveInputDirection()
{
	if (m_pCollsionManager->Update(m_Direction))
	{
		return false;
	}
	return true;
}

void Player::DirectionStatusCheck()
{
	if (m_pDirectX->IsKeyPressed(DIK_LEFT))
	{
		m_Direction = LEFT;
		return;
	}
	if (m_pDirectX->IsKeyPressed(DIK_RIGHT))
	{
		m_Direction = RIGHT;
		return;
	}
	if (m_pDirectX->IsKeyPressed(DIK_UP))
	{
		m_Direction = UP;
		return;
	}
	if (m_pDirectX->IsKeyPressed(DIK_DOWN))
	{
		m_Direction = DOWN;
		return;
	}
	m_Direction = STAYING;
}


void Player::RowandColunmMove(int direction)
{
	switch (direction)
	{
	case LEFT:
		m_Row -= 1;
		break;
	case RIGHT:
		m_Row += 1;
		break;
	case UP:
		m_Colunm -= 1;
		break;
	case DOWN:
		m_Colunm += 1;
		break;
	}
}

void Player::Motion()
{
	m_DirectionInputSignalRejectionTime++;

	DirectionStatusMotion();

	if (m_JudgmentofFootWalk)
	{
		tuOperation(RIGHT);
	}
	if (!m_JudgmentofFootWalk)
	{
		tuOperation(LEFT);
	}
	if (m_DirectionInputSignalRejectionTime == m_DirectionInputSignalRejectionMaxTime)
	{
		tuOperation(STAYING);
		m_JudgmentofFootWalk = !m_JudgmentofFootWalk;
	}
}

void Player::tuOperation(int direction)
{
	float tuAverage = 1.f / 12.f;
	int leftSideMultiplier = 0;
	int rightSideMultiplier = 0;
	switch (direction)
	{
	case LEFT:
		leftSideMultiplier = 2;
		rightSideMultiplier = 3;
		break;
	case RIGHT:
		leftSideMultiplier = 0;
		rightSideMultiplier = 1;
		break;
	case STAYING:
		leftSideMultiplier = 1;
		rightSideMultiplier = 2;
		break;
	}
	for (int i = 0;i < 4;i++)
	{
		if(i == 0 || i == 3) m_Player[i].tu = tuAverage * leftSideMultiplier;
		if(i == 1 || i == 2) m_Player[i].tu = tuAverage * rightSideMultiplier;
	}
}

void Player::DirectionStatusMotion()
{
	int divideMoveSpeed = m_DirectionInputSignalRejectionMaxTime;

	switch (m_Direction)
	{
	case LEFT:
		for(int i = 0;i < 4;i++)
		{ 
			m_Player[i].x -= m_SquaresSize / divideMoveSpeed;
		}
		tvOperation(LEFT);
		break;
	case RIGHT:
		for (int i = 0;i < 4;i++)
		{
			m_Player[i].x += m_SquaresSize / divideMoveSpeed;
		}
		tvOperation(RIGHT);
		break;
	case UP:
		for (int i = 0;i < 4;i++)
		{
			m_Player[i].y -= m_SquaresSize / divideMoveSpeed;
		}
		tvOperation(UP);
		break;
	case DOWN:
		for (int i = 0;i < 4;i++)
		{
			m_Player[i].y += m_SquaresSize / divideMoveSpeed;
		}
		tvOperation(DOWN);
		break;
	}
}

void Player::tvOperation(int direction)
{
	float tvAverage = 1.f / 8.f;
	int upSideMultiplier = 0;
	int downSideMultiplier = 0;

	switch (direction)
	{
	case LEFT:
		upSideMultiplier = 3;
		downSideMultiplier = 4;
		break;
	case RIGHT:
		upSideMultiplier = 1;
		downSideMultiplier = 2;
		break;
	case UP:
		upSideMultiplier = 0;
		downSideMultiplier = 1;
		break;
	case DOWN:
		upSideMultiplier = 2;
		downSideMultiplier = 3;
		break;
	}
	for (int i = 0;i < 4;i++)
	{
		if (i == 0 || i == 1) m_Player[i].tv = tvAverage * upSideMultiplier;
		if (i == 2 || i == 3) m_Player[i].tv = tvAverage * downSideMultiplier;
	}
}

void Player::Movement()
{
	if (m_CanDirectionInput)
	{
		if (m_pStageScroll->GetCanDirectionInput())
		{
			DirectionStatusCheck();
			if (m_Direction == STAYING) return;
			if (CanMoveInputDirection())
			{
				RowandColunmMove(m_Direction);
				m_CanDirectionInput = false;
			}
		}
	}

	if (!m_CanDirectionInput)
	{
		m_pStageScroll->Operation(&m_Direction, m_Player ,&m_DirectionInputSignalRejectionMaxTime);
		Motion();
		if (m_DirectionInputSignalRejectionTime == m_DirectionInputSignalRejectionMaxTime)
		{
			m_CanDirectionInput = true;
			m_DirectionInputSignalRejectionTime = 0;

			RowandColunmMove(m_pStageScroll->GetPreviousScroll());
		}
		m_pStageScroll->SetPreviousScroll(STAYING);
	}	
}


void Player::GameOverandClearConfirmation()
{

}
