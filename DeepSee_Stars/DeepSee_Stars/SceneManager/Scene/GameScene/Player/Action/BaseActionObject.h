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
			for (int i = 0;i < 5;i++)
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
		const TCHAR* m_actionTextureKey[5] =
		{
			_T("AutotomyObject"),
			_T("AvatarObject"),
			_T("PlayerLeft"),
			_T("PlayerRight"),
			_T("PlayerUp"),
		};
		const TCHAR* m_actionTextureName[5] =
		{
			_T("2DTexture/Game/Autotomy.png"),
			_T("2DTexture/Game/Player/PlayerReadyAction.png"),
			_T("2DTexture/Game/Player/PlayerLeft.png"),
			_T("2DTexture/Game/Player/PlayerRight.png"),
			_T("2DTexture/Game/Player/PlayerUp.png"),
		};

	};
}
#endif // BASEACTIONOBJECT_H
