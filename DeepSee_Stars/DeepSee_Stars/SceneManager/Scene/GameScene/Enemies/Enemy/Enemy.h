#ifndef ENEMY_H_
#define ENEMY_H_

#include "GameObject.h"
#include "../../Enum/Direction.h"
#include "BaseEnemyAction/BaseEnemyAction.h"

namespace deepseestars
{
	/// <summary>
	/// 視界の危険度
	/// </summary>
	enum Visibility
	{
		NORMAL,
		ATTENTION,
		DANGER
	};

	/// <summary>
	/// 敵クラス
	/// </summary>
	class Enemy :public GameObject
	{
	public:
		Enemy(const D3DXVECTOR2& playerPos, const std::vector<const TCHAR*>& textureKeys,
			  const D3DXVECTOR2& DistanceToOrigin,Visibility visibility,
			  EnemyMovingData movingData, const float& cellSize);

		~Enemy()
		{
			Release();
		}

		void Init();
		void Update();
		void Render();
		void Release();

		void MoveDestIfCanMove();

		inline void SetExistsPlayer(bool existsPlayer) { m_existsPlayer = existsPlayer; }
		inline void SetDirection(Direction direction)  { m_translationData.m_direction = direction; }
		inline void SetCanMove(bool canMove) { m_canMove = canMove; }
		inline void SetPos(D3DXVECTOR2 pos) { m_translationData.m_pos = pos; }

		inline Direction   GetDirection()  { return m_translationData.m_direction; }
		inline Visibility  GetVisibility() { return m_visibility; }
		inline D3DXVECTOR2 GetChaseVec()   { return m_chaseVec; }
		inline D3DXVECTOR2 GetDestination() { return m_translationData.m_pos + m_translationData.m_movement; }
		inline BaseEnemyAction::TranslationData GetTranslationData() { return m_translationData; }

	private:
		/// <summary>
		/// プレイヤーを追いかける
		/// </summary>
		void ChasePlayer();

		/// <summary>
		/// 方向を決める
		/// </summary>
		void DecideDirection();

		/// <summary>
		/// 巡回パターンを決める
		/// </summary>
		/// <param name="movingData">敵の動きを決めるデータが入っている構造体</param>
		/// <remarks>コンストラクタでしか使わない</remarks>
		void DecideActionPattern(const EnemyMovingData& movingData);

		const D3DXVECTOR2& m_playerPos;
		const D3DXVECTOR2& m_distanceToOrigin;
		const float& m_cellSize;

		Visibility m_visibility;
		BaseEnemyAction::TranslationData m_translationData;

		BaseEnemyAction* m_pEnemyAction;
		const std::vector<const TCHAR*>& m_rTextureKeys;

		D3DXVECTOR2 m_chaseVec;

		bool m_existsPlayer;
		bool m_canMove;
	};
}

#endif // !ENEMY_H_
