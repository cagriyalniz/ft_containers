#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

#include <cstddef>
#include <iterator>
#include "vector"

namespace ft
{
	template <class Iterator> struct iterator_traits
    {
        /* Result of subtracting one iterator from another, from Iterator. */
        typedef typename Iterator::difference_type       difference_type;

        /* Type of the element where iterator point, from Iterator. */
        typedef typename Iterator::value_type            value_type;

        /* Type of a pointer to an element where the iterator point, from Iterator. */
        typedef typename Iterator::pointer               pointer;

        /* Type of a reference where iterator point, from Iterator. */
        typedef typename Iterator::reference             reference;

        typedef typename Iterator::const_reference             const_reference;

        /* The iterator category from Iterator. */
        typedef typename Iterator::iterator_category     iterator_category;
    };



	template <class T>
	struct iterator_traits <T*>
	{
			typedef std::ptrdiff_t					difference_type;
			typedef T								value_type;
			typedef	T*								pointer;
			typedef T&								reference;
			typedef const T&						const_reference;
			typedef	std::random_access_iterator_tag	iterator_category;					
	};
	
	template <class T>
	struct iterator_traits <const T*>
	{
			typedef std::ptrdiff_t					difference_type;
			typedef T								value_type;
			typedef	const T*						pointer;
			typedef const T&						reference;
			typedef const T&						const_reference;
			typedef	std::random_access_iterator_tag	iterator_category;							
	};
}
#endif