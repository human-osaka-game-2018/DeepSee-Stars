#ifndef STAGESCROLL_H
#define STAGESCROLL_H

#include <vector>
#include "CustomVertex.h"
#include "DirectX.h"
#include "DirectionID.h"


class StageScroll
{
public:
	void Operation(const int *direction, CustomVertex player[4], const int *m_playerDirectionInputSignalRejectionMaxTime);
	void ScrollMove(const int direction, CustomVertex player[4], const int *m_playerDirectionInputSignalRejectionMaxTime);

	static StageScroll* GetInstance();
	void DeleteInstence();

	struct Position
	{
		int* Colunm;
		int* Row;
	};

	void StageInit(const int colunmSize, const int rowSize, const std::vector< std::vector<int>> ArrayData);

	void SetStageScroll(float *stageScrollY, float *stageScrollX)
	{
		m_StageScrollY = stageScrollY;
		m_StageScrollX = stageScrollX;
	}
	void SetPlayerPos(int *colunm, int *row)
	{
		m_PlayerPos.Colunm = colunm;
		m_PlayerPos.Row = row;
	}
	void SetPreviousScroll(const int direction)
	{
		m_PreviousScroll = direction;
	}

	bool GetCanDirectionInput()
	{
		return m_CanPlayerDirectionInput;
	}
	int GetPreviousScroll()
	{
		return m_PreviousScroll;
	}

private:
	StageScroll();
	~StageScroll();

	DirectX* m_pDirectX;

	std::vector< std::vector<int>> m_StageData;
	float* m_StageScrollY;
	float* m_StageScrollX;
	Position m_PlayerPos;
	bool m_CanPlayerDirectionInput = true;
	int m_PlayerDirectionInputSignalRejectionTime = 0;
	int m_PreviousScroll = STAYING;
	const float m_SquaresSize = 64.f;



	static StageScroll* m_pInstance;
};
#endif // STAGESCROLL_H
