#include "Bubbles.h"

#include <random>

namespace deepseestars
{
	using std::uniform_real_distribution;

	void Bubbles::Update()
	{
		for (auto& bubble : m_bubbles)
		{
			if (bubble->GetPos().y < 0.f) bubble->Init();

			bubble->Update();
		}
	}

	void Bubbles::Render()
	{
		for (auto& bubble : m_bubbles)
		{
			bubble->Render();
		}
	}

	void Bubbles::Release()
	{
		for (auto& bubble : m_bubbles)
		{
			delete bubble;
			bubble = nullptr;
		}

		m_bubbles.clear();
		m_bubbles.shrink_to_fit();
	}

	void Bubbles::Create()
	{
		const int BUBBLE_NUM = 15;
		for (int i = 0; i < BUBBLE_NUM; ++i)
		{
			m_bubbles.push_back(new Bubble(m_pTextureKey));
		}
	}

	void Bubbles::Bubble::Init()
	{
		std::random_device seed;
		std::mt19937 randGenerator(seed());

		D3DXVECTOR2 displaySize = m_vertices.GetDisplaySize();

		//出現位置の設定
		uniform_real_distribution<float> distPosX(0.f, displaySize.x);
		uniform_real_distribution<float> distPosY(displaySize.y * 0.5f, displaySize.y);
		m_pos = { distPosX(randGenerator),distPosY(randGenerator) };
		
		//泡の大きさの設定
		uniform_real_distribution<float> distScaleSize(3.f, 6.f);
		m_scaleSize = distScaleSize(randGenerator);
		
		//初期角度の設定
		uniform_real_distribution<float> distRad(0.f, 4.f * D3DX_PI);
		m_rad = distRad(randGenerator);

		//振動スピードの設定
		uniform_real_distribution<float> distVibrationSpeed(0.01f, 0.05f);
		m_vibrationSpeed = distVibrationSpeed(randGenerator);

		//浮力の設定
		uniform_real_distribution<float> distBuoyancy(1.f, 1.3f);
		m_buoyancy = distBuoyancy(randGenerator);

		m_vertices.InitFadeInCount();
	}

	void Bubbles::Bubble::Update()
	{
		m_pos.x += 0.3f * sin(m_rad += m_vibrationSpeed);
		m_pos.y -= m_buoyancy;
	}

	void Bubbles::Bubble::Render()
	{
		m_vertices.SetPos(m_pos);
		m_vertices.SetScale(D3DXVECTOR2(m_scaleSize, m_scaleSize));
		m_vertices.FadeIn(0x8F, 0x00, 120);
		m_rGameBaseMaker.Render(m_vertices, m_rGameBaseMaker.GetTex(m_pTextureKey));
	}
}
