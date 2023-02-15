#ifndef INPUTITERATOR_HPP
#define INPUTITERATOR_HPP

#include "Iterator.hpp"

namespace ft
{
    template <typename T>
    class InputIterator : public Iterator<T, std::input_access_iterator_tag>
    {
    private:
        typedef InputIterator<T> inputIterator;

    public:
        typedef ptrdiff_t difference_type;
        typedef T value_type;
        typedef T *pointer;
        typedef T &reference;
        ~InputIterator();
        InputIterator(pointer ptr)
        {
            this->_ptr = ptr;
        }
        reference operator*() const
        {
            return *(this->_ptr);
        };

        // Member selection via a pointer
        pointer operator->() const
        {
            return &(operator*());
        };

        friend bool operator!=(const InputIterator &_inputIterator)
        {
            return (this->_ptr != _inputIterator._ptr);
        }
        friend bool operator==(const InputIterator &_iterator)
        {
            return this->_ptr == _inputIterator._ptr;
        }
    };
}
#endif