#ifndef STAGE_H
#define STAGE_H

#include <vector>
#include "../Cell/Block/BlockCell.h"
#include "GameObject.h"

namespace deepseestars
{

	class Stage : public GameObject
	{
	public:
		Stage(const D3DXVECTOR2& differencetoStartingPoint) :
			GameObject(_T(""), _T("")), m_differencetoStartingPoint(differencetoStartingPoint)
		{
			Init();
		}

		~Stage() {}

		void Init()
		{
			LoadStageDate("csv/Stage1.csv");
			BlockCreate();
		}

		void Update();

		void Render();

		void Release() {}

		void LoadStageDate(const char* fileName);
		void BlockCreate();


		std::vector<BlockCell*> m_blockCellPos;
	private:

		const D3DXVECTOR2& m_differencetoStartingPoint;

		int m_row;
		int m_colunm;

		std::vector< std::vector<int> > m_stageData;

	};

}
#endif // STAGE_H
