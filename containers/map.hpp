#ifndef MAP_HPP
#define MAP_HPP

#include "../utils/pair.hpp"


namespace ft
{
    template<class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
    class map
    {
        public:
            typedef Key key_type;
            typedef T mapped_type;
            typedef pair<const Key, T> value_type;
            typedef std::size_t size_type;
            typedef std::ptrdiff_t difference_type;
            typedef Compare key_compare;
            typedef Allocator allocator_type;
            typedef value_type & reference;
            typedef const value_type & const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            
            //iterator
            //const_iterator
            //reverse_iterator
            //const_reverse_iterator
            //node_type
        private:
            class pair_compare
            {
                key_compare _compare;

                public:
                    pair_compare(const key_compare & compare) : _compare(compare){}
                    bool operator()(const value_type & x, const value_type & y) const{
                        return (_compare(x.first, y.first));
                    }
            };
        /* public:
            typedef pair_compare value_compare;
            typedef typename tree::iterator iterator; */

        private:
            allocator_type _alloc;
            tree_type _tree;
            key_compare _compare;
    };


}

#endif