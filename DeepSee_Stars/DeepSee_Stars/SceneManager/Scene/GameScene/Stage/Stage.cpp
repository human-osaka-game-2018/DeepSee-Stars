#include"Stage.h"
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>

using std::ifstream;
using std::string;
using std::stringstream;

namespace deepseestars
{

	void Stage::Update()
	{

	}

	void Stage::Render()
	{
		for (auto& blockCellData : m_blockCellPos)
		{
			blockCellData->Render();
		}
	}

	TYPE Stage::ConvertIntoType(const D3DXVECTOR2& pos)
	{
		int row = 0, column = 0;
		
		row =    static_cast<int>(pos.x / m_CellSize);
		column = static_cast<int>(pos.y / m_CellSize);

		return static_cast<TYPE>(m_stageSize[column][row]);
	}

	void Stage::CreateBlock(int colunm,int row)
	{
		int typeSelected = m_stageSize[colunm][row];
		float blockCenterPosY = (colunm * m_CellSize) + m_CellSize / 2;
		float blockCenterPosX = (row * m_CellSize) + m_CellSize / 2;
		D3DXVECTOR2 buf = { blockCenterPosX,blockCenterPosY };
		TYPE BlockType;
		switch (typeSelected)
		{
		case PLAYERINITPOS:
			m_playerStartPosRow = row;
			m_playerStartPosColunm = colunm;
			BlockType = FLOOR;
			break;
		case FLOOR:
			BlockType = FLOOR;
			break;
		case WHITE_BLOCK:
			BlockType = WHITE_BLOCK;
			break;
		case BLACK_BLOCK:
			BlockType = BLACK_BLOCK;
			break;
		case HIDE_BLOCK:
			BlockType = HIDE_BLOCK;
			break;
		case PLAYER_RECOVERY_OBJECT:
			BlockType = PLAYER_RECOVERY_OBJECT;
			break;
		case SEAWEED:
			BlockType = SEAWEED;
			break;
		case MISSION_ITEM:
			BlockType = MISSION_ITEM;
			break;
		case GAMECLEARZONE:
			BlockType = GAMECLEARZONE;
			break;
		case MISSIONSTART_GET4ITEMS:
			BlockType = MISSIONSTART_GET4ITEMS;
			break;
		default:
			return;
			break;
		}
		m_blockCellPos.push_back(new BlockCell(m_distanceToOrigin, buf, BlockType, m_CellSize));
	}


	void Stage::LoadStageData(const char* fileName)
	{
		// ファイル読み込み関数実行
		ifstream ifs(fileName);
		string str;

		int colunm = 0;
		bool isFirstLine = true;

		while (getline(ifs, str))
		{
			replace(str.begin(), str.end(), ',', ' ');
			stringstream staggStream(str);
			if (isFirstLine == true)
			{
				staggStream >> m_row;
				staggStream >> m_colunm;
				m_stageSize.resize(m_colunm);
				for (int j = 0; j < m_colunm; j++)
				{
					m_stageSize[j].resize(m_row);
				}

				isFirstLine = false;
				continue;
			}

			for (int row = 0;row < m_row;++row)
			{
				staggStream >> m_stageSize[colunm][row];
				CreateBlock(colunm, row);
			}
			colunm++;
		}
	}
}
