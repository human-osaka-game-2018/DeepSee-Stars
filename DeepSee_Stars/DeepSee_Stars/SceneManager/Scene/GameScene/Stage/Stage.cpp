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

	void Stage::BlockCreate()
	{
		for (int culunm = 0; culunm < m_colunm;culunm++)
		{
			for (int row = 0;row < m_row;row++)
			{
				int typeSelected = m_stageSize[culunm][row];
				float blockCenterPosY = (culunm * m_squaresSize) + m_squaresSize / 2;
				float blockCenterPosX = (row * m_squaresSize) + m_squaresSize / 2;
				D3DXVECTOR2 buf = { blockCenterPosX,blockCenterPosY };
				switch (typeSelected)
				{
				case FLOOR:
					m_blockCellPos.push_back(new BlockCell(m_distanceToOrigin,buf, FLOOR, m_squaresSize));
					break;
				case WHITE_BLOCK:
					m_blockCellPos.push_back(new BlockCell(m_distanceToOrigin,buf, WHITE_BLOCK, m_squaresSize));
					break;
				case BLACK_BLOCK:
					m_blockCellPos.push_back(new BlockCell(m_distanceToOrigin,buf, BLACK_BLOCK, m_squaresSize));
					break;
				case HIDE_BLOCK:
					m_blockCellPos.push_back(new BlockCell(m_distanceToOrigin,buf, HIDE_BLOCK, m_squaresSize));
					break;
				case PlAYER_RECOVERY_OBJECT:
					m_blockCellPos.push_back(new BlockCell(m_distanceToOrigin,buf, PlAYER_RECOVERY_OBJECT, m_squaresSize));
					break;
				}
			}
		}
	}

	void Stage::LoadStageDate(const char* fileName)
	{
		// ファイル読み込み関数実行
		ifstream ifs(fileName);
		string str;

		int colunm = 0;
		while (getline(ifs, str))
		{
			replace(str.begin(), str.end(), ',', ' ');
			stringstream staggStream(str);
			static bool flag = true;
			if (flag == true)
			{
				staggStream >> m_row;
				staggStream >> m_colunm;
				m_stageSize.resize(m_colunm);
				for (int j = 0; j < m_colunm; j++)
				{
					m_stageSize[j].resize(m_row);
				}
				flag = false;
				continue;
			}

			for (int row = 0;row < m_row;++row)
			{
				staggStream >> m_stageSize[colunm][row];
			}
			colunm++;
		}
	}
}
