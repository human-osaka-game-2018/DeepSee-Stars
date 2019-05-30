#include "StraightLine.h"

namespace deepseestars
{
	void StraightLine::Init()
	{
		//リングバッファの設定
		m_destQueue.push_back(1);
		m_destQueue.push_back(0);

		//初期の移動する道のりを計算する
		m_distance = m_dest[1] - m_dest[0];

		m_translationData.m_pos = m_initPos;
	}

	void StraightLine::Update()
	{
		UpdatePos();
		ArriveAtDestination(m_dest);
	}
}
