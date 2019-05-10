#ifndef TITLE_LOGO_H_
#define TITLE_LOGO_H_

#include "GameObject.h"

namespace deepseestars
{
	/// <summary>
	/// タイトル画面で使うロゴクラス
	/// </summary>
	class TitleLogo :public GameObject
	{
	public:
		TitleLogo() :
			GameObject(_T("Logo"),_T("2DTexture/Title/TitleLogo.png"))
		{
			Init();
		}

		~TitleLogo() {}
			
		void Init()
		{
			m_rGameBaseMaker.CreateTex(m_pTextureKey, m_pFileName);
		}

		void Update() {}

		void Render();

		void Release()
		{
			m_rGameBaseMaker.ReleaseAllTex();
		}
	};
}

#endif // !TITLE_LOGO_H_
