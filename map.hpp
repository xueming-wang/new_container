/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:22:59 by xuwang            #+#    #+#             */
/*   Updated: 2022/03/23 18:02:03 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MAP_HPP
#define MAP_HPP


#include <memory>
#include <cstddef>
#include <exception>
#include "utils.hpp"
#include "mapIterator.hpp"



namespace ft {

    // Declaration of the less operation if a < b is ? 1 : 0
    template <class T>
    class less {
    public:
         bool operator() (const T& x, const T& y) const { return x  < y; }  //x < y is true
    };

    template < class Key,                              // map::key_type 指定键（key）的类型
            class T,                                  // map::mapped_type 指定值（value）的类型
            class Compare = ft::less<Key>,                     // map::key_compare   
            class Alloc = std::allocator<ft::pair<const Key,T> > >   // map::allocator_type  par defaut mallco
    class map {
        public:
            typedef Key                                 key_type;   
            typedef T                                   mapped_type;  
            typedef Compare                             key_compare; 
            typedef Alloc                               allocator_type;
            typedef pair<const key_type, mapped_type>   value_type; //key , value
            
        /*class value_compare*/
        class value_compare : public binary_function<value_type, value_type, bool>{   
            friend class map;
            
            protected:
                key_compare comp;     //less<Key>
                value_compare (key_compare c) : comp(c) {} 
                
            public:
                typedef bool        result_type;  //true or faile
                typedef value_type  first_argument_type;
                typedef value_type  second_argument_type;
                
            bool operator() (const value_type& x, const value_type& y) const { //key Compare , first is key
                return comp(x.first, y.first);
            }
        };
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            typedef typename allocator_type::difference_type difference_type;
            typedef typename allocator_type::size_type size_type;

            typedef typename ft::mapIterator<value_type, ft::treeNode<value_type> > iterator;  //paire
            typedef typename ft::mapIterator<const value_type, ft::treeNode<value_type> > const_iterator;
            
            typedef typename ft::reverse_iterator<iterator> reverse_iterator;
            typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;

            /*constructor , destructor and operator*/
            /*empty container constructor (default constructor)*/
            explicit map (const key_compare& comp = key_compare(),
              const allocator_type& alloc = allocator_type()) : _btree() {
                  (void)comp;
                  (void)alloc;
              }   //malloc no key

            /*range constructor Constructs a container with as many elements as the range [first,last),*/
            template <class InputIterator>
            map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
                const allocator_type& alloc = allocator_type()): _btree() {
                (void)comp;
                (void)alloc;
                insert(first, last);
            }
            
            /*copy constructor*/            
            map (const map& x) {
                insert (x.begin(), x.end());
            }

            ~map(){
                clear();
                _btree.destory_null();
            }

             map& operator= (const map& x){
                if (this == &x)
                    return *this;
                this->~map();
                _btree = ft::Binarytree<value_type>();
                insert (x.begin(), x.end());
                return *this;
             }

            /*functions: iterarors*/
            /*An iterator to the first element in the container.*/
            iterator begin() {
                return iterator(_btree.getRoot(), _btree.min(), _btree.getNull());
            }

            const_iterator begin() const { return const_iterator(_btree.getRoot(), _btree.min(), _btree.getNull());} 

            /*Return iterator to end
            Returns an iterator referring to the past-the-end element in the map container.*/
            iterator end() { return iterator(_btree.getRoot(), _btree.getNull(), _btree.getNull());}
            const_iterator end() const  { return const_iterator(_btree.getRoot(), _btree.getNull(), _btree.getNull());}
            
            reverse_iterator rbegin() { return reverse_iterator(this->end()); }
            const_reverse_iterator rbegin() const { return const_reverse_iterator(this->end()); }

            reverse_iterator rend() { 
                return reverse_iterator(this->begin()); }

			const_reverse_iterator rend() const { return const_reverse_iterator(this->begin()); }
            
            
            /* functions Capacity*/
            /* Returns whether the map container is empty*/
            bool empty() const {return size() == 0; }

            /*Returns the number of elements in the map container.*/
            size_type size() const { return (_btree.size(_btree.getRoot()));}
    
            /*Returns the maximum number of elements that the map container can hold.*/
            size_type max_size() const { return (_btree.max_size());}

            /*Element access*/
            /*If k matches the key of an element in the container, the function returns mapped value
                insert(make_pair(k,mapped_type())) => ft::pair<it, bool>
                *it => node->_val
                ->second => node->val.second */
            mapped_type& operator[] (const key_type& k){
                // iterator it = insert(ft::make_pair(k, mapped_type())).first;
                // return it->second;
                //return insert(ft::make_pair(k, mapped_type())).first->second;
                return (*((insert(ft::make_pair(k, mapped_type()))).first)).second;
            }
            
            /*functions Modifiers*/
            /*function insert*/
            //set to true if a new element was inserted or false if an equivalent key already existed.
            ft::pair<iterator, bool> insert (const value_type& val){
                if (_btree.insert(val) == false) {
					return ft::make_pair(find(val.first), false);
                }
				return ft::make_pair(find(val.first), true);
            }

            iterator insert (iterator position, const value_type& val) {
                (void)position;
                return insert(val).first;
            }
            
            template <class InputIterator>
            void insert (InputIterator first, InputIterator last){
               for (; first != last; first++)
					insert(*first);
            }
            
             /*function erase*/
            /*Removes from the map container either a single element or a range of elements ([first,last)).*/
            void erase (iterator position){
                erase(position->first);
            }

            /* returns the number of elements erased.*/
            size_type erase (const key_type& k){
                if (_btree.delete_node(ft::make_pair(k, mapped_type())) == false)
                    return 0;
                return 1;
            }

            void erase (iterator first, iterator last) {
                while (first != last){
                    erase(first++);
                }
            }
            
            /*Exchanges the content of the container by the content of x*/
            void swap (map& x) { _btree.swap(x._btree); }

            void clear() { _btree.destory_tree();}
            
            /*functions Observers */
            key_compare key_comp() const { return key_compare(); }

            value_compare value_comp() const{ return value_compare(key_compare());}

            /* Operations */
            /*Searches the container for an element with a key equivalent to k and returns an iterator to it if found*/
            iterator find (const key_type& k){ 
                return iterator(_btree.getRoot(), _btree.searchTree(_btree.getRoot(), ft::make_pair(k, mapped_type())), _btree.getNull());
            }
            
            const_iterator find (const key_type& k) const{ 
                return const_iterator(_btree.getRoot(), _btree.searchTree(_btree.getRoot(), ft::make_pair(k, mapped_type())), _btree.getNull());
            }

            /*Searches the container for elements with a key equivalent to k and returns the number of matches.
            the function can only return 1 (if the element is found) or zero (otherwise).*/
            size_type count (const key_type& k) const{
                 if (_btree.searchTree(_btree.getRoot(), ft::make_pair(k, mapped_type())) == _btree.getNull())
                    return (0);
                return (1);
            }

            /*Return iterator to lower bound
            Returns an iterator pointing to the first element in the container whose key is
            not considered to go before k （c)*/
            iterator lower_bound (const key_type& k){
                return iterator(_btree.getRoot(), _btree.lower_bound(ft::make_pair(k, mapped_type())), _btree.getNull());
            }
            
            const_iterator lower_bound (const key_type& k) const{
                return const_iterator(_btree.getRoot(), _btree.lower_bound(ft::make_pair(k, mapped_type())), _btree.getNull());
            }

            iterator upper_bound (const key_type& k){
                return iterator(_btree.getRoot(), _btree.upper_bound(ft::make_pair(k, mapped_type())), _btree.getNull());
            }
    
            const_iterator upper_bound (const key_type& k) const{
               return const_iterator(_btree.getRoot(), _btree.upper_bound(ft::make_pair(k, mapped_type())), _btree.getNull());
            }

            /*Get range of equal elements
            Returns the bounds of a range that includes all the elements in the container which have a key equivalent to k.*/
            pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
                return ft::make_pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k));
            }
            pair<iterator,iterator> equal_range (const key_type& k){
                return ft::make_pair<iterator, iterator>(lower_bound(k), upper_bound(k)); 
            }
            
            allocator_type get_allocator() const{ return allocator_type();}
            
            private:
                ft::Binarytree<value_type>  _btree;
                
    };
    
    /*relational operators*/
    template <class Key, class T, class Compare, class Alloc>
    bool operator== ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ){
        if(lhs.size() != rhs.size())
            return (false);
        return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator!= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ){
        return !(lhs == rhs);
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator<  ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ){
         return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator<= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ){
        return !(rhs < lhs);
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator>  ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ){
        return rhs < lhs;
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator>= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ){
        return !(lhs < rhs);
    }
    
    template <class Key, class T, class Compare, class Alloc>
    void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y){
        x.swap(y);
    }
}



#endif