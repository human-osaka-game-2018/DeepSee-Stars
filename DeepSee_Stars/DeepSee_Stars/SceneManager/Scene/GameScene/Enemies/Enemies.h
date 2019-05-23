#ifndef ENEMIES_H_
#define ENEMIES_H_

#include <vector>

#include "GameObject.h"
#include "Enemy/Enemy.h"

namespace deepseestars
{
	class Enemies :public GameObject
	{
	public:
		Enemies(const D3DXVECTOR2& playerPos, const float& cellSize) :
			GameObject(), m_playerPos(playerPos), m_cellSize(cellSize)
		{}

		~Enemies()
		{
		}

		void Init();
		void Update();
		void Render();
		void Release();

		std::vector<Enemy*> GetEnemies() { return m_enemies; }

	private:
		void Load(const char* pFileName);

		std::vector<Enemy*> m_enemies;

		const D3DXVECTOR2& m_playerPos;
		const float& m_cellSize;
	};
}

#endif // !ENEMIES_H_
