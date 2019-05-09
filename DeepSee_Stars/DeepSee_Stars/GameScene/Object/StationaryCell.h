#include "BaseCell.h"
#include "DirectX.h"
#include "CustomVertex.h"
#include <vector>


#ifndef STATIONARYCELL_H
#define STATIONARYCELL_H

class StationaryCell : public BaseCell
{
public:
	StationaryCell(int colunm, int row, int type);
	~StationaryCell();
	void Update();
	void Render(float stageScrollX, float stageScrollY);

private:
	DirectX* m_pDirectX;
	int m_Colunm;
	int m_Row;
	int m_CellType;
	CustomVertex m_PositionOnStage[4];
	const float m_CELLSize = 64.f;

};

#endif // STATIONARYCELL_H