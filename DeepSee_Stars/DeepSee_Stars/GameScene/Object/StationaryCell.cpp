#include "StationaryCell.h"


StationaryCell::StationaryCell(int colunm, int row,int type) : m_Colunm(colunm),m_Row(row), m_CellType(type)
{
	m_pDirectX = DirectX::GetInstance();
	m_pDirectX->InitVertex(m_PositionOnStage);
	float centerPosY = (m_Colunm * m_CELLSize) + (m_CELLSize / 2);
	float centerPosX = (m_Row * m_CELLSize) + (m_CELLSize / 2);
	m_pDirectX->InitSquareCustomVertex(m_PositionOnStage, centerPosX, centerPosY, m_CELLSize);
}

StationaryCell::~StationaryCell()
{

}

void StationaryCell::Update()
{

}

void StationaryCell::Render(float stageScrollX, float stageScrollY)
{	
	float top = m_CELLSize * m_Colunm + stageScrollY;
	float left = m_CELLSize * m_Row + stageScrollX;

	for (int i = 0;i < 4;++i)
	{
		m_PositionOnStage[i].x = ((i == 0 || i == 3) ? left : left + m_CELLSize);
		m_PositionOnStage[i].y = ((i == 0 || i == 1) ? top : top + m_CELLSize);
	}

	switch (m_CellType)
	{
	case ROCK:
		m_pDirectX->DrawTexture("GAME_BLOCK_TEX", m_PositionOnStage);
		break;
	}
}
