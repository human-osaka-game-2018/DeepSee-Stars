#ifndef TITLE_BACK_GROUND_H_
#define TITLE_BACK_GROUND_H_

#include "GameObject.h"

namespace deepseestars
{
	/// <summary>
	/// タイトルの背景クラス
	/// </summary>
	class TitleBackGround :public GameObject
	{
	public:
		TitleBackGround() :
			m_pFileName(_T("2DTexture/Title/TitleBack.jpg")), m_pTextureKey(_T("Back"))
		{
			Init();
		}

		~TitleBackGround()
		{
			Release();
		}

		void Init() 
		{
			m_rGameBaseMaker.CreateTex(m_pTextureKey, m_pFileName);
		}

		void Update() {}

		void Render() 
		{
			m_rGameBaseMaker.Render(m_vertices, m_rGameBaseMaker.GetTex(m_pTextureKey));
		}

		void Release() 
		{
			m_rGameBaseMaker.ReleaseAllTex();
		}

	private:
		const TCHAR* m_pFileName;
		const TCHAR* m_pTextureKey;
	};
}

#endif // !TITLE_BACK_GROUND_H_
