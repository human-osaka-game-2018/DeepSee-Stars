#include "Object.h"
#include "CustomVertex.h"

#ifndef BACKGROUND_H
#define BACKGROUND_H

class BackGround : public Object
{
public:
	BackGround();
	~BackGround();
	void Init();
	void Update();
	void Render();
	


private:
	DirectX * m_pDirectX;
	CustomVertex m_BG[4];
};
#endif // BACKGROUND_H
