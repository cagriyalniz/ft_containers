#ifndef BIDIRECTIONALITERATOR_HPP
#define BIDIRECTIONALITERATOR_HPP

#include "./ForwardIterator.hpp"
#include "./Iterator.hpp"

namespace ft
{

#include <cstddef>
    template <typename T, typename Category>
    class BidirectionalIterator : public ForwardIterator<T>,
                                  public Iterator<T, std::bidirectional_iterator_tag>
    {
    protected:
        typedef T iterator_type;
        typedef typename ft::iterator_traits<T>::difference_type difference_type;
        typedef typename ft::iterator_traits<T>::reference reference;
        typedef typename ft::iterator_traits<T>::const_reference const_reference;
        typedef typename ft::iterator_traits<T>::pointer pointer;
        typedef typename ft::iterator_traits<T>::value_type value_type;
        pointer _ptr;

    public:
        BidirectionalIterator(const BidirectionalIterator &_iterator)
        {
            this->_ptr = _iterator._ptr;
        }
        BidirectionalIterator &operator=(const BidirectionalIterator &_iterator)
        {
            if (this == _iterator)
                return (*this);
            *this = _iterator;
            return (*this);
        }
        BidirectionalIterator(pointer ptr) : _ptr(ptr){};
        virtual ~BidirectionalIterator() {}
        BidirectionalIterator &operator--()
        {
            this->_ptr--;
            return (*this);
        }
        BidirectionalIterator operator--(int)
        {
            BidirectionalIterator tmp = *this;
            --(*tmp);
            return (tmp);
        }
        BidirectionalIterator operator*()
        {
            this->_ptr--;
            return *(this->_ptr);
        }
    };
}

#endif