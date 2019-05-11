#ifndef GAME_OBJECT_H_
#define GAME_OBJECT_H_

#include "../../GameBaseMaker/GameBaseMaker.h"

namespace deepseestars
{
	using gamebasemaker::GameBaseMaker;
	using gamebasemaker::Vertices;

	/// <summary>
	/// ゲームのオブジェクト基底クラス
	/// </summary>
	class GameObject
	{
	public:
		/// <summary>
		/// ファイルの名前とキーを設定するコンストラクタ
		/// </summary>
		/// <param name="pTextureKey">設定するキー</param>
		/// <param name="pFileName">画像のファイルの名前</param>
		GameObject(const TCHAR* pTextureKey,const TCHAR* pFileName):
			m_pTextureKey(pTextureKey),m_pFileName(pFileName)
		{}

		/// <summary>
		/// テクスチャのキーだけを設定するコンストラクタ
		/// </summary>
		GameObject(const TCHAR* pTextureKey) :
			m_pTextureKey(pTextureKey), m_pFileName(nullptr)
		{}

		/// <summary>
		/// ファイル名などを設定しないときに使用するコンストラクタ
		/// </summary>
		GameObject() :
			m_pTextureKey(nullptr), m_pFileName(nullptr)
		{}

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

	protected:
		GameBaseMaker& m_rGameBaseMaker = GameBaseMaker::GetInstance();
		Vertices m_vertices;

		/// <summary>
		/// ファイルの名前とキーの設定
		/// </summary>
		const TCHAR* m_pFileName;
		const TCHAR* m_pTextureKey;
	};
}

#endif // !GAME_OBJECT_H_
