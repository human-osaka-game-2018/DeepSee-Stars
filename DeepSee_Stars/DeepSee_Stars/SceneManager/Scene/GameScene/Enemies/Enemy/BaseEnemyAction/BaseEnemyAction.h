#ifndef BASE_ENEMY_ACTION_H_
#define BASE_ENEMY_ACTION_H_

#include <deque>

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

		/// <summary>
		/// 巡回するためのデータを詰めるコンストラクタ
		/// </summary>
		/// <param name="translationData">敵クラスにある移動に関するデータの参照</param>
		/// <param name="initPos">動き始める視点座標</param>
		/// <param name="dest">目的地の絶対座標</param>
		BaseEnemyAction(TranslationData& translationData,
			const D3DXVECTOR2& initPos, const D3DXVECTOR2& dest) :
			m_translationData(translationData),
			m_initPos(initPos), m_movingRange(dest)
		{}
		
		~BaseEnemyAction() {}

		/// <summary>
		/// 敵の更新処理
		/// </summary>
		virtual void Update() = 0;

	protected:
		/// <summary>
		/// 座標の更新をする
		/// </summary>
		void UpdatePos()
		{
			m_translationData.m_speed = m_distance / m_MOVE_SPEED_FRAME;
			m_translationData.m_movement = m_translationData.m_speed;

			m_translationData.m_pos += m_translationData.m_movement;
		}

		/// <summary>
		/// 目的地に着いたときの処理
		/// </summary>
		void ArriveAtDestination(D3DXVECTOR2* pDest)
		{
			int currentDest = m_destQueue.front();
			D3DXVECTOR2 absSpeed = { fabsf(m_translationData.m_speed.x),fabsf(m_translationData.m_speed.y) };

			D3DXVECTOR2 topLeft = { pDest[currentDest].x - absSpeed.x,pDest[currentDest].y - absSpeed.y };
			D3DXVECTOR2 bottomRight = { pDest[currentDest].x + absSpeed.x,pDest[currentDest].y + absSpeed.y };

			//目的地の範囲内に入っていたら
			if (((topLeft.x <= m_translationData.m_pos.x) && (bottomRight.x >= m_translationData.m_pos.x)) &&
				((topLeft.y <= m_translationData.m_pos.y) && (bottomRight.y >= m_translationData.m_pos.y)))
			{
				m_translationData.m_pos = pDest[currentDest];

				//入れ替え処理
				m_destQueue.pop_front();
				m_destQueue.push_back(currentDest);

				//次の目的地の距離を算出する
				m_distance = pDest[m_destQueue.front()] - pDest[m_destQueue.back()];
			}
		}

		template<typename T>
		/// <summary>
		/// 2つの値をもらい、現在の値じゃないほうに反転させる
		/// </summary>
		/// <param name="lhs">左辺値</param>
		/// <param name="rhs">右辺値</param>
		/// <param name="currentValue">現在がどちらの辺の値か</param>
		/// <returns>反転させた値</returns>
		inline T ReverseValue(T lhs, T rhs, T currentValue)
		{
			return (lhs + rhs) - currentValue;
		}

		TranslationData& m_translationData;

		D3DXVECTOR2 m_movingRange;
		const D3DXVECTOR2 m_initPos;

		//どれだけのフレームで動くか
		const float m_MOVE_SPEED_FRAME = 120.f;

		D3DXVECTOR2 m_distance;		//距離(向きと大きさ)

		std::deque<int> m_destQueue;	//ルート探索のためのキュー
	};
}

#endif // !BASE_ENEMY_ACTION_H_
