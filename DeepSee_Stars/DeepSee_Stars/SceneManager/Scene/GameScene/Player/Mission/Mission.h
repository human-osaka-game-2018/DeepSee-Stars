#ifndef MISSION_H_
#define MISSION_H_

#include "GameObject.h"

namespace deepseestars
{
	class Mission : public GameObject
	{
	public:
		Mission() :  GameObject()
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

		void Release(){}


		bool GetStartMissionGet4Items()
		{
			return m_startMissionGet4Items;
		}
		void SetStartMissionGet4Items(bool startMissionGet4Items)
		{
			m_startMissionGet4Items = startMissionGet4Items;
		}
	private:
		bool m_startMissionGet4Items;

	};
}

#endif // !MISSION_H_
