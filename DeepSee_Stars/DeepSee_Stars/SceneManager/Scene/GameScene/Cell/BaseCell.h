#ifndef BASECELL_H
#define BASECELL_H

#include "GameObject.h"

namespace deepseestars
{
	class BaseCell
	{
	public:
		BaseCell();
		virtual ~BaseCell();
		virtual void Update() = 0;
		virtual void Render() = 0;

	};
}
#endif // BASECELL_H

