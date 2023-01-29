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
            vector(const vector& other){if(*this != &other){ *this = other;}};
            
            //iterators
            iterator begin(){return iterator(this->_array);}
            iterator end(){return iterator(this->_array + this->_size);}
            iterator rbegin(){return reverse_iterator(this->_array);}
            iterator rend(){return reverse_iterator(this->_array[_size]);}
            const_iterator cbegin(){return const_iterator(this->_array);}
            const_reverse_iterator crend(){return const_iterator(this->_array[_size]);}

            //capacity
            size_t size() const {return _size;}
            size_t max_size() const {return this->_allocator.max_size();}
            size_t capacity() const {return _capacity;}

            //data

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

            void clear()
            {
                this->_allocator.destroy(this->_array);
                this->_size = 0;
            }


            size_type find_new_capacity(size_type n)
            {
                if (this->_capacity == 0)
                    return (n);
                if (this->_capacity < n + this->_size)
                    return (this->_capacity*2);
                return this->_capacity;
            }

            void insert(iterator pos, const value_type& val)
            {
                std::cout<<"\ninsert 2 parameter"<<std::endl;
                int mySize = this->_size;
                size_type new_capacity = find_new_capacity(1);
                value_type *newBlock;
                int j = 0;

				newBlock = this->_allocator.allocate(new_capacity);
                iterator myvec = this->begin();
                if (mySize == 0)
                {
				    this->_allocator.construct(&newBlock[j], val);
                    this->_array = newBlock;
				    this->_capacity = new_capacity;//
                    this->_size = mySize + 1;//
                }
                else
                {
                    for(size_type i = 0; i < this->_size; i++)
                    {
                        if (myvec != pos)
				    	    this->_allocator.construct(&newBlock[j], *myvec);
                        else
                        {
				    	    this->_allocator.construct(&newBlock[j++], val);
				    	    this->_allocator.construct(&newBlock[j], *myvec);
                        }
                        myvec++;
                        j++;
                    }
                    this->clear();//
                    this->_array = newBlock;
				    this->_capacity = new_capacity;//
                    this->_size = mySize + 1;//
                }
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


            size_type find_capacity_by_two_position(iterator pos_start, iterator pos_end)
            {
                size_type newCapacity = 0;
                while(pos_start != pos_end)
                {
                    newCapacity++;
                    pos_start++;
                }
                return newCapacity;
            }

            iterator erase(iterator pos)
            {
                std::cout<<"\nerase func 1 arg"<<std::endl;
  				iterator iter = pos;
				
				this->_allocator.destroy(&(*pos));
				while (iter != (this->end() - 1))
					this->_allocator.construct(&(*iter), *(++iter));
				this->_size--;
				return (pos);
            }

            iterator erase(iterator pos_start, iterator pos_end)
            {
                std::cout<<"\nerase func 2 arg"<<std::endl;
                value_type	*newBlock;
                int j = 0;
                int count = 0;
                size_type newCapacity = find_capacity_by_two_position(pos_start, pos_end);
				newBlock = this->_allocator.allocate(newCapacity);

				for (size_type i = 0; i < this->_size; i++)
                {
                    if (*pos_start == this->_array[i])
                        while(this->_array[i] != *pos_end)
                            {
                                count++;
                                i++;
                            }
                    this->_allocator.construct(&newBlock[j++], this->_array[i]);
                }
				this->clear();//mycode
				this->_array = newBlock;
				this->_capacity -= count;
                this->_size-= count;
                return pos_start;
            }

		    void push_back(value_type value)
            {
                //std::cout<<"push_back size : "<<this->_size<<"this->_capacity : "<< this->_capacity<<std::endl;
                this->_smart_reAlloc(this->_size + 1);
                //std::cout<<"this->_array[this->_size] : "<<this->_array[this->_size]<<std::endl;
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
            
			//resize
			

    };


}
