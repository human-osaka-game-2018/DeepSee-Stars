#include "Renderer.h"

namespace graphics
{
	Renderer::Renderer()
		:m_DXGraphicDevice(device::DirectXDevices::GetDXGraphicDevice())
	{

	}

	void Renderer::PrepareRendering()
	{
		 m_DXGraphicDevice->GetGraphicDevice()->Clear(
			0,
			NULL,
			D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
			D3DCOLOR_XRGB(0, 0, 0),					//画面をクリアするときの色
			1.f,
			0);

		 m_DXGraphicDevice->GetGraphicDevice()->BeginScene();
	}

	void Renderer::CleanUpRendering()
	{
		m_DXGraphicDevice->GetGraphicDevice()->EndScene();

		m_DXGraphicDevice->GetGraphicDevice()->Present(NULL, NULL, NULL, NULL);
	}

	void Renderer::Render(gamebasemaker::Vertices vertices, Texture texture)
	{
		m_DXGraphicDevice->GetGraphicDevice()->SetFVF(
			D3DFVF_XYZRHW |
			D3DFVF_DIFFUSE |
			D3DFVF_TEX1);

		m_DXGraphicDevice->GetGraphicDevice()->SetTexture(0, texture.GetTex());

		m_DXGraphicDevice->GetGraphicDevice()->DrawPrimitiveUP(
			D3DPT_TRIANGLEFAN,
			2,
			vertices.Get(), sizeof(gamebasemaker::CustomVertex));
	}
}
