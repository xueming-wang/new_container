/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 13:54:43 by xuwang            #+#    #+#             */
/*   Updated: 2022/03/29 17:46:16 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

//Result of pointer subtraction
#include <cstddef>
/*Traits class defining properties of iterators.
Standard algorithms determine certain properties of the iterators passed to them and the range they
represent by using the members of the corresponding iterator_traits instantiation.*/

namespace ft {
  
/*iterator_category*/
//  Marking input iterators.
  struct input_iterator_tag {};

//  Marking output iterators.
  struct output_iterator_tag {};

// Forward iterators support a superset of input iterator operations.
  struct forward_iterator_tag : public input_iterator_tag {};

// Bidirectional iterators support a superset of forward iterator
// operations.
  struct bidirectional_iterator_tag : public forward_iterator_tag {};

// Random-access iterators support a superset of bidirectional
// iterator operations.
  struct random_access_iterator_tag : public bidirectional_iterator_tag {};

/* Traits class defining properties of iterators.For every iterator type, 
  a corresponding specialization of iterator_traits class template shall be defined*/
/*  difference_type: Type to represent the difference between two iterators.
    value_type:	Type of elements pointed by the iterator.
    pointer: Type to represent a pointer to an element pointed by the iterator.
    reference: Type to represent a reference to an element pointed by the iterator。 */
    //typedef 用来为复杂的声明定义简单的别名
    template<class Iterator>
    class iterator_traits {
    public:
        typedef typename Iterator::iterator_category iterator_category;
        typedef typename Iterator::value_type        value_type;
        typedef typename Iterator::difference_type   difference_type;
        typedef typename Iterator::pointer           pointer;
        typedef typename Iterator::reference         reference;
      
    };
    //Traits class defining properties of iterators.
    template <class T> 
    class iterator_traits<T*> {
      public:
        typedef random_access_iterator_tag	       iterator_category;
        typedef T                                    value_type;
        typedef ptrdiff_t                            difference_type;
        typedef T*                                   pointer;
        typedef T&                                   reference;
      
    };
    template <class T> 
    class iterator_traits<const T*> {
     public:
        typedef random_access_iterator_tag	       iterator_category;
        typedef T                                    value_type;
        typedef ptrdiff_t                            difference_type;
        typedef T*                                   pointer;
        typedef T&                                   reference;
    };


//This is a base class template that can be used to derive iterator classes from it. It is not an iterator class
//ptrdiff_t for pointer - pointer， long int
  template <class Category,            // iterator::iterator_category
          class T,                     // iterator::value_type，Type of elements pointed by the iterator.
          class Distance = ptrdiff_t,  // iterator::difference_type，Type to represent the difference between two iterators.
          class Pointer = T*,          // iterator::pointer
          class Reference = T& >       // iterator::reference
    class iterator{
    public:
        typedef Category    iterator_category;
        typedef T           value_type;
        typedef Distance    difference_type;
        typedef Pointer     pointer;
        typedef Reference   reference;
  };

  template <class Iterator> 
  class reverse_iterator{
    /*A bidirectional iterator type.Or a random-access iterator, 
    if an operator that requires such a category of iterators is used.*/
    public:
      typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
      typedef typename iterator_traits<Iterator>::value_type        value_type;
      typedef typename iterator_traits<Iterator>::difference_type   difference_type;
      typedef typename iterator_traits<Iterator>::pointer           pointer;
      typedef typename iterator_traits<Iterator>::reference         reference;
      typedef Iterator                                              iterator_type;  //iterator

    public:
    /*constructeur and destructeur*/
        //default constructor:constructs a reverse iterator that points to no object.
        reverse_iterator():_it(){}
        //initalization constructor
        explicit reverse_iterator (iterator_type it):_it(it) {}     
        //Constructs a reverse iterator from some other reverse iterator. 
        //The constructed object keeps the same sense of iteration as rev_it.
        template <class Iter>
            reverse_iterator (const reverse_iterator<Iter>& rev_it): _it(rev_it.base()){}
        virtual ~reverse_iterator() {} 
        
        /*Member functions*/
        //Return base iterator
        iterator_type base() const{return this->_it;}

        //Dereference iterator: Returns a reference to the element pointed to by the iterator.
        //Internally, the function decreases a copy of its base iterator and returns the result of dereferencing it.
        reference operator*() const { 
            iterator_type tmp = _it;
            return *(--tmp);
        }

        //Addition operator: Returns a reverse iterator pointing to the element located n positions 
        //away from the element the iterator currently points to. n:Number of elements to offset.
        reverse_iterator operator+ (difference_type n) const{
            return (reserve_iterator(_it - n));
        }

        //Increment iterator position: The pre-increment version (1) returns *this.
        reverse_iterator &operator++() {
          --_it;
          return *this;
        }
        //The post-increment version (2) returns the value *this had before the call.
        reverse_iterator operator++(int) {
          reverse_iterator tmp = *this;
          operator++();
          return tmp;
        }
        
        //Advances the reverse_iterator by n element positions.
        reverse_iterator& operator+= (difference_type n){
          _it = _it - n;
          return (*this);
        }
        
        //Subtraction operator:Returns a reverse iterator pointing to the element located n positions 
        //before the element the iterator currently points to.
        reverse_iterator operator- (difference_type n) const {
            return (reverse_iterator(_it + n));
        }

        //Decreases the reverse_iterator by one position.
        reverse_iterator& operator--(void){
          ++_it;
          return (*this);
        }
        reverse_iterator  operator--(int) {
            reverse_iterator tmp(*this);
            operator--();
            return tmp;
        }

        //Descreases the reverse_iterator by n element positions.
        reverse_iterator& operator-= (difference_type n){
          _it = _it + n;
          return (*this);
        }

        //Returns a pointer to the element pointed to by the iterator (in order to access one of its members).
        pointer operator->() const{ return &(operator*()); }

        //Accesses the element located n positions away from the element currently pointed to by the iterator.
        reference operator[] (difference_type n) const{ return _it[-n - 1] ;}
            
      private:
        iterator_type _it;
        
  };

 /*Non-member function overloads :*/
        //Relational operators for reverse_iterator
        //Performs the appropriate comparison operation between the reverse_iterator objects lhs and rhs.
        //Internally, the function compares directly the base iterators using the reflexively equivalent relational operator:
            /* operator on          equivalent used
              reverse iterators	    onbase iterators
                        ==          ==
                        !=          !=
                        <           >
                        <=          >=
                        >           <
                        >=          <= */
  template <class Iterator>
  bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){ 
    return lhs.base() == rhs.base();
  }  
  template <class Iterator>
  bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){
    return lhs.base() != rhs.base();
  }
  template <class Iterator>
  bool operator<  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){
    return lhs.base() > rhs.base();
  }

  template <class Iterator>
  bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){
    return lhs.base() >= rhs.base();
  }
  template <class Iterator>
  bool operator>  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){
    return lhs.base() < rhs.base();
  }
  template <class Iterator>
  bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){
    return lhs.base() <= rhs.base();
  } 

//Returns a reverse iterator pointing to the element located n positions away from the element pointed to by rev_it.
template <class Iterator>
  reverse_iterator<Iterator> operator+ ( typename reverse_iterator<Iterator>::difference_type n,
    const reverse_iterator<Iterator>& rev_it){
      return rev_it + n;  
  }
      
//Returns the distance between lhs and rhs.
template <class Iterator>
  typename reverse_iterator<Iterator>::difference_type operator- (const reverse_iterator<Iterator>& lhs,
    const reverse_iterator<Iterator>& rhs){
      return lhs.base() - rhs.base();
  }
  
}

#endif