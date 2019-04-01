#include"ResultScene.h"
#include"SceneManager.h"

ResultScene::ResultScene()
{
	m_pDirectX = DirectX::GetInstance();
	m_pSceneManager = new SceneManager();
	LoadResources();
}

ResultScene::~ResultScene()
{
	delete m_pSceneManager;
}

void ResultScene::Updata()
{
	if (m_pDirectX->IsKeyPressed(DIK_RETURN))
	{
		m_pSceneManager->m_NextScene = m_pSceneManager->TITLE;
	}
}

void ResultScene::Render()
{
	CustomVertex BGVertex[4];
	m_pDirectX->InitRectangleCustomVertex(BGVertex, DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 2, DISPLAY_WIDTH, DISPLAY_HEIGHT);
	m_pDirectX->DrawTexture("RESULT_SCENE_TEX", BGVertex);
}

void ResultScene::LoadResources()
{
	m_pDirectX->LoadTexture("Texture/Result.png", "RESULT_SCENE_TEX");
}
