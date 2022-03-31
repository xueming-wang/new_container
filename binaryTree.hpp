/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binaryTree.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:47:49 by xuwang            #+#    #+#             */
/*   Updated: 2022/03/31 14:21:35 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include <memory>
#include <iostream>
#include "utils.hpp"

namespace ft {
    template <class T>
    class treeNode {
        
        public:
            T _value;  //T is pair<key, value>
            treeNode *_left; 
            treeNode *_right;
            treeNode *_parent; 
        
        public:
            treeNode(): _value(), _left(NULL), _right(NULL), _parent(NULL) {}
            
            treeNode(T const &val, treeNode *left = NULL, treeNode *right = NULL, treeNode *parent = NULL):
                    _value(val), _left(left), _right(right), _parent(parent) {}
                    
            treeNode(treeNode const&src): _value(src._value), _left(src._left), _right(src._right), _parent(src._parent) {}
            
            ~treeNode(){}
            
            treeNode & operator=(treeNode const &rhs){
                if (this == &rhs) return *this; 
                
                this->_value = rhs._value;
                this->_left = rhs._left;
                this->_right = rhs._left;
                this->_parent = rhs._parent;
                return *this;
            }
    };

    template<class T ,
            //class Compare,
            class Node = ft::treeNode<T>,
            class Allocator = std::allocator<Node> >
    class Binarytree {
            
        public:
            typedef	 T                          value_type;  // T is pair<key, value>
            typedef Node                        node_type; 
            typedef Allocator                   allocator_type;
           
            
			typedef	typename	allocator_type::pointer					pointer;
			typedef	typename	allocator_type::const_pointer			const_pointer;
			typedef	typename	allocator_type::size_type				size_type;
            
            /* default constructor */
            Binarytree() {
                this->_null =  allocator_type().allocate(1);
				allocator_type().construct(_null, node_type());
                this->_root = this->_null;
            }
    
            /* destructor */
            ~Binarytree(){}
            
            /* get value*/
            pointer getRoot()const {return this->_root;}
            
            pointer getNull()const {return this->_null;}
        
            size_type max_size() const {return allocator_type().max_size();}

            pointer min() const { return minVal(this->_root);}

            pointer max() const { return maxVal(this->_root);}

            /* size of node(tree) */
            size_type  size(pointer root) const {
                if (root == _null)
                    return 0;
                return (size(root->_left) + size(root->_right) + 1);
            }
            
            /* min val in tree*/
            pointer minVal(pointer root) const {
                if (root == _null)
                    return _null;
                while (root->_left != _null)
                    root = root->_left;
                return root;
            }
            
            /* max val in tree*/
            pointer maxVal(pointer root) const {
                 if (root == _null)
                    return _null;
                while (root->_right != _null)
                    root = root->_right;
                return root;
            }
            
            /*find node (value) */
            pointer searchTree(pointer root, value_type const& val) const {
                if (root == _null)
                    return _null;
                else {
                    if (val.first < root->_value.first) 
                        return searchTree(root->_left, val);
                    else if (val.first > root->_value.first) 
                        return searchTree(root->_right, val);
                    else
                        return root;
                }
            }
            
            /*add node at last return this node*/
            bool insert(value_type val) {    //val is key
                if (searchTree(this->_root, val) != _null)
                    return false;
                InsertNode(this->_root, val);
                return true;
            }
            
            pointer InsertNode(pointer &tree, value_type val) { 
            
                pointer toInsert = allocator_type().allocate(1);
				allocator_type().construct(toInsert, node_type(val, _null, _null, NULL));

				pointer current = NULL;
				pointer root = tree;

				while (root != _null) {
					current = root;
					if (toInsert->_value < root->_value)
						root = root->_left;
					else if (root->_value < toInsert->_value)
						root = root->_right;
					else {
						allocator_type().destroy(toInsert);
						allocator_type().deallocate(toInsert, 1);
						return _null;
					}
				}

				toInsert->_parent = current;
				if (current == NULL)
					tree = toInsert;
				else if (toInsert->_value < current->_value)
					current->_left = toInsert;
				else
					current->_right = toInsert;

				if (toInsert->_parent == NULL) {
					return tree;
				}

				if (toInsert->_parent->_parent == NULL)
					return tree;
                return tree;
            }  
            
            /*delete one node*/
            bool delete_node(value_type const& val) {
                if (DeleteNode(this->_root, val) == _null)
                     return false;
                return true;
            }
            
            pointer DeleteNode(pointer &tree, value_type const&val)  //val 是 paire
            {
                pointer tempNode;

                if (tree == _null) {
                    return _null;
                }
                else if (tree->_value.first > val.first)
                    tree->_left = DeleteNode(tree->_left, val);
                else if (tree->_value.first < val.first)
                    tree->_right = DeleteNode(tree->_right, val);
                else if  (tree->_value.first == val.first)
                { 
                    if (tree->_left !=_null && tree->_right != _null ) { 
                        tempNode = minVal(tree->_right);
                        tree = tempNode;
                        tree->_right = DeleteNode(tree->_right, tree->_value);	
                    }
                    else if (tree->_left == _null ) {
                        tempNode = tree;
                        tree = tree->_right;
                        allocator_type().destroy(tempNode);
                        allocator_type().deallocate(tempNode, 1);
                    }
                    else if (tree->_right  == _null) {
                        tempNode = tree;
                        tree = tree->_left;
                        allocator_type().destroy(tempNode);
                        allocator_type().deallocate(tempNode, 1);
                    } 
                    else {
                        tempNode = tree;
                        allocator_type().destroy(tempNode);
                        allocator_type().deallocate(tempNode, 1);
                    }

                }
                return (tree);
            }
            
            /*echange value this and src*/
            void swap(Binarytree &src) {
                
                pointer root = this->_root;
                pointer null = this->_null;

                this->_root = src.getRoot();
                this->_null = src.getNull();

                src._root = root;
                src._null = null;
            }
            
            /*delete tree */
            void destory_tree() {
                destory_tree(this->_root);
                this->_root = _null;
            }
            void destory_null()
            {
                allocator_type().destroy(_null);
                allocator_type().deallocate(_null, 1);
            }
            void destory_tree(pointer node){
                if (node == _null)
                    return;
                destory_tree(node->_left);
                destory_tree(node->_right);
                
                allocator_type().destroy(node);
                allocator_type().deallocate(node, 1);
                
            }
            
            void preOrder(pointer node) {
                if (node != _null){
                    std::cout << node->_value << " ";
                    preOrder(node->_left);
                    preOrder(node->_right);
                }
            }
            
            void inOrder(pointer node) {
                if (node != _null) {
                    inOrder(node->_left);
                    std::cout << node->_value << " ";
                    inOrder(node->_right);
                }
            }
    
            void postOrder(pointer node){
                if(node != _null) {
                    postOrder(node->_left);
                    postOrder(node->_right);
                    std::cout << node->_value << " ";
                }
            }
            
            /* val++ */
            pointer	successor(pointer node) const {
				if (node->_right != _null)
					return minVal(node->_right);
				if (node->_parent == _null || node == maxVal(this->_root))
					return _null;
				pointer tmp = node->_parent;
				while (tmp != _null && node == tmp->_right) {
					node = tmp;
					tmp = tmp->_parent;
				}
				return tmp;
			}

            pointer lower_bound(value_type const & val) {
				pointer begin = minVal(this->_root);
				while (begin != _null) {
					if (begin->_value >= val)
						break ;
					begin = successor(begin);
				}
				return begin;
			}

            pointer upper_bound(value_type const & val) {
				pointer begin = minVal(this->_root);
				while (begin != _null) {
					if (begin->_value.first > val.first) 
						break ;
					begin = successor(begin);
				}
				return begin;
			}
            
        private:
            pointer _root; 
            pointer _null;
    
        };

}

#endif