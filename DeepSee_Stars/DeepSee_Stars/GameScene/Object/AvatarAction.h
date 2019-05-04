#ifndef AVATARACTION_H
#define AVATARACTION_H

#include"BaseAction.h"
#include "CustomVertex.h"

class AvatarAction : public BaseAction
{
public:
	AvatarAction();
	~AvatarAction();
	void Operation();

private:
	CustomVertex m_PlayerPosBuf[4];
};

#endif // AVATARACTION_H