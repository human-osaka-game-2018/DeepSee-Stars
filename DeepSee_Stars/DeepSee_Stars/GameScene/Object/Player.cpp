#include "Player.h"


Player::Player()
{
	m_pDirectX = DirectX::GetInstance();
	Init();
}

Player::~Player()
{

}

void Player::Init()
{
	m_CanDirectionInput = true;
	m_IsHideState = false;
	m_OnAvatar = false;
	m_OnAutotomy = false;

	m_pDirectX->InitVertex(m_Player);
	m_pDirectX->InitRectangleCustomVertex(m_Player, 928, 512, m_TextureSizeX, m_TextureSizeY);

	m_CenterPos.x = m_Player[0].x + m_SquaresSize / 2;
	m_CenterPos.y = m_Player[0].y + m_SquaresSize + m_SquaresSize / 2;

	for (int i = 0;i < 4;i++)
	{
		if (i == 0 || i == 3) m_Player[i].tu = static_cast<float>(0.0833) * 1;
		if (i == 1 || i == 2) m_Player[i].tu = static_cast<float>(0.0833) * 2;
		if (i == 0 || i == 1) m_Player[i].tv = static_cast<float>(0.128) * 2;
		if (i == 2 || i == 3) m_Player[i].tv = static_cast<float>(0.128) * 3;
	}
}

void Player::Update()
{
	Movement();
	GameOverandClearConfirmation();
}

void Player::Render(D3DXVECTOR2 drawArea)
{
	m_CenterPosBuf = m_CenterPos + drawArea;
	CustomVertex vertexBuf[4];
	m_pDirectX->InitRectangleCustomVertex(vertexBuf, m_CenterPosBuf.x, m_CenterPosBuf.y - 32, m_TextureSizeX, m_TextureSizeY);
	for (int i = 0;i<4;++i)
	{
		vertexBuf[i].tu = m_Player[i].tu;
		vertexBuf[i].tv = m_Player[i].tv;
	}
	m_pDirectX->DrawTexture("GAME_PLAYER_TEX", vertexBuf);
	if (m_OnAutotomy)
	{
		D3DXVECTOR2 centerPosbBuf = m_AutotomyCenterPos + drawArea;
		m_pDirectX->InitSquareCustomVertex(m_Autotomy, centerPosbBuf.x, centerPosbBuf.y, m_SquaresSize);
		m_pDirectX->DrawTexture("GAME_PLAYER_TEX", m_Autotomy);
	}
	//if (m_OnAvatar)
	//{
	//	m_pDirectX->DrawTexture("GAME_PLAYER_TEX", m_Avatar);
	//}
}

void Player::Movement()
{
	if (m_CanDirectionInput)
	{
		DirectionStatusCheck();
	}
	Action();
	if (!m_IsHideState)
	{
		DirectionStatusMotion();
	}
}

void Player::Action()
{
	if (m_CanAction.IsHide)
	{
		Hide();
	}
	if (m_CanAction.IsAutotomy)
	{
		Autotomy();
	}
	if (m_CanAction.IsAvatar)
	{
		Avatar();
	}
}

void Player::Hide()
{
	if (m_pDirectX->IsKeyPressed(DIK_Z))
	{
		m_CenterPos.y = m_CenterPos.y - 64.f;
		m_IsHideState = true;
		m_Direction = STAYING;
	}
	else
	{
		if (!m_IsHideState)return;
		m_IsHideState = false;
		m_CanDirectionInput = true;
	}
}

void Player::Autotomy()
{
	if (m_pDirectX->IsKeyPressed(DIK_X))
	{
		if (!m_OnAutotomy)
		{
			m_OnAutotomy = true;
			m_AutotomyCenterPos = m_CenterPos;
		}
	}
}

void Player::Avatar()
{
	//if (m_pDirectX->IsKeyPressed(DIK_C))
	//{
	//	m_pDirectX->InitRectangleCustomVertex(m_Avatar, m_CenterPosbBuf.x - 64.f, m_CenterPosbBuf.y - 32, m_TextureSizeX, m_TextureSizeY);
	//	for (int i = 0;i<4;++i)
	//	{
	//		m_Avatar[i].tu = m_Player[i].tu;
	//		m_Avatar[i].tv = m_Player[i].tv;
	//	}
	//	m_OnAvatar = true;
	//}
}

void Player::DirectionStatusCheck()
{
	if (m_pDirectX->IsKeyPressed(DIK_LEFT))
	{
		if (m_CanMoveDirection.IsLeft)
		{
			m_Direction = LEFT;
			m_CanDirectionInput = false;
			return;
		}
	}
	if (m_pDirectX->IsKeyPressed(DIK_RIGHT))
	{
		if (m_CanMoveDirection.IsRight)
		{
			m_Direction = RIGHT;
			m_CanDirectionInput = false;
			return;
		}
	}
	if (m_pDirectX->IsKeyPressed(DIK_UP))
	{
		if (m_CanMoveDirection.IsUp)
		{
			m_Direction = UP;
			m_CanDirectionInput = false;
			return;
		}
	}
	if (m_pDirectX->IsKeyPressed(DIK_DOWN))
	{
		if (m_CanMoveDirection.IsDown)
		{
			m_Direction = DOWN;
			m_CanDirectionInput = false;
			return;
		}
	}
	m_Direction = STAYING;
}

void Player::DirectionStatusMotion()
{
	if (m_Direction == STAYING) return;

	static float variationValue = 0.f;
	switch (m_Direction)
	{
	case LEFT:
		for (int i = 0;i < 4;i++)
		{
			m_Player[i].x -= 4.f;
		}
		tvOperation(LEFT);
		break;
	case RIGHT:
		for (int i = 0;i < 4;i++)
		{
			m_Player[i].x += 4.f;
		}
		tvOperation(RIGHT);
		break;
	case UP:
		for (int i = 0;i < 4;i++)
		{
			m_Player[i].y -= 4.f;
		}
		tvOperation(UP);
		break;
	case DOWN:
		for (int i = 0;i < 4;i++)
		{
			m_Player[i].y += 4.f;
		}
		tvOperation(DOWN);
		break;
	}
	variationValue += 4.f;
	if (variationValue == m_SquaresSize)
	{
		variationValue = 0.f;
		m_CanDirectionInput = true;
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
		if (i == 0 || i == 3) m_Player[i].tu = tuAverage * leftSideMultiplier;
		if (i == 1 || i == 2) m_Player[i].tu = tuAverage * rightSideMultiplier;
	}
}

void Player::tvOperation(int direction)
{
	float tvAverage = 1.f / 8.f;
	int upSideMultiplier = 0;
	int downSideMultiplier = 0;

	switch (m_Direction)
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

void Player::GameOverandClearConfirmation()
{

}
