#ifndef TITLE_MENU_H_
#define TITLE_MENU_H_

#include "GameObject.h"

namespace deepseestars
{
	/// <summary>
	/// タイトルで使うメニュー画面クラス
	/// </summary>
	class TitleMenu :public GameObject
	{
	public:
		TitleMenu() :
			GameObject(_T("Menu"), _T("2DTexture/Title/TitleMenu.png"))
		{
			Init();
		}
			
		~TitleMenu()
		{
			Release();
		}

		void Init()
		{
			m_rGameBaseMaker.CreateTex(m_pTextureKey, m_pFileName);
		}

		void Update();

		void Render();

		void Release()
		{
			m_rGameBaseMaker.ReleaseAllTex();
		}
	};
}

#endif // !TITLE_MENU_H_
