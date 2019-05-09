#include "Keyboard.h"

namespace input
{
	void Keyboard::CheckInputStateDetatils()
	{
		bool isInputtedPrev = false;
		bool isInputted = false;

		const int KEYBOARD_KEYS_MAX = 256;
		ZeroMemory(m_details, sizeof(bool) * KEYBOARD_KEYS_MAX);
		
		for (int i = 0; i < KEYBOARD_KEYS_MAX; ++i)
		{
			isInputtedPrev = IsInputted(m_prevDiks[i]);
			isInputted = IsInputted(m_diks[i]);

			if (isInputtedPrev)
			{
				m_details[i] = (isInputted) ? IND_HOLD : IND_RELEASE;

				continue;
			}

			m_details[i] = (isInputted) ? IND_PRESS : IND_NEUTRAL;
		}
	}

	void Keyboard::Create()
	{
		LPDIRECTINPUT8 pInputDevice = device::DirectXDevices::GetDXInputDevice()->Get();

		pInputDevice->CreateDevice(
			GUID_SysKeyboard, &m_pDXInputDevice,
			NULL);

		m_pDXInputDevice->SetDataFormat(&c_dfDIKeyboard);

		m_pDXInputDevice->SetCooperativeLevel(
			m_HWND,
			DISCL_NONEXCLUSIVE | DISCL_BACKGROUND);
	}
}
