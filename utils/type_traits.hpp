#ifndef TYPE_TRAITS_HPP
#define TYPE_TRAITS_HPP
#include <iostream>
#include <string>
#include <cstdio>
namespace ft
{

   template<class T> struct remove_const { typedef T type; };

   template<class T> struct remove_const <const T> { typedef T type; };
   
   template <typename _Tp, _Tp _v>
   struct integral_constant
   {
      static const _Tp value = _v;

      typedef _Tp value_type;
      typedef integral_constant<_Tp, _v> type;

      operator value_type() const { return value; }
   };

   typedef integral_constant<bool, false> false_type;
   typedef integral_constant<bool, true> true_type;

   // is_integral
   template <typename T>
   struct is_integral : false_type
   {
      // printf("is_integral\n");
   };

   // specializations
   template <>
   struct is_integral<bool> : true_type
   {
   };

   template <>
   struct is_integral<char> : true_type
   {
   };

   template <>
   struct is_integral<unsigned char> : true_type
   {
   };

   template <>
   struct is_integral<int> : true_type
   {
   };

   template <>
   struct is_integral<unsigned int> : true_type
   {
   };

   template <>
   struct is_integral<long> : true_type
   {
   };

   template <>
   struct is_integral<long long> : true_type
   {
   };

   template <>
   struct is_integral<unsigned long long> : true_type
   {
   };

   // enable if
   template <bool Cond, class T = void>
   struct enable_if
   {
   };

   // Partial specialization for true
   template <class T>
   struct enable_if<true, T>
   {
      typedef T type;
   };

   template <class InputIt1, class InputIt2>
   bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
                                InputIt2 first2, InputIt2 last2)
   {
      for (; (first1 != last1) && (first2 != last2); ++first1, (void)++first2)
      {
         if (*first1 < *first2)
            return true;
         if (*first2 < *first1)
            return false;
      }
      return (first1 == last1) && (first2 != last2);
   }

   template <class InputIt1, class InputIt2, class Compare>
   bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
                                InputIt2 first2, InputIt2 last2,
                                Compare comp)
   {
      for (; (first1 != last1) && (first2 != last2); ++first1, (void)++first2)
      {
         if (comp(*first1, *first2))
            return true;
         if (comp(*first2, *first1))
            return false;
      }
      return (first1 == last1) && (first2 != last2);
   }

   template <class InputIterator1, class InputIterator2>
   bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
   {
      while (first1 != last1)
      {
         if (!(*first1 == *first2)) // or: if (!pred(*first1,*first2)), for version 2
            return false;
         ++first1;
         ++first2;
      }
      return true;
   }

}

#endif