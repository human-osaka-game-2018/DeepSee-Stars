#ifndef SCENE_H
#define SCENE_H

class Scene
{
public:
	Scene();
	virtual ~Scene();
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void LoadResources() = 0;
private:

};
#endif // SCENE_H
