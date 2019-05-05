#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <tchar.h>

#include <d3dx9.h>

#include "../../Device/DirectXDevices/DirectXDevices.h"

namespace graphics
{
	/// <summary>
	/// DirectXのテクスチャ情報を隠蔽したクラス
	/// </summary>
	class Texture
	{
	public:
		Texture() :m_graphicDevice(device::DirectXDevices::GetDXGraphicDevice()) {}
		~Texture() {}
	
		/// <summary>
		/// テクスチャの生成
		/// </summary>
		/// <param name="pKey">テクスチャのキーワード</param>
		/// <param name="pTexPath">テクスチャのファイルパス</param>
		void CreateTex(const TCHAR* pKey, const TCHAR* pTexPath);

		/// <summary>
		/// テクスチャの解放
		/// </summary>
		void Release()
		{
			m_texture->Release();
		}

		inline LPDIRECT3DTEXTURE9 GetTex()
		{
			return m_texture;
		}

	private:
		device::DirectXGraphicDevice* m_graphicDevice;
		LPDIRECT3DTEXTURE9 m_texture;
	};
}

#endif // !TEXTURE_H_
