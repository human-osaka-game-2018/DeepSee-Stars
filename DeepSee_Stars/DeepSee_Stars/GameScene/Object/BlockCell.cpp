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
	if (-BLOCKSIZE <= centerPosbBuf.x && centerPosbBuf.x <= DISPLAY_WIDTH + 64.f && -64.f <= centerPosbBuf.y && centerPosbBuf.y <= DISPLAY_HEIGHT + BLOCKSIZE)
	{
		m_pDirectX->DrawTexture("GAME_BLOCK_TEX", vertexBuf);
	}
}
