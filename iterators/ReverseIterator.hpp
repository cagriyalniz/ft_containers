#ifndef ReverseIterator_HPP
#define ReverseIterator_HPP

#include "./IteratorTraits.hpp"

class IteratorTraits;
template <class T>
class ReverseIterator
{
protected:
    T current;

public:
    typedef T iterator_type;
    typedef typename ft::iterator_traits<T>::difference_type difference_type;
    typedef typename ft::iterator_traits<T>::reference reference;
    typedef typename ft::iterator_traits<T>::const_reference const_reference;
    typedef typename ft::iterator_traits<T>::pointer pointer;
    typedef typename ft::iterator_traits<T>::value_type value_type;

    ReverseIterator() : current() {}
    explicit ReverseIterator(T other) : current(other) {}
    template <class U>
    ReverseIterator(const ReverseIterator<U> &other) : current(other.base()) {}
    template <class U>
    ReverseIterator &operator=(const ReverseIterator<U> &other)
    {
        if (this == other)
            return (*this);
        this->current = other.base();
        *this = other;
        return (*this);
    }
    ~ReverseIterator();
    iterator_type base() const
    {
        return (this->current);
    }

    // Dereference
    reference operator*() const
    {
        return *(this->current - 1);
    };

    // Member selection via a pointer
    pointer operator->() const
    {
        return &(operator*());
    };

    // Brackets (array subscript)
    reference operator[](difference_type n) const
    {
        return *(*this + n);
    }

    // Unary Operators (Postfix increment/decrement, Prefix increment/decrement)
    ReverseIterator &operator--()
    {
        this->current++;
        return (*this);
    }
    ReverseIterator operator--(int)
    {
        ReverseIterator tmp(*this);
        ++(this->current);
        return (tmp);
    }
    ReverseIterator &operator++()
    {
        this->current++;
        return (*this);
    }
    ReverseIterator operator++(int)
    {
        ReverseIterator tmp(*this);
        ++(this->current);
        return (tmp);
    }

    // Addition/subtraction
    ReverseIterator operator+(int other)
    {
        return (ReverseIterator(this->current + other));
    }
    ReverseIterator operator-(int other)
    {
        return (ReverseIterator(this->current - other));
    }
};

template <class T>
ReverseIterator<T> operator+(typename ReverseIterator<T>::difference_type n, const ReverseIterator<T> &rev_it)
{
    return (rev_it + n);
}

template <class _Iter1, class _Iter2>
typename ReverseIterator<_Iter1>::difference_type operator-(const ReverseIterator<_Iter1> &__left, const ReverseIterator<_Iter2> &__right)
{
    return (__right.base() - __left.base());
}

// Relational Operators
template <class T1, class T2>
bool operator!=(const ReverseIterator<T1> &__left, const ReverseIterator<T2> &__right)
{
    return (__left.base() != __right.base());
}

template <class T1, class T2>
bool operator==(const ReverseIterator<T1> &__left, const ReverseIterator<T2> &__right)
{
    return (__left.base() == __right.base());
}

template <class T1, class T2>
bool operator<(const ReverseIterator<T1> &__left, const ReverseIterator<T2> &__right)
{
    return (__left.base() > __right.base());
}

template <class T1, class T2>
bool operator<=(const ReverseIterator<T1> &__left, const ReverseIterator<T2> &__right)
{
    return (__left.base() >= __right.base());
}

template <class T1, class T2>
bool operator>(const ReverseIterator<T1> &__left, const ReverseIterator<T2> &__right)
{
    return (__left.base() < __right.base());
}

template <class T1, class T2>
bool operator>=(const ReverseIterator<T1> &__left, const ReverseIterator<T2> &__right)
{
    return (__left.base() <= __right.base());
}
#endif