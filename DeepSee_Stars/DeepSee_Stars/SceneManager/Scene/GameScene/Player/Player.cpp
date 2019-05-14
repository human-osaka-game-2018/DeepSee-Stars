#include "Player.h"


namespace deepseestars
{
	Player::~Player()
	{
		for (auto& actionObject : m_paction)
		{
			delete actionObject;
		}
	}

	void Player::Update()
	{
		Movement();
		GameOverandClearConfirmation();
	}

	void Player::Render()
	{
		m_centerPosBuf = m_centerPos + m_differencetoStartingPoint;

		D3DXVECTOR2 pos ={ m_centerPosBuf.x ,m_centerPosBuf.y};
		D3DXVECTOR2 scale = { m_TextureSizeX/2,m_TextureSizeY/2};

		m_vertices.SetPos(pos);
		m_vertices.SetScale(scale);


		for (auto& actionObject : m_paction)
		{
			actionObject->Render();
		}
		m_rGameBaseMaker.Render(m_vertices, m_rGameBaseMaker.GetTex(m_pTextureKey));
	}

	void Player::Movement()
	{
		if (m_canDirectionInput)
		{
			DirectionStatusCheck();
		}
		Action();
		if (!m_isHideState)
		{
			DirectionStatusMotion();
		}
	}

	void Player::Action()
	{

		Hide();
		//if (!m_IsHideState)
		//{
		//	Autotomy();
		//}
		//Avatar();

		//for (auto& actionObject : m_pAction)
		//{
		//	actionObject->Update(m_DrawArea);
		//}
	}

	void Player::Hide()
	{
		if (m_canAction.IsHide)
		{
			if (m_rGameBaseMaker.IsHoldToKeyboard(DIK_Z))
			{
			m_centerPos.y = m_centerPos.y - m_SquaresSize;
				tvOperation(DOWN);
				m_isHideState = true;
				m_direction = STAYING;
			}
			else
			{
				if (!m_isHideState)return;
				m_isHideState = false;
				m_canDirectionInput = true;
			}
		}
	}

	void Player::Autotomy()
	{
		if (!m_canAction.IsAutotomy) return;
		if (m_rGameBaseMaker.IsPressedToKeyboard(DIK_X))
		{
			if (!m_isAutotomy) return;
			if (m_Life > 0)
			{
				m_Life -= 1;
				m_isAutotomy = false;
				//m_pAction.push_back(new AutotomyAction(m_CenterPos));
			}
		}
	}

	void Player::Avatar()
	{
		if (m_canAction.IsAvatar)
		{
			
		}
	}

	void Player::DirectionStatusCheck()
	{
		if (m_rGameBaseMaker.IsHoldToKeyboard(DIK_LEFT))
		{
			if (m_canMoveDirection.IsLeft)
			{
				m_direction = LEFT;
				m_canDirectionInput = false;
				return;
			}
		}
		if (m_rGameBaseMaker.IsHoldToKeyboard(DIK_RIGHT))
		{
			if (m_canMoveDirection.IsRight)
			{
				m_direction = RIGHT;
				m_canDirectionInput = false;
				return;
			}
		}
		if (m_rGameBaseMaker.IsHoldToKeyboard(DIK_UP))
		{
			if (m_canMoveDirection.IsUp)
			{
				m_direction = UP;
				m_canDirectionInput = false;
				return;
			}
		}
		if (m_rGameBaseMaker.IsHoldToKeyboard(DIK_DOWN))
		{
			if (m_canMoveDirection.IsDown)
			{
				m_direction = DOWN;
				m_canDirectionInput = false;
				return;
			}
		}
		m_direction = STAYING;
	}

	void Player::DirectionStatusMotion()
	{
		if (m_direction == STAYING) return;
		static float variationValue = 0.f;
		switch (m_direction)
		{
		case LEFT:
			m_centerPos.x -= m_MoveSpeed;
			break;
		case RIGHT:
			m_centerPos.x += m_MoveSpeed;
			break;
		case UP:
			m_centerPos.y -= m_MoveSpeed;
			break;
		case DOWN:
			m_centerPos.y += m_MoveSpeed;
			break;
		}
		variationValue += m_MoveSpeed;
		if (variationValue == m_SquaresSize)
		{
			m_isAutotomy = true;
			variationValue = 0.f;
			m_canDirectionInput = true;
		}
	}

	void Player::tuOperation(int direction)
	{
		//float tuAverage = 1.f / 12.f;
		//int leftSideMultiplier = 0;
		//int rightSideMultiplier = 0;
		//switch (direction)
		//{
		//case LEFT:
		//	leftSideMultiplier = 2;
		//	rightSideMultiplier = 3;
		//	break;
		//case RIGHT:
		//	leftSideMultiplier = 0;
		//	rightSideMultiplier = 1;
		//	break;
		//case STAYING:
		//	leftSideMultiplier = 1;
		//	rightSideMultiplier = 2;
		//	break;
		//}
		//for (int i = 0;i < 4;i++)
		//{
		//	if (i == 0 || i == 3) m_Player[i].tu = tuAverage * leftSideMultiplier;
		//	if (i == 1 || i == 2) m_Player[i].tu = tuAverage * rightSideMultiplier;
		//}
	}

	void Player::tvOperation(int direction)
	{
		//float tvAverage = 1.f / 8.f;
		//int upSideMultiplier = 0;
		//int downSideMultiplier = 0;
		//
		//switch (direction)
		//{
		//case LEFT:
		//	upSideMultiplier = 3;
		//	downSideMultiplier = 4;
		//	break;
		//case RIGHT:
		//	upSideMultiplier = 1;
		//	downSideMultiplier = 2;
		//	break;
		//case UP:
		//	upSideMultiplier = 0;
		//	downSideMultiplier = 1;
		//	break;
		//case DOWN:
		//	upSideMultiplier = 2;
		//	downSideMultiplier = 3;
		//	break;
		//}
		//for (int i = 0;i < 4;i++)
		//{
		//	if (i == 0 || i == 1) m_Player[i].tv = tvAverage * upSideMultiplier;
		//	if (i == 2 || i == 3) m_Player[i].tv = tvAverage * downSideMultiplier;
		//}
	}

	void Player::GameOverandClearConfirmation()
	{

	}
}
