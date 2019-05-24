#ifndef L_SHAPED_H_
#define L_SHAPED_H_

#include "../BaseEnemyAction.h"

namespace deepseestars
{
	/// <summary>
	/// L字の点を巡回するクラス
	/// </summary>
	class L_Shaped :public BaseEnemyAction
	{
	public:
		/// <summary>
		/// 敵の動きの情報を受け渡すコンストラクタ
		/// </summary>
		/// <param name="translationData">敵の動きのデータ構造体</param>
		/// <param name="movingData">初期位置や目的地のデータ構造体</param>
		L_Shaped(TranslationData& translationData, const EnemyMovingData& movingData) :
			BaseEnemyAction(translationData, movingData.m_initPos, movingData.m_movingPos)
		{
			Init();
		}

		~L_Shaped() {}

		/// <summary>
		/// デキューの初期化
		/// </summary>
		void Init();

		/// <summary>
		/// 更新関数
		/// </summary>
		void Update();

	private:
		//目的地の座標
		D3DXVECTOR2 m_dest[3] =
		{
			{m_initPos.x,m_movingRange.y},
			m_initPos,
			{m_movingRange.x,m_initPos.y}
		};
	};
}

#endif // !L_SHAPED_H_
