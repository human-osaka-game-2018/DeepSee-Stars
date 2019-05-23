#ifndef PATROL_H_
#define PATROL_H_

#include "../BaseEnemyAction.h"

namespace deepseestars
{
	class Patrol :public BaseEnemyAction
	{
	public:
		Patrol(TranslationData& translationData,const EnemyMovingData& movingData) :
			BaseEnemyAction(translationData, movingData.m_initPos, movingData.m_movingPos)
		{
			Init(movingData.m_isClockWise);
		}

		~Patrol() {}

		void Init(bool isClockWise);
		void Update();

	private:
		/// <summary>
		/// 巡回順路を決める
		/// </summary>
		void DesideRoute();

		/// <summary>
		/// 動かす
		/// </summary>
		void Move();

		//向かう座標
		D3DXVECTOR2 m_distinations[4];

		//移動する前の座標
		D3DXVECTOR2 m_beginToMovePoint[4];

		//回る方向を決める
		Direction m_nextDirection[4];
	};
}

#endif // !PATROL_H_
