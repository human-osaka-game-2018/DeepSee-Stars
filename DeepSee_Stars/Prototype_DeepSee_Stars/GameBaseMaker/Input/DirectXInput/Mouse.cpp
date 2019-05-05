#include "Mouse.h"

namespace input
{
	void Mouse::Create()
	{
		LPDIRECTINPUT8 pInputDevice = device::DirectXDevices::GetDXInputDevice()->Get();

		pInputDevice->CreateDevice(
			GUID_SysMouse,
			&m_pDXInputDevice,
			NULL);

		m_pDXInputDevice->SetDataFormat(&c_dfDIMouse);

		m_pDXInputDevice->SetCooperativeLevel(
			m_HWND,
			DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);

		DIPROPDWORD mouseProp;
		mouseProp.diph.dwSize = sizeof(DIPROPDWORD);
		mouseProp.diph.dwHeaderSize = sizeof(mouseProp.diph);
		mouseProp.diph.dwObj = 0;
		mouseProp.diph.dwHow = DIPH_DEVICE;
		mouseProp.dwData = DIPROPAXISMODE_REL;

		m_pDXInputDevice->SetProperty(DIPROP_AXISMODE, &mouseProp.diph);
	}

	void Mouse::AcquireInputState()
	{
		m_pDXInputDevice->Acquire();						

		GetCursorPos(&m_cursorRelativePos);				//ここではまだディスプレイ基準の絶対座標
		ScreenToClient(m_HWND, &m_cursorRelativePos);	//ここでウィンドウ基準の相対座標に変換

		m_pDXInputDevice->GetDeviceState(					
			sizeof(DIMOUSESTATE),
			&m_state);
	}

	void Mouse::CheckInputStateDetatils()
	{
		bool isInputtedPrev = false;
		bool isInputted = false;

		ZeroMemory(&m_details, sizeof(BOOL) * DIM_MAX);

		for (INT i = 0; i < DIM_MAX; ++i)
		{
			isInputtedPrev = IsInputted(m_prevState.rgbButtons[i]);
			isInputted = IsInputted(m_state.rgbButtons[i]);

			if (isInputtedPrev)
			{
				m_details[i] = (isInputted) ? IND_HOLD : IND_RELEASE;

				continue;
			}

			m_details[i] = (isInputted) ? IND_PRESS : IND_NEUTRAL;
		}
	}
}
