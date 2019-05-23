#ifndef BASE_ENEMY_ACTION_H_
#define BASE_ENEMY_ACTION_H_

#include <d3dx9.h>

#include "../../../Enum/Direction.h"

namespace deepseestars
{
	enum ActionPattern
	{
		PATROL,
		L_SHAPED,
		STRAIGHTLINE,
		DONTMOVE
	};

	/// <summary>
	/// 敵の初期位置や移動範囲などの最初に必要なデータをまとめた構造体
	/// </summary>
	struct EnemyMovingData
	{
	public:
		D3DXVECTOR2		m_initPos;			//初期位置
		D3DXVECTOR2		m_movingPos;		//移動できる最大範囲
		ActionPattern	m_actionPattern;	//行動パターン
		bool			m_isClockWise;		//時計回りで巡回するか
	};

	/// <summary>
	/// 敵の巡回パターンの基底クラス
	/// </summary>
	class BaseEnemyAction
	{
	public:
		/// <summary>
		/// 敵の移動に関する情報をまとめた構造体
		/// </summary>
		struct TranslationData
		{
		public:
			D3DXVECTOR2   m_pos;
			D3DXVECTOR2   m_speed = { 10.f,10.f };
			D3DXVECTOR2   m_movement;
			Direction     m_direction;			
		};

		BaseEnemyAction(TranslationData& translationData,
			const D3DXVECTOR2& initPos, const D3DXVECTOR2& movingRange) :
			m_translationData(translationData),
			m_initPos(initPos), m_movingRange(movingRange)
		{}
		
		~BaseEnemyAction() {}

		virtual void Update() = 0;

	protected:
		TranslationData& m_translationData;

		D3DXVECTOR2 m_movingRange;
		const D3DXVECTOR2 m_initPos;

		bool m_isMoving;
	};
}

#endif // !BASE_ENEMY_ACTION_H_
