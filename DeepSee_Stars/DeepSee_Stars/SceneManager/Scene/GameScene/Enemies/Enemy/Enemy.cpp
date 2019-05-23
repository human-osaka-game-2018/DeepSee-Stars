#include "Enemy.h"

#include "BaseEnemyAction/Patorl/Patrol.h"

namespace deepseestars
{
	Enemy::Enemy(const TCHAR* pTextureKey, const D3DXVECTOR2& playerPos,
		Visibility visibility, EnemyMovingData movingData) :
		GameObject(pTextureKey), m_playerPos(playerPos), m_visibility(visibility)
	{
		switch (movingData.m_actionPattern)
		{
		case PATROL:
			m_pEnemyAction = new Patrol(m_translationData, movingData);
			
			break;

		case L_SHAPED:
			break;

		default:
			break;
		}
	}

	void Enemy::Init()
	{
		
	}

	void Enemy::Update()
	{
		ChasePlayer();
		DecideDirection();
	}

	void Enemy::Render()
	{
		m_vertices.SetPos(m_translationData.m_pos);
	}

	void Enemy::Release()
	{
		delete m_pEnemyAction;
		m_pEnemyAction = nullptr;
	}

	void Enemy::DecideDirection()
	{
		if (m_translationData.m_movement == 0) return;

		if (m_translationData.m_movement.x > 0) m_translationData.m_direction = RIGHT;
		if (m_translationData.m_movement.x < 0) m_translationData.m_direction = LEFT;
		if (m_translationData.m_movement.y < 0) m_translationData.m_direction = UP;
		if (m_translationData.m_movement.y > 0) m_translationData.m_direction = DOWN;
	}

	void Enemy::ChasePlayer()
	{
		if (!m_existsPlayer) return;

		D3DXVECTOR2 chaseVec = m_playerPos - m_translationData.m_pos;
		D3DXVec2Normalize(&chaseVec, &chaseVec);

		m_translationData.m_movement = 
		{ chaseVec.x * m_translationData.m_speed.x,chaseVec.y * m_translationData.m_speed.y };

		if (!m_canMove) return;

		m_translationData.m_pos += m_translationData.m_movement;
	}
}
