#ifndef CAMERA_H
#define CAMERA_H

#include "d3dx9.h"
#include "Object.h"

class Camera
{
public:
	void Operation(D3DXVECTOR2 center);

	D3DXVECTOR2 GetUpperLeft()
	{
		return m_UpperLeft;
	}
	D3DXVECTOR2 GetLowerRight()
	{
		return m_LowerRight;
	}
	D3DXVECTOR2 GetUpperLeftWithTheDifference()
	{
		return m_UpperLeftWithTheDifference;
	}
private:
	D3DXVECTOR2 m_WorldStartingPoint = {0.f,0.f};
	D3DXVECTOR2 m_UpperLeft;
	D3DXVECTOR2 m_LowerRight;
	D3DXVECTOR2 m_UpperLeftWithTheDifference;
};

#endif // CAMERA_H
