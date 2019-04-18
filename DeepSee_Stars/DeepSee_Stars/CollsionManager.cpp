#include "CollsionManager.h"

CollsionManager* CollsionManager::m_pInstance = NULL;

CollsionManager::CollsionManager()
{
	
}

CollsionManager::~CollsionManager()
{

}

CollsionManager* CollsionManager::GetInstance()
{
	if (m_pInstance == NULL)
	{
		m_pInstance = new CollsionManager();
	}
	return m_pInstance;
}

void CollsionManager::DeleteInstence()
{
	delete m_pInstance;
	m_pInstance = NULL;
}

void CollsionManager::StageInit(const int colunmSize, const int rowSize, const std::vector< std::vector<int>> ArrayData)
{
	m_StageData.resize(colunmSize);
	for (int j = 0; j < colunmSize; j++)
	{
		m_StageData[j].resize(rowSize);
	}
	m_StageData = ArrayData;
}


bool CollsionManager::Update(int direction)
{
	int playerPositionRowMove = *m_PlayerPos.Row;
	int playerPositionColunmMove = *m_PlayerPos.Colunm;
	int valueAddRow = 0;
	int valueAddColunm = 0;
	switch (direction)
	{
	case LEFT:
		valueAddRow = -1;
		break;
	case RIGHT:
		valueAddRow = 1;
		break;
	case UP:
		valueAddColunm = -1;
		break;
	case DOWN:
		valueAddColunm = 1;
		break;
	}
	playerPositionRowMove += valueAddRow;
	playerPositionColunmMove += valueAddColunm;
	if (m_StageData[playerPositionColunmMove][playerPositionRowMove] > 100)
	{
		return false;
	}
	if (m_StageData[playerPositionColunmMove][playerPositionRowMove] != 0)
	{
		return true;
	}
	return false;
}
