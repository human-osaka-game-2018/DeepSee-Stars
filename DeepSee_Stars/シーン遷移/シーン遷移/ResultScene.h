#pragma once
#include"Scene.h"
#include"DirectX.h"

class SceneManager;

class ResultScene : public Scene
{
public:
	ResultScene();
	~ResultScene();
	void Updata();
	void Render();
	void LoadResources();

private:
	DirectX * m_pDirectX;
	SceneManager* m_pSceneManager;
};
