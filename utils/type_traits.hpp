#ifndef TYPE_TRAITS_HPP
#define TYPE_TRAITS_HPP
#include <iostream>
#include <string>
#include <cstdio>
namespace ft
{
   template <typename _Tp, _Tp _v>
   struct integral_constant
   {
        static const _Tp                    value = _v;

        typedef      _Tp                    value_type;
        typedef integral_constant<_Tp, _v> type;

        operator value_type() const { return value;}
   };

   typedef integral_constant<bool, false> false_type;
   typedef integral_constant<bool, true> true_type;

   //is_integral
   template<typename T>
   struct is_integral : false_type{
      //printf("is_integral\n");
   };

   //specializations
   template<>
   struct is_integral<bool> : true_type{};

   template<>
   struct is_integral<char> : true_type{};

   template<>
   struct is_integral<unsigned char> : true_type{};

   template<>
   struct is_integral<int> : true_type{};

   template<>
   struct is_integral<unsigned int> : true_type{};

   template<>
   struct is_integral<long> : true_type{};

   template<>
   struct is_integral<long long> : true_type{};

   template<>
   struct is_integral<unsigned long long> : true_type{};

   //enable if
   template <bool Cond, class T = void>
   struct enable_if{};

   //Partial specialization for true
   template <class T>
   struct enable_if<true, T>{typedef T type;};

}

#endif