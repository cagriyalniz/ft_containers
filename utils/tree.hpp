#ifndef TREE_HPP
#define TREE_HPP

#include "../iterators/TreeIter.hpp"
#include "../iterators/Reverse_Iterator.hpp"
#include "memory"


namespace ft
{
    template <class T>
    struct Node
    {
        public:
            typedef T																value_type;

			T 																		key;
			Node*																	left;
			Node*																	right;
			Node*																	parent;
			int																		height;
		
		public:
		    Node(); key() {}
			Node(T key) : key(key) {}
    };

	template < class T, class Compare, class Allocator >
	class Tree
	{
		public:
			typedef T																value_type;
			typedef Compare															key_compare;
			typedef Allocator       												allocator_type;
		
		private:
			typedef typename allocator_type::template rebind<Node<T> >:: other		allocator_node; //??
			typedef typename allocator_node::reference								node_reference;
			typedef typename allocator_node::const_reference						node_const_reference;
			typedef typename allocator_node::difference_type						node_difference_type;
			typedef typename allocator_node::pointer                                node_pointer;
			typedef typename allocator_node::const_pointer							node_const_pointer;
			typedef typename allocator_node::size_type								node_size_type;
			typedef Node<value_type>												Node_type;
			typedef Node_type*														Node_ptr;
		
		public:
			typedef typename allocato_type::reference								reference;
			typedef typename allocator_type::const_reference						const_reference;
			typedef typename allocator_type::difference_type						difference_type;
			typedef typename allocator_type::pointer								pointer;
			typedef typename allocator_type::const_pointer							const_pointer;
			typedef typename allocator_type::size_type                              size_type;
			typedef typename value_type::first_type									key_type;
			typedef typename value_type::second_type                                mapped_type;
			typedef ft::TreeIter<pointer, Node_ptr>									iterator;
			typedef ft::TreeIter<const_pointer, Node_ptr>                    		const_iterator;
			typedef ft::ReverseIterator<iterator>   								reverse_iterator;
			typedef ft::ReverseIterator<const_iterator>                           	const_reverse_iterator;

		private:
			allocator_node 															_alloc;
			key_compare																_comp;
			Node_ptr                                                                _root;
			Node_ptr																_end;
			int																		_size;
		
		public:
		    Tree(const key_compare &compare = key_compare(), const allocator_type& alloc = allocator_type()): _comp(compare), _size(0)
			{
				this->_alloc = alloc;
				this->_end = this->_makeNode(value_type());
				this->_root = this->_end;
			}

			~Tree() {}

		public:
			//iterator begin(){return iterator(_root)} //mycode
			iterator begin()
			{
				return (iterator(Min()));
			}

			//const_iterator begin() const{return const_iterator(_root)} //mycode
			const_iterator begin() const
			{
				return (const_iterator(Min()));
			}

			iterator end()
			{
				return (iterator(this->_end));
			}

			const_iterator end() const
			{
				return (const_iterator(this->_end));
			}

