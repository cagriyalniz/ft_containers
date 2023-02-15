#ifndef RANDOMACCESSITERATOR_HPP
#define RANDOMACCESSITERATOR_HPP

#include "./Iterator.hpp"
#include "./BidirectionalIterator.hpp"

class BidirectionalIterator;


namespace ft
{
    template <typename T>
    class RandomAccessIterator :    public BidirectionalIterator<T, std::random_access_iterator_tag>
                                    public Iterator<T, std::random_access_iterator_tag>
    {
    private:
        typedef RandomAccessIterator<T> randomIterator;
    public:
        typedef T iterator_type;
		typedef	typename ft::iterator_traits<T>::difference_type	difference_type;
		typedef	typename ft::iterator_traits<T>::reference			reference;
		typedef	typename ft::iterator_traits<T>::const_reference	const_reference;
		typedef typename ft::iterator_traits<T>::pointer			pointer;
		typedef	typename ft::iterator_traits<T>::value_type			value_type;
        RandomAccessIterator()
        {
            this->_ptr = NULL;
        }
        RandomAccessIterator(const randomIterator &other)
        {
            this->_ptr = other._ptr;
        }
        RandomAccessIterator &operator=(const randomIterator &other)
        {
            if (this == other)
                return (*this);
            *this = other;
            return (*this);
        }
        ~RandomAccessIterator();
        RandomAccessIterator(pointer ptr) 
        {
            this->_ptr = ptr;
        }
        RandomAccessIterator &operator--()
        {
            this->_ptr--;
            return (*this);
        }
        RandomAccessIterator operator--(int)
        {
            RandomAccessIterator tmp = *this;
            --(*tmp);
            return (tmp);
        }
        reference operator[](const int n) const
        {
            return (this->_ptr[n]);
        }
        randomIterator operator+(int other)
        {
            return (randomIterator(this->_ptr + other));
        }
        randomIterator operator-(int other)
        {
            return (randomIterator(this->_ptr - other));
        }
    };

}
#endif