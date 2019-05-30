#include "Enemies.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

namespace deepseestars
{
	void Enemies::Init()
	{
		for (int i = 0; i < STAYING; ++i)
		{
			m_rGameBaseMaker.CreateTex(m_pTextureKeys[i], m_pFileNames[i]);
		}

		for (auto enemy : m_enemies)
		{
			enemy->Init();
		}
	}

	void Enemies::Load(const char* pFileName)
	{
		std::ifstream ifs(pFileName);
		std::string str;

		//1行目を無視する
		std::getline(ifs, str);

		const int XY = 2;

		int enemyInitPos[XY];		//初期位置の設定xy(セルのマス数)
		int enemyMovementPos[XY];	//移動する範囲の設定(セルのマス数)
		int visibility;				//初期の視界レベル
		int actionPattern;
		EnemyMovingData movingData;

		while (getline(ifs, str))
		{
			replace(str.begin(), str.end(), ',', ' ');
			std::stringstream EnemiesStream(str);

			//初期情報の読み込み
			EnemiesStream >>
				enemyInitPos[0] >> enemyInitPos[1] >>
				enemyMovementPos[0] >> enemyMovementPos[1] >>
				visibility >> actionPattern >> movingData.m_isClockWise;

			movingData.m_initPos =
			{ enemyInitPos[0] * m_cellSize,enemyInitPos[1] * m_cellSize };
			
			movingData.m_movingPos = 
			{ enemyMovementPos[0] * m_cellSize,enemyMovementPos[1] * m_cellSize };

			movingData.m_actionPattern = static_cast<ActionPattern>(actionPattern);

			//敵の生成
			m_enemies.push_back(new Enemy(m_playerPos, m_pTextureKeys,m_distanceToOrigin,
				static_cast<Visibility>(visibility), movingData, m_cellSize));
		}
	}

	void Enemies::Update()
	{
		for (auto enemy : m_enemies)
		{
			enemy->Update();
		}
	}

	void Enemies::Render()
	{
		for (auto enemy : m_enemies)
		{
			enemy->Render();
		}
	}

	void Enemies::Release()
	{
		for (auto enemy : m_enemies)
		{
			enemy->Release();

			delete enemy;
			enemy = nullptr;
		}

		m_enemies.clear();
		m_enemies.shrink_to_fit();
	}
}
