#include "L_Shaped.h"

namespace deepseestars
{
	void L_Shaped::Init()
	{
		//0,2だけの乱数
		int randam = 2 * (rand() % 2);

		//最初の移動方向を決める
		m_distance = m_dest[randam] - m_dest[1];

		//リングバッファの設定
		m_destQueue.push_back(randam);
		m_destQueue.push_back(1);
		m_destQueue.push_back(ReverseValue(0, 2, randam));	//選ばれなかったほうの値を詰める
	}

	void L_Shaped::Update()
	{
		ArriveAtDestination(m_dest);
		UpdatePos();
	}
}
