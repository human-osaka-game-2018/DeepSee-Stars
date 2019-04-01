#pragma once
#include "Scene.h"
#include"TitleScene.h"
#include"StageSelectScene.h"
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
		STAGESELECT,
		GAME,
		RESULT,
	};
	void Update();
	void Render();

	static SceneID m_NextScene;
	static SceneID m_CurrentScene;

private:
	Scene* m_pScene;

	void SceneFactory();
};
