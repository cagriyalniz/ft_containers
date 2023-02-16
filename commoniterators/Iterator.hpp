#ifndef ITERATOR_HPP
#define ITERATOR_HPP

namespace ft
{
    
    #include <cstddef> 
    template <typename T, typename Category>
    class Iterator
    {
    protected:
        typedef T iterator_type;
        typedef typename ft::iterator_traits<T>::difference_type    difference_type;
        typedef typename ft::iterator_traits<T>::reference          reference;
        typedef typename ft::iterator_traits<T>::const_reference    const_reference;
        typedef typename ft::iterator_traits<T>::pointer            pointer;
        typedef typename ft::iterator_traits<T>::value_type         value_type;
        typedef Category iterator_category;
        pointer _ptr;
    private:
    public:
        Iterator(const Iterator &_iterator)
        {
            this->_ptr = _iterator._ptr;
        }
        Iterator &operator=(const Iterator &_iterator)
        {
            if (this == _iterator)
                return (*this);
            *this = _iterator;
            return (*this);
        }
        Iterator(pointer ptr) : _ptr(ptr){};
        virtual ~Iterator() {}
        Iterator &operator++()
        {
            _ptr++;
            return (*this);
        }
        Iterator operator++(int)
        {
            Iterator tmp = *this;
            ++(*tmp);
            return (tmp);
        }

        // bool operator!=(const Iterator &_iterator)
        // {
        //     return (_ptr != _iterator._ptr);
        // }
        // bool operator==(const Iterator &_iterator)
        // {
        //     return this->_ptr == _iterator._ptr;
        // }

        // bool operator<(const Iterator &_iterator)
        // {
        //     return this->_ptr < _iterator._ptr;
        // }

        // bool operator<=(const Iterator &_iterator)
        // {
        //     return this->_ptr <= _iterator._ptr;
        // }

        // bool operator>(const Iterator &_iterator)
        // {
        //     return this->_ptr > _iterator._ptr;
        // }

        // bool operator>=(const Iterator &_iterator)
        // {
        //     return this->_ptr >= _iterator._ptr;
        // }
    };
}

#endif