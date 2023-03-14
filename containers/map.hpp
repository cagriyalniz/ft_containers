#ifndef MAP_HPP
#define MAP_HPP

#include "../utils/pair.hpp"
//#include "../utils/tree.hpp"
#include "../utils/type_traits.hpp"
#include "../iterators/Map_Iterator.hpp"
#include "../iterators/Rev_Map_Iterator.hpp"
#include <iostream>//std::less
#include <memory>//std::allocator




namespace ft
{

	/*
	member type					definition																					notes
	key_type					The first template parameter (Key)	
	mapped_type					The second template parameter (T)	
	value_type					pair<const key_type,mapped_type>	
	key_compare					The third template parameter (Compare)														defaults to: less<key_type>
	value_compare				Nested function class to compare elements													see value_comp
	allocator_type				The fourth template parameter (Alloc)														defaults to: allocator<value_type>
	reference					allocator_type::reference																	for the default allocator: value_type&
	const_reference				allocator_type::const_reference																for the default allocator: const value_type&
	pointer						allocator_type::pointer																		for the default allocator: value_type*
	const_pointer				allocator_type::const_pointer																for the default allocator: const value_type*
	iterator					a bidirectional iterator to value_type														convertible to const_iterator
	const_iterator				a bidirectional iterator to const value_type	
	reverse_iterator			reverse_iterator<iterator>	
	const_reverse_iterator		reverse_iterator<const_iterator>	
	difference_type				a signed integral type, identical to: iterator_traits<iterator>::difference_type			usually the same as ptrdiff_t
	size_type					an unsigned integral type that can represent any non-negative value of difference_type		usually the same as size_t

	*/
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
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
		template<class InputIterator>
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
			_lastElem = createNode(ft::pair<const key_type, mapped_type>());
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
			if (_comp(val.first, position->first))//val->first
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
			if (position != end() && val.first == position->first)
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

