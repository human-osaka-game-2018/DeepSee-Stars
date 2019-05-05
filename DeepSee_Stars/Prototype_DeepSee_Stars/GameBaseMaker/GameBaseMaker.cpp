#include "GameBaseMaker.h"

#include <chrono>
#include "../Wnd/Wnd.h"

namespace gamebasemaker
{
	using window::Wnd;

	void GameBaseMaker::Run(std::function<void()> Func)
	{
		std::chrono::system_clock::time_point currentTime, prevTime;
		const INT DEFAULT_FPS = 60;

		while (!Wnd::IsPostedQuitMessage())
		{
			if (Wnd::ExistsWinMSG()) continue;

			currentTime = std::chrono::system_clock::now();

			LONGLONG rapTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - prevTime).count();

			if (rapTime < 1000 / DEFAULT_FPS) continue;

			prevTime = currentTime;

			Prepare();

			Func();

			CleanUp();
		}
	}
}
