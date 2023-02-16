#ifndef INPUT_ITERATOR_HPP
#define INPUT_ITERATOR_HPP

namespace ft {
    template <class T>
    class InputIterator {
    public:    
        typedef T value_type;
        typedef std::ptrdiff_t difference_type;
        typedef T* pointer;
        typedef T& reference;
        typedef std::input_iterator_tag iterator_category;

        InputIterator() : _ptr(NULL) { }
        explicit InputIterator(T* ptr) : _ptr(ptr) { }
        InputIterator(const InputIterator& src) { *this = src; }
        InputIterator& operator=(const InputIterator& rhs) { _ptr = rhs._ptr; return *this; }
        ~InputIterator() { }

        reference operator*() const { return *_ptr; }
        pointer operator->() const { return _ptr; }

        InputIterator& operator++() { ++_ptr; return *this; }
        InputIterator operator++(int) { InputIterator tmp(*this); ++(*this); return tmp; }

        bool operator==(const InputIterator& rhs) const { return _ptr == rhs._ptr; }
        bool operator!=(const InputIterator& rhs) const { return !(*this == rhs); }

    private:
        T* _ptr;
    };
}

#endif 

/*
Sınıf, bir göstericiye sahip olduğu için _ptr adında bir özel 
üye değişkene sahiptir. _ptr değişkeni, 
ft_input_iterator sınıfının öğelerine erişim sağlamak için kullanılır. 
Sınıfın diğer üye fonksiyonları, 
std::input_iterator sınıfı için standart olanların tamamını uygular.
*/