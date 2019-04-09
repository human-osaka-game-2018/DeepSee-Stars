#ifndef PRESENT_PARAM_H_
#define PRESENT_PARAM_H_

#include <windows.h>

#include "../../../Wnd/Data/RectSize.h"

namespace device
{
	/// <summary>
	/// バックバッファ関係クラス
	/// </summary>
	class PresentParam
	{
	public:
		PresentParam(HWND hWnd, RectSize wndSize) :WND_SIZE(wndSize), hWND(hWnd) {};
		~PresentParam() {};

		/// <summary>
		/// 現在のウィンドウモードのD3DPRESENT_PARAMETERSを返す
		/// </summary>
		/// <returns>現在のウィンドウモードのD3DPRESENT_PARAMETERS </returns>
		inline D3DPRESENT_PARAMETERS GetD3DPRESENT_PARAMETERS()
		{
			D3DPRESENT_PARAMETERS PresentParam;
			InitPresentParam(&PresentParam);

			return PresentParam;
		}

		/// <summary>
		/// ウィンドウモードを切り替えそのD3DPRESENT_PARAMETERSを返す
		/// </summary>
		/// <returns>ウィンドウモード切替後のD3DPRESENT_PARAMETERS</returns>
		inline D3DPRESENT_PARAMETERS ToggleD3DPPWndMode()
		{
			m_isWindow = !m_isWindow;

			D3DPRESENT_PARAMETERS PresentParam;
			InitPresentParam(&PresentParam);

			return PresentParam;
		}

	private:
		/// <summary>
		/// D3DPRESENT_PARAMETERSを初期化する
		/// </summary>
		/// <param name="pD3DPP">初期化したいD3DPRESENT_PARAMETERS型のポインタ</param>
		void InitPresentParam(D3DPRESENT_PARAMETERS* pPresentParam);

		const HWND hWND;

		const RectSize WND_SIZE;

		bool m_isWindow = true;
	};
}

#endif // !PRESENT_PARAM_H_
