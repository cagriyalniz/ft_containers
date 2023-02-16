#ifndef BIDIRECTIONAL_ITERATOR_HPP
#define BIDIRECTIONAL_ITERATOR_HPP


#include <cstddef>

namespace ft
{
/*     // Forward declaration for use in ft::iterator_traits
    template<class T> class BidirectionalIterator;

    // Iterator traits for ft::BidirectionalIterator
    template<class T>
    struct iterator_traits<BidirectionalIterator<T> >
    {
        typedef std::ptrdiff_t                      difference_type;
        typedef T                                   value_type;
        typedef T*                                  pointer;
        typedef T&                                  reference;
        typedef std::bidirectional_iterator_tag     iterator_category;
    }; */

    // BidirectionalIterator class definition
    template<class T>
    class BidirectionalIterator
    {
    public:
        typedef T                                           value_type;
        typedef std::ptrdiff_t                              difference_type;
        typedef T*                                          pointer;
        typedef T&                                          reference;
        typedef const T&                                    const_reference;
        typedef std::bidirectional_iterator_tag             iterator_category;

        // Default constructor
        BidirectionalIterator() : ptr_(NULL) {}

        // Parameterized constructor
        explicit BidirectionalIterator(pointer ptr) : ptr_(ptr) {}

        // Copy constructor
        BidirectionalIterator(const BidirectionalIterator& other) : ptr_(other.ptr_) {}

        // Assignment operator
        BidirectionalIterator& operator=(const BidirectionalIterator& other)
        {
            ptr_ = other.ptr_;
            return *this;
        }

        // Dereference operator
        reference operator*() const
        {
            return *ptr_;
        }

        // Member access operator
        pointer operator->() const
        {
            return ptr_;
        }

        // Prefix increment operator
        BidirectionalIterator& operator++()
        {
            ++ptr_;
            return *this;
        }

        // Postfix increment operator
        BidirectionalIterator operator++(int)
        {
            BidirectionalIterator temp(*this);
            ++ptr_;
            return temp;
        }

        // Prefix decrement operator
        BidirectionalIterator& operator--()
        {
            --ptr_;
            return *this;
        }

        // Postfix decrement operator
        BidirectionalIterator operator--(int)
        {
            BidirectionalIterator temp(*this);
            --ptr_;
            return temp;
        }

        // Equality operator
        bool operator==(const BidirectionalIterator& other) const
        {
            return ptr_ == other.ptr_;
        }

        // Inequality operator
        bool operator!=(const BidirectionalIterator& other) const
        {
            return !(*this == other);
        }

    private:
        pointer ptr_;
    };
}

#endif

/*
Bu örnekte, ft::iterator_traits struct'ı, 
ft::ft_Bidirectional_iterator sınıfının bir türü için özellikler tanımlar.
 Ardından ft::ft_Bidirectional_iterator sınıfı, 
 standart std::bidirectional_iterator_tag etiketini kullanarak 
 bir çift yönlü ileriye doğru iteratörü taklit eder.
  Sınıf, bir önceki elemana ve sonraki elemana doğru hareket etmek için 
hem önek hem de son ek üye işlevleri sağlar.
*/