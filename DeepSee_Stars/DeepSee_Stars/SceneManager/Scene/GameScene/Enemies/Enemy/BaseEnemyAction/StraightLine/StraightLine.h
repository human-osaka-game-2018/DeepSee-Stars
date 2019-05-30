#ifndef STRAIGHT_LINE_H_
#define STRAIGHT_LINE_H_

#include "../../BaseEnemyAction/BaseEnemyAction.h"

namespace deepseestars
{
	/// <summary>
	/// 直線上に移動するクラス
	/// </summary>
	class StraightLine :public BaseEnemyAction
	{
	public:
		/// <summary>
		/// 敵の動きの情報を受け渡すコンストラクタ
		/// </summary>
		/// <param name="translationData">敵の動きのデータ構造体</param>
		/// <param name="movingData">初期位置や目的地のデータ構造体</param>
		StraightLine(TranslationData& translationData, const EnemyMovingData& movingData) :
			BaseEnemyAction(translationData, movingData.m_initPos, movingData.m_movingPos)
		{
			Init();
		}

		~StraightLine() {}

		void Init();
		void Update();

	private:
		D3DXVECTOR2 m_dest[2] =
		{
			m_initPos,
			m_movingRange
		};
	};
}

#endif // !STRAIGHT_LINE_H_
