#ifndef CUSTOM_VERTICES_H_
#define CUSTOM_VERTICES_H_

#include <d3dx9.h>

#include "../Color/Color.h"
#include "../TextureUV/TextureUV.h"

namespace gamebasemaker
{
	struct CustomVertex
	{
	public:
		D3DXVECTOR3 m_pos;

		float m_rHW = 1.0f;

		DWORD m_aRGB = 0xFFFFFFFF;

		D3DXVECTOR2 m_texUV;
	};

	class CustomVertices
	{
	public:
		CustomVertices() {}
		~CustomVertices() {}

		void BuildRect(const D3DXVECTOR3& center, const D3DXVECTOR2& scale,
			const D3DXVECTOR3& degree, Color color, TextureUV uv);

		void Rescale(const D3DXVECTOR2& scale);

		void RotateX(const float& degree, const D3DXVECTOR3& center);
		void RotateY(const float& degree, const D3DXVECTOR3& center);
		void RotateZ(const float& degree, const D3DXVECTOR3& center);

		void SetColor(Color color);

		void SetTextureUV(TextureUV uv);

		inline CustomVertex* Get()
		{
			return m_vertices;
		}

	private:
		void Rotate(const D3DXVECTOR3& center, const D3DXMATRIX& rotate);

		static const int m_RECT_VERTICES_NUM;
		CustomVertex m_vertices[4];
	};
}

#endif // !CUSTOM_VERTICES_H_
