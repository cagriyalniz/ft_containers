#ifndef RBTREE
#define RBTREE

#include <memory>
#include "../iterators/Tree_Iterator.hpp"


template<class Value, class Compare = std::less<Value>, class Alloc = std::allocator<Value> >
class RBTree
{
    public:
        typedef Value value_type;
        typedef Compare value_compare;
        typedef Alloc allocator_type;
        typedef typename Alloc::template
			                rebind<Node<Value> >::other            node_allocator;

        typedef typename node_allocator::pointer node_pointer;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef std::ptrdiff_t difference_type;
        typedef std::size_t size_type;
        typedef TreeIter<Value> iterator;
        typedef TreeIter<const Value> const_iterator;
        typedef ft::reverse_iterator<iterator> reverse_iterator;
        typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
    
    private:
        allocator_type _val_alloc;
        node_allocator _node_alloc;
        value_compare _compare;
        node_pointer _nill;
        node_pointer _header;
        node_pointer _root;
        size_type _size;

        //helper functions
        node_pointer tree_min(node_pointer n) const
        {
            while (n != NULL && !is_nil(n->left))
                n = n->left;
            return n;
        }

        node_pointer tree_max(node_pointer n) const
        {
            while (n!= NULL &&!is_nil(n->right))
                n = n->right;
            return n;
        }

        void _rotate_right(node_pointer node)
        {
            node_poiner y;

            y = node->left;
            node->left = y->right;
            if(!is_nil(y->right))
                y->right->parent = node;
            y->parent = node->parent;
            if(node->parent == NULL)
                _root = y;
            else if(node == node->parent->left)
                node->parent->left = y;
            else
                node->parent->right = y;
            y->right = node;
            node->parent = y;
        }

        void _rotate_left(node_pointer node)
        {
            node_poiner y;

            y = node->right;
            node->right = y->left;
            if(!is_nil(y->left))
                y->left->parent = node;
            y->parent = node->parent;
            if(node->parent == NULL)
                _root = y;
            else if(node == node->parent->right)
                node->parent->right = y;
            else
                node->parent->left = y;
            y->left = node;
            node->parent = y;
        }

        node_pointer _insert(node_pointer new_node)
        {
            if (_root == _header)
                _root = new_node;
            else
                _insert_to_node(_root, new_node);
            return new_node;
        }

        node_pointer _insert_to_node(node_pointer root, node_pointer new_nood)
        {
            if (_compare(*new_node->value, *root->value))
            {
                if(!is_nil(root->left))
                    return (_insert_to_node(root->right, new_nood));
                root->left = new_nood;
            }
            else
            {
                if(!is_nil(root->right))
                    return (_insert_to_node(root->right, new_nood));
                root->right = new_nood;
            }
            new_nood->parent = root;
            return (new_nood);
        }

        node_pointer _insert_into_tree(node_pointer new_node, node_pointer where)
        {
            if (_root == _header)
                _root = new_node;
            else
                _insert_to_node(where, new_node);
            return (new_node);
        }


};

#endif