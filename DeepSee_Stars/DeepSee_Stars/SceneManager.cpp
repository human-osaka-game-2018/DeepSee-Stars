#include"SceneManager.h"

SceneManager::SceneID SceneManager::m_NextScene = GAME;
SceneManager::SceneID SceneManager::m_CurrentScene = NONE;

SceneManager::SceneManager()
{
	
}

SceneManager::~SceneManager()
{

}

void SceneManager::Update()
{
	if (m_CurrentScene != m_NextScene) SceneFactory();
	m_pScene->Update();
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
	case GAME:
		m_pScene = new GameScene();
		break;
	case RESULT:
		m_pScene = new ResultScene();
		break;
	}
	m_CurrentScene = m_NextScene;
}
