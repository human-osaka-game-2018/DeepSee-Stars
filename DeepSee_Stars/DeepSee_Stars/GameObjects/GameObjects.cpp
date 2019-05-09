#include "GameObjects.h"

namespace deepseestars
{
	void GameObjects::Init()
	{
		for (auto* object : m_gameObjects)
		{
			object->Init();
		}
	}

	void GameObjects::Update()
	{
		for (auto* object : m_gameObjects)
		{
			object->Update();
		}
	}

	void GameObjects::Render()
	{
		for (auto* object : m_gameObjects)
		{
			object->Render();
		}
	}

	void GameObjects::Release()
	{
		for (auto* object : m_gameObjects)
		{
			object->Release();
			delete object;
		}

		m_gameObjects.clear();
		m_gameObjects.shrink_to_fit();
	}
}
