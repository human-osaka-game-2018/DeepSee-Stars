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
			m_pFileName(_T("2DTexture/Title/TitleMenu.png")), m_pTextureKey(_T("Menu"))
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

	private:
		const TCHAR* m_pFileName;
		const TCHAR* m_pTextureKey;
	};
}

#endif // !TITLE_MENU_H_
