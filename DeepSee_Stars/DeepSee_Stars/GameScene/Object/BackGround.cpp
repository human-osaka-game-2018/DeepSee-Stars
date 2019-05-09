#include "BackGround.h"

BackGround::BackGround()
{
	m_pDirectX = DirectX::GetInstance();
	Init();
}

BackGround::~BackGround()
{

}

void BackGround::Init()
{
	m_pDirectX->InitVertex(m_BG);
	m_pDirectX->InitRectangleCustomVertex(m_BG, DISPLAY_WIDTH/2, DISPLAY_HEIGHT/2, DISPLAY_WIDTH, DISPLAY_HEIGHT);
}

void BackGround::Update()
{

}

void BackGround::Render()
{
	//m_pDirectX->DrawTexture("GAME_BG_TEX", m_BG);
}
