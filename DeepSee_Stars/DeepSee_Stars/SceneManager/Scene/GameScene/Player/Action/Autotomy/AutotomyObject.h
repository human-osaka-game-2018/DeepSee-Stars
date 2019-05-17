#ifndef AUTOTOMYOBJECT_H
#define AUTOTOMYOBJECT_H

#include"../BaseActionObject.h"
#include "d3dx9math.h"


namespace deepseestars
{
	class AutotomyObject : public BaseActionObject
	{
	public:
		AutotomyObject(D3DXVECTOR2 playerCenterPos, const D3DXVECTOR2& distanceToOrigin, const float& squaresSize) :
			m_center(playerCenterPos), m_distanceToOrigin(distanceToOrigin), m_ObjectSize(squaresSize)
		{
			Init();
		}

		~AutotomyObject() {};

		void Init() 
		{

		}

		void Update();

		void Render();

		void Release() {}

	private:
		const D3DXVECTOR2 m_center;
		const D3DXVECTOR2& m_distanceToOrigin;
		const float& m_ObjectSize;

	};
}

#endif // AUTOTOMYOBJECT_H
