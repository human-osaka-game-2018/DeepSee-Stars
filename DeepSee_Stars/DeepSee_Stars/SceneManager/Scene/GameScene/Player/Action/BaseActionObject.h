#ifndef BASEACTIONOBJECT_H
#define BASEACTIONOBJECT_H

#include "GameObject.h"

namespace deepseestars
{
	class BaseActionObject : public GameObject
	{
	public:
		BaseActionObject() : GameObject()
		{
			Init();
		}

		virtual ~BaseActionObject()
		{
			Release();
		}

		virtual void Init()
		{
			for (auto& number : m_actionTextureKey)
			{
				int index = &number - m_actionTextureKey;

				m_rGameBaseMaker.CreateTex(m_actionTextureKey[index], m_actionTextureName[index]);
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
#endif // BASEACTIONOBJECT_H
