#include "BaseCELL.h"
#include "DirectX.h"
#include "CustomVertex.h"
#include <vector>


#ifndef STATIONARYCELL_H
#define STATIONARYCELL_H


class StationaryCELL : public BaseCELL
{
public:
	StationaryCELL(int colunm, int row, int type);
	~StationaryCELL();
	void Update();
	void Render(float stageScrollX, float stageScrollY);


private:
	DirectX* m_pDirectX;
	int m_Colunm;
	int m_Row;
	int m_CELLType;
	CustomVertex m_PositionOnStage[4];
	const float m_CELLSize = 64.f;
};

#endif // STATIONARYCELL_H