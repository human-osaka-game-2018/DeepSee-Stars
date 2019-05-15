#ifndef CAMERA_H
#define CAMERA_H

#include "GameObject.h"

namespace deepseestars
{
	class Camera : public GameObject
	{
	public:
		Camera(const D3DXVECTOR2& playerPos, const float& squaresSize) :
			GameObject(_T("Logo"), _T("2DTexture/Game/Ayototomy.png")), m_playerPos(playerPos), m_squaresSize(squaresSize)
		{
			Init();
		}
		~Camera() {};

		void Init()
		{
			m_center = { (m_squaresSize * 14) + (m_squaresSize / 2) ,(m_squaresSize * 8) + (m_squaresSize / 2) };

			m_upperLeftPos = { m_center.x - m_vertices.GetDisplaySize().x / 2 , m_center.y - m_vertices.GetDisplaySize().y / 2 };
			m_lowerRightPos = { m_center.x + m_vertices.GetDisplaySize().x / 2 , m_center.y + m_vertices.GetDisplaySize().y / 2 };

			m_distanceToOrigin = m_worldOrigin - m_upperLeftPos;
		}

		void Update();

		void Render(){}

		void Release()
		{
			m_rGameBaseMaker.ReleaseAllTex();
		}

		void DeterminePlayerIsHide();
		void KeyOperation();
		void CenterPosReset();
		

		D3DXVECTOR2 GetoperationValue()
		{
			return m_operationValue;
		}
		void SetoperationValue(D3DXVECTOR2 operationValue)
		{
			m_operationValue = operationValue;
		}

		D3DXVECTOR2 Getcenter()
		{
			return m_center;
		}

		void Setcenter(D3DXVECTOR2 center)
		{
			m_center = center;
		}

		D3DXVECTOR2 GetUpperLeftPos()
		{
			return m_upperLeftPos;
		}
		D3DXVECTOR2 GetLowerRightPos()
		{
			return m_lowerRightPos;
		}
		D3DXVECTOR2 GetdistanceToOrigin()
		{
			return m_distanceToOrigin;
		}

		void SetIsPlayerHide(bool isPlayerHide)
		{
			m_isPlayerHide = isPlayerHide;
		}

		bool GetIsCenterReset()
		{
			return m_isCenterReset;
		}
		
	private:;
		const float& m_squaresSize;
		const D3DXVECTOR2& m_playerPos;
		D3DXVECTOR2 m_center;

		D3DXVECTOR2 m_operationValue = { 0.f,0.f };
		D3DXVECTOR2 m_worldOrigin = { 0.f,0.f };
		D3DXVECTOR2 m_upperLeftPos;
		D3DXVECTOR2 m_lowerRightPos;
		D3DXVECTOR2 m_distanceToOrigin;

		bool m_isPlayerHide = false;
		bool m_isCenterReset = false;
		const float m_operationSpeed = 10.f;
		const D3DXVECTOR2 m_operationArea = { 920.f,440.f };
	};
}

#endif // CAMERA_H
