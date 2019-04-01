#include"StageSelectScene.h"
#include"SceneManager.h"

StageSelectScene::StageSelectScene()
{
	m_pDirectX = DirectX::GetInstance();
	m_pSceneManager = new SceneManager();
	LoadResources();
}

StageSelectScene::~StageSelectScene()
{
	delete m_pSceneManager;
}

void StageSelectScene::Updata()
{
	if (m_pDirectX->IsKeyPressed(DIK_RETURN))
	{
		m_pSceneManager->m_NextScene = m_pSceneManager->GAME;
	}
}

void StageSelectScene::Render()
{
	CustomVertex BGVertex[4];
	m_pDirectX->InitRectangleCustomVertex(BGVertex, DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 2, DISPLAY_WIDTH, DISPLAY_HEIGHT);
	m_pDirectX->DrawTexture("STAGESELECT_SCENE_TEX", BGVertex);
}

void StageSelectScene::LoadResources()
{
	m_pDirectX->LoadTexture("Texture/StageSelect.png", "STAGESELECT_SCENE_TEX");
}
