#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "Iterator_Traits.hpp"

namespace ft
{
	template<class T>
	class ReverseIterator : public std::iterator<std::random_access_iterator_tag, T>
	{
		public:
			typedef T													iterator_type;
			typedef typename std::random_access_iterator_tag			iterator_category;
			typedef typename iterator_traits<T>::value_type				value_type;
			typedef	typename iterator_traits<T>::difference_type		difference_type;
			typedef typename iterator_traits<T>::pointer				pointer;
			typedef typename iterator_traits<T>::reference				reference;

		private:
			iterator_type	_it;

		public:
			ReverseIterator(): _it(0) {};
			explicit	ReverseIterator( iterator_type x ): _it(x) {};
			template <class Iter>
			ReverseIterator ( const ReverseIterator<Iter>& rev_it ): _it(rev_it.base()) {};

			iterator_type			base() const							{ return (this->_it); };
			reference				operator*() const						{ return (*this->_it); };
			ReverseIterator		operator+( difference_type n ) const	{ return (ReverseIterator(this->_it - n)); };
			ReverseIterator		operator-( difference_type n ) const	{ return (ReverseIterator(this->_it + n)); };
			ReverseIterator&		operator++()							{ return (this->_it + 1); };
			ReverseIterator		operator++(int)							{ ReverseIterator temp(*this); (*this) = (*this) + 1; return (temp); };
			ReverseIterator&		operator--()							{ return (this->_it - 1); };
			ReverseIterator		operator--(int)							{ ReverseIterator temp(*this); (*this) = (*this) - 1; return (temp); };
			ReverseIterator&		operator+=( difference_type n )			{ this->_it -= n; return (*this); };
			ReverseIterator&		operator-=( difference_type n )			{ this->_it += n; return (*this); };
			pointer					operator->()							{ return (&(operator*())); };
			reference				operator[]( difference_type n ) const	{ return (*(this->_it + n)); };
	};

	template <class Iterator>
	bool operator== (const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs) { return (lhs.base() == rhs.base()); };
	template <class Iterator>
	bool operator!= (const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs) { return (lhs.base() != rhs.base()); };
	template <class Iterator>
	bool operator<  (const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs) { return (lhs.base() < rhs.base()); };
	template <class Iterator>
	bool operator<= (const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs) { return (lhs.base() <= rhs.base()); };
	template <class Iterator>
	bool operator>  (const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs) { return (lhs.base() > rhs.base()); };
	template <class Iterator>
	bool operator>=  (const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs) { return (lhs.base() >= rhs.base()); };

	template <class Iterator>
	ReverseIterator<Iterator> operator+ (typename ReverseIterator<Iterator>::difference_type n, const ReverseIterator<Iterator>& rev_it)
	{ return (ReverseIterator<Iterator>( rev_it - n)); };
	template <class Iterator>
	typename ReverseIterator<Iterator>::difference_type operator- (const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs)
	{ return (lhs.base() - rhs.base()); };

};

#endif