#ifndef SCENE_MANAGER_H_
#define SCENE_MANAGER_H_

#include "../Singleton/Singleton.h"
#include "Scene/Scene.h"

namespace deepseestars
{
	using singleton::Singleton;

	/// <summary>
	/// シーン管理クラス
	/// </summary>
	class SceneManager :public Singleton<SceneManager>
	{
	public:
		friend class Singleton<SceneManager>;

		~SceneManager() 
		{
			delete m_pScene;
		}

		enum SCENE_ID
		{
			TITLE = 1 ,
			GAME,
			RESULT
		};

		/// <summary>
		/// 現在のシーンの更新関数を呼ぶ
		/// </summary>
		inline void Update()
		{
			Factory();
			m_pScene->Update();
		}

		/// <summary>
		/// 現在のシーンの描画関数を呼ぶ
		/// </summary>
		inline void Render()
		{
			m_pScene->Render();
		}

		void SetNextScene(SCENE_ID nextSceneId)
		{
			m_nextScene = nextSceneId;
		}

	private:
		SceneManager() :m_nextScene(SCENE_ID::TITLE) {}

		/// <summary>
		/// シーン生成する
		/// </summary>
		void Factory();

		SCENE_ID m_currentScene;
		SCENE_ID m_nextScene;

		Scene* m_pScene;
	};
}

#endif // !SCENE_MANAGER_H_

