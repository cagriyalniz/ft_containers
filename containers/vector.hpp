//dizayn: https://cplusplus.com/reference/vector/vector/?kw=vector

#pragma once
#include <stddef.h>
#include <memory> // typename A = std::allocator<T>
#include <iostream>
#include <string>
#include "vectorIterator.hpp"
#include "../iterators/RandomAccess_Iterator.hpp"
#include "../iterators/Reverse_Iterator.hpp"
#include "../utils/type_traits.hpp"
namespace ft
{

	/*
	member type 			|	definition																				|	notes

	value_type				|	The first template parameter (T)														|
	allocator_type			|	The second template parameter (Alloc)													|	defaults to: allocator<value_type>
	reference				|	allocator_type::reference																|	for the default allocator: value_type&
	const_reference			|	allocator_type::const_reference															|	for the default allocator: const value_type&
	pointer					|	allocator_type::pointer																	|	for the default allocator: value_type*
	const_pointer			|	allocator_type::const_pointer															|	for the default allocator: const value_type*
	iterator				|	a random access iterator to value_type													|	convertible to const_iterator
	const_iterator			|	a random access iterator to const value_type											|
	reverse_iterator		|	reverse_iterator<iterator>																|
	const_reverse_iterator	|	reverse_iterator<const_iterator>														|
	difference_type			|	a signed integral type, identical to: iterator_traits<iterator>::difference_type		|	usually the same as ptrdiff_t
	size_type				|	an unsigned integral type that can represent any non-negative value of difference_type	|	usually the same as size_t

	*/
    template <class T, class Alloc = std::allocator<T> >
    class vector{
        public:
            typedef T                                       value_type; //Element type
            typedef Alloc                                   allocator_type; //
            typedef typename Alloc::reference               reference; //Reference to element
            typedef typename Alloc::const_reference         const_reference; //Reference to constant element
            typedef typename Alloc::pointer                 pointer;   //Pointer to element
            typedef typename Alloc::const_pointer           const_pointer;   //Pointer to const element
            typedef ft::RandomAccessIterator<value_type>             iterator;
            typedef ft::RandomAccessIterator<const value_type>		const_iterator;
            //typedef ft::ConstVectorIterator<T>            const_iterator;
            typedef ft::ReverseIterator<iterator>          		reverse_iterator;
            typedef ft::ReverseIterator<const_iterator>          		const_reverse_iterator;
            //typedef ft::ConstReverseVectorIterator<T>     const_reverse_iterator;
            typedef ptrdiff_t                               difference_type; //	Difference between two pointers/iterators // #include <stddef.h>
            typedef std::size_t                             size_type;
			
        private:
            size_type                                       _size;
            size_type                                       _capacity;
            Alloc                                           _allocator;
            value_type                                      *_data;//my_code
            //pointer                                        _data;
        

	/*
	member functions

	(constructor)		Construct vector (public member function)
	(destructor)		Vector destructor (public member function)
	operator=			Assign content (public member function)

	*/	

        public:
            explicit vector(const allocator_type& alloc = allocator_type()): _size(0), _capacity(0), _allocator(alloc), _data(NULL){}
            
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): _size(n), _capacity(n), _allocator(alloc), _data(NULL)
			{
			    _data = _allocator.allocate(_capacity);
			    for (size_type i = 0; i < this->_size; i++)
			        this->_allocator.construct(&this->_data[i], val);
			}

			template <class InputIterator>
			explicit vector(InputIterator first, InputIterator sec, const allocator_type &alloc = allocator_type(), typename ft::enable_if<!is_integral<InputIterator>::value, bool>::type = true): _size(0), _capacity(0), _data(NULL), _allocator(alloc)
			{
			    assign(first, sec);
			};

			public:
            vector(const vector& other):_size(other._size), _capacity(other._capacity), _allocator(other._allocator), _data(other._data){}
			
			vector &operator=(const vector &vector)
        	{
            	if (this == &vector)
            	    return (*this);
            	*this = vector;
            	return (*this);
        	}
            ~vector(){};

/*
member functions - iterators:
begin		Return iterator to beginning 						-> iterator begin() 		 || const_iterator begin() const
end			Return iterator to end 								-> iterator end()   		 || const_iterator end() const
rbegin		Return reverse iterator to reverse beginning 		-> reverse_iterator rbegin() || const_reverse_iterator rbegin() const
rend		Return reverse iterator to reverse end 
cbegin		Return const_iterator to beginning 
cend		Return const_iterator to end 
crbegin		Return const_reverse_iterator to reverse beginning 
crend		Return const_reverse_iterator to reverse end 

*/

