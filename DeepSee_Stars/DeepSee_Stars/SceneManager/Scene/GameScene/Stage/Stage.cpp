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
			int a = m_differencetoStartingPoint.x;
			blockCellData->Render();
		}
	}

	void Stage::BlockCreate()
	{
		for (int culunm = 0; culunm < m_colunm;culunm++)
		{
			for (int row = 0;row < m_row;row++)
			{
				int typeSelected = m_stageData[culunm][row];
				float blockCenterPosY = (culunm * BLOCKSIZE) + BLOCKSIZE / 2;
				float blockCenterPosX = (row * BLOCKSIZE) + BLOCKSIZE / 2;
				D3DXVECTOR2 buf = { blockCenterPosX,blockCenterPosY };
				switch (typeSelected)
				{
				case FLOOR:
					m_blockCellPos.push_back(new BlockCell(m_differencetoStartingPoint,buf, FLOOR));
					break;
				case WHITE_BLOCK:
					m_blockCellPos.push_back(new BlockCell(m_differencetoStartingPoint,buf, WHITE_BLOCK));
					break;
				case BLACK_BLOCK:
					m_blockCellPos.push_back(new BlockCell(m_differencetoStartingPoint,buf, BLACK_BLOCK));
					break;
				case HIDE_BLOCK:
					m_blockCellPos.push_back(new BlockCell(m_differencetoStartingPoint,buf, HIDE_BLOCK));
					break;
				case PlAYER_RECOVERY_OBJECT:
					m_blockCellPos.push_back(new BlockCell(m_differencetoStartingPoint,buf, PlAYER_RECOVERY_OBJECT));
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
				m_stageData.resize(m_colunm);
				for (int j = 0; j < m_colunm; j++)
				{
					m_stageData[j].resize(m_row);
				}
				flag = false;
				continue;
			}

			for (int row = 0;row < m_row;++row)
			{
				staggStream >> m_stageData[colunm][row];
			}
			colunm++;
		}
	}
}
