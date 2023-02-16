#ifndef OUTPUT_ITERATOR_HPP
#define OUTPUT_ITERATOR_HPP

namespace ft {
	template <class T>
	class OutputIterator {
	public:
		typedef T							value_type;
		typedef std::ptrdiff_t				difference_type;
		typedef T*							pointer;
		typedef T&							reference;
		typedef std::output_iterator_tag	iterator_category;

		OutputIterator() {}
		OutputIterator(const OutputIterator& src) { (void)src; }
		~OutputIterator() {}

		OutputIterator& operator=(const T& value) {
			*static_cast<T*>(NULL) = value; // hiçbir işlem yapmayacak, ama derleyici için gerekli
			return (*this);
		}

		OutputIterator& operator*() { return (*this); }
		OutputIterator& operator++() { return (*this); }
		OutputIterator& operator++(int) { return (*this); }
	};
}

#endif

/* Bu sınıf, std::output_iterator_tag'in aynı öğelerini kullanırken, 
value_type, pointer ve reference öğeleri, sınıfın kullanıldığı türde 
const öznitelikli olmayacak şekilde ayarlanmıştır. operator= fonksiyonu, 
verilen değeri hiçbir yere atamaz; bunun yerine, hiçbir işlem yapmayacak, 
ancak sınıfın standartlara uygun olmasını sağlamak için 
static_cast<T*>(NULL) ifadesini kullanacaktır. operator* ve operator++ 
işlemleri de hiçbir işlem yapmaz. */