/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:02:24 by xuwang            #+#    #+#             */
/*   Updated: 2022/01/19 14:45:18 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECITERATOR_HPP
#define VECITERATOR_HPP

#include "iterator.hpp"

namespace ft {
     
 template <class  T>
 class vecIterator: public ft::iterator<random_access_iterator_tag, T> {

 public:
    typedef typename ft::iterator<random_access_iterator_tag, T>::iterator_category iterator_category;
    typedef typename ft::iterator<random_access_iterator_tag, T>::value_type        value_type;
    typedef typename ft::iterator<random_access_iterator_tag, T>::difference_type   difference_type;
    typedef typename ft::iterator<random_access_iterator_tag, T>::pointer           pointer;
    typedef typename ft::iterator<random_access_iterator_tag, T>::reference         reference;

    /*constructeur and destructeur*/
    vecIterator():_element(NULL){}
    
    explicit vecIterator (pointer element):_element(element) {}       	
    
    vecIterator (vecIterator const &src):_element(src._element){}
    
    ~vecIterator() {} 
    
    vecIterator &operator= (const vecIterator &rhs) {
       if (this == &rhs) 
         return *this;
      this->_element = rhs._element;
      return *this;
    }

    /*Member functions*/
    pointer base() const{return _element;}
    
    //Dereference iterator
    reference operator*() const { return *_element; };

   //Addition operator
    vecIterator operator+ (difference_type n) const {
       vecIterator tmp = *this;
       tmp._element = _element + n;
       return tmp;
    }
    
   //Increment iterator position
   vecIterator &operator++() {
      ++_element;
      return *this;
   }
   //The post-increment version
   vecIterator operator++(int) {
      vecIterator tmp(*this);
      ++_element;
      return tmp;
   }
   
   //Advances the iterator by n element positions.
   vecIterator& operator+= (difference_type n){
      _element += n;
      return *this;
   }

   //Subtraction operator
    vecIterator operator- (difference_type n) const{
       vecIterator tmp = *this;
       tmp._element = _element - n;
       return tmp;
    }

   //Decreases iterator position
    vecIterator& operator--(){
      --_element;
      return *this;
   }
   //The post-increment version
   vecIterator operator--(int){
      vecIterator tmp = *this;
      --_element;
      return tmp;
   }
   
    //Descreases the veciterator by n element positions.
    vecIterator& operator-= (difference_type n){
       _element -= n;
       return *this;
    }

   //Returns a pointer to the element pointed to by the iterator (in order to access one of its members).
   pointer operator->() const{ return &(operator*()); }
   
    //Accesses the element located n positions away from the element currently pointed to by the iterator.
   reference operator[] (difference_type n) const{ return *(_element + n);}

   operator vecIterator<const T> (void) {
			return vecIterator<const T>(_element);
	}
   
   private:
      pointer _element;
       
};


/*Non-member function overloads :*/
  template <class T>
  bool operator== (const vecIterator<T>& lhs, const vecIterator<T>& rhs){ 
    return lhs.base() == rhs.base();
  }  
  template <class T>
  bool operator!= (const vecIterator<T>& lhs, const vecIterator<T>& rhs){
    return lhs.base() != rhs.base();
  }
  template <class T>
  bool operator<  (const vecIterator<T>& lhs, const vecIterator<T>& rhs){
    return lhs.base() < rhs.base();
  }

  template <class T>
  bool operator<= (const vecIterator<T>& lhs, const vecIterator<T>& rhs){
    return lhs.base() <= rhs.base();
  }
  template <class T>
  bool operator>  (const vecIterator<T>& lhs, const vecIterator<T>& rhs){
    return lhs.base() > rhs.base();
  }
  template <class T>
  bool operator>= (const vecIterator<T>& lhs, const vecIterator<T>& rhs){
    return lhs.base() >= rhs.base();
  }

 /*Non-member function overloads : const case*/ 
 template <class T, class _T>
  bool operator== (const vecIterator<T>& lhs, const vecIterator<_T>& rhs){ 
    return lhs.base() == rhs.base();
  }  
  template <class T, class _T>
  bool operator!= (const vecIterator<T>& lhs, const vecIterator<_T>& rhs){
    return lhs.base() != rhs.base();
  }
  template <class T, class _T>
  bool operator<  (const vecIterator<T>& lhs, const vecIterator<_T>& rhs){
    return lhs.base() < rhs.base();
  }

  template <class T, class _T>
  bool operator<= (const vecIterator<T>& lhs, const vecIterator<_T>& rhs){
    return lhs.base() <= rhs.base();
  }
  template <class T, class _T>
  bool operator>  (const vecIterator<T>& lhs, const vecIterator<_T>& rhs){
    return lhs.base() > rhs.base();
  }
  template <class T, class _T>
  bool operator>= (const vecIterator<T>& lhs, const vecIterator<_T>& rhs){
    return lhs.base() >= rhs.base();
  }

 //Returns a reverse iterator pointing to the element located n positions away from the element pointed to by _it.
 template <class T>
   vecIterator<T> operator+ (typename vecIterator<T>::difference_type n, const vecIterator<T>& _it) {
      return _it + n;
 }

 //Returns the distance between lhs and rhs.
 template <class T>
  typename vecIterator<T>::difference_type operator- (const vecIterator<T> &lhs, const vecIterator<T> &rhs) {
     return lhs.base() - rhs.base();
 }

}

#endif 