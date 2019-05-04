#ifndef HIDEACTION_H
#define HIDEACTION_H

#include"BaseAction.h"
#include "CustomVertex.h"

class HideAction :public BaseAction
{
public:
	HideAction();
	~HideAction();
	D3DXVECTOR2 Operation(D3DXVECTOR2 playerCenterPos);

private:
	CustomVertex m_PlayerPosBuf[4];
};

#endif // HIDEACTION_H
