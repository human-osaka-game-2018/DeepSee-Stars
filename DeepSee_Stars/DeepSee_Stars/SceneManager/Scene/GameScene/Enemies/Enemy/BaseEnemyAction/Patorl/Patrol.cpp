#include "Patrol.h"

namespace deepseestars
{
	void Patrol::Init(bool isClockWise)
	{
		//右回りか左回りでバッファの値を変える
		int ClockWiseValue = (isClockWise) ? 1 : 3;

		//リングバッファを設定する
		m_destQueue.push_back(0);
		m_destQueue.push_back(ClockWiseValue);
		m_destQueue.push_back(2);
		m_destQueue.push_back(ReverseValue(1, 3, ClockWiseValue));	//ClockWiseValueと逆の値を入れる

		//初期の移動する道のりを計算する
		m_distance = m_dest[ClockWiseValue] - m_dest[0];

		m_translationData.m_pos = m_initPos;
	}

	void Patrol::Update()
	{
		UpdatePos();
		ArriveAtDestination(m_dest);
	}
}
