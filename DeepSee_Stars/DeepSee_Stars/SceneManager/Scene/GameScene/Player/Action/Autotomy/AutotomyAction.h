#ifndef AUTOTOMYACTION_H
#define AUTOTOMYACTION_H

#include"../BaseAction.h"
#include "d3dx9math.h"


namespace deepseestars
{
	class AutotomyAction : public BaseAction
	{
	public:
		AutotomyAction(D3DXVECTOR2 playerCenterPos, const D3DXVECTOR2& distanceToOrigin, const float& squaresSize) : m_center(playerCenterPos), m_distanceToOrigin(distanceToOrigin), m_ObjectSize(squaresSize)
		{
			Init();
		}

		~AutotomyAction() {};

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

		//CustomVertex m_Autotomy[4];
	};
}

#endif // AUTOTOMYACTION_H
