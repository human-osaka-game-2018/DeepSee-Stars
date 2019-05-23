#include "SafetyLevel.h"

namespace deepseestars
{

	void SafetyLevel::Update()
	{
		if (m_isPlayerInTheSeaWeed)
		{
			m_safetyLevel = 80;
		}
		else
		{
			NaturalRise();
			OverflowGuard();
		}
	}

	void SafetyLevel::NaturalRise()
	{
		static int playerStopTime = 0;
		if (m_playerDirection != STAYING)
		{
			playerStopTime = 0;
		}
		if (m_playerDirection != STAYING) return;
		if (m_safetyLevel > 40 && !m_isPlayerHideState) return;
		playerStopTime++;
		if (playerStopTime != 60)return;
		playerStopTime = 0;
		m_safetyLevel += 3;
	}

	void SafetyLevel::OverflowGuard()
	{
		if (m_safetyLevel > 40 && !m_isPlayerHideState)
		{
			m_safetyLevel = 40;
		}
		if (m_safetyLevel > 80)
		{
			m_safetyLevel = 80;
		}
		if (m_safetyLevel <= 0)
		{
			m_safetyLevel = 0;
		}
	}
	
	void SafetyLevel::Render()
	{
		D3DXVECTOR2 pos = { 210.f ,70.f };
		D3DXVECTOR2 scale = { 70.f , 70.f };

		m_vertices.SetPos(pos);
		m_vertices.SetScale(scale);
		m_rGameBaseMaker.Render(m_vertices, m_rGameBaseMaker.GetTex(m_SafetyLevelUITextureKey[10]));

		int theTenDigit = m_safetyLevel / 10;
		int theOneDigit = m_safetyLevel % 10;

		pos = { 180.f ,70.f };
		scale = { 60.f ,60.f };
		m_vertices.SetPos(pos);
		m_vertices.SetScale(scale);
		if (theTenDigit != 0)
		{
			m_rGameBaseMaker.Render(m_vertices, m_rGameBaseMaker.GetTex(m_SafetyLevelUITextureKey[theTenDigit]));
		}

		if (theTenDigit == 0)
		{
			pos = { 210.f ,70.f };
			scale = { 60.f , 60.f };
		}
		else
		{
			pos = { 230.f ,70.f };
			scale = {60.f , 60.f };
		}
		m_vertices.SetPos(pos);
		m_vertices.SetScale(scale);
		m_rGameBaseMaker.Render(m_vertices, m_rGameBaseMaker.GetTex(m_SafetyLevelUITextureKey[theOneDigit]));
	}
}
