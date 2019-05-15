#include "Camera.h"

namespace deepseestars
{

	void Camera::Update()
	{
		DeterminePlayerIsHide();
		KeyOperation();
		CenterPosReset();
		m_center -= m_operationValue;

		m_upperLeftPos = { m_center.x - m_vertices.GetDisplaySize().x / 2 , m_center.y - m_vertices.GetDisplaySize().y / 2 };
		m_lowerRightPos = { m_center.x + m_vertices.GetDisplaySize().x / 2 , m_center.y + m_vertices.GetDisplaySize().y / 2 };
		m_distanceToOrigin = m_worldOrigin - m_upperLeftPos;
	}

	void Camera::DeterminePlayerIsHide()
	{
		if (m_isPlayerHide)
		{
			m_center = m_playerPos;
			return;
		}

		D3DXVECTOR2 playerIsHideStateCamera(0.f, 0.f);
		playerIsHideStateCamera.y = -m_CellSize;
		m_center = m_playerPos + playerIsHideStateCamera;
	}

	void Camera::KeyOperation()
	{
		if (m_rGameBaseMaker.IsPressedToKeyboard(DIK_RIGHT) ||
			m_rGameBaseMaker.IsPressedToKeyboard(DIK_LEFT) ||
			m_rGameBaseMaker.IsPressedToKeyboard(DIK_UP) ||
			m_rGameBaseMaker.IsPressedToKeyboard(DIK_DOWN))
		{
			m_isCenterReset = true;
		}

		if (m_isCenterReset) return;

		if (m_rGameBaseMaker.IsHoldToKeyboard(DIK_A))
		{
			if (m_operationValue.x >= m_operationArea.x)return;
			m_operationValue.x += m_operationSpeed;
		}
		if (m_rGameBaseMaker.IsHoldToKeyboard(DIK_D))
		{
			if (m_operationValue.x <= -m_operationArea.x)return;
			m_operationValue.x -= m_operationSpeed;
		}
		if (m_rGameBaseMaker.IsHoldToKeyboard(DIK_W))
		{
			if (m_operationValue.y >= m_operationArea.y)return;
			m_operationValue.y += m_operationSpeed;
		}
		if (m_rGameBaseMaker.IsHoldToKeyboard(DIK_S))
		{
			if (m_operationValue.y <= -m_operationArea.y)return;
			m_operationValue.y -= m_operationSpeed;
		}
	}


	void Camera::CenterPosReset()
	{
		if (!m_isCenterReset) return;

		if (m_operationValue.x > 0)
		{
			m_operationValue.x -= m_operationSpeed * 5;
			if (m_operationValue.x > 0)return;
			m_operationValue.x = 0.f;
		}
		if (m_operationValue.x < 0)
		{
			m_operationValue.x += m_operationSpeed * 5;
			if (m_operationValue.x < 0)return;
			m_operationValue.x = 0.f;
		}
		if (m_operationValue.y > 0)
		{
			m_operationValue.y -= m_operationSpeed * 5;
			if (m_operationValue.y > 0)return;
			m_operationValue.y = 0.f;
		}
		if (m_operationValue.y < 0)
		{
			m_operationValue.y += m_operationSpeed * 5;
			if (m_operationValue.y < 0)return;
			m_operationValue.y = 0.f;
		}

		if (m_operationValue.x == 0 && m_operationValue.y == 0)
		{
			m_isCenterReset = false;
		}
	}

}
