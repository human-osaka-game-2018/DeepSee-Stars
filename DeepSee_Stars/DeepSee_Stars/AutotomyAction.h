﻿#ifndef AUTOTOMYACTION_H
#define AUTOTOMYACTION_H

#include"BaseAction.h"
#include "CustomVertex.h"

class AutotomyAction :public BaseAction
{
public:
	AutotomyAction(D3DXVECTOR2 playerCenterPos);
	~AutotomyAction();
	void Operation(D3DXVECTOR2 drawArea);
	void Render();

private:
	DirectX * m_pDirectX;
	D3DXVECTOR2 m_AutotomyCenterPos;
	CustomVertex m_Autotomy[4];
	const float m_SquaresSize = 100.f;
};

#endif // AUTOTOMYACTION_H
