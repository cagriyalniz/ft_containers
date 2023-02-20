#ifndef RANDOMACCESS_ITERATOR_HPP
#define RANDOMACCESS_ITERATOR_HPP
#include "Iterator_Traits.hpp"
namespace ft
{
    template <typename T>
    class RandomAccessIterator : public std::iterator<std::random_access_iterator_tag, T>
    {
    public:
        typedef typename iterator_traits<T>::value_type value_type;
        typedef typename iterator_traits<T>::difference_type difference_type;
        typedef typename iterator_traits<T>::pointer pointer;
        typedef typename iterator_traits<T>::reference reference;
		typedef RandomAccessIterator<const T>			const_iterator;
        typedef const T &const_reference;
        typedef const T *const_pointer;
        RandomAccessIterator() : _ptr(NULL) {}
        RandomAccessIterator(T ptr) : _ptr(ptr) {}
        template <class Itererator>
        explicit RandomAccessIterator(const RandomAccessIterator<Itererator> &other) : _ptr(other.base()) {}
        RandomAccessIterator &operator=(const RandomAccessIterator &other)
        {
            _ptr = other._ptr;
            return *this;
        }

		operator const_iterator() const {return const_iterator(_ptr);} // const_iterator begin() fonksiyonu için
        reference operator*() { return *this->_ptr; }
        const_reference operator*() const { return *this->_ptr; }
        pointer operator->() { return _ptr; }
        const_pointer operator->() const { return _ptr; }
        RandomAccessIterator &operator++()
        {
            ++_ptr;
            return *this;
        }
        RandomAccessIterator operator++(int)
        {
            RandomAccessIterator temp(*this);
            ++_ptr;
            return temp;
        }
        RandomAccessIterator &operator--()
        {
            --_ptr;
            return *this;
        }
        RandomAccessIterator operator--(int)
        {
            RandomAccessIterator temp(*this);
            --_ptr;
            return temp;
        }
        RandomAccessIterator operator+(difference_type n) const { return RandomAccessIterator(_ptr + n); }
        RandomAccessIterator operator-(difference_type n) const { return RandomAccessIterator(_ptr - n); }
        RandomAccessIterator &operator+=(difference_type n)
        {
            _ptr += n;
            return *this;
        }
        RandomAccessIterator &operator-=(difference_type n)
        {
            _ptr -= n;
            return *this;
        }
        reference operator[](difference_type n) { return *(_ptr + n); }
        const_reference operator[](difference_type n) const { return *(_ptr + n); }
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
    private:
        T _ptr;
    };
    template <typename T>
    RandomAccessIterator<T> operator+(typename RandomAccessIterator<T>::difference_type n, const RandomAccessIterator<T> &x) { return x + n; }
} // namespace ft
#endif
/*
base() işlemi, bir iterator'un temel halini (base) döndürür.
Bu temel hal, bir arka uç (past-the-end) işaretçisiyle birleştirilebilir ve
çoğu durumda bir aralığın başlangıcını belirlemek için kullanılabilir.
Örneğin, bir reverse_iterator tipindeki bir iterator,
standart bir iteratorun tam tersine işaret eder.
base() işlemi, reverse_iterator'ın işaret ettiği standart iteratorunun
temel halini döndürür.
Böylece, base() işlemi, reverse_iterator'ı bir aralığın sonundan başlayarak
öğeleri gezinmek için kullanırken başlangıç noktasını belirlemek için
kullanılabilir.
*/