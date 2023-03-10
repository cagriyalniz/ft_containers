#ifndef TREEITER_HPP
#define TREEITER_HPP

#include <memory>
#include "../utils/tree.hpp"
#include "./Iterator_Traits.hpp"


namespace ft
{
    template<class T, class Node_ptr>
    class TreeIter : public std::iterator<std::bidirectional_iterator_tag, T>
    {
        public:
            typedef T                                                   iterator_type;
            typedef std::bidirectional_iterator_tag                     iterator_category;
            typedef typename ft::iterator_traits<T>::value_type             value_type;
            typedef typename ft::iterator_traits<T>::difference_type        difference_type;
            typedef typename ft::iterator_traits<T>::pointer                pointer;
            typedef typename ft::iterator_traits<T>::reference              reference;

        private:
            Node_ptr _it;
        
        public:
            TreeIter(): _it(nullptr) {};
            explicit TreeIter(Node_ptr x): _it(x) {};

            template <class Iter>
            TreeIter(const TreeIter<Iter, Node_ptr>& node_it): _it(node_it.base()) {};

            Node_ptr    base() const 
            {
                return (this->_it);
            }

            reference operator*() const
            {
                return (this->_it->key);
            }

            TreeIter& operator++()
            {
                this->_it = successor(this->_it);
                return (*this);
            }

            TreeIter operator++(int)
            {
                TreeIter tmp(*this);
                ++(*this);
                return (tmp);
            }

            TreeIter& operator--()
            {
                this->_it = predecessor(this->_it);
                return (*this);
            }

            TreeIter operator--(int)
            {
                TreeIter tmp(*this);
                --(*this);
                return (tmp);
            }

            pointer operator->()
            {
                return (&(operator*()));
            }

            reference operator[](difference_type n) const
            {
                return (*(this->_it + n));
            }
    };

    template<class T, class Node_ptr>
    bool operator== (const TreeIter<T, Node_ptr>& lhs, const TreeIter<T, Node_ptr>& rhs)
    {
        return (lhs.base() == rhs.base());
    }

    template<class T, class Node_ptr>
    bool operator!= (const TreeIter<T, Node_ptr>& lhs, const TreeIter<T, Node_ptr>& rhs)
    {
        return (lhs.base() != rhs.base());
    }

    template<class T, class Node_ptr>
    bool operator< (const TreeIter<T, Node_ptr>& lhs, const TreeIter<T, Node_ptr>& rhs)
    {
        return (lhs.base() < rhs.base());
    }

    template<class T, class Node_ptr>
    bool operator<= (const TreeIter<T, Node_ptr>& lhs, const TreeIter<T, Node_ptr>& rhs)
    {
        return (lhs.base() <= rhs.base());
    }

    template<class T, class Node_ptr>
    bool operator> (const TreeIter<T, Node_ptr>& lhs, const TreeIter<T, Node_ptr>& rhs)
    {
        return (lhs.base() > rhs.base());
    }

    template<class T, class Node_ptr>
    bool operator>= (const TreeIter<T, Node_ptr>& lhs, const TreeIter<T, Node_ptr>& rhs)
    {
        return (lhs.base() >= rhs.base());
    }


}

#endif