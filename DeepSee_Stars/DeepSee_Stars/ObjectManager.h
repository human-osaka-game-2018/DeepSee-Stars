#pragma once
#include <vector>
#include"Stage.h"

class Object;

class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();
	void Update();
	void Render();
	std::vector<Object*> m_Object;
private:

};
