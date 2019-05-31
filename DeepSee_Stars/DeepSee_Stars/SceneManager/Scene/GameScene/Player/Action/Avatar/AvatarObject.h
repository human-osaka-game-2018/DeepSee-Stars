#ifndef AVATAROBJECT_H
#define AVATAROBJECT_H

#include"../BaseActionObject.h"
#include"../../SceneManager/Scene/GameScene/Enum/Direction.h"

namespace deepseestars
{
	class AvatarObject : public BaseActionObject
	{
	public:
		AvatarObject(D3DXVECTOR2& CenterPos, const D3DXVECTOR2& distanceToOrigin, const float& squaresSize, const Direction& direction) :
			m_center(CenterPos), m_distanceToOrigin(distanceToOrigin), m_ObjectSize(squaresSize), m_direction(direction)
		{
			Init();
		}

		~AvatarObject()
		{
			Release();
		}

		void Init()
		{
			D3DXVECTOR2 centerBuf = m_center + m_distanceToOrigin;

			D3DXVECTOR2 pos = { centerBuf.x ,centerBuf.y - m_ObjectSize / 4 };
			D3DXVECTOR2 scale = { m_ObjectSize / 2 ,m_ObjectSize / 2 };

			m_vertices.SetPos(pos);
			m_vertices.SetScale(scale);
		}

		void Update();

		void Render();

		void Release() {}

	private:
		const D3DXVECTOR2& m_center;
		const D3DXVECTOR2& m_distanceToOrigin;
		const float& m_ObjectSize;
		const Direction& m_direction;

	};
}

#endif // AVATAROBJECT_H
