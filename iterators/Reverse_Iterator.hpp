/* #ifndef REVERSEITERATOR_HPP
#define REVERSEITERATOR_HPP

namespace ft
{

    template<class Iterator>
    class reverse_iterator
    {
        public:
            typedef Iterator iterator_type;
            typedef typename iterator_traits<Iterator>::difference_type difference_type;
            typedef typename iterator_traits<Iterator>::value_type value_type;
            typedef typename iterator_traits<Iterator>::pointer pointer;
            typedef typename iterator_traits<Iterator>::reference reference;
            typedef typename iterator_traits<Iterator>::iterator_category iterator_category;

            reverse_iterator() : current() {}
            explicit reverse_iterator(iterator_type x) : current(x) {}

            template <class Iter>
            reverse_iterator(const reverse_iterator<Iter>& other) : current(other.base()) {}

            iterator_type base() const { return current; }
            reference operator*() const {
                iterator_type tmp = current;
                return *--tmp;
            }
            pointer operator->() const { return &(operator*()); }

            reverse_iterator& operator++() {
                --current;
                return *this;
            }

            reverse_iterator operator++(int) {
                reverse_iterator tmp = *this;
                --current;
                return tmp;
            }

            reverse_iterator& operator--() {
                ++current;
                return *this;
            }

            reverse_iterator operator--(int) {
                reverse_iterator tmp = *this;
                ++current;
                return tmp;
            }

            reverse_iterator operator+(difference_type n) const { return reverse_iterator(current - n); }
            reverse_iterator& operator+=(difference_type n) { current -= n; return *this; }
            reverse_iterator operator-(difference_type n) const { return reverse_iterator(current + n); }
            reverse_iterator& operator-=(difference_type n) { current += n; return *this; }

            reference operator[](difference_type n) const { return *(*this + n); }

        private:
            iterator_type current;
    };

        template <class Iterator>
        bool operator==(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
        {
            return x.base() == y.base();
        }

        template <class Iterator>
        bool operator!=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
        {
            return x.base() != y.base();
        }

        template <class Iterator>
        bool operator<(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
        {
            return y.base() < x.base();
        }

        template <class Iterator>
        bool operator>(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
        {
            return y < x;
        }

        template <class Iterator>
        bool operator<=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
        {
            return !(y < x);
        }

        template <class Iterator>
        bool operator>=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
        {
            return !(x < y);
        }

        template <class Iterator>
        typename reverse_iterator<Iterator

}

#endif */