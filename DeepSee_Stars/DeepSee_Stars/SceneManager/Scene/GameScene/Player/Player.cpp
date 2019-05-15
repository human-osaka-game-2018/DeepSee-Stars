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
		Move();
		GameOverandClearConfirmation();
	}

	void Player::Render()
	{
		m_centerBuf = m_center + m_distanceToOrigin;

		D3DXVECTOR2 pos ={ m_centerBuf.x ,m_centerBuf.y};
		D3DXVECTOR2 scale = { m_TextureSizeX/2,m_TextureSizeY/2};

		m_vertices.SetPos(pos);
		m_vertices.SetScale(scale);


		for (auto& actionObject : m_paction)
		{
			actionObject->Render();
		}
		m_rGameBaseMaker.Render(m_vertices, m_rGameBaseMaker.GetTex(m_pTextureKey));
	}

	void Player::Move()
	{
		if (m_canDirectionInput)
		{
			DirectionStatusCheck();
		}
		Action();
		if (m_isHideState) return;
		DirectionStatusMotion();
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
		if (!m_action.CanHide) return;

		if (m_rGameBaseMaker.IsHoldToKeyboard(DIK_Z))
		{
			m_center.y = m_center.y - m_CellSize;
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

	void Player::Autotomy()
	{
		if (!m_action.CanAutotomy) return;

		if (m_rGameBaseMaker.IsPressedToKeyboard(DIK_X))
		{
			if (!m_isAutotomyState) return;

			if (m_Life < 0) return;

			m_Life -= 1;
			m_isAutotomyState = false;
			//m_pAction.push_back(new AutotomyAction(m_CenterPos));
		}
	}

	void Player::Avatar()
	{
		if (m_action.CanAvatar)
		{
			
		}
	}

	void Player::DirectionStatusCheck()
	{
		if (m_rGameBaseMaker.IsHoldToKeyboard(DIK_LEFT))
		{
			if (m_movements.CanMoveLeft)
			{
				m_direction = LEFT;
				m_canDirectionInput = false;
				return;
			}
		}
		if (m_rGameBaseMaker.IsHoldToKeyboard(DIK_RIGHT))
		{
			if (m_movements.CanMoveRight)
			{
				m_direction = RIGHT;
				m_canDirectionInput = false;
				return;
			}
		}
		if (m_rGameBaseMaker.IsHoldToKeyboard(DIK_UP))
		{
			if (m_movements.CanMoveUp)
			{
				m_direction = UP;
				m_canDirectionInput = false;
				return;
			}
		}
		if (m_rGameBaseMaker.IsHoldToKeyboard(DIK_DOWN))
		{
			if (m_movements.CanMoveDown)
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
		switch (m_direction)
		{
		case LEFT:
			m_center.x -= m_MoveSpeed;
			break;
		case RIGHT:
			m_center.x += m_MoveSpeed;
			break;
		case UP:
			m_center.y -= m_MoveSpeed;
			break;
		case DOWN:
			m_center.y += m_MoveSpeed;
			break;
		}

		m_variationValue += m_MoveSpeed;

		if (m_variationValue != m_CellSize) return;
		m_isAutotomyState = true;
		m_variationValue = 0.f;
		m_canDirectionInput = true;
	}

	void Player::GameOverandClearConfirmation()
	{

	}
}
