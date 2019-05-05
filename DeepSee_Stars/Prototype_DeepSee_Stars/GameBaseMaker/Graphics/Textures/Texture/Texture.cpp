#include "Texture.h"

namespace graphics
{
	void Texture::CreateTex(const TCHAR* pKey, const TCHAR* pTexPath)
	{
		D3DXCreateTextureFromFile(
			m_graphicDevice->GetGraphicDevice(),
			pTexPath,
			&m_texture);
	}
}
