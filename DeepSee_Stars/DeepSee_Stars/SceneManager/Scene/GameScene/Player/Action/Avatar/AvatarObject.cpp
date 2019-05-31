#include "AvatarObject.h"


namespace deepseestars
{

	void AvatarObject::Update()
	{
		D3DXVECTOR2 centerBuf = m_center + m_distanceToOrigin;
		D3DXVECTOR2 pos = { centerBuf.x ,centerBuf.y - m_ObjectSize / 4 };

		m_vertices.SetPos(pos);
	}

	void AvatarObject::Render()
	{
		switch (m_direction)
		{
		case LEFT:
			m_pTextureKey = GetactionTextureKey()[2];
			break;
		case RIGHT:
			m_pTextureKey = GetactionTextureKey()[3];
			break;
		case UP:
			m_pTextureKey = GetactionTextureKey()[4];
			break;
		case DOWN:
			m_pTextureKey = GetactionTextureKey()[1];
			break;
		case STAYING:
			m_pTextureKey = GetactionTextureKey()[1];
			break;
		}
		m_rGameBaseMaker.Render(m_vertices, m_rGameBaseMaker.GetTex(m_pTextureKey));
	}
}
