#include "Camera.h"

Camera::Camera()
{
	m_pDirectX = DirectX::GetInstance();
}

Camera::~Camera()
{
	
}

void Camera::Update(D3DXVECTOR2 center)
{
	KeyOperation();
	CenterPosReset();
	center -= m_OperationValue;

	m_UpperLeft = { center.x - DISPLAY_WIDTH / 2 , center.y - DISPLAY_HEIGHT / 2 };
	m_LowerRight = { center.x + DISPLAY_WIDTH / 2 , center.y + DISPLAY_HEIGHT / 2 };

	m_UpperLeftWithTheDifference = m_WorldStartingPoint - m_UpperLeft;
}


void Camera::KeyOperation()
{
	if (!m_IsKeyOperation)
	{
		if (m_pDirectX->IsKeyPressed(DIK_A))
		{
			if (m_OperationValue.x >= m_OperationArea.x)return;
				m_OperationValue.x += m_OperationSpeed;
		}
		if (m_pDirectX->IsKeyPressed(DIK_D))
		{
			if (m_OperationValue.x <= -m_OperationArea.x)return;
				m_OperationValue.x -= m_OperationSpeed;
		}
		if (m_pDirectX->IsKeyPressed(DIK_W))
		{
			if (m_OperationValue.y >= m_OperationArea.y)return;
				m_OperationValue.y += m_OperationSpeed;
		}
		if (m_pDirectX->IsKeyPressed(DIK_S))
		{
			if (m_OperationValue.y <= -m_OperationArea.y)return;
				m_OperationValue.y -= m_OperationSpeed;
		}
	}
	if (m_pDirectX->IsKeyPressed(DIK_RIGHT))
	{
		m_IsKeyOperation = true;
	}
	if (m_pDirectX->IsKeyPressed(DIK_LEFT))
	{
		m_IsKeyOperation = true;
	}
	if (m_pDirectX->IsKeyPressed(DIK_UP))
	{
		m_IsKeyOperation = true;
	}
	if (m_pDirectX->IsKeyPressed(DIK_DOWN))
	{
		m_IsKeyOperation = true;
	}
}


void Camera::CenterPosReset()
{
	if (m_IsKeyOperation)
	{
		if (m_OperationValue.x > 0)
		{
			m_OperationValue.x -= m_OperationSpeed * 5;
			if (m_OperationValue.x > 0)return;
			m_OperationValue.x = 0.f;
		}
		if (m_OperationValue.x < 0)
		{
			m_OperationValue.x += m_OperationSpeed * 5;
			if (m_OperationValue.x < 0)return;
			m_OperationValue.x = 0.f;
		}
		if (m_OperationValue.y > 0)
		{
			m_OperationValue.y -= m_OperationSpeed * 5;
			if (m_OperationValue.y > 0)return;
			m_OperationValue.y = 0.f;
		}
		if (m_OperationValue.y < 0)
		{
			m_OperationValue.y += m_OperationSpeed * 5;
			if (m_OperationValue.y < 0)return;
			m_OperationValue.y = 0.f;
		}

		if (m_OperationValue.x == 0 && m_OperationValue.y == 0)
		{
			m_IsKeyOperation = false;
		}
	}
}
