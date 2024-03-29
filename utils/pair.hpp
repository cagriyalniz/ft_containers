#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft
{
	/**
	 * @brief 
	 * Pair sınıfı, iki farklı türdeki nesnelerin birleşik bir yapıda saklanması için kullanılır.
	 *	Sınıf iki şablon argümanı alır: T1 ve T2. Bu argümanlar, pair'in first ve second veri elemanlarının veri türlerini belirler.
	 *	Sınıfın public kısmında first ve second isimli iki veri elemanı bulunur. Bu veri elemanları, pair nesnesinin iki bileşenini temsil eder.
	 * @tparam T1 
	 * @tparam T2 
	 */
	template <typename T1, typename T2>
	class pair
	{
		public:
			T1 first;
			T2 second;
			pair() : first(), second() {}; //default constructor
			pair(const T1& a, const T2& b) : first(a), second(b) {}; // define constructor
			pair(const pair<T1, T2>& copy) : first(copy.first), second(copy.second) {}; // copy constructor
		
			template <typename U, typename V>
			pair(const pair<U, V>& copy) : first(copy.first), second(copy.second) {};

			~pair() {};
			pair& operator=(const pair& assign)
			{
				if (this != &assign)
				{
					first = assign.first;
					second = assign.second;
				}
				return (*this);
			}
	};
	template <class T1,class T2>
	pair<T1,T2> make_pair(T1 x, T2 y)
	{
		return pair<T1,T2>(x,y);
	}
} // namespace ft

#endif