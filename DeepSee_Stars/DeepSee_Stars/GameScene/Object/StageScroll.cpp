#include"StageScroll.h"

StageScroll* StageScroll::m_pInstance = NULL;

StageScroll::StageScroll()
{
	m_pDirectX = DirectX::GetInstance();
}

StageScroll::~StageScroll()
{

}

StageScroll* StageScroll::GetInstance()
{
	if (m_pInstance == NULL)
	{
		m_pInstance = new StageScroll();
	}
	return m_pInstance;
}

void StageScroll::DeleteInstence()
{
	delete m_pInstance;
	m_pInstance = NULL;
}

void StageScroll::StageInit(const int colunmSize, const int rowSize, const std::vector< std::vector<int>> ArrayData)
{
	m_StageData.resize(colunmSize);
	for (int j = 0; j < colunmSize; j++)
	{
		m_StageData[j].resize(rowSize);
	}
	m_StageData = ArrayData;
}

void StageScroll::Operation(const int *direction, CustomVertex player[4], const int *m_playerDirectionInputSignalRejectionMaxTime)
{
	if (m_StageData[*m_PlayerPos.Colunm][*m_PlayerPos.Row] < 100) return;

	m_CanPlayerDirectionInput = false;

	m_PlayerDirectionInputSignalRejectionTime++;
	if (m_PlayerDirectionInputSignalRejectionTime == *m_playerDirectionInputSignalRejectionMaxTime)
	{
		m_PlayerDirectionInputSignalRejectionTime = 0;
		m_CanPlayerDirectionInput = true;
	}
	ScrollMove(*direction, player, m_playerDirectionInputSignalRejectionMaxTime);
}

void  StageScroll::ScrollMove(const int direction, CustomVertex player[4], const int *m_playerDirectionInputSignalRejectionMaxTime)
{
	int divideMoveSpeed = *m_playerDirectionInputSignalRejectionMaxTime;
	float valuetoScroll = (m_StageData[*m_PlayerPos.Colunm][*m_PlayerPos.Row] - 100) * m_SquaresSize;
	switch (direction)
	{
	case LEFT:
		*m_StageScrollX += (valuetoScroll + m_SquaresSize * 2) / divideMoveSpeed;
		for (int i = 0;i < 4;i++)
		{
			player[i].x += (valuetoScroll + m_SquaresSize) / divideMoveSpeed;
		}
		m_PreviousScroll = LEFT;
		break;
	case RIGHT:
		*m_StageScrollX -= (valuetoScroll + m_SquaresSize * 2) / divideMoveSpeed;
		for (int i = 0;i < 4;i++)
		{
			player[i].x -= (valuetoScroll + m_SquaresSize) / divideMoveSpeed;
		}
		m_PreviousScroll = RIGHT;
		break;
	case UP:
		*m_StageScrollY += (valuetoScroll + m_SquaresSize * 2) / divideMoveSpeed;
		for (int i = 0;i < 4;i++)
		{
			player[i].y += (valuetoScroll + m_SquaresSize) / divideMoveSpeed;
		}
		m_PreviousScroll = UP;
		break;
	case DOWN:
		*m_StageScrollY -= (valuetoScroll + m_SquaresSize * 2) / divideMoveSpeed;
		for (int i = 0;i < 4;i++)
		{
			player[i].y -= (valuetoScroll + m_SquaresSize) / divideMoveSpeed;
		}
		m_PreviousScroll = DOWN;
		break;
	}
}
