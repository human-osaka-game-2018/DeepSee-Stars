#pragma once

class Scene
{
public:
	Scene();
	virtual ~Scene();
	virtual void Updata() = 0;
	virtual void Render() = 0;
	virtual void LoadResources() = 0;
private:

};
