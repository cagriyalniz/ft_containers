#ifndef RANDOMACCESS_ITERATOR_HPP
#define RANDOMACCESS_ITERATOR_HPP
#include "Iterator_Traits.hpp"
#include "Reverse_Iterator.hpp"

namespace ft
{
    template <typename T>
    class RandomAccessIterator
    {

    public:
        typedef	typename iterator_traits<T*>::value_type 	value_type;
		typedef	typename iterator_traits<T*>::pointer	pointer;
		typedef	typename iterator_traits<T*>::reference	reference;
		typedef	typename iterator_traits<T*>::difference_type	difference_type;
		//typedef pointer iterator_type;
		//this is for std::functions
		typedef	std::random_access_iterator_tag iterator_category;

        private:
            pointer _ptr;
	public:

		// CONSTRUCTORS
		RandomAccessIterator() : _ptr() {}

		RandomAccessIterator(pointer a) : _ptr(a) {}

		virtual ~RandomAccessIterator() {}

		RandomAccessIterator(const RandomAccessIterator<typename remove_const<value_type>::type > & src) : _ptr(&(*src)) {}

		RandomAccessIterator<value_type> & operator=(RandomAccessIterator<typename remove_const<value_type>::type > const & src) {
			_ptr = &(*src);
			return *this;
		}

        bool operator==(const RandomAccessIterator &rhs) const { return _ptr == rhs._ptr; }
        bool operator!=(const RandomAccessIterator &rhs) const { return _ptr != rhs._ptr; }
        bool operator<(const RandomAccessIterator &rhs) const { return _ptr < rhs._ptr; }
        bool operator<=(const RandomAccessIterator &rhs) const { return _ptr <= rhs._ptr; }
        bool operator>(const RandomAccessIterator &rhs) const { return _ptr > rhs._ptr; }
        bool operator>=(const RandomAccessIterator &rhs) const { return _ptr >= rhs._ptr; }

		int operator+(const RandomAccessIterator &right_hand_side)
        {
            return (this->_ptr + right_hand_side._ptr);
        }
        int operator-(const RandomAccessIterator &right_hand_side)
        {
            return (this->_ptr - right_hand_side._ptr);
        }

        pointer base() const { return _ptr; }
		

		//OPERATORS
		RandomAccessIterator & operator++() {
			++_ptr;
			return *this;
		}

		RandomAccessIterator operator++(int) {
			RandomAccessIterator tmp(*this);
			++_ptr;
			return tmp;
		}

		RandomAccessIterator & operator--() {
			--_ptr;
			return *this;
		}

		RandomAccessIterator  operator--(int) {
			RandomAccessIterator tmp = *this;
			--_ptr;
			return tmp;
		}
		RandomAccessIterator operator+(const difference_type & a) const {
			return _ptr + a;
		}

		RandomAccessIterator operator-(const difference_type & a) const {
			return _ptr - a;
		}

		RandomAccessIterator & operator+=(const difference_type & a) {
			_ptr += a;
			return (*this);
		}

		RandomAccessIterator & operator-=(const difference_type & a) {
			_ptr -= a;
			return (*this);
		}

		pointer operator->() const {
			return _ptr;
		}

		reference operator*() const {
			return *_ptr;
		}

		reference operator[](difference_type n) const {
			return *(_ptr + n);
		}
    };
    template <typename T>
    RandomAccessIterator<T> operator+(typename RandomAccessIterator<T>::difference_type n, const RandomAccessIterator<T> &x) { return x + n; }

 	template <typename T>
    RandomAccessIterator<T> operator-(typename RandomAccessIterator<T>::difference_type n, const RandomAccessIterator<T> &x) { return x - n; }
	

/*     template <class revIterator, class randIterator>
    bool operator!=(const ft::ReverseIterator<revIterator>& x, const RandomAccessIterator<randIterator>& y)
    {
        return x.base() != y.base();
    }

    template <class revIterator, class randIterator>
    bool operator!=(const RandomAccessIterator<randIterator>& y, const ft::ReverseIterator<revIterator>& x)
    {
        return x.base() != y.base();
    } */

} // namespace ft
#endif
/*
base() i??lemi, bir iterator'un temel halini (base) d??nd??r??r.
Bu temel hal, bir arka u?? (past-the-end) i??aret??isiyle birle??tirilebilir ve
??o??u durumda bir aral??????n ba??lang??c??n?? belirlemek i??in kullan??labilir.
??rne??in, bir reverse_iterator tipindeki bir iterator,
standart bir iteratorun tam tersine i??aret eder.
base() i??lemi, reverse_iterator'??n i??aret etti??i standart iteratorunun
temel halini d??nd??r??r.
B??ylece, base() i??lemi, reverse_iterator'?? bir aral??????n sonundan ba??layarak
????eleri gezinmek i??in kullan??rken ba??lang???? noktas??n?? belirlemek i??in
kullan??labilir.
*/