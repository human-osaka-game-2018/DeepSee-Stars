#include "Object.h"
#include <vector>
#include "StageScroll.h"
#include "MobileCell.h"
#include "StationaryCell.h"

#ifndef STAGE_H
#define STAGE_H


class Stage : public Object
{
public:
	Stage();
	~Stage();
	void Init();
	void Update();
	void Render();
	void LoadStageDate(const char* fileName);
	void BlockCreate();

private:
	DirectX * m_pDirectX;
	CollsionManager * m_pCollsionManager;
	StageScroll* m_pStageScroll;
	int m_Row;
	int m_Colunm;
	float m_StageScrollX;
	float m_StageScrollY;
	std::vector<MobileCell*> m_MobileCellData;
	std::vector<StationaryCell*> m_StationaryCellData;
	std::vector< std::vector<int> > m_StageData;

};
#endif // STAGE_H
