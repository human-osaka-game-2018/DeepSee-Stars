#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "Scene.h"
#include "DirectX.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "World.h"
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
	DirectX * m_pDirectX;
	CollsionManager * m_pCollsionManager;
	SceneManager* m_pSceneManager;
	ObjectManager* m_pObjectManager;
	World* m_pWorld;
	BackGround* m_pBackGround;
};
#endif // GAMESCENE_H
