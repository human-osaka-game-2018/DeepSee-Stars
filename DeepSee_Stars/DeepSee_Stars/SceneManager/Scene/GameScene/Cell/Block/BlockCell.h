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


	const float BLOCKSIZE = 50.f;

	class BlockCell : public GameObject
	{
	public:
		BlockCell(const D3DXVECTOR2& differencetoStartingPoint,D3DXVECTOR2 blockPos, TYPE blockType) :
			GameObject(_T("Block"), _T("2DTexture/Game/Floor.png")), m_differencetoStartingPoint(differencetoStartingPoint), m_blockCenterPos(blockPos), m_blockType(blockType)
		{
			Init();
		}

		~BlockCell(){}

		void Init()
		{
			m_rGameBaseMaker.CreateTex(m_pTextureKey, m_pFileName);
			m_rGameBaseMaker.CreateTex(m_pTextureKey, m_pFileName);
		}

		void Update();

		void Render();

		void Release()
		{
			m_rGameBaseMaker.ReleaseAllTex();
		}

		D3DXVECTOR2 m_blockCenterPos;
		TYPE m_blockType;
	private:
		const D3DXVECTOR2& m_differencetoStartingPoint;
		const TCHAR* m_block[PlAYER_RECOVERY_OBJECT + 1];
	};
}

#endif // BLOCKCELL_H
