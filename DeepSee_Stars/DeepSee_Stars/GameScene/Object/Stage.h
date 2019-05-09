#ifndef STAGE_H
#define STAGE_H

#include <vector>
#include "CustomVertex.h"
#include "BlockCell.h"
#include "Object.h"


class Stage{
public:
	Stage();
	~Stage();
	void Init();
	void Update();
	void Render(D3DXVECTOR2 drawArea);
	void LoadStageDate(const char* fileName);
	void BlockCreate();


	std::vector<BlockCell*> m_BlockCellPos;
private:
	DirectX * m_pDirectX;
	int m_Row;
	int m_Colunm;
	CustomVertex m_BlockPos[4];

	std::vector< std::vector<int> > m_StageData;

};
#endif // STAGE_H
