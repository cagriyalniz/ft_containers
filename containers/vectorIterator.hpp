#pragma once

namespace ft
{
    template <class T>
    class VectorIterator
    {
        public:
            typedef T value_type;
            typedef T& reference;
            typedef T* pointer;
        
        protected:
            pointer _ptr;//bunu yazmayıp yukarıdaki pointer'ı kullansak da çalışır

        public:
            VectorIterator(){};
            VectorIterator(const VectorIterator &other){*this = other;};
            VectorIterator(pointer ptr): _ptr(ptr){};
            ~VectorIterator(){};
            VectorIterator &operator=(const VectorIterator &other){_ptr = other._ptr; return (*this);}
            VectorIterator &operator++(void){_ptr++; return (*this);}
            VectorIterator &operator--(void){_ptr--; return (*this);}
            VectorIterator operator+(int n) const{VectorIterator tmp(*this); tmp += n; return (*this);}
            VectorIterator operator-(int n) const{VectorIterator tmp(*this); tmp -= n; return (*this);}
            VectorIterator &operator+=(int n){while(n < 0){(*this)--; n++;}; while(n > 0){(*this)++; n--;}; return (*this);}
            VectorIterator &operator-=(int n){while(n < 0){(*this)++; n++;}; while(n > 0){(*this)--; n--;}; return (*this);}
            //VectorIterator operator++(int){}
            //VectorIterator operator--(int){}
            bool operator==(const VectorIterator &other) const {return _ptr == other._ptr;} //fonksiyon sonundaki const döndürülen değerin değiştirilememesini sağlıyor
            bool operator!=(const VectorIterator &other) const {return _ptr!= other._ptr;}
            bool operator>=(const VectorIterator &other) const {return _ptr >= other._ptr;}
            bool operator>(const VectorIterator &other) const {return _ptr > other._ptr;}
            bool operator<=(const VectorIterator &other) const {return _ptr <= other._ptr;}
            bool operator<(const VectorIterator &other) const {return _ptr < other._ptr;}
            value_type &operator*(void){return (*_ptr);}
            value_type *operator->(void){return (_ptr);}
            value_type &operator[](int n) const {return (*(*this + n));}

    };

    template <class T>
    class ReverseVectorIterator
    {
        public:
            typedef T value_type;
            typedef T& reference;
            typedef T* pointer;
        
        protected:
            pointer _ptr;//bunu yazmayıp yukarıdaki pointer'ı kullansak da çalışır

        public:
            ReverseVectorIterator(){};
            ReverseVectorIterator(const ReverseVectorIterator &other){*this = other;};
            ReverseVectorIterator(pointer ptr): _ptr(ptr){};
            ~ReverseVectorIterator(){};
            ReverseVectorIterator &operator=(const ReverseVectorIterator &other){_ptr = other._ptr; return (*this);}
            ReverseVectorIterator &operator++(void){_ptr++; return (*this);}
            ReverseVectorIterator &operator--(void){_ptr--; return (*this);}
            ReverseVectorIterator operator+(int n) const{ReverseVectorIterator tmp(*this); tmp += n; return (*this);}
            ReverseVectorIterator operator-(int n) const{ReverseVectorIterator tmp(*this); tmp -= n; return (*this);}
            ReverseVectorIterator &operator+=(int n){while(n < 0){(*this)--; n++;}; while(n > 0){(*this)++; n--;}; return (*this);}
            ReverseVectorIterator &operator-=(int n){while(n < 0){(*this)++; n++;}; while(n > 0){(*this)--; n--;}; return (*this);}
            //ReverseVectorIterator operator++(int){}
            //ReverseVectorIterator operator--(int){}
            bool operator==(const ReverseVectorIterator &other) const {return _ptr == other._ptr;} //fonksiyon sonundaki const döndürülen değerin değiştirilememesini sağlıyor
            bool operator!=(const ReverseVectorIterator &other) const {return _ptr!= other._ptr;}
            bool operator>=(const ReverseVectorIterator &other) const {return _ptr >= other._ptr;}
            bool operator>(const ReverseVectorIterator &other) const {return _ptr > other._ptr;}
            bool operator<=(const ReverseVectorIterator &other) const {return _ptr <= other._ptr;}
            bool operator<(const ReverseVectorIterator &other) const {return _ptr < other._ptr;}
            value_type &operator*(void){return (*_ptr);}
            value_type *operator->(void){return (_ptr);}
            value_type &operator[](int n) const {return (*(*this + n));}

    };

    template <class T>
    class ConstVectorIterator
    {
        public:
            typedef T value_type;
            typedef T& reference;
            typedef T* pointer;
        
