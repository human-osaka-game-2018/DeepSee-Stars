#include "Object.h"
#include "CustomVertex.h"
#include <vector>
#include"StageScroll.h"

#ifndef STAGE_H
#define STAGE_H

enum Type
{
	NONE,
	ROCK,
};

class Stage : public Object
{
public:
	Stage();
	~Stage();
	void Init();
	void Update();
	void Render();
	void LoadStageDate(const char* fileName);

	CustomVertex m_Position[4];

private:
	DirectX * m_pDirectX;
	CollsionManager * m_pCollsionManager;
	StageScroll* m_pStageScroll;
	int m_Row;
	int m_Colunm;
	float m_StageScrollX;
	float m_StageScrollY;
	std::vector< std::vector<int> > m_StageData;
	const float m_BlockSize = 64.f;
};
#endif // STAGE_H
