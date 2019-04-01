#include"GameScene.h"
#include"SceneManager.h"

GameScene::GameScene()
{
	m_pDirectX = DirectX::GetInstance();
	m_pSceneManager = new SceneManager();
	LoadResources();
}

GameScene::~GameScene()
{
	delete m_pSceneManager;
}

void GameScene::Updata()
{
	if (m_pDirectX->IsKeyPressed(DIK_RETURN))
	{
		m_pSceneManager->m_NextScene = m_pSceneManager->RESULT;
	}
}

void GameScene::Render()
{
	CustomVertex BGVertex[4];
	m_pDirectX->InitRectangleCustomVertex(BGVertex, DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 2, DISPLAY_WIDTH, DISPLAY_HEIGHT);
	m_pDirectX->DrawTexture("GAME_SCENE_TEX", BGVertex);
}

void GameScene::LoadResources()
{
	m_pDirectX->LoadTexture("Texture/Game.png", "GAME_SCENE_TEX");
}
