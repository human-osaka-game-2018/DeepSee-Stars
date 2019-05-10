#include "TitleMenu.h"

#include "../../SceneManager/SceneManager.h"

namespace deepseestars
{
	void TitleMenu::Update()
	{
		m_rGameBaseMaker.LoopStart(m_pSoundKey);

		if (!m_rGameBaseMaker.IsPressedToKeyboard(DIK_RETURN)) return;

		SceneManager& rSceneManager = SceneManager::GetInstance();
		rSceneManager.SetNextScene(SceneManager::SCENE_ID::GAME);
	}

	void TitleMenu::Render()
	{
		D3DXVECTOR2 pos =
		{ m_vertices.GetDisplaySize().x * 0.5f ,m_vertices.GetDisplaySize().y * 0.75f };
		D3DXVECTOR2 scale = m_vertices.GetDisplaySize() * 0.15f;

		m_vertices.SetPos(pos);
		m_vertices.SetScale(scale);

		const int FLASH_FRAME = 120;

		m_vertices.Flash(0xff, 0x00, FLASH_FRAME);

		m_rGameBaseMaker.Render(m_vertices, m_rGameBaseMaker.GetTex(m_pTextureKey));
	}
}
