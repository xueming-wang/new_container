/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 20:32:43 by xuwang            #+#    #+#             */
/*   Updated: 2022/02/16 15:01:44 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPITERATOR_HPP
#define MAPITERATOR_HPP

#include "binaryTree.hpp"
#include "iterator.hpp"
#include <iostream>

namespace ft {
    
    template <class T, class treeNode>
    class mapIterator: public ft::iterator<bidirectional_iterator_tag, T> {
      
    public:
        typedef T               value_type;   //pair<key, mapped_value>
        typedef treeNode*       node_pointer;
      
        typedef typename ft::iterator<bidirectional_iterator_tag, T>::iterator_category iterator_category;
        typedef typename ft::iterator<bidirectional_iterator_tag, T>::difference_type   difference_type;
        typedef typename ft::iterator<bidirectional_iterator_tag, T>::pointer           pointer;
        typedef typename ft::iterator<bidirectional_iterator_tag, T>::reference         reference;

  
        /*constructor and destructor*/
        mapIterator():_root(NULL), _node(NULL), _null(NULL) {}
        
        mapIterator (node_pointer root, node_pointer node, node_pointer null):
          _root(root),
          _node(node),
          _null(null) {}       	
        
        mapIterator (mapIterator const&src) :_root(src._root), _node(src._node), _null(src._null) {}
        
        ~mapIterator() {} 
        
        mapIterator &operator= (const mapIterator &rhs) {
            if (this == &rhs) 
                return *this;
            this->_root = rhs._root;
            this->_node = rhs._node;
            this->_null = rhs._null;
            return *this;
        }
         /*Member functions*/
        node_pointer getRoot() const{return this->_root;}
        node_pointer getNode() const{return this->_node;}
        
        //Dereference iterator
        reference operator*() const { return this->_node->_value; }; //_value is pair<key, mapped_value>

         //Returns a pointer to the root pointed to by the iterator (in order to access one of its members).
        pointer operator->() const{ return &(operator*()); }

        //Increment iterator position  ++key
        mapIterator &operator++() {
            if (this->_node == max()) {
                this->_node = _null;
                return *this;
            }
            else if (this->_node == _null) {
                this->_node = _null;
                return *this;
            }  
            this->_node = successor(this->_node);
            return *this;
          }
          
        node_pointer min() { return minVal(this->_root);}

        node_pointer max() { return maxVal(this->_root);}
        
        //The post-increment version
        mapIterator operator++(int) {
            mapIterator tmp(*this);
            this->operator++();
            return tmp;
        }

        //Decreases iterator position --key
        mapIterator& operator--() {
          if (this->_node == _null) {
              this->_node = max();
              return *this;
          }
          this->_node = predecessor(this->_node);
          return *this;
        }
        
        //The post-increment version
        mapIterator operator--(int){
            mapIterator  tmp(*this);
            this->operator--();
            return tmp;
        }

        node_pointer minVal(node_pointer node) const {
            if (node == _null)
                return _null;
            while (node->_left != _null)
                node = node->_left;
            return node;
        }
        
        /* max val in node*/
        node_pointer maxVal(node_pointer node) const {
              if (node == _null)
                return _null;
            while (node->_right != _null)
                node = node->_right;
            return node;
        }
        
        node_pointer	successor(node_pointer node) const {
          if (node->_right != _null)
              return minVal(node->_right);
          node_pointer tmp = node->_parent;
          while (tmp != _null && node == tmp->_right) {
            node = tmp;
            tmp = tmp->_parent;
          }
          return tmp;
		  	}

        node_pointer	predecessor(node_pointer node) {
          if (node->_left != _null)
            return maxVal(node->_left);

          node_pointer tmp = node->_parent;
          while (tmp != _null && node == tmp->_left) {
            node = tmp;
            tmp = tmp->_parent;
          }
          return tmp;
			}
        
        operator mapIterator<const T,  treeNode> (void) {
			      return mapIterator<const T,  treeNode>(_root, _node, _null);
	      }

        private:
            node_pointer _root;
            node_pointer _node;
            node_pointer _null;

    };
    
  /*Non-member function overloads :*/
  template <class T, class Node>
  bool operator== (const mapIterator<T, Node>& lhs, const mapIterator<T, Node>& rhs){ 
    return lhs.getNode() == rhs.getNode();
  }  
  template <class T, class Node>
  bool operator!= (const mapIterator<T, Node>& lhs, const mapIterator<T, Node>& rhs){
    return lhs.getNode() != rhs.getNode();
  }
   /*Non-member function overloads : const case*/ 
 template <class T, class _T, class Node>
  bool operator== (const mapIterator<T, Node>& lhs, const mapIterator<_T, Node>& rhs){ 
    return lhs.getNode() == rhs.getNode();
  }  
  template <class T, class _T, class Node>
  bool operator!= (const mapIterator<T, Node>& lhs, const mapIterator<_T, Node>& rhs){
    return lhs.getNode() != rhs.getNode();
  }
}

#endif