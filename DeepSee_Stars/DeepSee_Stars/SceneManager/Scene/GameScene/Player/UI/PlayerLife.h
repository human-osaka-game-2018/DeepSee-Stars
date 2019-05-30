#ifndef PLAYERLIFE_H
#define PLAYERLIFE_H

#include "GameObject.h"

namespace deepseestars
{
	class PlayerLife : public GameObject
	{
	public:
		PlayerLife() : GameObject()
		{
			Init();
		}

		~PlayerLife() 
		{
			Release();
		}

		void Init()
		{
			m_life = 5;
			for (auto& number : m_LifeUITextureKey)
			{
				int index = &number - m_LifeUITextureKey;

				m_rGameBaseMaker.CreateTex(m_LifeUITextureKey[index], m_LifeUITextureName[index]);
			}
		}

		void Update();

		void Render();

		void Release()
		{
			m_rGameBaseMaker.ReleaseAllTex();
		}

		int GetLife()
		{
			return m_life;
		}
		void SetLife(int life)
		{
			m_life = life;
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

		int m_life;
	};
}

#endif // PLAYERLIFE_H
