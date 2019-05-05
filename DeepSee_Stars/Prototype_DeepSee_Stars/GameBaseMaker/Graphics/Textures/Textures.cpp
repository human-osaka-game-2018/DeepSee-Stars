#include "Textures.h"

namespace graphics
{
	void Textures::CreateTex(const TCHAR* pKey, const TCHAR* pTexPath)
	{
		if (Exists(pKey)) return;

		m_textures[pKey].CreateTex(pKey, pTexPath);
	}

	void Textures::EraseTex(const TCHAR* pKey)
	{
		if (!Exists(pKey)) return;

		m_textures[pKey].Release();
		m_textures.erase(pKey);
	}

	void Textures::ReleaseAllTex()
	{
		if (!m_textures.size()) return;

		for(auto texture : m_textures)
		{
			(texture.second).Release();
		}

		m_textures.clear();
	}

	bool Textures::Exists(const TCHAR* pKey)
	{
		return (m_textures.find(pKey) != m_textures.end());
	}
}
