#ifndef COLOR_H_
#define COLOR_H_

#include <Windows.h>

#include <d3dx9.h>

namespace gamebasemaker
{
	class Color
	{
	public:
		Color() {}

		/// <summary>
		/// カラーコードを代入する
		/// </summary>
		/// <param name="colorCord"></param>
		explicit Color(DWORD colorCord);

		Color(BYTE alpha, BYTE red, BYTE green, BYTE blue);

		~Color() {}

		/// <summary>
		/// フェードイン,フェードアウトをする
		/// </summary>
		/// <param name="alphaMax">アルファ値の最大値</param>
		/// <param name="alphaMin">アルファ値の最小値</param>
		/// <param name="flashCount">アルファ値を増やすフレームカウント数</param>
		/// <param name="OneCycleCount">フレームのサイクル数</param>
		void FadeIn(BYTE alphaMax, BYTE alphaMin, int& flashCount, int OneCycleCount);
		void FadeOut(BYTE alphaMax, BYTE alphaMin, int& flashCount, int OneCycleCount);

		/// <summary>
		/// 点滅させる
		/// </summary>
		/// <param name="alphaMax">アルファ値の最大値</param>
		/// <param name="alphaMin">アルファ値の最小値</param>
		/// <param name="flashCount">アルファ値を増やすフレームカウント数</param>
		/// <param name="OneCycleCount">フレームのサイクル数</param>
		void Flash(BYTE alphaMax, BYTE alphaMin, int& flashCount, int OneCycleCount);
		
		void SetAlpha(BYTE alpha) { m_alpha = alpha; }
		void SetRed(BYTE red)     { m_red   = red; }
		void SetGreen(BYTE green) { m_green = green; }
		void SetBlue(BYTE blue)   { m_blue  = blue; }
		void SetColorCord(DWORD colorCord);

		BYTE GetAlpha()  { return m_alpha; }
		BYTE GetRed()	 { return m_red; }
		BYTE GetGreen()	 { return m_green; }
		BYTE GetBlue()	 { return m_blue; }
		DWORD GetColorCord() { return D3DCOLOR_ARGB(m_alpha, m_red, m_green, m_blue); }
		
	private:
		BYTE m_alpha = 0xFF;
		BYTE m_red	 = 0xFF;
		BYTE m_green = 0xFF;
		BYTE m_blue  = 0xFF;
	};
}

#endif // !COLOR_H_
