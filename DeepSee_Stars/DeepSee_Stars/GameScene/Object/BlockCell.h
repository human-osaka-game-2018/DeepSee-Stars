#ifndef BLOCKCELL_H
#define BLOCKCELL_H

#include "BaseCell.h"
#include <vector>

enum TYPE
{
	NONE,
	ROCK,
	HIDEBLOCK,
};


const float BLOCKSIZE = 64.f;

class BlockCell : public BaseCell
{
public:
	BlockCell(D3DXVECTOR2 blockPos, TYPE blockType);
	~BlockCell();
	void Update();
	void Render( D3DXVECTOR2 drawArea);

	D3DXVECTOR2 m_BlockCenterPos;
	TYPE m_BlockType;
private:
	DirectX * m_pDirectX;

	CustomVertex m_PositionOnStage[4];

};

#endif // BLOCKCELL_H