		void erase(iterator first, iterator last)
		{
			while (first != last)
			{
				iterator tmp(first);
				++first;
				erase(tmp);
			}
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

		key_compare key_comp() const
		{
			return _comp;
		}

		value_compare value_comp() const
		{
			return value_compare(_comp);
		}

		//operators

		iterator find(const key_type& key)
		{
			Node* tmp = searchNode(_root, key);
			
			if(tmp)
				return iterator(tmp, _lastElem, _comp);
			return end();//case no match
		}

		const_iterator find(const key_type& key) const
		{
			Node* tmp = searchNode(_root, key);
            
            if(tmp)
                return const_iterator(tmp, _lastElem, _comp);
            return end();//case no match
		}

		size_type count (const key_type& key) const
		{
			Node* tmp = searchNode(_root, key);

			if (tmp)
				return true;
			return false;
		}

		iterator lower_bound(const key_type& key)
		{
			iterator it = begin();

			for(; it != end(); ++it)
				if (!_comp(it->first, key))
					break;
			return it;
		}
		const_iterator lower_bound(const key_type& key) const
		{
			const_iterator it = begin();

            for(; it!= end(); ++it)
                if (!_comp(it->first, key))
                    break;
            return it;
		}

		iterator upper_bound(const key_type& key)
		{
			/* iterator it = end();

            for(; it!= begin(); --it)
                if (!_comp(key, it->first))
                    break;
            return it; */

			iterator it = begin();

			for(; it!= end(); ++it)
				if (_comp(key, it->first))
					break;
			return it;
		}


		const_iterator upper_bound(const key_type& key) const
		{
			const_iterator it = begin();

            for(; it!= end(); ++it)
                if (_comp(key, it->first))
                    break;
            return it;
		}

		/**
		 * @brief Construct a new pair<iterator, iterator>equal range object
		 * key argümanına karşılık gelen elemanları bulmak için kullanılır. equal_range fonksiyonu, pair veri yapısı kullanarak iki adet iterator değeri döndürür. İlk iterator, key değerine eşit olan ilk elemanın konumunu, ikinci iterator ise key değerine eşit olmayan ilk elemanın konumunu işaret eder.

			Fonksiyonun içinde önce, upper_bound fonksiyonu ile key değerinden büyük ilk elemanın konumu bulunur ve bu konum it adlı bir iterator değişkenine atanır. Ardından, it değişkeni kontrol edilir. Eğer it begin() değilse, bir önceki elemana geri alınır (--it). Daha sonra, key değeri ile önceki elemanın anahtar değeri arasındaki karşılaştırma yapılır. Eğer key, önceki elemanın anahtarından daha küçük veya eşitse, it değişkeni önceki elemana ayarlanır.

			Sonra, next adlı bir iterator değişkeni oluşturulur ve it değişkeni end() değilse, next değişkeni it'nin bir sonraki elemanına ayarlanır (++next).

			Son olarak, ft::make_pair fonksiyonu kullanılarak, it ve next değişkenleri bir pair yapısına dönüştürülür ve dönüştürülen pair yapısı fonksiyon tarafından döndürülür.
		 * @param key 
		 */

		pair<iterator, iterator>equal_range(const key_type& key)
		{
			iterator it = upper_bound(key);

			if (it != begin())
			{
				--it;
				if (_comp(key, it->first) || _comp(key, it->first))
					++it;
			}

			iterator next(it);
			if (it != end())
				++next;

			return ft::make_pair<iterator, iterator>(it, next);
		}

		pair<const_iterator, const_iterator>equal_range(const key_type& key) const
		{
			const_iterator it = upper_bound(key);

            if (it!= begin())
            {
                --it;
                if (_comp(key, it->first))
                    ++it;
            }

            const_iterator next(it);
            if (it!= end())
                ++next;

            return ft::make_pair<const_iterator, const_iterator>(it, next);
		}

		//private member funct

		private:
			template <typename U>
			void swap(U& a, U&b)
			{
				U tmp = a;
				a = b;
				b = tmp;
				createNode();
			}

			/**
			 * @brief Create a Node object
			 * 
			 * @param pair 
			 * @return Node* 
			 */
			Node* createNode(const value_type& pair)
			{
				Node* newNode = _allocNode.allocate(1);

				_allocPair.construct(&newNode->content, pair);
				newNode->parent = 0;
				newNode->left = 0;
				newNode->right = 0;

				return newNode;
			}

			void deallocateNode(Node* del)
			{
				_allocPair.destroy(&del->content);
				_allocNode.deallocate(del, 1);
			}

			int heightTree(Node *root, int h)
			{
				/* if (root == NULL)
                    return 0;

                if (root->left == NULL && root->right == NULL)
                    return h;

                int l = heightTree(root->left, h + 1);
                int r = heightTree(root->right, h + 1);

                if (l < h)
                    return l;

                if (r < h)
                    return r;

                return max(l, r); */
				if (!root || root == _lastElem)
					return h - 1;

				int leftH = heightTree(root->left, h + 1);
				int rightH = heightTree(root->right, h + 1);

				if (leftH > rightH)
					return leftH;
				return rightH;
			}

			/**
			 * @brief 
			 * verilen bir key değerini içeren düğümü bulmak için bir Binary Search Tree'si üzerinde dolaşır. root parametresi, ağacın başlangıç düğümüdür ve key parametresi, aranan anahtarın değeridir. Fonksiyon, bir düğümü bulduğunda, bulduğu düğümün bir işaretçisini döndürür; aksi halde, NULL döndürür.

			 *	İlk olarak, if (!root || root == _lastElem) koşulu, root düğümünün NULL ya da _lastElem (ağacın son elemanı) olup olmadığını kontrol eder. Eğer öyleyse, NULL değeri döndürülür, aksi takdirde işleme devam edilir.

			 *	Daha sonra, if (!_comp(root->content.first, key,) && !_comp(key, root->content.first)) koşulu, root düğümünün anahtarının, aranan key değerine eşit olup olmadığını kontrol eder. Eğer öyleyse, root düğümünün bir işaretçisi döndürülür.

			 *	Eğer root düğümünün anahtarı, aranan key değerinden büyükse ve root düğümünün sol alt ağacı (root->left) varsa ve _lastElem değilse, searchNode(root->left, key) fonksiyonu, sol alt ağacın içindeki key değerini aramak için çağrılır. Benzer şekilde, root düğümünün anahtarı, aranan key değerinden küçükse ve root düğümünün sağ alt ağacı (root->right) varsa ve _lastElem değilse, searchNode(root->right, key) fonksiyonu, sağ alt ağacın içindeki key değerini aramak için çağrılır.

			 *	Eğer hiçbir koşul sağlanmazsa, yani root düğümü aranan key değerine eşit değilse ve sol ya da sağ alt ağaç yoksa ya da _lastElem ise, 0 (NULL) döndürülür.
			 * @param root 
			 * @param key 
			 * @return Node* 
			 */
			Node* searchNode(Node* root, key_type key) const
			{
				if (!root || root == _lastElem)
					return NULL;
				
				if (!_comp(root->content.first, key) && !_comp(key, root->content.first))
					return (root);

				if (root->content.first > key && root->left && root->left != _lastElem)
					return (searchNode(root->left, key));
				else if(root->content.first < key && root->right && root->right != _lastElem)
					return searchNode(root->right, key);
				return 0;
			}

			Node* searchMaxNode(Node *root) const
			{
				if (root->right && root->right != _lastElem)
					return searchMaxNode(root->right);
				return root;
			}

			Node* searchMinNode(Node *root) const
			{
				if (root->left && root->left != _lastElem)
					return searchMinNode(root->left);
				return root;
			}

			/**
			 * @brief 
			 * Eğer ağaç boşsa, yeni düğümü kök olarak oluştur ve geri dön. Bu işlemde, kök düğüm, sol ve sağ düğümleri olarak kendisi ve _lastElem olarak adlandırılan sentinelleri gösterecektir.

				Eğer eklemek istenen çiftin anahtar değeri, ağaçta zaten varsa, fonksiyon 0 değerini döndürür.
				
				Eğer eklemek istenen çiftin anahtarı, mevcut düğümün anahtarından küçükse ve mevcut düğümün sol düğümü boş değilse, sol alt ağaca geç ve rekürsif olarak yeni düğüm eklemeyi dene.
				
				Eğer eklemek istenen çiftin anahtarı, mevcut düğümün anahtarından büyükse ve mevcut düğümün sağ düğümü boş değilse, sağ alt ağaca geç ve rekürsif olarak yeni düğüm eklemeyi dene.
				
				Eğer yukarıdaki koşullar sağlanmazsa, yeni bir düğüm oluştur ve uygun konuma yerleştir. Bu işlemde, ağaçta boş bir yer yoksa, _lastElem sentinellerinden birinin altına yerleştirilir. Yeni düğümün anahtarının, mevcut düğümün anahtarından küçük olup olmadığına veya büyük olup olmadığına bağlı olarak, sol veya sağ tarafa yerleştirilir.
				
				Yeni düğümün ebeveyni, eklemek istenen düğümün üzerine yerleştirilir.
				
				Ağacın dengesi korunur ve dengesizlik varsa, rotasyonlar yapılır.
				
				Son olarak, yeni eklenen düğümün işaretçisi döndürülür.
			 * @param insertPos 
			 * @param pair 
			 * @return Node* 
			 */
			Node* insertNode(Node* insertPos, const value_type& pair)
			{
				if (_root == _lastElem)
				{
					_root = createNode(pair);

					_root->left = _lastElem;
					_root->right = _lastElem;
					_lastElem->left = _root;
					_lastElem->right = _root;

					return _root;
				}

				if (insertPos->content.first == pair.first)
					return (0);

				if (_comp(pair.first, insertPos->content.first) && insertPos->left && insertPos->left != _lastElem)
					return insertNode(insertPos->left, pair);
				else if (_comp(insertPos->content.first, pair.first) && insertPos->right && insertPos->right != _lastElem)
					return insertNode(insertPos->right, pair);

				Node *newNode = createNode(pair);

				if (_comp(newNode->content.first, insertPos->content.first) && !insertPos->left)
					insertPos->left = newNode;
				else if (_comp(insertPos->content.first, newNode->content.first) && !insertPos->right)
					insertPos->right = newNode;

				else if (insertPos->left && _comp(newNode->content.first, insertPos->content.first))
				{
					newNode->left = _lastElem;
					_lastElem->right = newNode;
					insertPos->left = newNode;
				}
				else if (insertPos->right && _comp(insertPos->content.first, newNode->content.first))
				{
					newNode->right = _lastElem;
					_lastElem->left = newNode;
					insertPos->right = newNode;
				}
				newNode->parent = insertPos;
				balanceTheTree(&_root, newNode);
				return newNode;
				
			}

			bool deleteNode(Node* deletePos, key_type key)
			{
/* 				if (!deletePos)
                    return false;

                if (deletePos->content.first == key)
                {
                    if (deletePos->left && deletePos->left->content.first == key)
                    {
                        deletePos->left = deleteNode(deletePos->left, key);
                        return true;
                    }
                    else if (deletePos->right && deletePos->right->content.first == key)
                    {
                        deletePos->right = deleteNode(deletePos->right, key);
                        return true;
                    }
                }
                else if (deletePos->content.first == key)
				{
					if (deletePos->right && deletePos->right->content.first == key)
                    {
                        deletePos->right = deleteNode(deletePos->right, key);
                        return true;
                    }
                    else if (deletePos->left && deletePos->left->content.first == key)
                    {
                        deletePos->left = deleteNode(deletePos->left, key);
                        return true;
                    }
				}
				return false; */

				Node* balanceNode = NULL;
				Node* del = searchNode(deletePos, key);
				if (!del)
					return false;
				if (!del->parent)
				{
					//agacta tek bir node var ve _root'u lastElem yaparsak _root 0'ı gostetit ve en son veriyi sileriz
					if(del->left == _lastElem && del->right == _lastElem)
					{
						_root = _lastElem;
						_lastElem->left = _lastElem;
						_lastElem->right = _lastElem;
					}
					//sol tarafta eleman varsa ve sag taraf bossa
					else if(del->left && del->right == _lastElem)
					{
						_root = del->left;
						del->left->parent = 0;
						_lastElem->left = del->left;
						del->left->right = _lastElem;
					}
					//sag tarafta eleman varsa(max 2 eleman) ve sol taraf bos ise
					else if(del->left == _lastElem && del->right)
					{
						_root = del->right;
						del->right->parent = 0;
						_lastElem->right = del->right;
						del->right->left = _lastElem;
					}
					//geriye kalan tum durumlarda soldaki en buyuk eleman en uste cikartilir
					else
					{
						Node* maxNode = searchMaxNode(del->left);

						_allocPair.destroy(&del->content);
						_allocPair.construct(&del->content, maxNode->content);

						return deleteNode(del->left, maxNode->content.first);
					}
				}
				//silinecek node son eleman ise
				else if ((!del->left || del->left == _lastElem) && (!del->right || del->right == _lastElem ))
				{
					balanceNode = del->parent;

					Node* linkToParent = 0;
					if (del->left == _lastElem || del->right == _lastElem)
					{
						linkToParent = _lastElem;
						del->content.first <= del->parent->content.first ? _lastElem->right = del->parent : _lastElem->left = del->parent;
/* 						if(del->content.first <= del->parent->content.first)
						{
							_lastElem->right = del->parent;
						}
						else 
						{
							_lastElem->left = del->parent;
						} */
					}
					del->content.first <= del->parent->content.first ? del->parent->left = del->left : del->parent->right = del->left;
/* 					if (del->content.first <= del->parent->constent.first)
					{
						del->parent->left = linkToParent;
					}
					else
					{
						del->parent->right = linkToParent;
					} */
				}
				//sol tarafi dolu ve sag tarafi bos ise
				else if((del->left && del->left != _lastElem) && (!del->right || del->right == _lastElem))
				{
					balanceNode = del->parent;

					del->content.first <= del->parent->content.first ?
						del->parent->left = del->left : del->parent->right = del->left;
					/*
					if (del->content.first <= del->parent->content.first)
                    {
                        del->parent->left = del->left
                    }
                    else
                    {
                        del->left : del->parent->right = del->left;
                    } */
					del->left->parent = del->parent;

					if (del->right == _lastElem)
					{
						_lastElem->left = del->left;
						del->left->right = _lastElem;
					}
				}
				//sag tarafi dolu ve sol tarafi bos ise
				else if((!del->left || del->left == _lastElem) && del->right && del->right != _lastElem)
				{
					balanceNode = del->parent;

                    del->content.first <= del->parent->content.first?
                        del->parent->left = del->left : del->parent->right = del->left;
                    /*
                    if (del->content.first <= del->parent->content.first)
                    {
                        del->parent->left = del->left
                    }
                    else
                    {
                        del->left : del->parent->right = del->left;
                    } */
                    del->right->parent = del->parent;

                    if (del->left == _lastElem)
                    {
                        _lastElem->right = del->right;
                        del->right->left = _lastElem;
                    }
				}
				// node'un iki tarafı da dolu ise sol tarafın en yuksek degeri ile degistirilir
				else
				{
					Node* maxNode = searchMaxNode(del->left);

					_allocPair.destroy(&del->content);
					_allocPair.construct(&del->content, maxNode->content);

					return deleteNode(del->left, maxNode->content.first);
				}
				balanceTheTree(&_root, balanceNode);
				deallocateNode(del);
				return true;
			}

			int balanceOfSubtrees(Node* node)
			{
/* 				if(node == _root)
                {
                    return 0;
                }
                else
                {
                    return balanceOfSubtrees(node->left) + 1 + balanceOfSubtrees(node->right);
                } */
				if (!node)
					return 0;
				return (heightTree(node->left, 1) - heightTree(node->right, 1));
			}

			/**
			 * @brief 
			 * "nodeGoingUp" adlı bir geçici düğüm değişkeni, "nodeGoingDown" düğümünün sol alt düğümüne atanır.
			 * "nodeGoingDown" düğümünün sol alt düğümü, "nodeGoingUp" düğümünün sağ alt düğümüne atanır.
			 * Eğer "nodeGoingUp" düğümünün sağ alt düğümü varsa, o zaman bu düğümün ebeveyni "nodeGoingDown" olarak atanır.
			 * "nodeGoingUp" düğümünün sağ alt düğümü, "nodeGoingDown" düğümüne atanır.
			 * "nodeGoingUp" düğümünün ebeveyni, "nodeGoingDown" düğümünün ebeveynine atanır.
			 * Eğer "nodeGoingDown" düğümünün ebeveyni varsa ve "nodeGoingDown" düğümüğünün sol alt düğümü ise, "nodeGoingUp" düğümü, "nodeGoingDown" düğümünün ebeveyninin sağ alt düğümüne atanır. Aksi takdirde, "nodeGoingUp" düğümü, "nodeGoingDown" düğümünün ebeveyninin sol alt düğümüne atanır.
			 * "nodeGoingDown" düğümünün ebeveyni, "nodeGoingUp" düğümüne atanır.
			 * Eğer "nodeGoingUp" düğümünün ebeveyni yoksa, o zaman "nodeGoingUp", ağacın kökü olarak işaretlenir.
			 * @param root 
			 * @param nodeGoingDown 
			 */
			void rotateRight(Node** root, Node* nodeGoingDown)
			{
				Node* nodeGoingUp = nodeGoingDown->left;

				nodeGoingDown->left = nodeGoingUp->right;

				if (nodeGoingUp->right)
					nodeGoingUp->right->parent = nodeGoingDown;
				
				nodeGoingUp->right = nodeGoingDown;

				nodeGoingUp->parent = nodeGoingDown->parent;

				if (nodeGoingDown->parent && nodeGoingDown->parent->left == nodeGoingDown)
					nodeGoingDown->parent->right = nodeGoingUp;
				else if (nodeGoingDown->parent)
					nodeGoingDown->parent->right = nodeGoingUp;
				
				nodeGoingDown->parent = nodeGoingUp;
				if (!nodeGoingUp->parent)
					*root = nodeGoingUp;
			}

			void rotateLeft(Node** root, Node* nodeGoingDown)
			{
				Node* nodeGoingUp = nodeGoingDown->right;

                nodeGoingDown->right = nodeGoingUp->left;

                if (nodeGoingUp->left)
                    nodeGoingUp->left->parent = nodeGoingDown;
                
                nodeGoingUp->left = nodeGoingDown;

                nodeGoingUp->parent = nodeGoingDown->parent;

                if (nodeGoingDown->parent && nodeGoingDown->parent->left == nodeGoingDown)
                    nodeGoingDown->parent->left = nodeGoingUp;
                else if (nodeGoingDown->parent)
                    nodeGoingDown->parent->right = nodeGoingUp;
                
                nodeGoingDown->parent = nodeGoingUp;
				if (!nodeGoingUp->parent)
					*root = nodeGoingUp;
			}

			void balanceTheTree(Node** root, Node* node)
			{
/* 				if (node->left)
                    rotateLeft(root, node->left);

                if (node->right)
                    rotateRight(root, node->right); */
				while(node)
				{
					int balance;

					if((balance = balanceOfSubtrees(node)) < -1 && balanceOfSubtrees(node->right) < 0)
						rotateLeft(root, node);
					else if (balance < -1 && balanceOfSubtrees(node->right) >= 0)
					{
						rotateRight(root, node->right);
						rotateLeft(root, node);
					}

					else if (balance > 1 && balanceOfSubtrees(node->left) > 0)
						rotateRight(root, node);
					else if (balance > 1 && balanceOfSubtrees(node->left) <= 0)
					{
						rotateLeft(root, node->left);
                        rotateRight(root, node);
					}
					node = node->parent;
				}
				
			}

	};
    
}

//Iterators

void mapBegin();
void mapEnd();
void mapRBegin();
void mapREnd();

//Capacity
void mapEmpty();
void mapSize();
void mapMaxSize();

//Element access:
void mapBoxBrackets();

//Modifiers:
void mapInsert();
void mapErase();
void mapSwap();
void mapClear();

void mapKeyComp();
void mapValueComp();
#endif