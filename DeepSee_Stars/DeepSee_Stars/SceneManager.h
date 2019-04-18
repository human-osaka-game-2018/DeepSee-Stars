#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "Scene.h"
#include"TitleScene.h"
#include"GameScene.h"
#include"ResultScene.h"


class Scene;

class SceneManager
{
public:
	SceneManager();
	~SceneManager();
	enum SceneID
	{
		NONE,
		TITLE,
		GAME,
		RESULT,
	};
	void Update();
	void Render();

	void SetNextScene(SceneID nextScene)
	{
		m_NextScene = nextScene;
	}

private:
	Scene* m_pScene;
	static SceneID m_NextScene;
	static SceneID m_CurrentScene;

	void SceneFactory();
};
#endif // SCENEMANAGER_H
