#include"GameScene.h"


GameScene::GameScene()
{
	m_pDirectX = DirectX::GetInstance();
	m_pCollsionManager = CollsionManager::GetInstance();
	m_pSceneManager = new SceneManager();
	m_pObjectManager = new ObjectManager();
	m_pStage = new Stage();
	m_pPlayer = new Player();
	m_pBackGround = new BackGround();

	LoadResources();

	m_pObjectManager->m_Object.push_back(m_pBackGround);
	m_pObjectManager->m_Object.push_back(m_pStage);
	m_pObjectManager->m_Object.push_back(m_pPlayer);

}

GameScene::~GameScene()
{
	delete m_pSceneManager;
	delete m_pObjectManager;
	delete m_pStage;
	delete m_pPlayer;
	delete m_pBackGround;
	m_pCollsionManager->DeleteInstence();
}

void GameScene::Update()
{
	m_pObjectManager->Update();
}

void GameScene::Render()
{
	m_pObjectManager->Render();
}

void GameScene::LoadResources()
{
	m_pDirectX->LoadTexture("Texture/Block.png", "GAME_BLOCK_TEX");
	m_pDirectX->LoadTexture("Texture/Player.png", "GAME_PLAYER_TEX");
	m_pDirectX->LoadTexture("Texture/BG.png", "GAME_BG_TEX");
}
