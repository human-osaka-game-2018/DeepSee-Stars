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
	m_pCollsionManager = CollsionManager::GetInstance();
	m_pStageScroll = StageScroll::GetInstance();
	Init();
	m_pStageScroll->SetStageScroll(&m_StageScrollY,&m_StageScrollX);
}

Stage::~Stage()
{
	for (auto& stationaryCell : m_StationaryCellData)
	{
		delete stationaryCell;
	}
	for (auto& mobileCELL : m_MobileCellData)
	{
		delete mobileCELL;
	}
}

void Stage::Init()
{
	LoadStageDate("csv/Stage1.csv");
	BlockCreate();
	m_StageScrollY = 0.f;
	m_StageScrollX = 0.f;
}

void Stage::Update()
{
	
}

void Stage::Render()
{
	for (auto& stationaryCell : m_StationaryCellData)
	{
		stationaryCell->Render(m_StageScrollX, m_StageScrollY);
	}
	for (auto& mobileCELL : m_MobileCellData)
	{
		mobileCELL->Render(m_StageScrollX, m_StageScrollY);
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
			switch (typeSelected)
			{
			case ROCK:
				m_StationaryCellData.push_back(new StationaryCell(culunm, row, ROCK));
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

	static int colunm = 0;
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
	m_pCollsionManager->StageInit(m_Colunm, m_Row, m_StageData);
	m_pStageScroll->StageInit(m_Colunm, m_Row, m_StageData);
}
