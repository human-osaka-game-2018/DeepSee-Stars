#include "BlockCell.h"


BlockCell::BlockCell(D3DXVECTOR2 blockPos, TYPE blockType)
{
	m_pDirectX = DirectX::GetInstance();
	m_BlockCenterPos = blockPos;
	m_BlockType = blockType;
	m_pDirectX->InitVertex(m_PositionOnStage);
	m_pDirectX->InitSquareCustomVertex(m_PositionOnStage, blockPos.x, blockPos.y, BLOCKSIZE);
}

BlockCell::~BlockCell()
{

}

void BlockCell::Update()
{

}

void BlockCell::Render( D3DXVECTOR2 drawArea)
{
	D3DXVECTOR2 centerPosbBuf = m_BlockCenterPos + drawArea;
	CustomVertex vertexBuf[4];
	m_pDirectX->InitSquareCustomVertex(vertexBuf, centerPosbBuf.x, centerPosbBuf.y, BLOCKSIZE);
	if (-BLOCKSIZE <= centerPosbBuf.x && centerPosbBuf.x <= DISPLAY_WIDTH + 100.f && -100.f <= centerPosbBuf.y && centerPosbBuf.y <= DISPLAY_HEIGHT + BLOCKSIZE)
	{
		switch (m_BlockType)
		{
		case FLOOR:
			m_pDirectX->DrawTexture("GAME_FLOOR_TEX", vertexBuf);
			break;
		case WHITEBLOCK:
			m_pDirectX->DrawTexture("GAME_WHITEBLOCK_TEX", vertexBuf);
			break;
		case BLACKBLOCK:
			m_pDirectX->DrawTexture("GAME_BLACKBLOCK_TEX", vertexBuf);
			break;
		case HIDEBLOCK:
			m_pDirectX->DrawTexture("GAME_HIDEBLOCK_TEX", vertexBuf);
			break;
		}
	}
}
