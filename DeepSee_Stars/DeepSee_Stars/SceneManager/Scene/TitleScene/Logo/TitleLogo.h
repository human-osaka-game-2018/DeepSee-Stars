#ifndef TITLE_LOGO_H_
#define TITLE_LOGO_H_

#include "GameObject.h"

namespace deepseestars
{
	class TitleLogo :public GameObject
	{
	public:
		TitleLogo() :
			m_pFileName(_T("2DTexture/Title/TitleLogo.png")), m_pTextureKey(_T("Logo"))
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

	private:
		const TCHAR* m_pFileName;
		const TCHAR* m_pTextureKey;
	};
}

#endif // !TITLE_LOGO_H_
