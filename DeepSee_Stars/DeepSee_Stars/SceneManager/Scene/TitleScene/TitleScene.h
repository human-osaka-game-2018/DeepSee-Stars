#ifndef TITLE_SCENE_H_
#define TITLE_SCENE_H_

#include "../Scene.h"

#include "BackGround/TitleBackGround.h"
#include "Logo/TitleLogo.h"

namespace deepseestars
{
	/// <summary>
	/// タイトルシーンクラス
	/// </summary>
	class TitleScene :public Scene
	{
	public:
		TitleScene()
		{
			m_objects.Register(static_cast<GameObject*>(new TitleBackGround()));
			m_objects.Register(static_cast<GameObject*>(new TitleLogo()));
		}
	};
}

#endif // !TITLE_SCENE_H_
