#ifndef BASECELL_H
#define BASECELL_H


#include "Object.h"

class BaseCell
{
public:
	BaseCell();
	virtual ~BaseCell();
	virtual void Update() = 0;
	virtual void Render(D3DXVECTOR2 drawArea) = 0;

private:

};
#endif // BASECELL_H

