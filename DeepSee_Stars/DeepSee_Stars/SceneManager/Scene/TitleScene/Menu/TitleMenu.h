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
			GameObject(_T("Menu"), _T("2DTexture/Title/TitleMenu.png")),
			m_pSoundKey(_T("TitleBgm")), m_pSoundFileName(_T("Audio/Title/TitleBgm.mp3"))
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
			m_rGameBaseMaker.AddFile(m_pSoundFileName, m_pSoundKey, Sound::SoundType::BGM);
			m_rGameBaseMaker.LoopStart(m_pSoundKey);
		}

		void Update();

		void Render();

		void Release()
		{
			m_rGameBaseMaker.ReleaseAllTex();
			m_rGameBaseMaker.Stop(m_pSoundKey);
		}

	private:
		const TCHAR* m_pSoundFileName;
		const TCHAR* m_pSoundKey;
	};
}

#endif // !TITLE_MENU_H_
