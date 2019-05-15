#ifndef BLOCKCELL_H
#define BLOCKCELL_H

#include "GameObject.h"
#include <vector>

namespace deepseestars
{
	enum TYPE
	{
		FLOOR,
		WHITE_BLOCK,
		BLACK_BLOCK,
		HIDE_BLOCK,
		PlAYER_RECOVERY_OBJECT,
	};


	class BlockCell : public GameObject
	{
	public:
		BlockCell(const D3DXVECTOR2& distanceToOrigin,D3DXVECTOR2 blockPos, TYPE blockType, const float& blockSize,const TCHAR* TextureKey) :
			GameObject(TextureKey), m_distanceToOrigin(distanceToOrigin), m_center(blockPos), m_type(blockType),m_blockSize(blockSize)
		{
			Init();
		}

		~BlockCell(){}

		void Init()
		{
			
		}

		void Update();

		void Render();

		void Release()
		{
			m_rGameBaseMaker.ReleaseAllTex();
		}

		D3DXVECTOR2 Getcenter()
		{
			return m_center;
		}
		void Setcenter(D3DXVECTOR2 center)
		{
			m_center = center;
		}

		TYPE Gettype()
		{
			return m_type;
		}
		void Settype(TYPE type)
		{
			m_type = type;
		}
	private:
		const D3DXVECTOR2& m_distanceToOrigin;
		const float& m_blockSize;

		D3DXVECTOR2 m_center;
		TYPE m_type;
		bool m_isWithinRenderArea = false;
	};
}

#endif // BLOCKCELL_H
