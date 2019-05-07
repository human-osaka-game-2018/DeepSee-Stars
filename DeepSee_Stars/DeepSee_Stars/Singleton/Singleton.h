#ifndef SINGLETON_H_
#define SINGLETON_H_

#include <memory>

namespace singleton
{
	template <class T>
	class Singleton
	{
	public:
		Singleton() {};
		virtual ~Singleton() {};

		/// <summary>
		/// インスタンスを生成する
		/// </summary>
		/// <returns>クラス参照</returns>
		inline static T& GetInstance()
		{
			static std::unique_ptr<T> ptr(new T());

			return *ptr;
		}

	};
}

#endif // !SINGLETON_H_
