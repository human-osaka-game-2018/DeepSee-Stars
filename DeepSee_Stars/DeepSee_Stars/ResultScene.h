#ifndef RESULTSCENE_H
#define RESULTSCENE_H

#include"Scene.h"
#include"DirectX.h"
#include"SceneManager.h"


class SceneManager;

class ResultScene : public Scene
{
public:
	ResultScene();
	~ResultScene();
	void Update();
	void Render();
	void LoadResources();

private:
	DirectX * m_pDirectX;
	SceneManager* m_pSceneManager;
};
#endif // RESULTSCENE_H
