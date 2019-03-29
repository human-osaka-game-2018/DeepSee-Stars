#ifndef WND_H
#define WND_H

#include <windows.h>

class Wnd
{
public:
	Wnd(const HINSTANCE hInst, const TCHAR* pAppName);	//WinMainからHINSTANCEを取得 Crate()を呼ぶ
	~Wnd() {};

	static void Create(const HINSTANCE hInst, const TCHAR* pAppName);

	/**
	* @brief ウィンドウハンドルを取得する
	* @return ウィンドウハンドル
	*/
	inline static const HWND GetHWND() 
	{
		return m_hWnd;
	}

	/**
	* @brief WinMessageの構造体を取得する
	* @return WinMessageの構造体
	*/
	inline static MSG GetMSG() 
	{
		return m_msg;
	}

	/**
	* @brief ウィンドウのサイズを取得する
	* @return ウィンドウのサイズ
	*/
	inline static RectSize GetWndSize() 
	{
		return WND_SIZE;
	}

	/**
	* @brief ウィンドウを終了するメッセージが投げられたか
	* @return 投げられていたらTRUE
	*/
	inline static bool IsPostedQuitMessage() 
	{
		if (m_msg.message == WM_QUIT) return TRUE;

		return FALSE;
	}

	/**
	* @brief WinMessageが何かあるか
	* @return あればTRUE
	*/
	static bool ExistsWinMSG();

	/**
	* @brief クライアント領域をm_WND_SIZEと同じにする
	*/
	static void ResizeWnd();

private:
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);    //ウィンドウを生成するときにProcの関数ポインタが必要なのでstatic
																							//IDX3D経由でDX3DのメソッドToggleWndMode()を呼ぶ
	static HWND m_hWnd;

	static MSG m_msg;

	static const RectSize WND_SIZE;
};

#endif // !WND_H
