#ifndef TEXTURES_H_
#define TEXTURES_H_

#include <tchar.h>
#include <unordered_map>

#include "Texture/Texture.h"

namespace graphics
{
	/// <summary>
	/// テクスチャの情報をまとめたクラス
	/// </summary>
	class Textures
	{
	public:
		Textures() {}
		~Textures() {}

		/// <summary>
		/// テクスチャの生成
		/// </summary>
		/// <param name="pKey">テクスチャのキーワード</param>
		/// <param name="pTexPath">テクスチャのファイルパス</param>
		void CreateTex(const TCHAR* pKey, const TCHAR* pTexPath);

		/// <summary>
		/// 指定したテクスチャの削除
		/// </summary>
		/// <param name="pKey">削除したいテクスチャのキーワード</param>
		void EraseTex(const TCHAR* pKey);

		/// <summary>
		/// テクスチャの全開放
		/// </summary>
		void ReleaseAllTex();

		inline Texture GetTex(const TCHAR* pKey)
		{
			return m_textures[pKey];
		}

	private:
		/// <summary>
		/// テクスチャが存在するか
		/// </summary>
		/// <param name="pKey">テクスチャのキーワード</param>
		/// <returns>存在していたらtrue</returns>
		bool Exists(const TCHAR* pKey);

		std::unordered_map<const TCHAR*, Texture> m_textures;
	};
}

#endif // !TEXTURES_H_
