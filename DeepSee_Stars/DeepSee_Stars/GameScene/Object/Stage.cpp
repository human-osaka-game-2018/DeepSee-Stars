#include"Stage.h"
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>

using std::ifstream;
using std::string;
using std::stringstream;

Stage::Stage()
{
	m_pDirectX = DirectX::GetInstance();
	Init();
}

Stage::~Stage()
{

}

void Stage::Init()
{
	LoadStageDate("csv/Stage1.csv");
	BlockCreate();
	m_pDirectX->InitVertex(m_BlockPos);
}

void Stage::Update()
{

}

void Stage::Render(D3DXVECTOR2 drawArea)
{
	for (auto& blockCellData : m_BlockCellPos)
	{
		blockCellData->Render(drawArea);
	}
}

void Stage::BlockCreate()
{
	for (int culunm = 0; culunm < m_Colunm;culunm++)
	{
		for (int row = 0;row < m_Row;row++)
		{
			if (m_StageData[culunm][row] == 0)	continue;

			int typeSelected = m_StageData[culunm][row];
			float blockCenterPosY = (culunm * BLOCKSIZE) + BLOCKSIZE / 2;
			float blockCenterPosX = (row * BLOCKSIZE) + BLOCKSIZE / 2;
			D3DXVECTOR2 buf = { blockCenterPosX,blockCenterPosY };
			m_StagiesPos.push_back(buf);
			switch (typeSelected)
			{
			case ROCK:
				m_BlockCellPos.push_back(new BlockCell(buf, ROCK));
				break;
			case HIDEBLOCK:
				m_BlockCellPos.push_back(new BlockCell(buf, HIDEBLOCK));
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
			staggStream >> m_Row;
			staggStream >> m_Colunm;
			m_StageData.resize(m_Colunm);
			for (int j = 0; j < m_Colunm; j++)
			{
				m_StageData[j].resize(m_Row);
			}
			flag = false;
			continue;
		}

		for (int row = 0;row < m_Row;++row)
		{
			staggStream >> m_StageData[colunm][row];
		}
		colunm++;
	}
}
