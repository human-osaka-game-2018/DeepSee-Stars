﻿#include "Player.h"


namespace deepseestars
{
	void Player::Init()
	{
		m_safetyLevel = 40;
		m_retentionMissionItem = 0;
		m_variationValue = 0.f;

		m_canDirectionInput = true;
		m_isHideState = false;
		m_inTheSeaWeed = false;
		m_isAutotomyState = true;
		m_isAvatarState = true;
		m_isAutotomyAnimation = false;
		m_isAvatarAnimation = false;
		m_isAvatarCreated = false;
		m_isMoving = false;
		m_missionDirection = STAYING;
		m_prevDirection = STAYING;
		m_avatarDirection = STAYING;

		gamebasemaker::TextureUV autotomy(D3DXVECTOR2(0.0f, 0.0f), D3DXVECTOR2(1024.f, 150.f), D3DXVECTOR2(150.f, 150.f));
		m_vertices.SetTextureUV(autotomy);

		for (int i = 0;i < 7;i++)
		{
			m_rGameBaseMaker.CreateTex(m_playerTextureKey[i], m_playerTextureName[i]);
		}

		m_vertices.SetImageSize(D3DXVECTOR2(150.f, 150.f));
		m_vertices.ClippingImage(D3DXVECTOR2(0.f, 0.f), D3DXVECTOR2(150.f, 150.f));

		m_pTextureKey = m_playerTextureKey[3];

		m_center = { (m_cellSize * m_startPosRow) + (m_cellSize / 2) ,(m_cellSize * m_startPosColunm) + (m_cellSize / 2) };
	}

	void Player::Update()
	{
		UpdateAction();
		GameOverandClearConfirmation();
		m_psafetyLevel->Update();
		m_pplayerLife->Update();
		m_pretentionMissionItem->Update();
	}

	void Player::Render()
	{
		m_centerBuf = m_center + m_distanceToOrigin;
	
		//m_cellSize / 4はキャラの描画位置を上げるだけの値
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

		if (!m_pmission->GetStartMissionGet4Items()) return;
		m_pretentionMissionItem->Render();
	}

	void Player::UpdateAction()
	{
		Action();

		if (m_canDirectionInput)
		{
			if (m_isAutotomyAnimation)return;
			if (m_isAvatarAnimation)return;
			CheckDirectionStatus();
		}

		if (m_isHideState) return;

		Move();
	}

