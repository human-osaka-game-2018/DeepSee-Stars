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
		Stage(const D3DXVECTOR2& distanceToOrigin, const float& squaresSize) :
			GameObject(),m_distanceToOrigin(distanceToOrigin), m_squaresSize(squaresSize)
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

		std::vector<BlockCell*> GetblockCellPos()
		{
			return m_blockCellPos;
		}
	private:
		const float& m_squaresSize;
		const D3DXVECTOR2& m_distanceToOrigin;
		//const TCHAR* m_blockTextureKey[PlAYER_RECOVERY_OBJECT + 1];
		//const TCHAR* m_blockTextureName[PlAYER_RECOVERY_OBJECT + 1];

		int m_row;
		int m_colunm;

		std::vector<BlockCell*> m_blockCellPos;
		std::vector< std::vector<int> > m_stageSize;

	};

}
#endif // STAGE_H
