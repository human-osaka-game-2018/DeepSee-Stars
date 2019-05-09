#include "BaseCell.h"
#include "DirectX.h"
#include "CustomVertex.h"
#include <vector>

#ifndef MOBILECELL_H
#define MOBILECELL_H

class MobileCell : public BaseCell
{
public:
	MobileCell(int colunm, int row, int type);
	~MobileCell();
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

#endif // MOBILECELL_H