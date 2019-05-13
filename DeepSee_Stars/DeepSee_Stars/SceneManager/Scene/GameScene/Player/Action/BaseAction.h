#ifndef BASEACTION_H
#define BASEACTION_H


class BaseAction
{
public:
	BaseAction();
	virtual ~BaseAction();
	virtual void Update();
	virtual void Render();

private:


};
#endif // BASEACTION_H
