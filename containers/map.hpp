#ifndef MAP_HPP
#define MAP_HPP

#include "../utils/pair.hpp"
#include "../utils/tree.hpp"
#include "../utils/type_traits.hpp"
#include "../iterators/Map_Iterator.hpp"
#include "../iterators/Rev_Map_Iterator.hpp"
#include <iostream>//std::less
#include <memory>//std::allocator




namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> >
	class map
	{
		private:
			struct Node
			{
				ft::pair<const Key, T> content;
				Node					*parent;
				Node					*left;
				Node					*right;
			};
		
		public:

			typedef Key										key_type;
			typedef Compare									key_compare;
			typedef Alloc									allocator_type;
			typedef T										mapped_type;
			typedef ft::pair<const key_type, mapped_type>	value_type;
			typedef long int								difference_type;
			typedef size_t									size_type;
			typedef T&										reference;
			typedef const T&                                const_reference;
			typedef const T*								pointer;
			typedef const T*								const_pointer;

			typedef typename ft::map_iterator<Key, T, Compare, Node, false> iterator;
			typedef typename ft::map_iterator<const Key, T, Compare, Node, true> const_iterator;
			typedef typename ft::rev_map_iterator<Key, T, Compare, Node, false> reverse_iterator;
			typedef typename ft::rev_map_iterator<Key, T, Compare, Node, true> const_reverse_iterator;

			class value_compare
			{
				friend class map;

				protected:

					key_compare comp;

					value_compare(Compare c) : comp(c) {}

				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;

					bool operator()(const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					}
			};
		
		private:
		    
			Node* 					_root;
			Node*					_lastElem;
			size_type				_size;
			allocator_type			_allocPair;
			key_compare				_comp;
			std::allocator<Node>	_allocNode;
		
		public:
		//def constr
		explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _size(0), _allocPair(alloc), _comp(comp)
		{
			_lastElem = createNode(ft::pair<const key_type, mapped_type>());
			_root = _lastElem;
			_lastElem->left = _lastElem;
			_lastElem->right = _lastElem;
		}

		//Range const
		template>class InputIterator>
		explicit map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = true ):
		    _size(0), _allocPair(alloc), _comp(comp)
			{
				_lastElem = createNode(ft::pair<const key_type, mapped_type>());
				_root = _lastElem;
				_lastElem->left = _lastElem;
				_lastElem->right = _lastElem;

				for (; first != last; ++ first)
					insert(*first);
			}

		//copy constr
		map(const map& x): _size(0), _allocPair(x._allocPair), _comp(x._comp), _allocNode(x._allocNode)
		{
			_lastElem = createNode(ft::pair<const key_type, mapped_type>(*x._lastElem));
            _root = _lastElem;
            _lastElem->left = _lastElem;
            _lastElem->right = _lastElem;

			for(const iterator it = x.begin(); it != x.end(); ++it)
				insert(*it);
		}

		~map()
		{
			clear();
			deallocateNode(_lastElem);
		}

		map& operator=(const map& x)
		{
			/* if (this!= &x)
            {
                map(x).swap(*this);
            }
            return *this; */
			map tmp(x);
			this->swap(tmp);

			return *this;
		}

		iterator begin()
		{
			return iterator(_lastElem->right, _lastElem, _comp);
		}

		const_iterator begin() const
		{
			return const_iterator(_lastElem->right, _lastElem, _comp);
		}

		iterator end()
        {
			return iterator(_lastElem, _lastElem, _comp);
		}

		const_iterator end() const
		{
			return const_iterator(_lastElem, _lastElem, _comp);
		}

		reverse_iterator rbegin() 
		{
//			return reverse_iterator(end());
			return reverse_iterator(_lastElem->left, _lastElem, _comp);
		}

		const_reverse_iterator rbegin() const
		{
			//return const_reverse_iterator(end());
			return (const_reverse_iterator(_lastElem->left, _lastElem, _comp));
		}

		reverse_iterator rend()
		{
			return reverse_iterator(_lastElem, _lastElem, _comp);
		}

		const_reverse_iterator rend() const
		{
			return (const_reverse_iterator(_lastElem, _lastElem, _comp));
		}

		bool empty() const 
		{
			if (_size == 0)
				return (true);
			return (false);
		}

		size_type size() const
		{
			return (_size);
		}

		size_type max_size() const
		{
			return (_allocPair.max_size());
		}


		//element access

		mapped_type& operator[](const key_type& key)
		{
			/* iterator it = find(key);
            if (it!= end())
                return it->second;
            else
                return insert(value_type(key, mapped_type())).first->second; */
			Node* tmp = searchNode(_root, key);
			if (tmp)
				return tmp->content.second;
			
			value_type val = ft::make_pair<key_type, mapped_type>(key, mapped_type());
			_size++;
			return insertNode(_root, val)->content.second;
		}

		//modifiers

		ft::pair<iterator, bool>insert (const value_type& val)
		{
			Node* elemIsPresent = searchNode(_root, val.first);
			if (elemIsPresent)
				return (ft::pair<iterator, bool>(iterator(elemIsPresent, _lastElem, _comp), false));
			
			++_size;
			return ft::pair<iterator, bool>(iterator(insertNode(_root, val), _lastElem, _comp), true);
		}

		iterator insert (iterator position, const value_type& val)
		{
			if (_comp(val->first, position->first))
			{
				/* Node* elemIsPresent = searchNode(_root, val->first);
                if (elemIsPresent)
                    return (iterator(elemIsPresent, _lastElem, _comp)); */
				iterator prev(position);
				--prev;
				while(prev != end() && prev->first >= val.first)
				{
					--position;
					--prev;
				}
			}
			else if (_comp(position->first, val.first))
			{
				/* Node* elemIsPresent = searchNode(_root, val.first);
                if (elemIsPresent)
                    return (iterator(elemIsPresent, _lastElem, _comp)); */
					iterator next(position);
					++next;
					while(next != end() && next->first <= val.first)
					{
						++position;
                        ++next;
					}
			}
			if (position != end() && vaL.first == position->first)
				return (position);
			++_size;
			return iterator(insertNode(position.getNode(), val), _lastElem, _comp);
		}

		template <class InputIterator>
		void insert(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = true)
		{
			while(first != last)
				insert(*first++);
		}

		void erase(iterator position)
		{
			/* if (position!= end() && vaL.first == position->first)
                eraseNode(position.getNode());
            --_size; */
			deleteNode(position.getNode(), position->first);
			--_size;
		}

		size_type erase (const key_type& key)
		{
			size_type ret = deleteNode(_root, key);
			_size -= ret;
			return ret;
		}

		void swap(map& other)
		{
			std::swap(_root, other._root);
            std::swap(_comp, other._comp);
            std::swap(_size, other._size);
            std::swap(_lastElem, other._lastElem);
			std::swap(_allocPair, other._allocPair);
			std::swap(_allocNode, other._allocNode);
		}

		void clear()
		{
			erase(begin(), end());
		}

		key_compare() const
		{
			return _comp;
		}

		value_comp() const
		{
			return value_compare(_comp);
		}

		//operators

		iterator find(const key_type& key)
		{
			Node* tmp = searchNode(_root, key);
			
			if(tmp)
				return iterator(tmp, _lastElem, _comp);
			return end();
		}

	};
    
}

void mapBegin();
void mapEnd();
void mapInsertTest();
void mapRBegin();
void mapREnd();

#endif