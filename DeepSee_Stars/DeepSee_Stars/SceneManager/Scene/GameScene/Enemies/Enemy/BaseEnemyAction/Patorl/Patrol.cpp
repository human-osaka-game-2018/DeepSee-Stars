#include "Patrol.h"

namespace deepseestars
{
	void Patrol::Init(bool isClockWise)
	{
		const int FOUR_WAYS = 4;
		int pattern = static_cast<int>(isClockWise);

		Direction nextDirection[2][FOUR_WAYS] = 
		{
			{ DOWN,UP,LEFT,RIGHT },
			{ UP,DOWN,RIGHT,LEFT}
		};

		//向かう座標
		D3DXVECTOR2 distinations[2][FOUR_WAYS] =
		{
			{
				m_initPos,
				m_movingRange,
				{m_movingRange.x, m_initPos.y},
				{m_initPos.x, m_movingRange.y}
			},

			{
				{m_initPos.x, m_movingRange.y},
				{m_movingRange.x, m_initPos.y},
				m_initPos,
				m_movingRange,
			}
		};

		//移動する前の座標
		D3DXVECTOR2 beginToMovePoint[2][FOUR_WAYS] =
		{
			{
				{m_movingRange.x, m_initPos.y},
				{m_initPos.x, m_movingRange.y},
				 m_movingRange,
				 m_initPos,
			},

			{
				m_movingRange,
				m_initPos,
				{m_initPos.x, m_movingRange.y},
				{m_movingRange.x, m_initPos.y},
			}
		};

		for (int i = 0; i < FOUR_WAYS; ++i)
		{
			m_nextDirection[i] = nextDirection[pattern][i];
			m_beginToMovePoint[i] = beginToMovePoint[pattern][i];
			m_distinations[i] = distinations[pattern][i];
		}
	}

	void Patrol::Update()
	{
		DesideRoute();
		Move();
	}

	void Patrol::DesideRoute()
	{
		if (m_isMoving) return;

		m_isMoving = true;

		m_translationData.m_direction = m_nextDirection[m_translationData.m_direction];
	}

	void Patrol::Move()
	{
		if (!m_isMoving) return;

		const float MOVE_SPEED_FRAME = 5.0f;

		D3DXVECTOR2 distanceMax = 
			m_distinations[m_translationData.m_direction] - m_beginToMovePoint[m_translationData.m_direction];

		m_translationData.m_speed = distanceMax / MOVE_SPEED_FRAME;

		m_translationData.m_movement = m_translationData.m_speed;

		bool finishedMoving[DOWN + 1] =
		{
			m_translationData.m_pos.x <= m_distinations[m_translationData.m_direction].x,
			m_translationData.m_pos.x >= m_distinations[m_translationData.m_direction].x,
			m_translationData.m_pos.y <= m_distinations[m_translationData.m_direction].y,
			m_translationData.m_pos.y >= m_distinations[m_translationData.m_direction].y
		};

		if (finishedMoving[m_translationData.m_direction])
		{
			m_isMoving = false;
		}
		else m_translationData.m_pos += m_translationData.m_movement;
	}
}
