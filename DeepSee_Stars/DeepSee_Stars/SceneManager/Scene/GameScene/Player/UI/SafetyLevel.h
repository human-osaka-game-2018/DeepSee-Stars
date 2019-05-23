#ifndef SAFETYLIFE_H
#define SAFETYLIFE_H

#include "GameObject.h"
#include "../DirectionID.h"

namespace deepseestars
{
	class SafetyLevel : public GameObject
	{
	public:
		SafetyLevel(int& safetyLevel,const Direction& playerDirection, const bool& isPlayerHideState, const bool& isPlayerInTheSeaWeed) :
			GameObject(), m_safetyLevel(safetyLevel), m_playerDirection(playerDirection), m_isPlayerHideState(isPlayerHideState), m_isPlayerInTheSeaWeed(isPlayerInTheSeaWeed)
		{
			Init();
		}

		~SafetyLevel() {};

		void Init()
		{
			for (int i = 0;i <= 11;i++)
			{
				m_rGameBaseMaker.CreateTex(m_SafetyLevelUITextureKey[i], m_SafetyLevelUITextureName[i]);
			}

		}

		void Update();

		void Render();

		void Release()
		{
			m_rGameBaseMaker.ReleaseAllTex();
		}

	private:
		const TCHAR* m_SafetyLevelUITextureKey[11] =
		{
			_T("SafetyLevel0"),
			_T("SafetyLevel1"),
			_T("SafetyLevel2"),
			_T("SafetyLevel3"),
			_T("SafetyLevel4"),
			_T("SafetyLevel5"),
			_T("SafetyLevel6"),
			_T("SafetyLevel7"),
			_T("SafetyLevel8"),
			_T("SafetyLevel9"),
			_T("SafetyLevelFrame"),
		};
		const TCHAR* m_SafetyLevelUITextureName[11] =
		{
			_T("2DTexture/Game/UI/Number0.png"),
			_T("2DTexture/Game/UI/Number1.png"),
			_T("2DTexture/Game/UI/Number2.png"),
			_T("2DTexture/Game/UI/Number3.png"),
			_T("2DTexture/Game/UI/Number4.png"),
			_T("2DTexture/Game/UI/Number5.png"),
			_T("2DTexture/Game/UI/Number6.png"),
			_T("2DTexture/Game/UI/Number7.png"),
			_T("2DTexture/Game/UI/Number8.png"),
			_T("2DTexture/Game/UI/Number9.png"),
			_T("2DTexture/Game/UI/SafetyLevelFrame.png"),
		};

		int& m_safetyLevel;
		const Direction& m_playerDirection;
		const bool& m_isPlayerHideState;
		const bool& m_isPlayerInTheSeaWeed;

		void NaturalRise();
		void OverflowGuard();
	};
}

#endif // SAFETYLIFE_H