        protected:
            pointer _ptr;//bunu yazmayıp yukarıdaki pointer'ı kullansak da çalışır

        public:
            ConstVectorIterator(){};
            ConstVectorIterator(const ConstVectorIterator &other){*this = other;};
            ConstVectorIterator(pointer ptr): _ptr(ptr){};
            ~ConstVectorIterator(){};
            ConstVectorIterator &operator=(const ConstVectorIterator &other){_ptr = other._ptr; return (*this);}
            ConstVectorIterator &operator++(void){_ptr++; return (*this);}
            ConstVectorIterator &operator--(void){_ptr--; return (*this);}
            ConstVectorIterator operator+(int n) const{ConstVectorIterator tmp(*this); tmp += n; return (*this);}
            ConstVectorIterator operator-(int n) const{ConstVectorIterator tmp(*this); tmp -= n; return (*this);}
            ConstVectorIterator &operator+=(int n){while(n < 0){(*this)--; n++;}; while(n > 0){(*this)++; n--;}; return (*this);}
            ConstVectorIterator &operator-=(int n){while(n < 0){(*this)++; n++;}; while(n > 0){(*this)--; n--;}; return (*this);}
            //ConstVectorIterator operator++(int){}
            //ConstVectorIterator operator--(int){}
            bool operator==(const ConstVectorIterator &other) const {return _ptr == other._ptr;} //fonksiyon sonundaki const döndürülen değerin değiştirilememesini sağlıyor
            bool operator!=(const ConstVectorIterator &other) const {return _ptr!= other._ptr;}
            bool operator>=(const ConstVectorIterator &other) const {return _ptr >= other._ptr;}
            bool operator>(const ConstVectorIterator &other) const {return _ptr > other._ptr;}
            bool operator<=(const ConstVectorIterator &other) const {return _ptr <= other._ptr;}
            bool operator<(const ConstVectorIterator &other) const {return _ptr < other._ptr;}
            value_type &operator*(void){return (*_ptr);}
            value_type *operator->(void){return (_ptr);}
            value_type &operator[](int n) const {return (*(*this + n));}

    };

    template <class T>
    class ConstReverseVectorIterator
    {
        public:
            typedef T value_type;
            typedef T& reference;
            typedef T* pointer;
        
        protected:
            pointer _ptr;//bunu yazmayıp yukarıdaki pointer'ı kullansak da çalışır

        public:
            ConstReverseVectorIterator(){};
            ConstReverseVectorIterator(const ConstReverseVectorIterator &other){*this = other;};
            ConstReverseVectorIterator(pointer ptr): _ptr(ptr){};
            ~ConstReverseVectorIterator(){};
            ConstReverseVectorIterator &operator=(const ConstReverseVectorIterator &other){_ptr = other._ptr; return (*this);}
            ConstReverseVectorIterator &operator++(void){_ptr++; return (*this);}
            ConstReverseVectorIterator &operator--(void){_ptr--; return (*this);}
            ConstReverseVectorIterator operator+(int n) const{ConstReverseVectorIterator tmp(*this); tmp += n; return (*this);}
            ConstReverseVectorIterator operator-(int n) const{ConstReverseVectorIterator tmp(*this); tmp -= n; return (*this);}
            ConstReverseVectorIterator &operator+=(int n){while(n < 0){(*this)--; n++;}; while(n > 0){(*this)++; n--;}; return (*this);}
            ConstReverseVectorIterator &operator-=(int n){while(n < 0){(*this)++; n++;}; while(n > 0){(*this)--; n--;}; return (*this);}
            //ConstReverseVectorIterator operator++(int){}
            //ConstReverseVectorIterator operator--(int){}
            bool operator==(const ConstReverseVectorIterator &other) const {return _ptr == other._ptr;} //fonksiyon sonundaki const döndürülen değerin değiştirilememesini sağlıyor
            bool operator!=(const ConstReverseVectorIterator &other) const {return _ptr!= other._ptr;}
            bool operator>=(const ConstReverseVectorIterator &other) const {return _ptr >= other._ptr;}
            bool operator>(const ConstReverseVectorIterator &other) const {return _ptr > other._ptr;}
            bool operator<=(const ConstReverseVectorIterator &other) const {return _ptr <= other._ptr;}
            bool operator<(const ConstReverseVectorIterator &other) const {return _ptr < other._ptr;}
            value_type &operator*(void){return (*_ptr);}
            value_type *operator->(void){return (_ptr);}
            value_type &operator[](int n) const {return (*(*this + n));}

    };

}