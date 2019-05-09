#ifndef SCENE_H_
#define SCENE_H_

#include "../../GameObjects/GameObjects.h"

namespace deepseestars
{
	/// <summary>
	/// シーン基底クラス
	/// </summary>
	class Scene
	{
	public:
		Scene()
		{
			Init();
		}

		virtual ~Scene()
		{
			Release();
		}

		/// <summary>
		/// シーンで使うオブジェクトを初期化する
		/// </summary>
		virtual void Init()
		{
			m_objects.Init();
		}

		/// <summary>
		/// シーンで使うオブジェクトを更新する 
		/// </summary>
		virtual void Update()
		{
			m_objects.Update();
		}

		/// <summary>
		/// シーンで使うオブジェクトを描画する
		/// </summary>
		virtual void Render()
		{
			m_objects.Render();
		}

		/// <summary>
		/// シーンで使うオブジェクトを解放する
		/// </summary>
		virtual void Release()
		{
			m_objects.Release();
		}

	private:
		GameObjects m_objects;
	};
}

#endif // !SCENE_H_
