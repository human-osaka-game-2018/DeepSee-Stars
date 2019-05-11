#ifndef GAME_OBJECTS_H_
#define GAME_OBJECTS_H_

#include <vector>

#include "GameObject/GameObject.h"

namespace deepseestars
{
	class GameObjects
	{
	public:
		GameObjects() {}
		~GameObjects() 
		{
			Release();
		}
		
		/// <summary>
		/// ゲームオブジェクトを登録する
		/// </summary>
		/// <param name="gameObject">登録したいゲームオブジェクトのポインタ</param>
		inline void Register(GameObject* gameObject)
		{
			m_gameObjects.push_back(gameObject);
		}

		/// <summary>
		/// ゲームオブジェクトの中身をすべて初期化する
		/// </summary>
		void Init();

		/// <summary>
		/// ゲームオブジェクトの中身をすべて更新する
		/// </summary>
		void Update();

		/// <summary>
		/// ゲームオブジェクトの中身をすべて描画する
		/// </summary>
		void Render();

		/// <summary>
		/// ゲームオブジェクトの中身をすべて解放する
		/// </summary>
		void Release();

	private:
		std::vector<GameObject*> m_gameObjects;
	};
}

#endif // !GAME_OBJECTS_H_
