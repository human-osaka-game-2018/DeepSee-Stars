#ifndef WND_H
#define WND_H

#include <windows.h>

namespace window
{
	/// <summary>
	/// ウィンドウクラス
	/// </summary>
	class Wnd
	{
	public:
		Wnd() {};
		~Wnd() {};

		/// <summary>
		/// ウィンドウを生成する
		/// </summary>
		/// <param name="hInst">hInstance</param>
		/// <param name="pAppName">アプリ名</param>
		static void Create(const HINSTANCE hInst, const TCHAR* pAppName);

		/// <summary>
		/// ウィンドウハンドルを取得する
		/// </summary>
		/// <returns>ウィンドウハンドル</returns>
		inline static const HWND GetHWND()
		{
			return m_hWnd;
		}

		/// <summary>
		/// WinMessageの構造体を取得する
		/// </summary>
		/// <returns>WinMessageの構造体</returns>
		inline static MSG GetMSG()
		{
			return m_msg;
		}

		/// <summary>
		/// ウィンドウのサイズを取得する
		/// </summary>
		/// <returns>ウィンドウのサイズ</returns>
		inline static RectSize GetWndSize()
		{
			return WND_SIZE;
		}

		/// <summary>
		/// ウィンドウを終了するメッセージが投げられたか
		/// </summary>
		/// <returns>投げられていたらTRUE</returns>
		inline static bool IsPostedQuitMessage()
		{
			if (m_msg.message == WM_QUIT) return TRUE;

			return FALSE;
		}

		/// <summary>
		/// WinMessageが何かあるか
		/// </summary>
		/// <returns>あればTRUE</returns>
		static bool ExistsWinMSG();

		/// <summary>
		/// クライアント領域をm_WND_SIZEと同じにする
		/// </summary>
		static void ResizeWnd();

	private:
		/// <summary>
		/// ウィンドウを生成するときにProcの関数ポインタが必要なのでstatic
		/// IDX3D経由でDX3DのメソッドToggleWndMode()を呼ぶ
		/// </summary>
		static LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);    
																								
		static HWND m_hWnd;

		static MSG m_msg;

		static const RectSize WND_SIZE;
	};
}

#endif // !WND_H
