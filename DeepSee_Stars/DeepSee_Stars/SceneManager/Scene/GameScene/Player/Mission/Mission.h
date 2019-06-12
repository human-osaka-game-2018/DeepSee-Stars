#ifndef MISSION_H_
#define MISSION_H_

#include "GameObject.h"

namespace deepseestars
{
	class Mission : public GameObject
	{
	public:
		Mission() : GameObject()
		{
			Init();
		}

		~Mission()
		{
			Release();
		}

		void Init()
		{
			m_startMissionGet4Items = false;
		}

		void Update();

		void Render();

		void Release() {}
		bool GetStartMissionGet3Items()
		{
			return m_startMissionGet3Items;
		}
		void SetStartMissionGet3Items(bool startMissionGet3Items)
		{
			m_startMissionGet3Items = startMissionGet3Items;
		}

		bool GetStartMissionGet4Items()
		{
			return m_startMissionGet4Items;
		}
		void SetStartMissionGet4Items(bool startMissionGet4Items)
		{
			m_startMissionGet4Items = startMissionGet4Items;
		}
	private:
		bool m_startMissionGet3Items;
		bool m_startMissionGet4Items;

	};
}

#endif // !MISSION_H_
