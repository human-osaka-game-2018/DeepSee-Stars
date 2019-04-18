#ifndef TITLE_H
#define TITLE_H

#include"Scene.h"
#include"DirectX.h"


class SceneManager;

class TitleScene : public Scene
{
public:
	TitleScene();
	~TitleScene();
	void Update();
	void Render();
	void LoadResources();

private:
	DirectX* m_pDirectX;
	SceneManager* m_pSceneManager;
};
#endif // TITLE_H
