#ifndef BASEACTION_H
#define BASEACTION_H

#include "GameObject.h"


namespace deepseestars
{
	class BaseAction : public GameObject
	{
	public:
		BaseAction() : GameObject()
		{
			
		}

		~BaseAction();

		virtual void Init();

		virtual void Update();

		virtual void Render();

		virtual void Release();


	};
}
#endif // BASEACTION_H
