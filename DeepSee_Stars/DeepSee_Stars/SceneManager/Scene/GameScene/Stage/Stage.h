#ifndef STAGE_H
#define STAGE_H

#include <vector>
#include "../Cell/Block/BlockCell.h"
#include "../Cell/Block/MissionCell.h"
#include "GameObject.h"

namespace deepseestars
{

	class Stage : public GameObject
	{
	public:
		Stage(const D3DXVECTOR2& distanceToOrigin, const float& squaresSize) :
			GameObject(), m_distanceToOrigin(distanceToOrigin), m_CellSize(squaresSize)
		{
			Init();
		}

		~Stage()
		{
			Release();
		}

		void Init()
		{
			for (auto& name : m_blockTextureName)
			{
				int index = static_cast<int>(&name - &m_blockTextureName[0]);

				m_rGameBaseMaker.CreateTex(m_blockTextureKey[index], name);
			}

			LoadStageData("csv/Stage1.csv");
			CreateMissionArea("csv/Mission_Stage1.csv");
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
			for (auto& block : m_missionBlockPos)
			{
				delete block;
				block = nullptr;
			}

			m_blockCellPos.clear();
			m_blockCellPos.shrink_to_fit();
			m_missionBlockPos.clear();
			m_missionBlockPos.shrink_to_fit();
		}

		/// <summary>
		/// 座標を入れるとその位置のステージブロックのタイプに変換する
		/// </summary>
		/// <param name="pos">座標</param>
		/// <returns>ステージブロックのタイプ</returns>
		TYPE ConvertIntoType(const D3DXVECTOR2& pos);

		void LoadStageData(const char* fileName);
		void CreateBlock(int colunm, int row);
		void MissionCreateBlock(int colunm, int row, const char typeSelected);
		void CreateMissionArea(const char* fileName);

		std::vector<BlockCell*> GetblockCellPos()
		{
			return m_blockCellPos;
		}

		std::vector<MissionCell*> GetmissionBlockPos()
		{
			return m_missionBlockPos;
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

		const TCHAR* m_blockTextureKey[8] =
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

		const TCHAR* m_blockTextureName[8] =
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
		std::vector<MissionCell*> m_missionBlockPos;
		std::vector< std::vector<int> > m_stageSize;
		std::vector< std::vector<char> > m_missionStageSize;

	};

}
#endif // STAGE_H
