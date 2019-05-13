#ifndef GAME_SCENE_H_
#define GAME_SCENE_H_

#include "../Scene.h"

#include "../GameScene/World/World.h"

namespace deepseestars
{
	class GameScene :public Scene
	{
	public:
		GameScene()
		{
			m_objects.Register(static_cast<GameObject*>(new World()));
		}
	};
}

#endif // !GAME_SCENE_H_
