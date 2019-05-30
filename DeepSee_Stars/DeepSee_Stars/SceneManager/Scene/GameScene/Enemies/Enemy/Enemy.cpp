#include "Enemy.h"

#include "BaseEnemyAction/Patorl/Patrol.h"
#include "BaseEnemyAction/L_Shaped/L_Shaped.h"
#include "BaseEnemyAction/StraightLine/StraightLine.h"

namespace deepseestars
{
	Enemy::Enemy(const D3DXVECTOR2& playerPos, const std::vector<const TCHAR*>& textureKeys,
		const D3DXVECTOR2& DistanceToOrigin, Visibility visibility,
		EnemyMovingData movingData, const float& cellSize) :
		GameObject(), m_playerPos(playerPos), m_visibility(visibility), m_distanceToOrigin(DistanceToOrigin),
		m_cellSize(cellSize), m_rTextureKeys(textureKeys)
	{
		DecideActionPattern(movingData);
		Init();
	}

	void Enemy::Init()
	{
		
	}

	void Enemy::Update()
	{	
		m_pEnemyAction->Update();	
		DecideDirection();
	}

	void Enemy::Render()
	{
		D3DXVECTOR2 buff = m_distanceToOrigin +	m_translationData.m_pos;
		
		m_vertices.SetPos(buff);
		m_vertices.SetScale(D3DXVECTOR2(m_cellSize * 0.5f, m_cellSize * 0.5f));

		m_rGameBaseMaker.Render(m_vertices, 
			m_rGameBaseMaker.GetTex(m_rTextureKeys[m_translationData.m_direction]));
	}

	void Enemy::Release()
	{
		delete m_pEnemyAction;
		m_pEnemyAction = nullptr;
	}

	void Enemy::DecideActionPattern(const EnemyMovingData& movingData)
	{
		switch (movingData.m_actionPattern)
		{
		case PATROL:
			m_pEnemyAction = new Patrol(m_translationData, movingData);
			break;

		case L_SHAPE:
			m_pEnemyAction = new L_Shape(m_translationData, movingData);
			break;

		case STRAIGHTLINE:
			m_pEnemyAction = new StraightLine(m_translationData, movingData);
			break;

		default:
			break;
		}
	}

	void Enemy::DecideDirection()
	{
		if (m_translationData.m_movement == 0) return;

		if (m_translationData.m_movement.x > 0) m_translationData.m_direction = RIGHT;
		if (m_translationData.m_movement.x < 0) m_translationData.m_direction = LEFT;
		if (m_translationData.m_movement.y > 0) m_translationData.m_direction = DOWN;
		if (m_translationData.m_movement.y < 0) m_translationData.m_direction = UP;
	}

	void Enemy::ChasePlayer()
	{
		if (!m_existsPlayer) return;

		D3DXVECTOR2 chaseVec = m_playerPos - m_translationData.m_pos;
		D3DXVec2Normalize(&chaseVec, &chaseVec);

		m_translationData.m_movement = 
		{ chaseVec.x * m_translationData.m_speed.x,chaseVec.y * m_translationData.m_speed.y };

		m_translationData.m_pos += m_translationData.m_movement;
	}
}
