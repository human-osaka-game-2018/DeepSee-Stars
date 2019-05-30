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
			for (int i = 0;i <= 8;i++)
			{
				m_rGameBaseMaker.CreateTex(m_blockTextureKey[i], m_blockTextureName[i]);
			}
			LoadStageData("csv/Stage1.csv");
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

		void LoadStageData(const char* fileName);
		void CreateBlock(int colunm, int row);

		std::vector<BlockCell*> GetblockCellPos()
		{
			return m_blockCellPos;
		}

		int GetPlayerStartPosRow()
		{
			return m_playerStartPosRow;
		}
		int GetPlayerStartPosColunm()
		{
			return m_playerStartPosColunm;
		}
	private:
		const float& m_CellSize;
		const D3DXVECTOR2& m_distanceToOrigin;

		const TCHAR* m_blockTextureKey[8]=
		{
			_T("FloorBlock"),
			_T("WhiteBlock"),
			_T("BlackBlock"),
			_T("HideBlock"),
			_T("PlayerRecoveryObject"),
			_T("SeaWeed"),
			_T("MissionItem"),
			_T("MissionStartLine"),
		};

		const TCHAR* m_blockTextureName[8]=
		{
			_T("2DTexture/Game/Floor.png"),
			_T("2DTexture/Game/WhiteBlock.png"),
			_T("2DTexture/Game/BlackBlock.png"),
			_T("2DTexture/Game/HideBlock.png"),
			_T("2DTexture/Game/PlayerRecoveryObject.png"),
			_T("2DTexture/Game/SeaWeed.png"),
			_T("2DTexture/Game/MissionItem.png"),
			_T("2DTexture/Game/MissionStart.png"),
		};

		int m_row;
		int m_colunm;

		int m_playerStartPosRow;
		int m_playerStartPosColunm;

		std::vector<BlockCell*> m_blockCellPos;
		std::vector< std::vector<int> > m_stageSize;

	};

}
#endif // STAGE_H
