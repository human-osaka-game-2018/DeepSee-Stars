#ifndef BUBBLES_H_
#define BUBBLES_H_

#include <vector>

#include "GameObject.h"

namespace deepseestars
{
	/// <summary>
	/// 泡が出るエフェクトのクラス
	/// </summary>
	class Bubbles :public GameObject
	{
	public:
		Bubbles() :
			GameObject(_T("Bubble"), _T("2DTexture/Title/Bubble.png"))
		{
			Init();
		}

		~Bubbles()
		{
			Release();
		}

		void Init()
		{
			m_rGameBaseMaker.CreateTex(m_pTextureKey, m_pFileName);
			Create();
		}

		void Update();

		void Render();

		void Release();

	private:
		/// <summary>
		/// 泡一つの動きを設定するクラス
		/// </summary>
		class Bubble :public GameObject
		{
		public:
			Bubble(const TCHAR* pTextureKey) :
				GameObject(pTextureKey)
			{
				Init();
			}

			~Bubble()
			{
				Release();
			}

			void Init();

			void Update();

			void Render();

			void Release() {}

			inline D3DXVECTOR2 GetPos() { return m_pos; }

		private:
			D3DXVECTOR2 m_pos;
		};

		/// <summary>
		/// Bubbleクラスを生成する
		/// </summary>
		/// <remarks>呼ぶと10個必ず生成される</remarks>
		void Create();

		std::vector<Bubble*> m_bubbles;
	};
}

#endif // !BUBBLES_H_
