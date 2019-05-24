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
		delete m_pplayerLife;
		m_pplayerLife = nullptr;
		delete m_psafetyLevel;
		m_psafetyLevel = nullptr;
	}

	void Player::Init()
	{
		m_life = 5;
		m_safetyLevel = 40;
		m_pplayerLife = new PlayerLife(m_life);
		m_psafetyLevel = new SafetyLevel(m_safetyLevel, m_direction, m_isHideState, m_inTheSeaWeed);

		gamebasemaker::TextureUV autotomy(D3DXVECTOR2(0.0f, 0.0f), D3DXVECTOR2(1024.f, 150.f), D3DXVECTOR2(150.f, 150.f));
		m_vertices.SetTextureUV(autotomy);

		for (int i = 0;i <= 8;i++)
		{
			m_rGameBaseMaker.CreateTex(m_playerTextureKey[i], m_playerTextureName[i]);
		}

		m_vertices.SetImageSize(D3DXVECTOR2(150.f, 150.f));
		m_vertices.ClippingImage(D3DXVECTOR2(0.f, 0.f), D3DXVECTOR2(150.f, 150.f));

		m_pTextureKey = m_playerTextureKey[2];

		m_canDirectionInput = true;
		m_isHideState = false;
		m_inTheSeaWeed = false;
		m_isAutotomyState = true;
		m_isAutotomyAnimation = false;

		m_center = { (m_cellSize * m_startPosRow) + (m_cellSize / 2) ,(m_cellSize * m_startPosColunm) + (m_cellSize / 2) };
	}

	void Player::Update()
	{
		UpdateAction();
		StatusManagement();
		GameOverandClearConfirmation();
	}

	void Player::Render()
	{
		m_centerBuf = m_center + m_distanceToOrigin;

		float posY = m_centerBuf.y - m_cellSize / 4;
		if (m_isHideState)
		{
			posY = m_centerBuf.y;
		}
		D3DXVECTOR2 pos ={ m_centerBuf.x ,posY };
		D3DXVECTOR2 scale = { m_textureSizeX/2,m_textureSizeY/2};

		m_vertices.SetPos(pos);
		m_vertices.SetScale(scale);

		for (auto& actionObject : m_paction)
		{
			actionObject->Render();
		}
		
		m_rGameBaseMaker.Render(m_vertices, m_rGameBaseMaker.GetTex(m_pTextureKey));

		m_pplayerLife->Render();
		m_psafetyLevel->Render();
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
		if (!m_isAutotomyAnimation)
		{
			Hide();
		}
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
			if (!m_isHideState)
			{
				m_safetyLevel += 40;
			}
			m_center.y = m_center.y - m_cellSize;
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
			m_safetyLevel -= 40;
		}
	}

	void Player::Autotomy()
	{
		if (!m_action.CanAutotomy) return;

		if (m_life <= 0) return;

		//if (m_pautotomyAction->Update())
		//{
		//	m_paction.push_back(new AutotomyObject(m_center, m_distanceToOrigin, m_CellSize));
		//	m_life -= 1;
		//	m_pTextureKey = m_playerTextureKey[2];
		//	m_vertices.SetImageSize(D3DXVECTOR2(150.f, 150.f));
		//	m_vertices.ClippingImage(D3DXVECTOR2(0.f, 0.f), D3DXVECTOR2(150.f, 150.f));
		//}
	
		if (m_rGameBaseMaker.IsPressedToKeyboard(DIK_X))
		{
			if (!m_isAutotomyState) return;
		
			m_isAutotomyAnimation = true;
		
			m_isAutotomyState = false;
		
			
			m_vertices.PossibleAnimation();
			m_vertices.SetImageSize(D3DXVECTOR2(1024.f, 150.f));
			m_vertices.ClippingImage(D3DXVECTOR2(0.f, 0.f), D3DXVECTOR2(150.f, 150.f));
			m_pTextureKey = m_playerTextureKey[4];
		}
		
		if (m_isAutotomyAnimation)
		{
			m_vertices.Animation(6, 6);
			if (!m_vertices.GetIsPossibleAnimation())
			{
				m_isAutotomyAnimation = false;
				m_paction.push_back(new AutotomyObject(m_center, m_distanceToOrigin, m_cellSize));
				m_life -= 1;
				m_pTextureKey = m_playerTextureKey[2];
				m_vertices.SetImageSize(D3DXVECTOR2(150.f, 150.f));
				m_vertices.ClippingImage(D3DXVECTOR2(0.f, 0.f), D3DXVECTOR2(150.f, 150.f));
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
			m_center.x -= m_moveSpeed;
			break;
		case RIGHT:
			m_center.x += m_moveSpeed;
			break;
		case UP:
			m_center.y -= m_moveSpeed;
			break;
		case DOWN:
			m_center.y += m_moveSpeed;
			break;
		}

		m_variationValue += m_moveSpeed;

		if (m_variationValue != m_cellSize) return;

		m_isAutotomyState = true;
		m_variationValue = 0.f;
		m_canDirectionInput = true;
		m_safetyLevel -= 1;

	}

	void Player::StatusManagement()
	{
		m_psafetyLevel->Update();

		m_pplayerLife->Update();
	}

	void Player::GameOverandClearConfirmation()
	{

	}
}
