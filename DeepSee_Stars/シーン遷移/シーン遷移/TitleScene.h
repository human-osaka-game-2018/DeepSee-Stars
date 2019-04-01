#pragma once
#include"Scene.h"
#include"DirectX.h"

class SceneManager;

class TitleScene : public Scene
{
public:
	TitleScene();
	~TitleScene();
	void Updata();
	void Render();
	void LoadResources();

private:
	DirectX* m_pDirectX;
	SceneManager* m_pSceneManager;
};
