#include "AutotomyAction.h"

AutotomyAction::AutotomyAction(D3DXVECTOR2 playerCenterPos)
{
	m_pDirectX = m_pDirectX->GetInstance();
	m_AutotomyCenterPos = playerCenterPos;
}

AutotomyAction::~AutotomyAction()
{

}

void AutotomyAction::Operation(D3DXVECTOR2 drawArea)
{
	D3DXVECTOR2 centerPosbBuf = m_AutotomyCenterPos + drawArea;
	m_pDirectX->InitSquareCustomVertex(m_Autotomy, centerPosbBuf.x, centerPosbBuf.y, m_SquaresSize);
}

void AutotomyAction::Render()
{
	m_pDirectX->DrawTexture("GAME_AUTOTOMY_TEX", m_Autotomy);
}
