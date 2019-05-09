#ifndef BASEACTION_H
#define BASEACTION_H

#include "Object.h"

class BaseAction
{
public:
	BaseAction();
	virtual ~BaseAction();
	virtual void Operation(D3DXVECTOR2 drawArea);
	virtual void Render();

private:


};
#endif // BASEACTION_H
