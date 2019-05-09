#include"GameScene.h"


GameScene::GameScene()
{
	m_pDirectX = DirectX::GetInstance();
	m_pCollsionManager = CollsionManager::GetInstance();
	m_pSceneManager = new SceneManager();
	m_pObjectManager = new ObjectManager();
	m_pWorld = new World();
	m_pBackGround = new BackGround();

	LoadResources();

	m_pObjectManager->m_Object.push_back(m_pBackGround);
	m_pObjectManager->m_Object.push_back(m_pWorld);

}

GameScene::~GameScene()
{
	delete m_pSceneManager;
	delete m_pObjectManager;
	delete m_pWorld;
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
	m_pDirectX->LoadTexture("Texture/BlackBlock.png", "GAME_BLACKBLOCK_TEX");
	m_pDirectX->LoadTexture("Texture/WhiteBlock.png", "GAME_WHITEBLOCK_TEX");
	m_pDirectX->LoadTexture("Texture/HideBlock.png", "GAME_HIDEBLOCK_TEX");
	m_pDirectX->LoadTexture("Texture/Player.png", "GAME_PLAYER_TEX");
	m_pDirectX->LoadTexture("Texture/LifeNumber.png", "GAME_LIFENUMBER_TEX");
	m_pDirectX->LoadTexture("Texture/LifeFrame.png", "GAME_LIFEFRAME_TEX");
	m_pDirectX->LoadTexture("Texture/Floor.png", "GAME_FLOOR_TEX");
	m_pDirectX->LoadTexture("Texture/Autotomy.png", "GAME_AUTOTOMY_TEX");
	m_pDirectX->LoadTexture("Texture/BG.png", "GAME_BG_TEX");
}
