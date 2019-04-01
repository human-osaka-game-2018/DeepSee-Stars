#include"SceneManager.h"

SceneManager::SceneID SceneManager::m_NextScene = TITLE;
SceneManager::SceneID SceneManager::m_CurrentScene = NONE;

SceneManager::SceneManager()
{
	
}

SceneManager::~SceneManager()
{

}

void SceneManager::Update()
{
	if (m_CurrentScene != m_NextScene)
	{
		SceneFactory();
	}
	m_pScene->Updata();
}

void SceneManager::Render()
{
	m_pScene->Render();
}

void SceneManager::SceneFactory()
{
	delete m_pScene;
	switch (m_NextScene)
	{
	case TITLE:
		m_pScene = new TitleScene();
		break;
	case STAGESELECT:
		m_pScene = new StageSelectScene();
		break;
	case GAME:
		m_pScene = new GameScene();
		break;
	case RESULT:
		m_pScene = new ResultScene();
		break;
	}
	m_CurrentScene = m_NextScene;
}
