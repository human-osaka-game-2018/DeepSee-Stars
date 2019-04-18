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

}

void Stage::Init()
{
	m_pDirectX->InitVertex(m_Position);
	LoadStageDate("csv/Stage1.csv");
	m_StageScrollY = 0.f;
	m_StageScrollX = 0.f;
}

void Stage::Update()
{
	
}

void Stage::Render()
{
	for (int culunm = 0; culunm < m_Colunm;culunm++)
	{
		for (int row = 0;row < m_Row;row++)
		{
			if (m_StageData[culunm][row] == 0)	continue;

			float top = m_BlockSize * culunm + m_StageScrollY;
			float left = m_BlockSize * row + m_StageScrollX;

			for (int j = 0;j < 4;j++)
			{
				if (j == 0)
				{
					m_Position[j].x = left;
					m_Position[j].y = top;
				}
				if (j == 1)
				{
					m_Position[j].x = (left + m_BlockSize);
					m_Position[j].y = top;
				}
				if (j == 2)
				{
					m_Position[j].x = (left + m_BlockSize);
					m_Position[j].y = (top + m_BlockSize);
				}
				if (j == 3)
				{
					m_Position[j].x = left;
					m_Position[j].y = (top + m_BlockSize);
				}
			}

			int typeSelected = m_StageData[culunm][row];
			switch (typeSelected)
			{
			case ROCK:
				m_pDirectX->DrawTexture("GAME_BLOCK_TEX", m_Position);
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
		}
		else
		{
			for (int row = 0;row < m_Row;row++)
			{
				staggStream >> m_StageData[colunm][row];
			}
			colunm++;
		}
	}
	m_pCollsionManager->StageInit(m_Colunm, m_Row, m_StageData);
	m_pStageScroll->StageInit(m_Colunm, m_Row, m_StageData);
}
