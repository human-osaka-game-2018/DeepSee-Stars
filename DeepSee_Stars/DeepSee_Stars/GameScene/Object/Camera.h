#ifndef CAMERA_H
#define CAMERA_H

#include "d3dx9.h"
#include "Object.h"

class Camera
{
public:
	Camera();
	~Camera();
	void Update(D3DXVECTOR2 center);
	void KeyOperation();
	void CenterPosReset();

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

	bool GetIsKeyOperation()
	{
		return m_IsKeyOperation;
	}
private:
	DirectX * m_pDirectX;

	D3DXVECTOR2 m_OperationValue = { 0.f,0.f };
	D3DXVECTOR2 m_WorldStartingPoint = {0.f,0.f};
	D3DXVECTOR2 m_UpperLeft;
	D3DXVECTOR2 m_LowerRight;
	D3DXVECTOR2 m_UpperLeftWithTheDifference;

	bool m_IsKeyOperation = false;
	const float m_OperationSpeed = 10.f;
	const D3DXVECTOR2 m_OperationArea = {920.f,440.f};
};

#endif // CAMERA_H
