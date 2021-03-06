﻿#include "SceneManager.h"

#include "Scene/TitleScene/TitleScene.h"
#include "Scene/GameScene/GameScene.h"

namespace deepseestars
{
	void SceneManager::Factory()
	{
		if (m_currentScene == m_nextScene) return;

		m_currentScene = m_nextScene;

		switch (m_nextScene)
		{
		case SCENE_ID::TITLE:
			delete m_pScene;

			m_pScene = new TitleScene();

			break;

		case SCENE_ID::GAME:
			delete m_pScene;

			m_pScene = new GameScene();

			break;

		case SCENE_ID::RESULT:
			delete m_pScene;

			break;

		default:
			break;
		}
	}
}
