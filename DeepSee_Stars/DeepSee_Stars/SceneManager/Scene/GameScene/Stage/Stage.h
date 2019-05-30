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
			GameObject(),m_distanceToOrigin(distanceToOrigin), m_CellSize(squaresSize)
		{
			Init();
		}

		~Stage() 
		{
			Release();
		}

		void Init()
		{
			for (int i = 0;i <= PlAYER_RECOVERY_OBJECT;i++)
			{
				m_rGameBaseMaker.CreateTex(m_blockTextureKey[i], m_blockTextureName[i]);
			}
			LoadStageDate("csv/Stage1.csv");
			CreateBlock();
		}

		void Update();

		void Render();

		void Release() 
		{
			for (auto& block : m_blockCellPos)
			{
				delete block;
				block = nullptr;
			}

			m_blockCellPos.clear();
			m_blockCellPos.shrink_to_fit();

			m_rGameBaseMaker.ReleaseAllTex();
		}

		void LoadStageDate(const char* fileName);
		void CreateBlock();

		std::vector<BlockCell*> GetblockCellPos()
		{
			return m_blockCellPos;
		}
	private:
		const float& m_CellSize;
		const D3DXVECTOR2& m_distanceToOrigin;
		const TCHAR* m_blockTextureKey[PlAYER_RECOVERY_OBJECT + 1]=
		{
			_T("FloorBlock"),
			_T("WhiteBlock"),
			_T("BlackBlock"),
			_T("HideBlock"),
			_T("PlayerRecoveryObject"),
		};

		const TCHAR* m_blockTextureName[PlAYER_RECOVERY_OBJECT + 1]=
		{
			_T("2DTexture/Game/Floor.png"),
			_T("2DTexture/Game/WhiteBlock.png"),
			_T("2DTexture/Game/BlackBlock.png"),
			_T("2DTexture/Game/HideBlock.png"),
			_T("2DTexture/Game/PlayerRecoveryObject.png"),
		};

		int m_row;
		int m_colunm;

		std::vector<BlockCell*> m_blockCellPos;
		std::vector< std::vector<int> > m_stageSize;

	};

}
#endif // STAGE_H
