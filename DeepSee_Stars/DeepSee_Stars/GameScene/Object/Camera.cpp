#include "Camera.h"


void Camera::Operation(D3DXVECTOR2 center)
{
	m_UpperLeft = { center.x - DISPLAY_WIDTH / 2 , center.y - DISPLAY_HEIGHT / 2 };
	m_LowerRight = { center.x + DISPLAY_WIDTH / 2 , center.y + DISPLAY_HEIGHT / 2 };

	m_UpperLeftWithTheDifference = m_WorldStartingPoint - m_UpperLeft;
}
