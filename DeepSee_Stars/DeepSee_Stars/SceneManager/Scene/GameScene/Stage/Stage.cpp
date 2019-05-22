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

	void Stage::CreateBlock(int colunm,int row)
	{
		int typeSelected = m_stageSize[colunm][row];
		float blockCenterPosY = (colunm * m_CellSize) + m_CellSize / 2;
		float blockCenterPosX = (row * m_CellSize) + m_CellSize / 2;
		D3DXVECTOR2 buf = { blockCenterPosX,blockCenterPosY };
		switch (typeSelected)
		{
		case FLOOR:
			m_blockCellPos.push_back(new BlockCell(m_distanceToOrigin, buf, FLOOR, m_CellSize));
			break;
		case WHITE_BLOCK:
			m_blockCellPos.push_back(new BlockCell(m_distanceToOrigin, buf, WHITE_BLOCK, m_CellSize));
			break;
		case BLACK_BLOCK:
			m_blockCellPos.push_back(new BlockCell(m_distanceToOrigin, buf, BLACK_BLOCK, m_CellSize));
			break;
		case HIDE_BLOCK:
			m_blockCellPos.push_back(new BlockCell(m_distanceToOrigin, buf, HIDE_BLOCK, m_CellSize));
			break;
		case PLAYER_RECOVERY_OBJECT:
			m_blockCellPos.push_back(new BlockCell(m_distanceToOrigin, buf, PLAYER_RECOVERY_OBJECT, m_CellSize));
			break;
		}
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
