#include "ColorBlender.h"

namespace graphics
{
	void ColorBlender::DefaultColorBlending() const
	{
		DefaultBlendMode();
		m_DXGraphicDevice->GetGraphicDevice()->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
		m_DXGraphicDevice->GetGraphicDevice()->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
		m_DXGraphicDevice->GetGraphicDevice()->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
		m_DXGraphicDevice->GetGraphicDevice()->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATEREQUAL);
		m_DXGraphicDevice->GetGraphicDevice()->SetRenderState(D3DRS_ALPHAREF, 0x01);

		m_DXGraphicDevice->GetGraphicDevice()->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
		m_DXGraphicDevice->GetGraphicDevice()->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
		
		m_DXGraphicDevice->GetGraphicDevice()->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
		m_DXGraphicDevice->GetGraphicDevice()->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
	}
}