		//------------Iterator Functions------------------------//
			//begin
			//end
			//rbegin
			//rend

            iterator begin(){return iterator(this->_data);}
			const_iterator begin() const { return const_iterator(this->_data); }

			iterator end(){return iterator(this->_data + this->_size);}
			const_iterator end() const {return const_iterator(this->_data + this->_size);}

            reverse_iterator rbegin(){ return (reverse_iterator(this->end())); }
            const_reverse_iterator rbegin() const { return (const_reverse_iterator(this->end())); }
			
            reverse_iterator rend(){return (reverse_iterator(this->begin()));}
            const_reverse_iterator rend() const {return (const_reverse_iterator(this->begin()));}
            /* const_iterator cbegin(){return const_iterator(this->_data);}
            const_reverse_iterator crend(){return const_iterator(this->_data[_size]);} */
		//------------Iterator Functions end------------------------//

/*
member functions - capacity:
size			Return size (public member function)
max_size		Return maximum size (public member function)
resize			Change size (public member function)
capacity		Return size of allocated storage capacity (public member function)
empty			Test whether vector is empty (public member function)
reserve			Request a change in capacity (public member function)
shrink_to_fit	Shrink to fit (public member function)

*/

 		//------------Capacity Functions------------------------//
			//size
			//max_size
			//resize
			//capacity
			//empty
			//reserve
			//shrink_to_fit c++11

            size_t size() const {return this->_size;}

            size_t max_size() const {return this->_allocator.max_size();}

			
			void resize(size_type n, value_type val = value_type())
			{
				if (n == this->_size)
					return ;
				if (n < this->_size)
				{
					size_type i = n;
					while(i != this->_size)
						this->_allocator.destroy(&this->_data[i++]);
				}
				else
				{
					size_type i = n;
					size_type oldSize = this->_size;
					while (i > oldSize)
					{
						this->push_back(val);
						i--;
					}
				}
				this->_size = n;
			}

            size_t capacity() const {return this->_capacity;}

			bool empty()
			{
				if (this->_size)
					return (false);
				return (true);
			}
			


			void reserve(size_t size)
			{
				this->_reAlloc(size);
			}

		//------------Capacity Functions end------------------------//

	/*
	member functions - element access:
	operator[]	Access element (public member function)
	at			Access element (public member function)
	front		Access first element (public member function)
	back		Access last element (public member function)
	data		Access data (public member function)

	*/

		//------------Element Access------------------------//
			//at
			//operator[]
			//front
			//back
			//data




			reference at(size_type pos)
			{
				this->checkIndex(pos);
				return (this->_data[pos]);
			}

			reference operator[](int pos)
			{
				//this->checkIndex(pos);
				return (_data[pos]);
			}

			allocator_type get_allocator() const
        	{
            return (this->_allocator);
        	}

/* 			reference operator[](size_type pos) const
			{
				this->checkIndex(pos);
				return (this->_data[pos]);
			} */

			reference front(void)
			{
				return (this->_data[0]);
			}

			reference back(void)
			{
				return (this->_data[this->_size - 1]);
			}

        //------------Element Access end------------------------//

	/*
	member functions - modifiers:
	assign			Assign vector content (public member function)
	push_back		Add element at the end (public member function)
	pop_back		Delete last element (public member function)
	insert			Insert elements (public member function)
	erase			Erase elements (public member function)
	swap			Swap content (public member function)
	clear			Clear content (public member function)
	emplace			Construct and insert element (public member function)
	emplace_back	Construct and insert element at the end (public member function)
	*/
			//------------Modifiers Functions------------------------//
			//clear
			//insert
			//emplace c++11
			//erase
			//push_back
			//emplace_bacj c++11
			//pop_back
			//swap
			
            void clear()
            {
                this->_allocator.destroy(this->_data);
                this->_size = 0;
            }

			size_type distance_forward(iterator first, iterator end)
			{
				size_type dis = 0;
				while(1)
				{
					dis++;
					first++;
					if (first == end)
						break;

				}
				return dis;
			}

