#include "HideAction.h"

HideAction::HideAction()
{

}

HideAction::~HideAction()
{

}

D3DXVECTOR2 HideAction::Operation(D3DXVECTOR2 playerCenterPos)
{
	playerCenterPos.y = playerCenterPos.y - 64.f;
	return playerCenterPos;
}
