#include "Enemies.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

namespace deepseestars
{
	void Enemies::Init()
	{
		const int DIRECTIONS_NUM = 4;
		m_textureKeys.resize(DIRECTIONS_NUM);

		m_textureKeys[Direction::LEFT] = (_T("2DTexture/Game/Enemies/enemyLeft.png"));
		m_textureKeys[Direction::RIGHT] = (_T("2DTexture/Game/Enemies/enemyRight.png"));
		m_textureKeys[Direction::UP] = (_T("2DTexture/Game/Enemies/enemyUp.png"));
		m_textureKeys[Direction::DOWN] = (_T("2DTexture/Game/Enemies/enemyDown.png"));

		for (auto& texturePath : m_textureKeys)
		{
			m_rGameBaseMaker.CreateTex(texturePath, texturePath);
		}

		for (auto& enemy : m_enemies)
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

		struct Vector2Int
		{
		public:
			int m_x;	
			int m_y;
		};

		Vector2Int enemyInitPos;		//初期位置の設定xy(セルのマス数)
		Vector2Int enemyMovementPos;	//移動する範囲の設定(セルのマス数)
		int visibility;				//初期の視界レベル
		int actionPattern;
		EnemyMovingData movingData;

		while (getline(ifs, str))
		{
			replace(str.begin(), str.end(), ',', ' ');
			std::stringstream EnemiesStream(str);

			//初期情報の読み込み
			EnemiesStream >>
				enemyInitPos.m_x >> enemyInitPos.m_y >>
				enemyMovementPos.m_x >> enemyMovementPos.m_y >>
				visibility >> actionPattern >> movingData.m_isClockWise;

			movingData.m_initPos =
			{ enemyInitPos.m_x * m_cellSize,enemyInitPos.m_y * m_cellSize };
			
			movingData.m_movingPos = 
			{ enemyMovementPos.m_x * m_cellSize,enemyMovementPos.m_y * m_cellSize };

			movingData.m_actionPattern = static_cast<ActionPattern>(actionPattern);

			//敵の生成
			m_enemies.push_back(new Enemy(m_playerPos, m_textureKeys, m_distanceToOrigin,
				static_cast<Visibility>(visibility), movingData, m_cellSize));
		}
	}

	void Enemies::Update()
	{
		for (auto& enemy : m_enemies)
		{
			enemy->Update();
		}
	}

	void Enemies::Render()
	{
		for (auto& enemy : m_enemies)
		{
			enemy->Render();
		}
	}

	void Enemies::Release()
	{
		for (auto& enemy : m_enemies)
		{
			enemy->Release();

			delete enemy;
			enemy = nullptr;
		}

		m_enemies.clear();
		m_enemies.shrink_to_fit();
	}
}
