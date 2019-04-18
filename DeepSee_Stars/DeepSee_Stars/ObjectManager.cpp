#include"ObjectManager.h"

ObjectManager::ObjectManager()
{
	
}

ObjectManager::~ObjectManager()
{

}


void ObjectManager::Update()
{
	for (auto &object : m_Object)
	{
		object->Update();
	}
}

void ObjectManager::Render()
{
	for (auto &object : m_Object)
	{
		object->Render();
	}
}
