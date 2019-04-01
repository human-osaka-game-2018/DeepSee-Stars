#pragma once
#include"Scene.h"
#include"DirectX.h"

class SceneManager;

class GameScene : public Scene
{
public:
	GameScene();
	~GameScene();
	void Updata();
	void Render();
	void LoadResources();

private:
	DirectX* m_pDirectX;
	SceneManager* m_pSceneManager;
};