			reverse_iterator rbegin()
			{
				return (reverse_iterator(end()));
			}

			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(end()));
			}

			reverse_iterator rend()
			{
				return (reverse_iterator(begin()));
			}

			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(begin()));
			}

		public:
			bool empty() const 
			{
				if (this->_size)
					return (false);
				return (true);
			}

			size_type size() const
			{
				return (this->_size);
			}

			//size_type max_size() const {return this->_alloc.max_size();}//mycode

			size_type max_size() const
			{
				return (std::min<size_type>(std::numeric_limits<size_type>::max() / sizeof(Node_type), std::numeric_limits<difference_type>::max()));
			}

		private:
		    void _destroy(Node_ptr node)
			{
				if (node != nullptr)
				{
					_destroy(node->left);
					_destroy(node->right);
					this->_alloc.destroy(node);
					this->_alloc.deallocate(node, 1);
				}
			}

		    Node_ptr makeNode(value_type key)
			{
				Node_ptr newnode = this->_alloc.allocate(1);
				this->_alloc.construct(newnode, key);
				newnode->height = 1;
				newnode->parent = nullptr;
				newnode->left = nullptr;
				newnode->right = nullptr;
				return (newnode);
			}

			void _deleteNode(Node_ptr* node)//Node_ptr node
			{
				this->_alloc.destroy(*node);
				this->_alloc.deallocate(*node, 1);
				*node = nullptr;
			}

			int _Height(Node_ptr h)
			{
				if (h == nullptr)
					return (0);
				return(h->height);
			}

			int _getBalanceFactor(Node_ptr n)
			{
				if (n == NULL)//n == nullptr
				    return (0);
				return (_Height(n->left) - _Height(n->right));
			}

			Node_ptr _leftRotate(Node_ptr node)
			{
				/* Node_ptr newnode = this->_alloc.allocate(1);
                this->_alloc.construct(newnode, node->key);
                newnode->parent = node->parent;
                newnode->left = node->left;
                if (node->left!= nullptr)
                    node->left->parent = newnode;
                newnode->right = node->right;
                if (node->right!= nullptr)
                    node->right->parent = newnode;
                newnode->height = _Height(node->left) + _Height(node->right) + 1;
                node->parent = newnode;
                node->left = newnode;
                node->right = nullptr;
                return (newnode); */
				Node_ptr y =  node->right;
				Node_ptr T2 = node->left;
				Node_ptr p = node->parent;

				y->left = node;
				if (p != this->_end)
				{
					if (p->left == node)
                        p->left = y;
                    else
                        p->right = y;
				}
				y->parent = node->parent;
				node->parent = y;
				if (T2 != nullptr)
					T2->parent = node;
				node->height = std::max(_Height(node->left), _Height(node->right)) + 1;// _Height(node->left) + _Height(node->right) + 1
				y->height = std::max(_Height(y->left), _Height(y->right)) + 1;
				return y;
			}

			Node_ptr _rightRotate(Node_ptr node)
			{
				/* Node_ptr newnode = this->_alloc.allocate(1);
                this->_alloc.construct(newnode, node->key);
                newnode->parent = node->parent;
                newnode->left = node->left;
                if (node->left!= nullptr)
                    node->left->parent = newnode;
                newnode->right = node->right;
                if (node->right!= nullptr)
                    node->right->parent = newnode;
                newnode->height = _Height(node->left) + _Height(node->right) + 1;
                node->parent = newnode;
                node->left = newnode;
                node->right = nullptr;
                return (newnode); */
                Node_ptr child =  node->left;
                Node_ptr T2 = child->right;
				Node_ptr p = node->parent;
				child->right = node;
				node->left = T2;
				if (p!= this->_end)
				{
					if (p->left == node)
                        p->left = child;
                    else
                        p->right = child;
				}
				child->parent = node->parent;
				node->parent = child;
				if (T2!= nullptr)
				    T2->parent = node;
				node->height = std::max(_Height(node->left), _Height(node->right)) + 1;// _Height(node->left) + _Height(node->right) + 1
				child->height = std::max(_Height(child->left), _Height(child->right)) + 1;
				return child;
			}

			Node_ptr _RightLeftRotate(Node_ptr node)
			{
				node->right = _rightRotate(node->right);
				return (_leftRotate(node));
			}

			Node_ptr _LeftRightRotate(Node_ptr node)
			{
				node->left = _leftRotate(node->left);
                return (_rightRotate(node));
			}

			Node_ptr _reBalance(Node_ptr node)
			{
				int balanceFactor = _getBalanceFactor(node);
				if (balanceFactor > 1)
				{
					if (_getBalanceFactor(node->left) >= 0)
						return (_rightRotate(node));
					else
					    return (_LeftRightRotate(node));
				}
				else if (balanceFactor < -1)
				{
					if (_getBalanceFactor(node->right) <= 0)
                        return (_leftRotate(node));
                    else
                        return (_RightLeftRotate(node));
				}
				return (node);
			}

			Node_ptr _insert(Node_ptr temp, Node_ptr newNode)
			{
			}

	};







	template<class Node_ptr>
	Node_ptr _TreeMin(Node_ptr temp)
	{
		while (temp->left != nullptr)
			temp = temp->left;
		return (temp);
	};

	template<class Node_ptr>
	Node_ptr _TreeMax(Node_ptr temp)
	{
		while (temp->right != nullptr)
			temp = temp->right;
		return (temp);
	};
	//Bir düğümün sıralı ardılı, sağ alt ağacında en az değere 
	//sahip olan düğümdür, yani sağ alt ağacının en soldaki çocuğu.
	/*  Hangi ataların ardıl olduğunu bulmak için, 
	ebeveyninin sol çocuğu olan bir node'la karşılaşana kadar ağaçta köke
	doğru ilerleyebiliriz. Böyle bir node bulunursa, sıra dışı ardıl onun üst öğesidir; */
	template<class Node_ptr>
	Node_ptr successor(Node_ptr node)
	{
		if (node->right)
			return (_TreeMin(node->right));

		Node_ptr temp = node->parent;
		while (temp && temp->right == node)
		{
			node = temp;
			temp = temp->parent;
		}
		return (temp);
	};

	template<class Node_ptr>
	Node_ptr predecessor(Node_ptr node)
	{
		if (node->left)
			return (_TreeMax(node->left));

		Node_ptr temp = node->parent;
		while (temp && temp->left == node)
		{
			node = temp;
			temp = temp->parent;
		}
		if (temp == nullptr)
			return (node);
		return (temp);
	};
}


#endif