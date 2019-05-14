#include "Camera.h"

namespace deepseestars
{

	void Camera::Update()
	{
		DeterminePlayerIsHide();
		KeyOperation();
		CenterPosReset();
		m_center -= m_operationValue;

		m_upperLeft = { m_center.x - m_vertices.GetDisplaySize().x / 2 , m_center.y - m_vertices.GetDisplaySize().y / 2 };
		m_lowerRight = { m_center.x + m_vertices.GetDisplaySize().x / 2 , m_center.y + m_vertices.GetDisplaySize().y / 2 };

		m_differencetoStartingPoint = m_worldStartingPoint - m_upperLeft;
	}

	void Camera::DeterminePlayerIsHide()
	{
		if (m_isPlayerHide)
		{
			m_center = m_playerPos;
		}
		if (!m_isPlayerHide)
		{
			D3DXVECTOR2 playerHideStateCamera(0.f, 0.f);
			playerHideStateCamera.y = -50.f;
			m_center = m_playerPos + playerHideStateCamera;
		}
	}

	void Camera::KeyOperation()
	{
		if (!m_isKeyOperation)
		{
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

		if (m_rGameBaseMaker.IsPressedToKeyboard(DIK_RIGHT)||
			m_rGameBaseMaker.IsPressedToKeyboard(DIK_LEFT) ||
			m_rGameBaseMaker.IsPressedToKeyboard(DIK_UP)|| 
			m_rGameBaseMaker.IsPressedToKeyboard(DIK_DOWN))
		{
			m_isKeyOperation = true;
		}
	}


	void Camera::CenterPosReset()
	{
		if (m_isKeyOperation)
		{
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
				m_isKeyOperation = false;
			}
		}
	}

}
