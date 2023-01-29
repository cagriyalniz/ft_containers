#pragma once

namespace ft
{
    template<class T>
    class reverse_iterator
    {
        public:
            using iterator_type          = reverse_iterator<T>;
            using iterator_category = std::forward_iterator_tag;
            using value_type        = T;
            using pointer           = T*;
            using reference         = T&;
            using difference_type   = std::ptrdiff_t;
            using const_iterator    = random_access_iterator<const T>;
        
        private:
            iterator_type _current;

        public:
            reverse_iterator(void): _current(NULL){};

            //explicit reverse_iterator(iterator_type it): _current(it){};
            reverse_iterator(iterator_type it): _current(it){};

            reverse_iterator(const reverse_iterator<Iter> &other): _current(other._current){};
            template <class Iter>
            reverse_iterator(const reverse_iterator<Iter>& other): _current(other.getCurrent()){};

            ~reverse_iterator(void){};  

            iterator_type getCurrent(void) const
            {
                return (this->_current);
            }

            reference operator[](difference_type n) const
            {
                return (this->getCurrent()[])
            }




    };
}