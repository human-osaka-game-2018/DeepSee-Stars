#ifndef GAME_OBJECT_H_
#define GAME_OBJECT_H_

#include "../../GameBaseMaker/GameBaseMaker.h"

namespace deepseestars
{
	using gamebasemaker::GameBaseMaker;

	/// <summary>
	/// ゲームのオブジェクト基底クラス
	/// </summary>
	class GameObject
	{
	public:
		GameObject() {}
		virtual ~GameObject() {}

		/// <summary>
		/// 基底初期化関数
		/// </summary>
		virtual void Init() = 0;

		/// <summary>
		/// 基底更新関数
		/// </summary>
		virtual void Update() = 0;

		/// <summary>
		/// 基底描画関数
		/// </summary>
		virtual void Render() = 0;

		/// <summary>
		/// 基底解放関数
		/// </summary>
		virtual void Release() = 0;

	private:
		GameBaseMaker& rGameBaseMaker = GameBaseMaker::GetInstance();
	};
}

#endif // !GAME_OBJECT_H_
