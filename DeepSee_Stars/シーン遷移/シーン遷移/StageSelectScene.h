#pragma once
#include"Scene.h"
#include"DirectX.h"

class SceneManager;

class StageSelectScene : public Scene
{
public:
	StageSelectScene();
	~StageSelectScene();
	void Updata();
	void Render();
	void LoadResources();

private:
	DirectX* m_pDirectX;
	SceneManager* m_pSceneManager;
};
