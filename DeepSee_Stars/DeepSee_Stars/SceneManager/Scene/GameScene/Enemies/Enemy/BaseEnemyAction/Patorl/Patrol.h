#ifndef PATROL_H_
#define PATROL_H_

#include "../BaseEnemyAction.h"

namespace deepseestars
{
	/// <summary>
	/// 4方向の点を巡回するパターンクラス
	/// </summary>
	class Patrol :public BaseEnemyAction
	{
	public:
		/// <summary>
		/// 敵の動きの情報を受け渡すコンストラクタ
		/// </summary>
		/// <param name="translationData">敵の動きのデータ構造体</param>
		/// <param name="movingData">初期位置や目的地のデータ構造体</param>
		Patrol(TranslationData& translationData,const EnemyMovingData& movingData) :
			BaseEnemyAction(translationData, movingData.m_initPos, movingData.m_movingPos)
		{
			Init(movingData.m_isClockWise);
		}

		~Patrol() {}

		/// <summary>
		/// デキューの初期化
		/// </summary>
		/// <param name="isClockWise"></param>
		void Init(bool isClockWise);

		/// <summary>
		/// 更新処理
		/// </summary>
		void Update();

	private:
		//目的地の座標
		D3DXVECTOR2 m_dest[4] =
		{
			m_initPos,
			{m_movingRange.x, m_initPos.y},
			m_movingRange,
			{m_initPos.x, m_movingRange.y}
		};
	};
}

#endif // !PATROL_H_
