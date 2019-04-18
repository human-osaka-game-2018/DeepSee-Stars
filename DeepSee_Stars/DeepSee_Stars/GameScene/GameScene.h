#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "Scene.h"
#include "DirectX.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "Stage.h"
#include "Player.h"
#include "BackGround.h"


class SceneManager;

class GameScene : public Scene
{
public:
	GameScene();
	~GameScene();
	void Update();
	void Render();
	void LoadResources();

private:
	DirectX* m_pDirectX;
	CollsionManager * m_pCollsionManager;
	SceneManager* m_pSceneManager;
	ObjectManager* m_pObjectManager;
	Stage* m_pStage;
	Player* m_pPlayer;
	BackGround* m_pBackGround;
};
#endif // GAMESCENE_H