			size_type distance_back(iterator first, iterator end)
			{
				size_type dis = 0;
				while(1)
				{
					dis++;
					first--;
					if (first == end)
						break;
				}
				return dis;
			}

			iterator insert(iterator position, const value_type& val)
            {
				size_type index = position - begin();
            	if (this->_size >= this->_capacity)
            	{
            	    _smart_reAlloc(this->_size + 1);
            	    position = begin() + index;
            	}
            	iterator last = end() - 1;
            	while (last >= position)
            	{
            	    *(last + 1) = *last;
            	    --last;
            	}
            	this->_allocator.construct(&(*(position)), val);
            	++this->_size;
            	return (begin() + index);
            }

            void insert(iterator position, size_type n,const value_type& val)
            {
                size_type index = position - begin();
            	if (this->_size + n > this->_capacity)
            	{
            	    _smart_reAlloc(this->_size + n);
            	    position = begin() + index;
            	}
            	iterator last = end() - 1;
            	while (last >= position)
            	{
            	    *(last + n) = *last;
            	    --last;
            	}
            	for (iterator it = position; it != position + n; ++it)
            	    this->_allocator.construct(&(*it), val);
            	this->_size += n;
            }

            //emplace c++11

			iterator erase(iterator pos)
            {
                //std::cout<<"\nerase func 1 arg"<<std::endl;
  				iterator iter = pos;
				
				this->_allocator.destroy(&(*pos));
				while (iter != (this->end() - 1))
					this->_allocator.construct(&(*iter), *(++iter));
				this->_size--;
				return (pos);
            }

            iterator erase(iterator pos_start, iterator pos_end)
            {
                //std::cout<<"\nerase func 2 arg"<<std::endl;
                int count = 0;
                size_type newCapacity = this->_capacity;
  				iterator iter = pos_start;
				while (iter != pos_end)
				{
					this->_allocator.destroy(&(*iter));
					iter++;
					count++;
				}
				iter = this->begin();
				while (iter != (this->end() - 1))
					this->_allocator.construct(&(*iter), *(++iter));

				this->_capacity = newCapacity;
                this->_size-= count;
                return pos_start;
            }

		   void push_back(value_type value)
			{
			    this->_smart_reAlloc(this->_size + 1);
            	this->_allocator.construct(&this->_data[this->_size], value);
            	this->_size++;
			}

			//emplace_back

            void pop_back(void)
            {
                if (this->_size == 0)
                    return ;
                this->_allocator.destroy(this->_data + this->_size - 1);
                this->_size--;
            }




			void swap(vector& other)
			{
				size_type tempSize = other._size;
				size_type tempCapacity = other._capacity;
				Alloc	  tempAlloc = other._allocator;
				pointer   tempArray = other._data;

				other._size = this->_size;
				other._capacity = this->_capacity;
				other._allocator = this->_allocator;
				other._data = this->_data;

				this->_size = tempSize;
				this->_capacity = tempCapacity;
				this->_allocator = tempAlloc;
				this->_data = tempArray; 
			}


			template< class InputIt >
			void assign(InputIt first,
						InputIt last,
						typename ft::enable_if<!ft::is_integral<InputIt>::value, bool>::type = false)
			{
				if (this->_data)
					this->_allocator.deallocate(this->_data, this->_capacity);
				this->_size = last - first;
				if (this->_capacity < this->_size)
					this->_capacity = this->_size;
				this->_data = this->_allocator.allocate(this->_capacity);
				for (size_type i = 0; i < this->_size; i++)
					this->_allocator.construct(&this->_data[i], *(first + i));
			}

			void assign (size_type n, const value_type& val)
			{
				reserve(n);
				clear();
				this->_size = n;
				for (size_type i = 0; i < this->_size; i++)
					this->_allocator.construct(&this->_data[i],val);
			}
		//------------Modifiers Functions end------------------------//


	/*
	member functions - allocator:
	get_allocator	Get allocator (public member function)
	*/	

		//------------Allocator Functions------------------------//


		//------------Allocator Functions end------------------------//

			
			//helping funcs
			size_type find_new_capacity(size_type n)
            {
                if (this->_capacity == 0)
                    return (n);
                if (this->_capacity < n + this->_size)
                    return (this->_capacity*2);
                return this->_capacity;
            }
			

