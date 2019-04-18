#include "Object.h"
#include <vector>
#include "StageScroll.h"
#include "MoveCELL.h"
#include "StationaryCELL.h"

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

	std::vector<MoveCELL*> m_MoveCELLData;
	std::vector<StationaryCELL*> m_StationaryCELLData;

private:
	DirectX * m_pDirectX;
	CollsionManager * m_pCollsionManager;
	StageScroll* m_pStageScroll;
	int m_Row;
	int m_Colunm;
	float m_StageScrollX;
	float m_StageScrollY;
	std::vector< std::vector<int> > m_StageData;
};
#endif // STAGE_H