	void Player::Action()
	{
		if (!m_isAutotomyAnimation && !m_isAvatarAnimation)
		{
			Hide();
		}
		if (!m_isAutotomyAnimation)
		{
			if (m_direction == STAYING)
			{
				Avatar();
			}
		}
		if (!m_isHideState && !m_isAvatarAnimation)
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
			m_pTextureKey = m_playerTextureKey[4];
		}
		else
		{
			if (!m_isHideState)return;
			m_isHideState = false;
			m_canDirectionInput = true;
			m_pTextureKey = m_playerTextureKey[3];
			m_safetyLevel -= 40;
		}
	}

	void Player::Autotomy()
	{
		if (!m_action.CanAutotomy) return;

		if (m_pplayerLife->GetLife() <= 0) return;
	
		if (m_rGameBaseMaker.IsPressedToKeyboard(DIK_X))
		{
			if (!m_isAutotomyState) return;
		
			m_isAutotomyAnimation = true;
		
			m_isAutotomyState = false;
		
			m_vertices.PossibleAnimation();
			m_vertices.SetImageSize(D3DXVECTOR2(1024.f, 150.f));
			m_vertices.ClippingImage(D3DXVECTOR2(0.f, 0.f), D3DXVECTOR2(150.f, 150.f));
			m_pTextureKey = m_playerTextureKey[5];
		}
		
		if (m_isAutotomyAnimation)
		{
			m_vertices.Animation(6, 6);
			if (!m_vertices.GetIsPossibleAnimation())
			{
				m_isAutotomyAnimation = false;
				m_paction.push_back(new AutotomyObject(m_center, m_distanceToOrigin, m_cellSize));
				m_pplayerLife->SetLife(m_pplayerLife->GetLife() - 1);
				m_pTextureKey = m_playerTextureKey[3];
				m_vertices.SetImageSize(D3DXVECTOR2(150.f, 150.f));
				m_vertices.ClippingImage(D3DXVECTOR2(0.f, 0.f), D3DXVECTOR2(150.f, 150.f));
			}
		}
	}

	void Player::Avatar()
	{
		if (!m_action.CanAvatar) return;

		if (m_pplayerLife->GetLife() < 3) return;

		if (m_isAvatarCreated) return;

		if (m_rGameBaseMaker.IsPressedToKeyboard(DIK_C))
		{
			if (!m_isAvatarState) return;

			m_isAvatarAnimation = true;

			m_isAvatarState = false;

			m_vertices.PossibleAnimation();
			m_vertices.SetImageSize(D3DXVECTOR2(1024.f, 150.f));
			m_vertices.ClippingImage(D3DXVECTOR2(0.f, 0.f), D3DXVECTOR2(150.f, 150.f));
			m_pTextureKey = m_playerTextureKey[6];
		}

		if (m_isAvatarAnimation)
		{
			m_vertices.Animation(6, 4);
			if (!m_vertices.GetIsPossibleAnimation())
			{
				m_isAvatarAnimation = false;
				m_avatarCenter = m_center;

				if (m_directionAvatarCreate.CanMoveRight)
				{
					m_avatarCenter.x += m_cellSize;
				}
				else if (m_directionAvatarCreate.CanMoveLeft)
				{
					m_avatarCenter.x -= m_cellSize;
				}
				else if (m_directionAvatarCreate.CanMoveUp)
				{
					m_avatarCenter.y -= m_cellSize;
				}
				else if (m_directionAvatarCreate.CanMoveDown)
				{
					m_avatarCenter.y += m_cellSize;
				}
	
				m_avatarDirection = STAYING;
				m_paction.push_back(new AvatarObject(m_avatarCenter, m_distanceToOrigin, m_cellSize, m_avatarDirection));
				m_pplayerLife->SetLife(m_pplayerLife->GetLife() - 3);
				m_pTextureKey = m_playerTextureKey[3];
				m_vertices.SetImageSize(D3DXVECTOR2(150.f, 150.f));
				m_vertices.ClippingImage(D3DXVECTOR2(0.f, 0.f), D3DXVECTOR2(150.f, 150.f));
				m_isAvatarCreated = true;
			}
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
				m_pTextureKey = m_playerTextureKey[0];
				return;
			}
		}
		if (m_rGameBaseMaker.IsHoldToKeyboard(DIK_RIGHT))
		{
			if (m_movements.CanMoveRight)
			{
				m_direction = RIGHT;
				m_canDirectionInput = false;
				m_pTextureKey = m_playerTextureKey[1];
				return;
			}
		}
		if (m_rGameBaseMaker.IsHoldToKeyboard(DIK_UP))
		{
			if (m_movements.CanMoveUp)
			{
				m_direction = UP;
				m_canDirectionInput = false;
				m_pTextureKey = m_playerTextureKey[2];
				return;
			}
		}
		if (m_rGameBaseMaker.IsHoldToKeyboard(DIK_DOWN))
		{
			if (m_movements.CanMoveDown)
			{
				m_direction = DOWN;
				m_canDirectionInput = false;
				m_pTextureKey = m_playerTextureKey[3];
				return;
			}
		}
		m_direction = STAYING;
	}

	void Player::Move()
	{
		if (m_missionDirection != STAYING)
		{
			m_prevCenter = m_center;
			switch (m_missionDirection)
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
		}
		else
		{
			if (m_direction == STAYING) return;
			if (!m_isMoving)
			{
				m_prevCenter = m_center;
				m_avatarCenterBuf = m_prevCenter - m_avatarCenter;
				m_isMoving = true;
			}
			switch (m_direction)
			{
			case LEFT:
				m_center.x -= m_moveSpeed;
				m_prevDirection = LEFT;
				break;
			case RIGHT:
				m_center.x += m_moveSpeed;
				m_prevDirection = RIGHT;
				break;
			case UP:
				m_center.y -= m_moveSpeed;
				m_prevDirection = UP;
				break;
			case DOWN:
				m_center.y += m_moveSpeed;
				m_prevDirection = DOWN;
				break;
			}
			D3DXVECTOR2 avatarMoveBuf = m_avatarCenterBuf / (m_cellSize / m_moveSpeed);
			if (avatarMoveBuf.x < 0)
			{
				m_avatarDirection = LEFT;
			}
			if (avatarMoveBuf.x > 0)
			{
				m_avatarDirection = RIGHT;
			}
			if (avatarMoveBuf.y < 0)
			{
				m_avatarDirection = UP;
			}
			if (avatarMoveBuf.y > 0)
			{
				m_avatarDirection = DOWN;
			}
			m_avatarCenter += avatarMoveBuf;
		}

		m_variationValue += m_moveSpeed;

		if (m_variationValue != m_cellSize) return;

		switch (m_direction)
		{
		case LEFT:
			m_avatarDirection = LEFT;
			break;
		case RIGHT:
			m_avatarDirection = RIGHT;
			break;
		case UP:
			m_avatarDirection = UP;
			break;
		case DOWN:
			m_avatarDirection = DOWN;
			break;
		}

		m_isMoving = false;
		m_missionDirection = STAYING;
		m_isAutotomyState = true;
		m_variationValue = 0.f;
		m_canDirectionInput = true;
		m_safetyLevel -= 1;

	}

	void Player::GameOverandClearConfirmation()
	{

	}
}
