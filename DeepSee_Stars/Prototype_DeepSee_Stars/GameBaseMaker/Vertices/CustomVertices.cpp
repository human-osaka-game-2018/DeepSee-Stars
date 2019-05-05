#include "CustomVertices.h"

namespace gamebasemaker
{
	const int CustomVertices::m_RECT_VERTICES_NUM = 4;

	void CustomVertices::BuildRect(const D3DXVECTOR3& center, const D3DXVECTOR2& scale,
		const D3DXVECTOR3& degree, Color color, TextureUV uv)
	{
		for (int i = 0; i < m_RECT_VERTICES_NUM; ++i)
		{
			m_vertices[i].m_pos.x = (i == 0 || i == 3) ? center.x - scale.x : center.x + scale.x;
			m_vertices[i].m_pos.y = (i == 0 || i == 1) ? center.y - scale.y : center.y + scale.y;
			m_vertices[i].m_pos.z = center.z;

			m_vertices[i].m_aRGB = color.GetColorCord();
			m_vertices[i].m_texUV.x = (i == 0 || i == 3) ? uv.GetStartUV().x : uv.GetEndUV().x;
			m_vertices[i].m_texUV.y = (i == 0 || i == 1) ? uv.GetStartUV().y : uv.GetEndUV().y;
		}

		RotateX(degree.x, center);
		RotateY(degree.y, center);
		RotateZ(degree.z, center);
	}

	void CustomVertices::Rescale(const D3DXVECTOR2& scale)
	{
		D3DXVECTOR2 rectCenter(
			(m_vertices[0].m_pos.x + m_vertices[2].m_pos.x) * 0.5f,
			(m_vertices[0].m_pos.y + m_vertices[2].m_pos.y) * 0.5f);

		D3DXVECTOR2 distancesVertexBetweenCenter[m_RECT_VERTICES_NUM];

		for (int i = 0; i < m_RECT_VERTICES_NUM; ++i)
		{
			distancesVertexBetweenCenter[i].x = m_vertices[i].m_pos.x - rectCenter.x;
			distancesVertexBetweenCenter[i].y = m_vertices[i].m_pos.y - rectCenter.y;
		};

		for (int i = 0; i < m_RECT_VERTICES_NUM; ++i)
		{
			m_vertices[i].m_pos.x = scale.x*distancesVertexBetweenCenter[i].x + rectCenter.x;
			m_vertices[i].m_pos.y = scale.y*distancesVertexBetweenCenter[i].y + rectCenter.y;
		}
	}

	void CustomVertices::RotateX(const float& degree, const D3DXVECTOR3& center)
	{
		if (degree == 0) return;

		D3DXMATRIX rotate;
		D3DXMatrixRotationX(&rotate, D3DXToRadian(degree));
		Rotate(center, rotate);
	}

	void CustomVertices::RotateY(const float& degree, const D3DXVECTOR3& center)
	{
		if (degree == 0) return;

		D3DXMATRIX rotate;
		D3DXMatrixRotationY(&rotate, D3DXToRadian(degree));
		Rotate(center, rotate);
	}

	void CustomVertices::RotateZ(const float& degree, const D3DXVECTOR3& center)
	{
		if (degree == 0) return;

		D3DXMATRIX rotate;
		D3DXMatrixRotationZ(&rotate, D3DXToRadian(degree));
		Rotate(center, rotate);
	}

	void CustomVertices::Rotate(const D3DXVECTOR3& center, const D3DXMATRIX& rotate)
	{
		D3DXVECTOR3 rectCenter(										//対角線によってすでに回転が行われているものの中心も割り出せる
			(m_vertices[0].m_pos.x + m_vertices[2].m_pos.x) * 0.5f,
			(m_vertices[0].m_pos.y + m_vertices[2].m_pos.y) * 0.5f,
			(m_vertices[0].m_pos.z + m_vertices[2].m_pos.z) * 0.5f);

		D3DXVECTOR3 verticesRectCenterToOri[m_RECT_VERTICES_NUM];	//回転の中心は必ずしも矩形の中心ではない
		
		for (int i = 0; i < m_RECT_VERTICES_NUM; ++i)
		{
			verticesRectCenterToOri[i].x = m_vertices[i].m_pos.x - rectCenter.x;
			verticesRectCenterToOri[i].y = m_vertices[i].m_pos.y - rectCenter.y;
			verticesRectCenterToOri[i].z = m_vertices[i].m_pos.z - rectCenter.z;
		};

		D3DXVECTOR3 verticesRotateCenterToOri[m_RECT_VERTICES_NUM];
		for (int i = 0; i < m_RECT_VERTICES_NUM; ++i)
		{
			verticesRotateCenterToOri[i].x = verticesRectCenterToOri[i].x - center.x;
			verticesRotateCenterToOri[i].y = verticesRectCenterToOri[i].y - center.y;
			verticesRotateCenterToOri[i].z = verticesRectCenterToOri[i].z - center.z;
		};

		for (int i = 0; i < m_RECT_VERTICES_NUM; ++i)
		{
			D3DXVec3TransformCoord(
				&m_vertices[i].m_pos,
				&verticesRotateCenterToOri[i],
				&rotate);

			D3DXVec3Add(
				&m_vertices[i].m_pos,
				&m_vertices[i].m_pos,
				&rectCenter);

			D3DXVec3Add(
				&m_vertices[i].m_pos,
				&m_vertices[i].m_pos,
				&center);
		}
	}

	void CustomVertices::SetColor(Color color)
	{
		for (auto& vertex : m_vertices)
		{
			vertex.m_aRGB = color.GetColorCord();
		}
	}

	void CustomVertices::SetTextureUV(TextureUV uv)
	{
		for (int i = 0; i < m_RECT_VERTICES_NUM; ++i)
		{
			m_vertices[i].m_texUV = (i == 0 || i == 3) ? uv.GetStartUV() : uv.GetEndUV();
		}
	}
}
