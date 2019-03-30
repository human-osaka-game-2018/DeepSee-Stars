﻿#ifndef D3DPP_H_
#define D3DPP_H_

#include <d3dx9.h>

#include "../../Wnd/Data/RectSize.h"

namespace device
{
	/// <summary>
	/// バックバッファ関係クラス
	/// </summary>
	class D3DPP
	{
	public:
		D3DPP(HWND hWnd, RectSize wndSize) :WND_SIZE(wndSize), hWND(hWnd) {};	
		~D3DPP() {};

		/// <summary>
		/// 現在のウィンドウモードのD3DPRESENT_PARAMETERSを返す
		/// </summary>
		/// <returns>現在のウィンドウモードのD3DPRESENT_PARAMETERS </returns>
		inline D3DPRESENT_PARAMETERS GetD3DPRESENT_PARAMETERS()
		{
			D3DPRESENT_PARAMETERS D3DPP;
			InitD3DPP(&D3DPP);

			return D3DPP;
		}

		/// <summary>
		/// ウィンドウモードを切り替えそのD3DPRESENT_PARAMETERSを返す
		/// </summary>
		/// <returns>ウィンドウモード切替後のD3DPRESENT_PARAMETERS</returns>
		inline D3DPRESENT_PARAMETERS ToggleD3DPPWndMode()
		{
			m_isWindow = !m_isWindow;

			D3DPRESENT_PARAMETERS D3DPP;
			InitD3DPP(&D3DPP);

			return D3DPP;
		}

	private:
		/// <summary>
		/// D3DPRESENT_PARAMETERSを初期化する
		/// </summary>
		/// <param name="pD3DPP">初期化したいD3DPRESENT_PARAMETERS型のポインタ</param>
		void InitD3DPP(D3DPRESENT_PARAMETERS* pD3DPP);

		const HWND hWND = nullptr;

		const RectSize WND_SIZE;

		bool m_isWindow = true;
	};
}

#endif // !D3DPP_H_
