#ifndef COLOR_BLENDER_H_
#define COLOR_BLENDER_H_

#include "../../../Device/DirectXDevices/DirectXDevices.h"

namespace graphics
{
	class ColorBlender
	{
	public:
		ColorBlender() :m_DXGraphicDevice(device::DirectXDevices::GetDXGraphicDevice()) 
		{
			m_DXGraphicDevice->GetGraphicDevice()->SetRenderState(D3DRS_ZENABLE, TRUE);
			DefaultColorBlending();
		}

		~ColorBlender() {}

		/// <summary>
		/// 色の合成を通常合成に変更する デフォルトでは通常合成になっている
		/// </summary>
		inline void DefaultBlendMode() const
		{
			m_DXGraphicDevice->GetGraphicDevice()->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
		}

		/// <summary>
		/// 色の合成を加算合成に変更する
		/// </summary>
		inline void AddtionBlendMode() const
		{
			m_DXGraphicDevice->GetGraphicDevice()->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);
		}

		/// <summary>
		/// デフォルトの色合成を使用する ウィンドウモードを切り替えた時には再設定する必要がある
		/// </summary>
		void DefaultColorBlending() const;

	private:
		device::DirectXGraphicDevice* m_DXGraphicDevice;
	};
}

#endif // !COLOR_BLENDER_H_
