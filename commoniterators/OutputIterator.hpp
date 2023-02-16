#ifndef OUTPUTITERATOR_HPP
#define OUTPUTITERATOR_HPP

#include "Iterator.hpp"

namespace ft
{
    template <typename T>
    class OutputIterator : public Iterator<T, std::output_iterator_tag>
    {
    private:
        typedef OutputIterator<T> outputIterator;

    public:
        typedef ptrdiff_t difference_type;
        typedef T value_type;
        typedef T *pointer;
        typedef T &reference;
        OutputIterator()
        {
            this->_ptr = NULL;
        }
        OutputIterator(const outputIterator &other)
        {
            this->_ptr = other._ptr;
        }
        OutputIterator &operator=(const outputIterator &other)
        {
            if (this == other)
                return (*this);
            *this = other;
            return (*this);
        }
        ~OutputIterator();
        OutputIterator(pointer ptr)
        {
            this->_ptr = ptr;
        }
        reference operator*(const T &other)
        {
            this->_ptr = other;
            return *(this->_ptr);
        }

        // reference operator*(const T &other1)
        // {
        //     T *ptrCpy = this->_ptr++;
        //     ptrCpy = other1;
        //     return *(ptrCpy);
        // }
    };
}
#endif