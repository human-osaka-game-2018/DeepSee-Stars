#include "Player.h"


namespace deepseestars
{
	Player::~Player()
	{
		for (auto& actionObject : m_paction)
		{
			delete actionObject;
			actionObject = nullptr;
		}
	}

	void Player::Update()
	{
		UpdateAction();
		GameOverandClearConfirmation();
	}

	void Player::Render()
	{
		m_centerBuf = m_center + m_distanceToOrigin;

		float posY = m_centerBuf.y - m_CellSize / 4;
		if (m_isHideState)
		{
			posY = m_centerBuf.y;
		}
		D3DXVECTOR2 pos ={ m_centerBuf.x ,posY };
		D3DXVECTOR2 scale = { m_TextureSizeX/2,m_TextureSizeY/2};

		m_vertices.SetPos(pos);
		m_vertices.SetScale(scale);

		for (auto& actionObject : m_paction)
		{
			actionObject->Render();
		}
		
		m_rGameBaseMaker.Render(m_vertices, m_rGameBaseMaker.GetTex(m_pTextureKey));
	}

	void Player::UpdateAction()
	{
		Action();

		if (m_canDirectionInput)
		{
			if (m_isAutotomyAnimation)return;
			CheckDirectionStatus();
		}

		if (m_isHideState) return;

		Move();
	}

	void Player::Action()
	{

		Hide();
		if (!m_isHideState)
		{
			Autotomy();
		}
		//Avatar();

		for (auto& actionObject : m_paction)
		{
			actionObject->Update();
		}
	}

	void Player::Hide()
	{
		if (!m_action.CanHide) return;

		if (m_rGameBaseMaker.IsHoldToKeyboard(DIK_Z))
		{
			m_center.y = m_center.y - m_CellSize;
			m_isHideState = true;
			m_direction = STAYING;
			m_pTextureKey = m_playerTextureKey[3];
		}
		else
		{
			if (!m_isHideState)return;
			m_isHideState = false;
			m_canDirectionInput = true;
			m_pTextureKey = m_playerTextureKey[2];
		}
	}

	void Player::Autotomy()
	{
		if (!m_action.CanAutotomy) return;

		if (m_rGameBaseMaker.IsPressedToKeyboard(DIK_X))
		{
			if (m_life <= 0) return;

			if (!m_isAutotomyState) return;

			m_pTextureKey = m_playerTextureKey[4];

			m_vertices.PossibleAnimation();

			m_isAutotomyAnimation = true;

			m_isAutotomyState = false;
		}

		if (m_isAutotomyAnimation)
		{
			m_vertices.Animation(4, 6);
			if (!m_vertices.GetIsPossibleAnimation())
			{
				m_paction.push_back(new AutotomyAction(m_center, m_distanceToOrigin, m_CellSize));
				m_life -= 1;
				m_isAutotomyAnimation = false;
			}
		}
	}

	void Player::Avatar()
	{
		if (m_action.CanAvatar)
		{
			
		}
	}

	void Player::CheckDirectionStatus()
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

	void Player::Move()
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
