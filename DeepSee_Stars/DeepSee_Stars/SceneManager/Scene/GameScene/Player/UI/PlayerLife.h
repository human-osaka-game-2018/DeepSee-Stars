#ifndef PLAYERLIFE_H
#define PLAYERLIFE_H

#include "GameObject.h"

namespace deepseestars
{
	class PlayerLife : public GameObject
	{
	public:
		PlayerLife(int& playerLife) : GameObject(), m_playerLife(playerLife)
		{
			Init();
		}

		~PlayerLife() {};

		void Init()
		{
			for (int i = 0;i <= 7;i++)
			{
				m_rGameBaseMaker.CreateTex(m_LifeUITextureKey[i], m_LifeUITextureName[i]);
			}

		}

		void Update();

		void Render();

		void Release()
		{
			m_rGameBaseMaker.ReleaseAllTex();
		}

	private:
		const TCHAR* m_LifeUITextureKey[7] =
		{
			_T("LifeFrame"),
			_T("LifeNumber0"),
			_T("LifeNumber1"),
			_T("LifeNumber2"),
			_T("LifeNumber3"),
			_T("LifeNumber4"),
			_T("LifeNumber5"),
		};
		const TCHAR* m_LifeUITextureName[7] =
		{
			_T("2DTexture/Game/UI/LifeFrame.png"),
			_T("2DTexture/Game/UI/Number0.png"),
			_T("2DTexture/Game/UI/Number1.png"),
			_T("2DTexture/Game/UI/Number2.png"),
			_T("2DTexture/Game/UI/Number3.png"),
			_T("2DTexture/Game/UI/Number4.png"),
			_T("2DTexture/Game/UI/Number5.png"),
		};

		int& m_playerLife;
	};
}

#endif // PLAYERLIFE_H
