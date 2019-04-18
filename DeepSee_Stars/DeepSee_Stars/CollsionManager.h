#ifndef COLLSIONMANAGER_H
#define COLLSIONMANAGER_H

#include <vector>
#include"d3dx9math.h"
#include"DirectionID.h"

class CollsionManager
{
public:
	bool Update(int direction);

	static CollsionManager* GetInstance();
	void DeleteInstence();

	struct Position
	{
		int* Colunm;
		int* Row;
	};

	void StageInit(const int colunmSize, const int rowSize, const std::vector< std::vector<int>> ArrayData);
	void SetPlayerPos(int *colunm, int *row)
	{
		m_PlayerPos.Colunm = colunm;
		m_PlayerPos.Row = row;
	}

private:
	CollsionManager();
	~CollsionManager();

	std::vector< std::vector<int>> m_StageData;
	Position m_PlayerPos;

	static CollsionManager* m_pInstance;
};
#endif // COLLSIONMANAGER_H
