/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:23:01 by xuwang            #+#    #+#             */
/*   Updated: 2022/03/29 17:56:34 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <memory>
#include <algorithm>
#include <stdexcept>
#include <exception>
#include <limits>
#include "vecIterator.hpp"
#include "utils.hpp"

namespace ft
{
    template <class T, class Allocator = std::allocator<T> >
    class vector {
        public:
            typedef T          value_type; //vector type (int char...)
            typedef Allocator  allocator_type; //malloc 
            
            typedef typename allocator_type::reference  reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            typedef typename allocator_type::difference_type difference_type;
            typedef typename allocator_type::size_type size_type;
            
            typedef typename ft::vecIterator<value_type> iterator;
            typedef typename ft::vecIterator<const value_type> const_iterator;
            
            typedef typename ft::reverse_iterator<iterator> reverse_iterator;
            typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;

            /*functions: constructor, destructor and operator*/
         public:   
            //default constructor: Constructs an empty container, with no elements.
            explicit vector (const allocator_type& alloc = allocator_type()): 
                    _allocator(alloc), _capacity(NULL), _begin(NULL), _end(NULL) {}
            
                    
            //fill constructor: Constructs a container with n elements. Each element is a copy of val.
            explicit vector (size_type n, const value_type& val = value_type(),const allocator_type& alloc = allocator_type()):
                    _allocator(alloc), _capacity(NULL), _begin(NULL), _end(NULL){
                      try {
                        this->_begin = _allocator.allocate(n);
                      }
                      catch (std::length_error &e) {
                        throw std::length_error("vector");
                      }
                      this->_capacity = this->_begin + n;
                      this->_end = this->_begin;
                      for(;n > 0; n--)
                          _allocator.construct(this->_end++, val);
                    }
                    
            // range constructor: Constructs a container with as many elements as the range [first,last],
            // with each element constructed from its corresponding element in that range, in the same order.         
            template <class InputIterator>
            vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
            typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL):
                  _allocator(alloc){
                    size_type n = last - first;
                    _begin = _allocator.allocate(n);
                    _capacity = _begin + n;
                    _end = _begin;
                    for(;n > 0; n--)
                       _allocator.construct(_end++, *first++);
              }

            //copy constructor: Constructs a container with a copy of each of the elements in x, in the same order.
            vector (const vector& x){
                  size_type n = x.size();
                  this->_begin = _allocator.allocate(n);
                  this->_capacity = this->_begin + n;
                  this->_end = this->_begin;
                  pointer tmp = x._begin;
                  for(; n > 0; n--)
                     this->_allocator.construct(this->_end++, *tmp++);
            }
          
            //Destroys the container object.
            ~vector() {
                clear();
                _allocator.deallocate(this->_begin, capacity());
            }
            
            //Assign conten: Assigns new contents to the container, replacing its current contents, and modifying its size accordingly.
            vector& operator= (const vector& x) {
                if (this == &x)
                  return *this;
                clear();
                size_type _n = x.size();
                if (_n > capacity())
                    reserve(_n);
                pointer tmp = x._begin;
                for(; _n != 0; _n--)
                    this->_allocator.construct(this->_end++, *tmp++);
                return *this;
            }

           
            /*functions: iterarors*/
            //返回指向第一个元素的迭代器
            //Return iterator to beginnin
            iterator begin() { return iterator(this->_begin);}
            const_iterator begin() const { return const_iterator(this->_begin);}
            //Return iterator to end
            iterator end() {return iterator(this->_end);}
            const_iterator end() const { return const_iterator(this->_end);}
            //Return reverse iterator to reverse beginning
            reverse_iterator rbegin(){ return reverse_iterator(end());}
            const_reverse_iterator rbegin() const { return const_reverse_iterator(end());}
            //Return reverse iterator to reverse end
            reverse_iterator rend(){return reverse_iterator(begin());}
            const_reverse_iterator rend() const {return const_reverse_iterator(begin());}

            /*functions: Capacity*/
            
            //The number of elements in the container. Member type size_type is an unsigned integral type.
            size_type size() const{ return ( this->_end - this->_begin);}
    
            //The maximum number of elements a vector container can hold as content.
            size_type max_size() const { 
              #if defined(__APPLE__) && defined(__MACH__)
				          size_type ret1 = allocator_type().max_size();
				          size_type ret2 = std::numeric_limits<difference_type>::max(); 
				          return (ret1 < ret2) ? ret1 : ret2;
              #else
                  return (allocator_type().max_size());
              #endif
              }
            
            //Resizes the container so that it contains n elements.
            void resize (size_type n, value_type val = value_type()) {
              if (n > max_size())
                  throw std::length_error("vector");
              size_type _size = size(); 
              if (_size > n) { 
                while (size() > n)
                _allocator.destroy(this->_end--);
              }
              else { 
                  if (n > capacity()) 
                      reserve(n); 
              }
              for(; _size < n ; _size++)
                _allocator.construct(this->_end++, val);
            }
            
            //Return size of allocated storage capacity
            size_type capacity() const {return this->_capacity - this->_begin;}

            //Test whether vector is empty
            //return begin() == end()
            bool empty() const { return size() == 0; }
            
            //Requests that the vector capacity be at least enough to contain n elements.
            void reserve (size_type n){
              if (n > max_size())
                throw std::length_error("vector");
              if (n > capacity()) {
                
                size_type pre_size = size();
                pointer pre_begin = this->_begin;
                pointer pre_end = this->_end;
                size_type pre_cap = capacity();
                
                this->_begin = _allocator.allocate(n);
                this->_end = this->_begin;
                this->_capacity = this->_begin + n;
                while(pre_begin != pre_end)
                  _allocator.construct(this->_end++, *pre_begin++);
                _allocator.deallocate(pre_begin - pre_size, pre_cap);
              }
            }
            /*functions: Element access*/
            // Returns a reference to the element at position n in the vector container.
            reference operator[](size_type n) { return *(begin() + n);}
            const_reference operator[] (size_type n) const { return *(begin() + n);}

            //Returns a reference to the element at position n in the vector.
            reference at (size_type n) {
              if (n >= size())
                throw std::out_of_range("vector");
              return (*this)[n];
            }
            const_reference at (size_type n) const {
              if (n >= size())
                throw std::out_of_range("vector");
              return (*this)[n];
            }

            //Access first element
            reference front() { return *(begin()); }
            const_reference front() const { return *(begin());}
            
            //Access last element
            reference back() { return *(this->_end - 1);}
            const_reference back() const {
                return *(this->_end - 1);
            }
            
            /*functions: modifiers*/
            //Assign vector content
            //Assigns new contents to the vector, replacing its current contents, 
            //and modifying its size accordingly.
            template <class InputIterator>
            // typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type
            void assign (InputIterator first, InputIterator last, 
            typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
            {
                clear();
                reserve(last - first);
                for (;first != last; first++) {
                  _allocator.construct(this->_end++, *first);
                }
            }
            
            //version (2), the new contents are n elements, each initialized to a copy of val. 
            void assign (size_type n, const value_type& val){
             
              clear();
              reserve(n);
              while (n-- > 0){
                _allocator.construct(this->_end++, val); }
            }

            //Add element at the end
            //Adds a new element at the end of the vector, after its current last element.
            //The content of val is copied (or moved) to the new element.
            void push_back (const value_type& val){
              if (this->_end == this->_capacity)
                reserve(size() > 0? capacity() * 2: 1);
              _allocator.construct(this->_end, val);
              this->_end++;
            }

            //Delete last element
            //Removes the last element in the vector, effectively reducing the container size by one.
            void pop_back(){
              _allocator.destroy(this->_end - 1);
              --this->_end;
            }

            //single element (1)	
            //Position: in the vector where the new elements are inserted.
            //Value to be copied to the inserted elements.
            iterator insert (iterator position, const value_type& val){
              size_type diff = position - begin();  
              insert(position, 1, val);
              return iterator(begin() + diff);
            }
            //fill (2)	
            void insert (iterator position, size_type n, const value_type& val) {
              size_type diff = position - begin(); 
              resize(size() + n);
              position = begin() + diff; 
              size_type diff_right = (end() - n) - position; //插入到结尾距离
              pointer pre_end = this->_end - n - 1;
              for(size_type i = 0; i < diff_right; i++)
                  *(this->_end - 1 - i) = *pre_end--;
              for(size_type i = 0; i < n; i++)
                *(position + i) = val;
            }
            
            //range (3)
            template <class InputIterator>
            void insert (iterator position, InputIterator first, InputIterator last,
            typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
            {
              size_type diff = position - begin(); 
              size_type n = last - first;
              size_type diff_right = end() - position; 
              
              resize(size() + n); 
              position = begin() + diff; 
              pointer pre_end = this->_end - n - 1;
              for(size_type i = 0; i < diff_right; i++)
                 *(this->_end - 1 - i) = *pre_end--;
              for(size_type j = 0; j < n && first != last ; j++, first++)
                *(position + j) = *first;
            }
            
            
            //参数是当前迭代器，返回值是指向删除的最后一个元素的下一位置的迭代器
            //Removes from the vector either a single element (position)
            // or a range of elements ([first,last)).
            //An iterator pointing to the new location of the element 
            //that followed the last element erased by the function call. 
            iterator erase (iterator position){
              iterator tmp= position; //保存
              size_type diff = position - begin();
              _allocator.destroy(this->_begin + diff);
              for(; tmp + 1 != end(); ++tmp)
                *tmp = *(position++ + 1);  //把原来的值给到新的位置
              this->_end--; //end 往前一位
              return iterator(position);//返回还是那个位置 
            }
           
            iterator erase (iterator first, iterator last){
                for(; first !=last; --last) //vector后面的元素会向前移位，形成新的容器
                  erase(first);
                return iterator(first);
            }
            
            //Swap content
            //Exchanges the content of the container by the content of x, 
            //which is another vector object of the same type. Sizes may differ.
            void swap (vector& x){
              pointer pre_cap = this->_capacity;
              pointer pre_begin = this->_begin;
              pointer pre_end = this->_end;
              allocator_type pre_allo = this->_allocator;

              this->_capacity = x._capacity;
              this->_begin = x._begin;
              this->_end = x._end;
              this->_allocator = x._allocator;

              x._capacity = pre_cap;
              x._begin = pre_begin;
              x._end = pre_end;
              x._allocator = pre_allo;
            }

            //Removes all elements from the vector ,leaving the container with a size of 0.
            void clear() {
              size_type n = size();
              while(n-- > 0)
                  this->_allocator.destroy(--this->_end);
            }
            
            /*function: Allocator*/
            allocator_type get_allocator() const {return this->_allocator; }

          private:
              allocator_type _allocator;
              pointer _capacity;
              pointer _begin;
              pointer _end;
              
    };
            


/* Non-member function overloads*/
/*:relational operators*/
template <class T, class Alloc>
  bool operator== (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
    if(lhs.size() != rhs.size())
      return (false);
    return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template <class T, class Alloc>
  bool operator!= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs){
    return !(lhs == rhs);
}

template <class T, class Alloc>
  bool operator<  (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs){
    return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

//use operator <
template <class T, class Alloc> 
  bool operator >  (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
    return (rhs < lhs);
}

template <class T, class Alloc>
  bool operator<= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs){
    return !(rhs > lhs);
}

template <class T, class Alloc>
  bool operator>= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs){
    return !(lhs < rhs);
}

/*Exchange contents of vectors*/
template <class T, class Alloc>
  void swap (ft::vector<T,Alloc>& x, ft::vector<T,Alloc>& y){
     x.swap(y);
  }
}

#endif


