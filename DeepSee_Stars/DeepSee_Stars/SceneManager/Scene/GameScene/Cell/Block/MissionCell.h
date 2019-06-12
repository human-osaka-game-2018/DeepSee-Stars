#ifndef MISSIONCELL_H
#define MISSIONCELL_H

#include "GameObject.h"
#include <vector>

namespace deepseestars
{
	class MissionCell : public GameObject
	{
	public:
		MissionCell(const D3DXVECTOR2& distanceToOrigin, D3DXVECTOR2 blockPos,const char blockType, const float& blockSize) :
			GameObject(), m_distanceToOrigin(distanceToOrigin), m_center(blockPos), m_type(blockType), m_blockSize(blockSize)
		{
			Init();
		}

		~MissionCell()
		{
			Release();
		}

		void Init()
		{

		}

		void Update();

		void Render();

		void Release() {}

		D3DXVECTOR2 Getcenter()
		{
			return m_center;
		}
		void Setcenter(D3DXVECTOR2 center)
		{
			m_center = center;
		}

		const char Gettype()
		{
			return m_type;
		}

	private:
		const D3DXVECTOR2& m_distanceToOrigin;
		const float& m_blockSize;

		D3DXVECTOR2 m_center;
		const char m_type;
		bool m_isWithinRenderArea = false;
	};
}

#endif // MISSIONCELL_H
