#include "BaseCELL.h"
#include "DirectX.h"
#include "CustomVertex.h"
#include <vector>

#ifndef MOVECELL_H
#define MOVECELL_H

class MoveCELL : public BaseCELL
{
public:
	MoveCELL(int colunm, int row, int type);
	~MoveCELL();
	void Update();
	void Render(float stageScrollX, float stageScrollY);


private:
	DirectX * m_pDirectX;
	int m_Colunm;
	int m_Row;
	int m_CELLType;
	CustomVertex m_PositionOnStage[4];
	const float m_CELLSize = 64.f;
};

#endif // MOVECELL_H