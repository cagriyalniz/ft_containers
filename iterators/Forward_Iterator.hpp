#ifndef FORWARD_ITERATOR_HPP
#define FORWARD_ITERATOR_HPP


namespace ft {
	template<typename T>
	class ForwardIterator {
	public:
		typedef T value_type;
		typedef T* pointer;
		typedef T& reference;
		typedef std::ptrdiff_t difference_type;
		typedef std::forward_iterator_tag iterator_category;

		ForwardIterator() : _ptr(NULL) {}
		ForwardIterator(pointer ptr) : _ptr(ptr) {}
		ForwardIterator(const ForwardIterator &other) { *this = other; }
		virtual ~ForwardIterator() {}

		ForwardIterator& operator=(const ForwardIterator &other) {
			if (this != &other)
				this->_ptr = other._ptr;
			return *this;
		}

		ForwardIterator& operator++() {
			++_ptr;
			return *this;
		}

		ForwardIterator operator++(int) {
			ForwardIterator tmp(*this);
			++(*this);
			return tmp;
		}

		bool operator==(const ForwardIterator &other) const {
			return this->_ptr == other._ptr;
		}

		bool operator!=(const ForwardIterator &other) const {
			return !(*this == other);
		}

		reference operator*() const {
			return *_ptr;
		}

		pointer operator->() const {
			return _ptr;
		}

	private:
		pointer _ptr;
	};
}

#endif

/*
Yukarıdaki sınıf, std::forward_iterator_tag kategorisindeki 
bir iteratör için gereken özellikleri sağlar. 
ForwardIterator sınıfı, ileriye doğru hareket etmek için 
operator++ işlemini ve ilgili operatorleri, 
değer ve işaretçi türlerini tanımlar. 
Ayrıca, operator* ve operator-> işlemlerini de tanımlar.
*/