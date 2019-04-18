#ifndef BASECELL_H
#define BASECELL_H

enum Type
{
	NONE,
	ROCK,
};

class BaseCELL
{
public:
	BaseCELL();
	virtual ~BaseCELL();
	virtual void Update() = 0;
	virtual void Render(float stageScrollX, float stageScrollY) = 0;
private:

	
};
#endif // BASECELL_H