            size_type find_size_by_two_position(iterator pos_start, iterator pos_end)
            {
                size_type newSize = 0;
                while(pos_start != pos_end)
                {
                    newSize++;
                    pos_start++;
                }
                return this->_size - newSize;
            }

			//memory functions
          
			void	_reAlloc(size_type newCapacity)
			{
				value_type	*newBlock;
				if (newCapacity < this->_capacity)
					return ;
				newBlock = this->_allocator.allocate(newCapacity);
				for (size_type i = 0; i < this->_size; i++)
					this->_allocator.construct(&newBlock[i], this->_data[i]);
				this->_allocator.deallocate(this->_data, this->_capacity);
				this->_data = newBlock;
				this->_capacity = newCapacity;
			} 

						



			void	_smart_reAlloc(size_type newCapacity)
			{
				if (newCapacity <= this->_capacity)
					return ;
				if (this->_size == 0)
                {
					this->_reAlloc(1);
                }
				else if(newCapacity > (this->_size * 2))
					this->_reAlloc(newCapacity);
				else
					this->_reAlloc(this->_size * 2);
			}






			void _open_space(size_type n, size_type index_to_insert)
			{
			    this->_smart_reAlloc(this->_size + n);

			    for (size_type i = this->_size + n - 1; i >= index_to_insert; i--)
			        this->_allocator.construct(&this->_data[i], this->_data[i - n]);

			    this->_size += n;
			}

/* void openSpace(size_type n, size_type index)
{
    if (index > this->_size)
        throw std::out_of_range("Index is out of range.");

    if (n == 0)
        return;

    size_type newSize = this->_size + n;
    size_type oldCapacity = this->_capacity;
	if (oldCapacity == 0)
		oldCapacity = 1;
    // If the new size exceeds the current capacity, reallocate the memory.
    if (newSize > oldCapacity)
    {
        // Double the capacity to reduce the number of reallocations.
        while (newSize > oldCapacity)
            oldCapacity *= 2;

        reallocateMemory(oldCapacity);
    }

    // Move the elements after the insertion point to make space for the new elements.
    for (size_type i = this->_size - 1; i >= index; i--)
    {
        this->_allocator.construct(&this->_data[i + n], std::move(this->_data[i]));
        this->_allocator.destroy(&this->_data[i]);
    }

    // Construct the new elements in the open space.
    for (size_type i = index; i < index + n; i++)
    {
        this->_allocator.construct(&this->_data[i], value_type());
    }

    this->_size = newSize;
}
 */



void reallocateMemory(size_type newCapacity)
{
    pointer newData = this->_allocator.allocate(newCapacity);

    for (size_type i = 0; i < _size; i++)
    {
        this->_allocator.construct(&newData[i], std::move(this->_data[i]));
        this->_allocator.destroy(&this->_data[i]);
    }

    this->_allocator.deallocate(this->_data, this->_capacity);
    this->_data = newData;
    this->_capacity = newCapacity;
}





			void checkIndex(size_type pos)
			{
				if (pos >= this->_size)
					throw OutOfBoundsException(pos);
			}

			class OutOfBoundsException : public std::exception
			{
				size_t _pos;

				public:
					OutOfBoundsException(int pos): _pos(pos){}
					virtual const char* what() const throw()
					{
						return ("out of index\n");
					}
 			};

    };

/* template< class T, class Alloc >
	bool operator!=( const vector<T,Alloc>& lhs,
		                 const vector<T,Alloc>& rhs ){
		return !(lhs == rhs);
	} */

/*
Non-member function overloads:

relational operators	Relational operators for vector (function template)
swap					Exchange contents of vectors (function template)
*/

	template< class T, class Alloc >
	void swap( ft::vector<T,Alloc>& lhs, ft::vector<T,Alloc>& rhs )
	{
		lhs.swap(rhs);
	}

/* 	template <class T, class Alloc>
	bool operator == (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	} */

	template <class T, class Alloc>
	bool operator != (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}

/* 	template <class T, class Alloc>
	bool operator < (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}
 */
	template <class T, class Alloc>
	bool operator <= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return ((lhs < rhs) || (lhs == rhs));
	}

	template <class T, class Alloc>
	bool operator > (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs == rhs)
			return (false);
		return (!(lhs < rhs));
	}

	template <class T, class Alloc>
	bool operator >= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return ((lhs > rhs) || (lhs == rhs));
	}


}
