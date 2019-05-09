#ifndef WORLD_H
#define WORLD_H

#include "Object.h"
#include "Player.h"
#include"Stage.h"
#include "Camera.h"

class World : public Object
{
public:
	World();
	~World();
	void Update();
	void Render();
	void Init();
	void ObjectCollision();
	void m_CanPlayerMoveJudg();
	void CanPlayerActionJudg();


private:
	Stage * m_pStage;
	Player* m_pPlayer;
	Camera* m_pCamera;

	D3DXVECTOR2 m_PlayerGirthCenterPos[4];

	DIRECTION m_PlayerDirection;
	ACTION m_PlayerAction;
	float m_WorldScrollX = 0.f;
	float m_WorldScrollY = 0.f;

	const float m_SquaresSize = 100.f;
};

#endif // WORLD_H
