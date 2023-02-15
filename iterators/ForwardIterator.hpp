#ifndef OUTPUTITERATOR_HPP
#define OUTPUTITERATOR_HPP

#include "Iterator.hpp"

namespace ft
{
    template <typename T>
    class ForwardIterator : public InputIterator<T, std::input_iterator_tag>,
                            public OutputIterator<T, std::output_iterator_tag>
    {
    private:
        typedef ForwardIterator<T> forwardIterator;

    public:
        typedef ptrdiff_t difference_type;
        typedef T value_type;
        typedef T *pointer;
        typedef T &reference;
        ForwardIterator()
        {
            this->_ptr = NULL;
        }
        ForwardIterator(const forwardIterator &other)
        {
            this->_ptr = other._ptr;
        }
        ForwardIterator &operator=(const forwardIterator &other)
        {
            if (this == other)
                return (*this);
            *this = other;
            return (*this);
        }
        ~ForwardIterator();
        ForwardIterator(pointer ptr)
        {
            this->_ptr = ptr;
        }
        reference operator*() const
        {
            return *(this->_ptr);
        };

        ForwardIterator &operator++()
        {
            ForwardIterator tmp = *this;
            _ptr++;
            return (tmp);
        }
    };
}
#endif