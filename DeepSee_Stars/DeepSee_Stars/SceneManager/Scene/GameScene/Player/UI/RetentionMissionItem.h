#ifndef RETENTIONMISSIONITEM_H_
#define RETENTIONMISSIONITEM_H_

#include "GameObject.h"

namespace deepseestars
{
	class RetentionMissionItem : public GameObject
	{
	public:
		RetentionMissionItem(int& missionItem) : GameObject(), m_missionItem(missionItem)
		{
			Init();
		}

		~RetentionMissionItem() 
		{
			Release();
		}

		void Init()
		{
			for (int i = 0;i < 6;i++)
			{
				m_rGameBaseMaker.CreateTex(m_MissionItemUITextureKey[i], m_MissionItemUITextureName[i]);
			}
		}

		void Update();

		void Render();

		void Release()
		{
			m_rGameBaseMaker.ReleaseAllTex();
		}

	private:
		const TCHAR* m_MissionItemUITextureKey[6] =
		{
			_T("MissionItemFrame"),
			_T("MissionItemNumber0"),
			_T("MissionItemNumber1"),
			_T("MissionItemNumber2"),
			_T("MissionItemNumber3"),
			_T("MissionItemNumber4"),
		};
		const TCHAR* m_MissionItemUITextureName[6] =
		{
			_T("2DTexture/Game/UI/MissionFrame.png"),
			_T("2DTexture/Game/UI/Number0.png"),
			_T("2DTexture/Game/UI/Number1.png"),
			_T("2DTexture/Game/UI/Number2.png"),
			_T("2DTexture/Game/UI/Number3.png"),
			_T("2DTexture/Game/UI/Number4.png"),
		};

		int& m_missionItem;
	};
}

#endif // !RETENTIONMISSIONITEM_H_
