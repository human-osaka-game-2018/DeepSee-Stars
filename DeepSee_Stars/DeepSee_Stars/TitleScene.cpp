#include"TitleScene.h"
#include"SceneManager.h"

TitleScene::TitleScene()
{
	m_pDirectX = DirectX::GetInstance();
	m_pSceneManager = new SceneManager();
	LoadResources();
}

TitleScene::~TitleScene()
{
	delete m_pSceneManager;
}

void TitleScene::Update()
{
	if (m_pDirectX->IsKeyPressed(DIK_RETURN))
	{
		m_pSceneManager->SetNextScene(m_pSceneManager->GAME);
	}
}

void TitleScene::Render()
{
	CustomVertex BGVertex[4];
	m_pDirectX->InitRectangleCustomVertex(BGVertex, DISPLAY_WIDTH/2, DISPLAY_HEIGHT/2 , DISPLAY_WIDTH, DISPLAY_HEIGHT);
	m_pDirectX->DrawTexture("TITLE_SCENE_TEX", BGVertex);
}

void TitleScene::LoadResources()
{
	m_pDirectX->LoadTexture("Texture/Tilte.png", "TITLE_SCENE_TEX");
}
