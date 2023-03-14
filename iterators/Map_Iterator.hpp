#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

#include <memory>
#include "./Iterator_Traits.hpp"
#include "../utils/type_traits.hpp"
//#include "type1_or_type2.hpp"


namespace ft
{
    template <class Key, class T, class Compare, typename Node, bool B>
    class map_iterator
    {
        public:
            typedef Key                                                 			key_type;
            typedef Compare                                             			key_compare;
            typedef T                                                   			mapped_type;
            typedef ft::pair<const key_type, mapped_type>               			value_type;
            typedef long int                                            			diference_type;
            typedef size_t                                              			size_type;
            typedef std::bidirectional_iterator_tag									iterator_category;
			typedef typename chooseConst<B, value_type&, const value_type&>::type	reference;
			typedef typename chooseConst<B, value_type*, const value_type*>::type	pointer;
			typedef Node*															nodePtr;

		private:
		    nodePtr 	_node;
			nodePtr 	_lastElem;
			key_compare _comp;

		public:
			//def const
			map_iterator(nodePtr node = 0, nodePtr lastElem = 0, const key_compare& comp = key_compare()):
			    _node(node), _lastElem(lastElem), _comp(comp){}
			
			//copy const
			map_iterator(const map_iterator<Key, T, Compare, Node, false>& copy)
			{
				_node = copy.getNode();
                _lastElem = copy.getLastElem();
                _comp = copy.getCompare();
			}

			~map_iterator(){}

			map_iterator& operator=(const map_iterator& other)
			{
				if (this != &other)
				{
                    _node = other._node;
                    _lastElem = other._lastElem;
                    _comp = other._comp;
                }
				return (*this);
			}

			nodePtr getNode() const 
			{
				return _node;
			}

			nodePtr getLastElem() const
			{
				return _lastElem;
			}

			key_compare getCompare() const
			{
				return _comp;
			}

			reference operator*() const 
			{
				return (_node->content);
			}

			pointer operator->() const
			{
				return (&(_node->content));
			}

			// ++int operator
			map_iterator& operator++()
			{
				nodePtr previousNode = _node;

				if (_node == _lastElem)
				{
					_node = _lastElem->right;
					return (*this);
				}
				while (_node != _lastElem && !_comp(previousNode->content.first, _node->content.first))
				{
					if (_node->right && (_node->right == _lastElem || _comp(previousNode->content.first, _node->right->content.first)))
					{
						_node = _node->right;
						Node *tmp = 0;
						if (_node != _lastElem && (tmp = searchMinNode(_node)))
							_node = tmp;
					}
					else
						_node = _node->parent;
				}
				return (*this);
			}
			map_iterator operator++(int)
			{
				map_iterator res(*this);

				if (_node == _lastElem)
				{
					_node = _lastElem->right;
                    return (res);
				}

				while (_node != _lastElem && !_comp(res->first, _node->content.first))
				{
					if (_node->right && (_node->right == _lastElem || _comp(res->first, _node->right->content.first)))
					{
						_node = _node->right;
                        Node *tmp = 0;
                        if (_node!= _lastElem && (tmp = searchMinNode(_node)))
                            _node = tmp;
					}
					else
					    _node = _node->parent;
				}
				return (res);
			}

			map_iterator& operator--()
			{
				nodePtr previousNode = _node;

                if (_node == _lastElem)
                {
                    _node = _lastElem->left;
                    return (*this);
                }
				// Eger ki node sona gelmediyse ve node'un contenti azaltilacak node'un contentinden buyukse dongu devam eder.
                while (_node!= _lastElem &&!_comp(_node->content.first, previousNode->content.first))
                {
					// node'un solu var ise ve node'un solundaki deger azaltilacak node'un contentinden kucuk ise girer.
                    if (_node->left && (_node->left == _lastElem || _comp(_node->left->content.first, previousNode->left->content.first)))
                    {
                        _node = _node->left;
                        Node *tmp = 0;
                        if (_node!= _lastElem && (tmp = searchMaxNode(_node)))
                            _node = tmp;
                    }
                    else
                        _node = _node->parent;
                }
                return (*this);
			}

			map_iterator operator--(int)
			{
				map_iterator res(*this);

                if (_node == _lastElem)
                {
                    _node = _lastElem->left;
                    return (res);
                }

                while (_node!= _lastElem &&!_comp(_node->content.first, res->first))
                {
                    if (_node->left && (_node->left == _lastElem || _comp(_node->left->content.first, res->first)))
                    {
                        _node = _node->left;
                        Node *tmp = 0;
                        if (_node!= _lastElem && (tmp = searchMaxNode(_node)))
                            _node = tmp;
                    }
                    else
                        _node = _node->parent;
                }
                return (res);
			}

			bool operator==(const map_iterator& it) const 
			{
				return (it._node == _node);
			}

			bool operator!=(const map_iterator& it) const
			{
				return (it._node!= _node);
			}

		private:

			Node* searchMaxNode(Node *root)
			{
				/* Node *tmp = 0;
                if (root->left)
                    tmp = searchMaxNode(root->left);
                if (root->right)
                    tmp = searchMaxNode(root->right);
                return tmp; */
				if (root && root != _lastElem && root->right && root->right != _lastElem)
					return searchMaxNode(root->right);
				return root;
				
			}

			Node* searchMinNode(Node *root)
			{
				/* Node *tmp = 0;
                if (root->left)
                    tmp = searchMinNode(root->left);
                if (root->right)
                    tmp = searchMinNode(root->right);
                return tmp; */
				if (root && root != _lastElem && root->left && root->left != _lastElem)
					return searchMinNode(root->left);
				return root;
			}
    };

}

#endif