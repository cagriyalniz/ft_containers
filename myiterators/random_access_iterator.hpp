#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP
namespace ft
{
    template <typename T>
    class random_access_iterator
    {
        public:
/*             using iterator                  = random_access_iterator<T>;
            using iterator_category         = std::random_access_iterator_tag;
            using value_type                = T;
            using pointer                   = T*;
            using reference                 = T&;
            using difference_type           = std::ptrdiff_t;
            using const_iterator            = random_access_iterator<const T>; */
			typedef random_access_iterator<T> 			iterator;
			typedef std::random_access_iterator_tag 	iterator_category;
			typedef T 									value_type;
			typedef T* 									pointer;
            typedef T& 									reference;
			typedef std::ptrdiff_t 						difference_type;
			typedef random_access_iterator<const T> 	const_iterator;

        private:
            pointer _pointer;

        public:
        random_access_iterator(): _pointer(NULL) {}
        //explicit random_access_iterator(pointer ptr) : _pointer(ptr) {}
        random_access_iterator(pointer ptr) : _pointer(ptr) {}
        ~random_access_iterator(){}
        random_access_iterator(const random_access_iterator& src) {*this = src;}
        random_access_iterator& operator=(const random_access_iterator& right_hand_side)
        {
            this->_pointer = right_hand_side._pointer;
            return *this;
        }

        pointer base(void)const //nonmember functions'da _pointer'a erişmek için
        {
            return (this->_pointer);
        }

        pointer getPointer(void)const
        {
            return (this->_pointer);
        }

        operator const_iterator() const {return const_iterator(_pointer);}


        bool operator==(const iterator& right_hand_side)
        {
            return this->_pointer == right_hand_side._pointer;
        }

        bool operator!=(const iterator& right_hand_side)
        {
            return this->_pointer != right_hand_side._pointer;
        }

        bool operator<(const iterator& right_hand_side)
        {
            return this->_pointer < right_hand_side._pointer;
        }

        bool operator<=(const iterator& right_hand_side)
        {
            return this->_pointer <= right_hand_side._pointer;
        }

        bool operator>(const iterator& right_hand_side)
        {
            return this->_pointer > right_hand_side._pointer;
        }

        bool operator>=(const iterator& right_hand_side)
        {
            return this->_pointer >= right_hand_side._pointer;
        }


		//prefix post fix için içlerine cout yazilacak
        iterator& operator++(void)
        {
            this->_pointer++;
            return (*this);
        }

        iterator operator++(int)
        {
            iterator tmp = *this;
            ++(*this);
            return (tmp);
        }

        iterator& operator--(void)
        {
            this->_pointer--;
            return (*this);
        }

        iterator operator--(int)
        {
            iterator tmp = *this;
            --(*this);
            return (tmp);
        }


        iterator operator+(int right_hand_side)
        {
            return (iterator(this->_pointer + right_hand_side));
        }

/*         iterator& operator+(int right_hand_side)
        {
            this->pointer += right_hand_side;
            return (*this);
        } */

        iterator operator-(int right_hand_side)
        {
            return (iterator(this->_pointer - right_hand_side));
        }

/*         iterator& operator-(int right_hand_side)
        {
            this->_pointer -= right_hand_side;
            return (*this);
        } */


        int operator+(const iterator &right_hand_side)
        {
            return (this->_pointer + right_hand_side._pointer);
        }

        int operator-(const iterator &right_hand_side)
        {
            return (this->_pointer - right_hand_side._pointer);
        }

        reference operator[] (const int n) const {return (this->_pointer[n]);} //reference --> T&
        reference operator* (void) const {return *(this->_pointer);}
        pointer operator->(void) {return (this->_pointer);}

    };

    //nonmember functions
    template<class T>
    bool operator==(const ft::random_access_iterator<T>& lhs, const ft::random_access_iterator<T>& rhs)
    {
        return lhs.getPointer() == rhs.getPointer();
    }

    template<class T>
    bool operator!=(const ft::random_access_iterator<T>& lhs, const ft::random_access_iterator<T>& rhs)
    {
        return lhs.getPointer() != rhs.getPointer();
    }

    template<class T>
    bool operator<(const ft::random_access_iterator<T>& lhs, const ft::random_access_iterator<T>& rhs)
    {
        return lhs.getPointer() < rhs.getPointer();
    }

    template<class T>
    bool operator<=(const ft::random_access_iterator<T>& lhs, const ft::random_access_iterator<T>& rhs)
    {
        return lhs.getPointer() <= rhs.getPointer();
    }

    template<class T>
    bool operator>(const ft::random_access_iterator<T>& lhs, const ft::random_access_iterator<T>& rhs)
    {
        return lhs.getPointer() > rhs.getPointer();
    }

    template<class T>
    bool operator>=(const ft::random_access_iterator<T>& lhs, const ft::random_access_iterator<T>& rhs)
    {
        return lhs.getPointer() >= rhs.getPointer();
    }

    template<class T_L, class T_R>
    bool operator==(const ft::random_access_iterator<T_L>& lhs, const ft::random_access_iterator<T_R>& rhs)
    {
        return lhs.getPointer() == rhs.getPointer();
    }
    
    template<class T_L, class T_R>
    bool operator!=(const ft::random_access_iterator<T_L>& lhs, const ft::random_access_iterator<T_R>& rhs)
    {
        return lhs.getPointer() != rhs.getPointer();
    }

    template<class T_L, class T_R>
    bool operator<(const ft::random_access_iterator<T_L>& lhs, const ft::random_access_iterator<T_R>& rhs)
    {
        return lhs.getPointer() < rhs.getPointer();
    }

    template<class T_L, class T_R>
    bool operator<=(const ft::random_access_iterator<T_L>& lhs, const ft::random_access_iterator<T_R>& rhs)
    {
        return lhs.getPointer() <= rhs.getPointer();
    }

    template<class T_L, class T_R>
    bool operator>(const ft::random_access_iterator<T_L>& lhs, const ft::random_access_iterator<T_R>& rhs)
    {
        return lhs.getPointer() > rhs.getPointer();
    }

    template<class T_L, class T_R>
    bool operator>=(const ft::random_access_iterator<T_L>& lhs, const ft::random_access_iterator<T_R>& rhs)
    {
        return lhs.getPointer() >= rhs.getPointer();
    }
}

#endif