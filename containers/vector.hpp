#pragma once
#include <stddef.h>
#include <memory> // typename A = std::allocator<T>
#include <iostream>
#include "vectorIterator.hpp"
#include "../iterators/random_access_iterator.hpp"
namespace ft
{
    template <class T, class Alloc = std::allocator<T> >
    class vector{
        //datalar, capacity, size, alloc_type
        protected:

        public:
            typedef T                                       value_type; //Element type
            typedef Alloc                                   allocator_type; //
            typedef typename Alloc::reference                   referance; //Reference to element
            typedef typename Alloc::const_reference             const_referance; //Reference to constant element
            typedef typename Alloc::pointer                     pointer;   //Pointer to element
            typedef typename Alloc::const_pointer               const_pointer;   //Pointer to const element
            typedef ft::random_access_iterator<T>             iterator;
            typedef ft::ConstVectorIterator<T>              const_iterator;
            typedef ft::ReverseVectorIterator<T>            reverse_iterator;
            typedef ft::ConstReverseVectorIterator<T>       const_reverse_iterator;
            typedef ptrdiff_t                               difference_type; //	Difference between two pointers/iterators // #include <stddef.h>
            typedef std::size_t                             size_type;
        private:
            size_t                                          _size;
            size_t                                          _capacity;
            size_t                                          _max_size;
            Alloc                                           _allocator;
            value_type*                                     _array;//my_code
            //pointer                                         _array;
        
        public:
            vector(const allocator_type& alloc = allocator_type()): _size(0), _capacity(0), _allocator(alloc), _array(NULL){}
            vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): _size(n), _capacity(n), _allocator(alloc), _array(this->_allocator.allocate(this->_capacity))
            {
                for (size_type i = 0; i < this->_size; i++)
                    this->_allocator.construct(&this->_array[i], val);
            }
            ~vector(){};
            vector(const vector& other):_size(0), _capacity(0), _allocator(other._allocator), _array(NULL){ *this = other;};
            

			//------------Element Access------------------------//
			//at
			//operator[]
			//front
			//back
			//data

			referance at(size_type pos)
			{
				this->checkIndex(pos);
				return (this->_array[pos]);
			}

			referance operator[](size_type pos)
			{
				this->checkIndex(pos);
				return (this->_array[pos]);
			}

/* 			referance operator[](size_type pos) const
			{
				this->checkIndex(pos);
				return (this->_array[pos]);
			} */

			referance front(void)
			{
				return (this->_array[0]);
			}

			referance back(void)
			{
				return (this->_array[this->_size - 1]);
			}


            //------------Iterator Functions------------------------//
			//begin
			//end
			//rbegin
			//rend

            iterator begin(){return iterator(this->_array);}
            iterator end(){return iterator(this->_array + this->_size);}
            iterator rbegin(){return reverse_iterator(this->_array);}
            iterator rend(){return reverse_iterator(this->_array[_size]);}
            //const_iterator cbegin(){return const_iterator(this->_array);}
            //const_reverse_iterator crend(){return const_iterator(this->_array[_size]);}
		//-------------------------------------------------------//


			//------------Capacity Functions------------------------//
			//empty
			//size
			//max_size
			//reserve
			//capacity
			//shrink_to_fit c++11

			bool empty()
			{
				if (this->_size)
					return (false);
				return (true);
			}

			
            size_t size() const {return this->_size;}

            size_t max_size() const {return this->_allocator.max_size();}

			void reserve(size_t size)
			{
				this->_reAlloc(size);
			}

            size_t capacity() const {return this->_capacity;}
		//-------------------------------------------------------//
            


			//------------Modifiers Functions------------------------//
			//clear
			//insert
			//emplace c++11
			//erase
			//push_back
			//emplace_bacj c++11
			//pop_back
			//resize
			//swap
			
            void clear()
            {
                this->_allocator.destroy(this->_array);
                this->_size = 0;
            }

			iterator insert(iterator pos, const value_type& val)
            {
                std::cout<<"\ninsert 2 parameter"<<std::endl;
                
                size_type index = pos - this->begin();
                this->_open_space(1, index);
                this->_allocator.construct(&this->_array[index], val);
				this->_size++;
				return (this->begin() + index);
            }

            void insert(iterator pos, size_type n,const value_type& val)
            {
                std::cout<<"\ninsert 3 parameter"<<std::endl;

				size_type index = pos - this->begin();
                this->_open_space(n, index);
                for (size_type i = 0; i < n; i++)
                    this->_allocator.construct(&this->_array[index + i], val);
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
                this->_allocator.construct(&this->_array[this->_size], value);
                this->_size++;

            }

			//emplace_back

            void pop_back(void)
            {
                if (this->_size == 0)
                    return ;
                this->_allocator.destroy(this->_array + this->_size - 1);
                this->_size--;
            }

			void resize(size_type n, value_type value = value_type())
			{
				if (n == this->_size)
					return ;
				if (n < this->_size)
				{
					size_type i = n;
					while(i != this->_size)
						this->_allocator.destroy(&this->_array[i++]);
				}
				else
				{
/* 					size_type i = this->_size;
					this->_reAlloc(n);
					while(i < n)
						this->_allocator.construct(&this->_array[i++], value); */
					size_type i = n;
					size_type oldSize = this->_size;
					while (i > oldSize)
					{
						this->push_back(value);
						i--;
					}
				}
				this->_size = n;
			}


			void swap(vector& other)
			{
				size_type tempSize = other._size;
				size_type tempCapacity = other._capacity;
				Alloc	  tempAlloc = other._allocator;
				pointer   tempArray = other._array;

				other._size = this->_size;
				other._capacity = this->_capacity;
				other._allocator = this->_allocator;
				other._array = this->_array;

				this->_size = tempSize;
				this->_capacity = tempCapacity;
				this->_allocator = tempAlloc;
				this->_array = tempArray; 
			}
		//-------------------------------------------------------//
			
			
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
                //std::cout<<"_reAlloc _capacity : "<<this->_capacity<<"new capacity: "<<newCapacity<<std::endl;

				if (newCapacity < this->_capacity)
					return ;
				newBlock = this->_allocator.allocate(newCapacity);
				for (size_type i = 0; i < this->_size; i++)
					this->_allocator.construct(&newBlock[i], this->_array[i]);
				this->_allocator.deallocate(this->_array, this->_capacity);
				this->_array = newBlock;
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
				for (size_type i = this->_size + n - 1; i > (index_to_insert + n - 1); i--)
					this->_allocator.construct(&this->_array[i], this->_array[i - n]);
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

	template< class T, class Alloc >
	void swap( ft::vector<T,Alloc>& lhs, ft::vector<T,Alloc>& rhs )
	{
		lhs.swap(rhs);
	}

	template <class T, class Alloc>
	bool operator == (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class T, class Alloc>
	bool operator != (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T, class Alloc>
	bool operator < (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

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
