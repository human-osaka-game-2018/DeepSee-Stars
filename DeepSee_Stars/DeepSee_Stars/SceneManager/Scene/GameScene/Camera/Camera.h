#ifndef CAMERA_H
#define CAMERA_H

#include "GameObject.h"

namespace deepseestars
{
	class Camera : public GameObject
	{
	public:
		Camera(const D3DXVECTOR2& playerPos) :
			GameObject(_T("Logo"), _T("2DTexture/Game/Ayototomy.png")), m_playerPos(playerPos)
		{
			Init();
		}
		~Camera() {};

		void Init()
		{
			const float squaresSize = 100.f;
		
			m_center = { (squaresSize * 14) + (squaresSize / 2) ,(squaresSize * 8) + (squaresSize / 2) };

			m_upperLeft = { m_center.x - m_vertices.GetDisplaySize().x / 2 , m_center.y - m_vertices.GetDisplaySize().y / 2 };
			m_lowerRight = { m_center.x + m_vertices.GetDisplaySize().x / 2 , m_center.y + m_vertices.GetDisplaySize().y / 2 };

			m_differencetoStartingPoint = m_worldStartingPoint - m_upperLeft;
		}

		void Update();

		void Render(){}

		void Release()
		{
			m_rGameBaseMaker.ReleaseAllTex();
		}

		void KeyOperation();
		void CenterPosReset();

		D3DXVECTOR2 Getcenter()
		{
			return m_center;
		}

		D3DXVECTOR2 GetUpperLeft()
		{
			return m_upperLeft;
		}
		D3DXVECTOR2 GetLowerRight()
		{
			return m_lowerRight;
		}
		D3DXVECTOR2 GetUpperLeftWithTheDifference()
		{
			return m_differencetoStartingPoint;
		}

		bool GetIsKeyOperation()
		{
			return m_isKeyOperation;
		}
	private:
		const D3DXVECTOR2& m_playerPos;
		D3DXVECTOR2 m_center;

		D3DXVECTOR2 m_operationValue = { 0.f,0.f };
		D3DXVECTOR2 m_worldStartingPoint = { 0.f,0.f };
		D3DXVECTOR2 m_upperLeft;
		D3DXVECTOR2 m_lowerRight;
		D3DXVECTOR2 m_differencetoStartingPoint;

		bool m_isKeyOperation = false;
		const float m_OperationSpeed = 10.f;
		const D3DXVECTOR2 m_operationArea = { 920.f,440.f };
	};
}

#endif // CAMERA_H
