#ifndef OBJECT_H
#define OBJECT_H

#include "DirectX.h"
#include "CollsionManager.h"


class Object
{
public:
	Object();
	virtual ~Object();
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
private:


};
#endif // OBJECT_H
