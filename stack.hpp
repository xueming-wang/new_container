/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:20:50 by xuwang            #+#    #+#             */
/*   Updated: 2022/03/29 16:30:21 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP


//Your stack will use your vector class as the underlying container by default
#include "vector.hpp"

namespace ft
{
    template <class T, class Container = ft::vector<T> > 
    class stack {
        public:
            typedef T                                   value_type;
            typedef Container                           container_type;
            typedef typename container_type::size_type  size_type;
        
        public:
            explicit stack (const container_type& ctnr = container_type()): _containerVec(ctnr){};
        
            ~stack(void) {}
            
            bool empty() const{ return _containerVec.empty(); }
            
            size_type size() const{ return _containerVec.size(); }
            
            /*Returns a reference to the top element in the stack. 
            Since stacks are last-in first-out containers, the top element is the last element inserted into the stack.*/
            value_type& top() { return _containerVec.back();}
            const value_type& top() const { return _containerVec.back();}
            
            /*Insert element
            Inserts a new element at the top of the stack, above its current top element*/
            void push (const value_type& val) { _containerVec.push_back(val); }

            /*Remove top element size -1 
            The element removed is the latest element inserted into the stack,stack::top.*/
            void pop() { _containerVec.pop_back();}
            
            friend bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
                    return lhs._containerVec == rhs._containerVec;
            }
            
            friend bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
                return !(lhs == rhs);
            }
            
            friend bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
                return lhs._containerVec < rhs._containerVec;
            }
            
            friend bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
                return rhs < lhs;
            }
            
            friend bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
                return !(rhs < lhs);
            }
            
            friend bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
                return !(lhs < rhs);
            }

        protected:
            container_type _containerVec;
        
    };
    /*Non-member function overloads*/
    /*relational operators (stack)*/
    
    

}

#endif


