#ifndef BASEACTION_H
#define BASEACTION_H

#include "GameObject.h"


namespace deepseestars
{
	class BaseAction : public GameObject
	{
	public:
		BaseAction() : GameObject()
		{
			Init();
		}

		~BaseAction();

		virtual void Init()
		{
			for (int i = 0;i <= 1;i++)
			{
				m_rGameBaseMaker.CreateTex(m_actionTextureKey[i], m_actionTextureName[i]);
			}
		}

		virtual void Update();

		virtual void Render();

		virtual void Release()
		{
			m_rGameBaseMaker.ReleaseAllTex();
		}

		const TCHAR** GetactionTextureKey()
		{
			return m_actionTextureKey;
		}
	private :
		const TCHAR* m_actionTextureKey[1] =
		{
			_T("AutotomyObject"),
		};
		const TCHAR* m_actionTextureName[1] =
		{
			_T("2DTexture/Game/Autotomy.png"),
		};

	};
}
#endif // BASEACTION_H
