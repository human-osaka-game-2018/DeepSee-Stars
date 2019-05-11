#include "Bubbles.h"

#include <random>

namespace deepseestars
{
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
		const int BUBBLE_NUM = 10;
		for (int i = 0; i < BUBBLE_NUM; ++i)
		{
			m_bubbles.push_back(new Bubble(m_pTextureKey));
		}
	}

	void Bubbles::Bubble::Init()
	{
		//ランダムで位置を決めている
		std::random_device rd;
		std::mt19937 mt(rd());

		std::uniform_real_distribution<float> randPosX(0.f, m_vertices.GetDisplaySize().x);
		std::uniform_real_distribution<float> randPosY(
			m_vertices.GetDisplaySize().y * 0.2f, m_vertices.GetDisplaySize().y);

		D3DXVECTOR2 appearPos = { randPosX(mt),randPosY(mt) };
		m_pos = appearPos;
	}

	void Bubbles::Bubble::Update()
	{
		//浮力
		const float BUOYANCY = 3.0f;

		m_pos.y -= BUOYANCY;
	}

	void Bubbles::Bubble::Render()
	{
		const float SCALE_SIZE = 16.f;

		m_vertices.SetPos(m_pos);
		m_vertices.SetScale(D3DXVECTOR2(SCALE_SIZE, SCALE_SIZE));
		m_rGameBaseMaker.Render(m_vertices, m_rGameBaseMaker.GetTex(m_pTextureKey));
	}
}
