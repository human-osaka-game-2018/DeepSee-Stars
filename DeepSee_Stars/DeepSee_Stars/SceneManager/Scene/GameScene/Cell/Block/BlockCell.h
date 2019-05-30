#ifndef BLOCKCELL_H
#define BLOCKCELL_H

#include "GameObject.h"
#include <vector>

namespace deepseestars
{
	enum TYPE
	{
		ERRORTYPE = -1,
		PLAYERINITPOS,//ヒトデの初期位置
		FLOOR,//床
		WHITE_BLOCK,//壁
		HIDE_BLOCK,//張り付き壁
		MISSION_ITEM,//ミッションで集めてクリアするアイテム
		PLAYER_RECOVERY_OBJECT,//サンゴ
		NONE6,//6番はなし
		NONE7,//7番はなし
		BLACK_BLOCK,
		NONE9,//9番はなし
		SEAWEED,//海藻
		GAMECLEARZONE = 50,//到達でゲームクリア
		MISSIONSTART_DESTINATIONS = 100,//通るとミッション開始してクリアするまで通れない
		MISSIONCLEARZONE_DESTINATIONS,//位置到達ミッションのクリア位置
		MISSIONSTART_GET3ITEMS,//3つアイテム入手ミッションのスタートライン
		MISSIONSTART_GET4ITEMS,//4つアイテム入手ミッションのスタートライン
		MISSIONSTART_SURVIVE2MINUTES,//2分間生存ミッションのスタートライン
		MISSIONSTART_SURVIVE3MINUTES,//2分間生存ミッションのスタートライン
	};


	class BlockCell : public GameObject
	{
	public:
		BlockCell(const D3DXVECTOR2& distanceToOrigin,D3DXVECTOR2 blockPos, TYPE blockType, const float& blockSize) :
			GameObject(), m_distanceToOrigin(distanceToOrigin), m_center(blockPos), m_type(blockType),m_blockSize(blockSize)
		{
			Init();
		}

		~BlockCell()
		{
			Release();
		}

		void Init()
		{
			
		}

		void Update();

		void Render();

		void Release(){}

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
