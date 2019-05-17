﻿#include "BlockCell.h"

namespace deepseestars
{

	void BlockCell::Update()
	{

	}

	void BlockCell::Render()
	{
		D3DXVECTOR2 centerBuf = m_center + m_distanceToOrigin;

		D3DXVECTOR2 pos = { centerBuf.x ,centerBuf.y };
		D3DXVECTOR2 scale = { m_blockSize/2 ,m_blockSize/2 };

		m_vertices.SetPos(pos);
		m_vertices.SetScale(scale);

		bool InRangeX = -m_blockSize <= centerBuf.x && centerBuf.x <= m_vertices.GetDisplaySize().x + m_blockSize;
		bool InRangeY = -m_blockSize <= centerBuf.y && centerBuf.y <= m_vertices.GetDisplaySize().y + m_blockSize;
		
		if (InRangeX && InRangeY)
		{
			m_isWithinRenderArea = true;
		}
		else
		{
			m_isWithinRenderArea = false;
		}

		if (!m_isWithinRenderArea) return;

		m_rGameBaseMaker.Render(m_vertices, m_rGameBaseMaker.GetTex(m_pTextureKey));
	}
}
