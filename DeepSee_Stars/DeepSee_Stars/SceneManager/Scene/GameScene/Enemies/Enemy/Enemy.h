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
		Enemy(const TCHAR* pTextureKey, const D3DXVECTOR2& playerPos,
			Visibility visibility, EnemyMovingData movingData);

		~Enemy()
		{}

		void Init();
		void Update();
		void Render();
		void Release();

		inline void SetExistsPlayer(bool existsPlayer) { m_existsPlayer = existsPlayer; }
		inline void SetDirection(Direction direction)  { m_translationData.m_direction = direction; }
		inline void SetCanMove(bool canMove)			{ m_canMove = canMove; }

		inline Direction   GetDirection() { return m_translationData.m_direction; }
		inline Visibility  GetVisibility() { return m_visibility; }
		inline BaseEnemyAction::TranslationData GetTranslationData()	    { return m_translationData; }

	private:
		/// <summary>
		/// プレイヤーを追いかける
		/// </summary>
		void ChasePlayer();

		/// <summary>
		/// 方向を決める
		/// </summary>
		void DecideDirection();

		const D3DXVECTOR2& m_playerPos;

		Visibility m_visibility;
		BaseEnemyAction::TranslationData m_translationData;

		BaseEnemyAction* m_pEnemyAction;

		bool m_existsPlayer;
		bool m_canMove;
	};
}

#endif // !ENEMY_H_
