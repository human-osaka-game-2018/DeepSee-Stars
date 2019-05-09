#include "Color.h"

#include <math.h>
#include <d3dx9.h>

namespace gamebasemaker
{
	Color::Color(BYTE alpha, BYTE red, BYTE green, BYTE blue)
	{
		SetAlpha(alpha);
		SetRed(red);
		SetGreen(green);
		SetBlue(blue);
	}

	Color::Color(DWORD colorCord)
	{
		SetColorCord(colorCord);
	}

	void Color::SetColorCord(DWORD colorCord)
	{
		m_alpha = static_cast<BYTE>(colorCord >> 24);
		m_red   = static_cast<BYTE>(colorCord >> 16);
		m_green = static_cast<BYTE>(colorCord >> 8);
		m_blue  = static_cast<BYTE>(colorCord);
	}

	void Color::FadeIn(BYTE alphaMax, BYTE alphaMin, int& flashCount, int OneCycleCount)
	{
		if (flashCount > OneCycleCount) return;

		++flashCount;
		
		float progressRatio = flashCount / static_cast<float>(OneCycleCount);
		float rad = progressRatio * 0.5f * D3DX_PI;
		
		m_alpha = static_cast<BYTE>((alphaMax - alphaMin) * fabsf(static_cast<float>(sin(rad))) + alphaMin);
	}

	void Color::FadeOut(BYTE alphaMax, BYTE alphaMin, int& flashCount, int OneCycleCount)
	{
		if (flashCount > OneCycleCount) return;

		++flashCount;

		float progressRatio = flashCount / static_cast<float>(OneCycleCount);
		float rad = progressRatio * 0.5f * D3DX_PI;

		m_alpha = static_cast<BYTE>((alphaMin - alphaMax) * fabsf(static_cast<float>(sin(rad))) + alphaMax);
	}

	void Color::Flash(BYTE alphaMax, BYTE alphaMin, int& flashCount, int OneCycleCount)
	{
		++flashCount;

		if (flashCount > OneCycleCount) flashCount = 0;

		float progressRatio = flashCount / static_cast<float>(OneCycleCount);
		float rad = progressRatio * D3DX_PI;

		m_alpha = static_cast<BYTE>((alphaMax - alphaMin) * fabsf(static_cast<float>(sin(rad))) + alphaMin);
	}
}
