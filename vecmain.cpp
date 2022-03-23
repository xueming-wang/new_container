/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecmain.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:17:49 by xuwang            #+#    #+#             */
/*   Updated: 2022/03/23 17:53:01 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//#include "Vector.hpp"
#include <vector>
#include <iostream>
#include <iterator>
#include <memory>
#include "vector.hpp"

void printstr(std::string string) {
  std::cout << string << std::endl;
}

template<class T>
void print_realsize(std::vector<T> realvec)
{
  std::cout << "size: " << realvec.size() << std::endl;
  std::cout << "max_size: " << realvec.max_size() << std::endl;
  std::cout << "capacity: " << realvec.capacity() << std::endl;
}

template<class T>
void print_mysize(ft::vector<T> myvec)
{
  std::cout << "size: " << myvec.size() << std::endl;
  std::cout << "max_size: " << myvec.max_size() << std::endl;
  std::cout << "capacity: " << myvec.capacity() << std::endl;
}

template<class T>
void  printrealvec(std::vector<T> realvec)
{
  for (typename std::vector<T>::iterator it = realvec.begin(); it != realvec.end(); ++it)
     std::cout << *it << ' ';
  std::cout << "\n";
}

template<class T>
void  printmyvec(ft::vector<T> myvec)
{
  for (typename ft::vector<T>::iterator it = myvec.begin(); it != myvec.end(); ++it)
    std::cout << *it << ' ';
  std::cout <<  "\n";
}

/**
 * constructor test
**/
void constructor_test(void){
 
  printstr("---------Test constructor-----------\n");
  printstr("[real vector info]");
  std::vector<int> first(4);                                // empty vector of ints
  std::vector<int> second(4, 42);                       // four ints with value 100
  std::vector<int> third (second.begin(),second.end());  // iterating through second
  std::vector<int> fourth (third);
  int ints[] = {0,-42,42,1,442}; 
  std::vector<int> fifth (ints,ints + sizeof(ints) / sizeof(int));
  printrealvec(first);
  printrealvec(second);
  printrealvec(third);
  printrealvec(fourth);
  printrealvec(fifth);
  first = second;
  std::cout << "test opearator " << std::endl;
  std::cout << "first vector: ";
  printrealvec(first);
  std::cout << std::endl;
  
  printstr("[my vector info]");  
  ft::vector<int> myfirst(4);                              
  ft::vector<int> mysecond(4, 42);                        
  ft::vector<int> mythird (mysecond.begin(),mysecond.end());
  ft::vector<int> myfourth (mythird);   
  int myints[] = {0,-42,42,1, 442};  
  ft::vector<int> myfifth (myints, myints + sizeof(myints) / sizeof(int) );
  printmyvec(myfirst);
  printmyvec(mysecond);
  printmyvec(mythird);
  printmyvec(myfourth);
  printmyvec(myfifth);
  myfirst = mysecond;
  std::cout << "test opearator " << std::endl;
  std::cout << "first vector: ";
  printrealvec(first);
  std::cout << std::endl;
  
}

/*
** iterator test
*/
void iterator_test(void)
{
  printstr("---------Test iterator-----------\n");
  printstr("[real vector info]");
  std::vector<int> realvec;
  for(int i = 1; i < 6; i++)
    realvec.push_back(i);
  printrealvec(realvec);
  std::vector<int>::iterator it = realvec.begin();
  std::cout << "iterator begin(it) is: "<< *it << std::endl;
  std::vector<int>::iterator ite = realvec.end();
  std::cout << "iterator end(ite) is: "<< *(ite - 1) << std::endl;
  it++;
  std::cout << "begin++(it++) is: "<< *it << std::endl;
  ite--;
  std::cout << "end--(ite--) is: "<< *(ite - 1) << std::endl;
  it += 1;
  std::cout << "it + 1 is: "<< *it << std::endl;
  ite -= 1;
  std::cout << "ite - 1  is: "<< *(ite - 1) << std::endl;
  
  std::vector<int>::const_iterator cit = realvec.begin();
  std::cout << "const_iterator begin is: " << *cit << std::endl;
  std::vector<int>::const_iterator cite = realvec.end();
  std::cout << "const_iterator end is: " <<*(cite - 1) << std::endl;
  
  std::vector<int>::reverse_iterator rit = realvec.rbegin();
  std::cout << "reverse_iterator rbegin is: " << *rit << std::endl;
  std::vector<int>::reverse_iterator rite = realvec.rend();
  std::cout <<  "reverse_iterator rend is: " << *(rite - 1) << std::endl;
  
  std::vector<int>::const_reverse_iterator crit = realvec.rbegin();
  std::cout << "const_reverse_iterator rbegin is: " << *crit << std::endl;
  std::vector<int>::const_reverse_iterator crite = realvec.rend();
  std::cout << "const_rend is: " << *(crite - 1) << std::endl << std::endl;
  
  
  printstr("[my vector info]");
  ft::vector<int> myvec;
  for(int i = 1; i < 6; i++)
    myvec.push_back(i);
  printmyvec(myvec);
  ft::vector<int>::iterator myit = myvec.begin();
  std::cout << "iterator begin(myit) is: "<< *myit << std::endl;
  ft::vector<int>::iterator myite = myvec.end();
  std::cout << "iterator end(myite) is: "<< *(myite - 1) << std::endl;
  myit++;
  std::cout << "begin++(myit++) is: "<< *myit << std::endl;
  myite--;
  std::cout << "end--(myite--) is: "<< *(myite - 1) << std::endl;
  myit += 1;
  std::cout << "myit + 1 is: "<< *myit << std::endl;
  myite -= 1;
  std::cout << "myite - 1  is: "<< *(myite - 1) << std::endl;
  
  ft::vector<int>::const_iterator mycit = myvec.begin();
  std::cout << "const_iterator begin is: " << *mycit << std::endl;
  ft::vector<int>::const_iterator mycite = myvec.end();
  std::cout << "const_iterator end is: " << *(mycite - 1) << std::endl;
  
  ft::vector<int>::reverse_iterator myrit = myvec.rbegin();
  std::cout << "reverse_iterator rbegin is: "<< *myrit << std::endl; 
  ft::vector<int>::reverse_iterator myrite = myvec.rend();
  std::cout << "reverse_iterator rend is: " << *(myrite - 1)<< std::endl;
  
  ft::vector<int>::const_reverse_iterator mycrit = myvec.rbegin();
  std::cout << "const_reverse_iterator rbegin is: "<< *mycrit << std::endl;
  ft::vector<int>::const_reverse_iterator mycrite = myvec.rend();
  std::cout << "const_reverse_iterator is: " << *(mycrite - 1) << std::endl << std::endl;
}
/*
** test size , max_size, capatity, empty
*/
void size_test()
{
  printstr("---------Test size/max_size/empty/capatity-----------\n");
  printstr("[real vector info]");
  std::vector<int> realvec;
  std::cout << "int: " << (realvec.empty() == true ? "realvec is empty" : "realvec is not empt" )<< std::endl;
  realvec.push_back(1);
  std::cout << "int: " << (realvec.empty() == true ? "realvec is empty" : "realvec is not empt" )<< std::endl;
  print_realsize(realvec);
  std::cout << std::endl;
  std::vector<char> realvecchar;
  std::cout << "char: " << (realvecchar.empty() == true ? "realvecchar is empty" : "realvechar is not empt" )<< std::endl;
  realvecchar.push_back('a');
  realvecchar.push_back('b');
  std::cout << "char: " << (realvecchar.empty() == true ? "realvecchar is empty" : "realvechar is not empt" )<< std::endl;
  printrealvec(realvecchar);
  print_realsize(realvecchar);
  std::cout << std::endl;
  
  printstr("[my vector info]");
  ft::vector<int> myvec;
  std::cout << "int: " << (myvec.empty() == true ? "myvec is empty" : "myvec is not empt" )<< std::endl;
  myvec.push_back(1);
  std::cout << "int: " << (myvec.empty() == true ? "myvec is empty" : "myvec is not empt" )<< std::endl;
  print_mysize(myvec);
  std::cout << std::endl;
  ft::vector<char> myvecchar;
  std::cout << "char: " << (myvecchar.empty() == true ? "myvecchar is empty" : "myvechar is not empt" )<< std::endl;
  myvecchar.push_back('a');
  myvecchar.push_back('b');
  std::cout << "char: " << (myvecchar.empty() == true ? "myvecchar is empty" : "myvechar is not empt" )<< std::endl;
  printmyvec(myvecchar);
  print_mysize(myvecchar);
  std::cout << std::endl;
}
/*
** test resize reserve
*/
void resize_test()
{
  printstr("---------Test resize / reserve-----------\n");
  printstr("[real vector info]");
  std::vector<int> realvec;
  realvec.push_back(42);
  printrealvec(realvec);
  realvec.resize(4, 1);
  printrealvec(realvec);
  realvec.resize(2);
  printrealvec(realvec);
  realvec.resize(4, 10);
  printrealvec(realvec);
  realvec.reserve(5);
  print_realsize(realvec);
  std::cout << std::endl;
  
  printstr("[my vector info]");
  ft::vector<int> myvec;
  myvec.push_back(42);
  printmyvec(myvec);
  myvec.resize(4, 1);
  printmyvec(myvec);
  myvec.resize(2);
  printmyvec(myvec);
  myvec.resize(4, 10);
  printmyvec(myvec);
  myvec.reserve(5);
  print_mysize(myvec);
  std::cout << std::endl;
}
/*
** Element access test
*/
void element_test()
{
  printstr("---------Test Element acces(at , [], front. back-----------\n");
  printstr("[real vector info]");
  std::vector<int> realvec;
  for(int i = 1; i <= 10; i++)
    realvec.push_back(i);
  printrealvec(realvec);
  std::cout << "real at(0) is: " << realvec.at(0) << std::endl;
  std::cout << "real operator[9] is: " << realvec[9] << std::endl;
  std::cout << "real operator[10] is: " << realvec[10] << std::endl;
  std::cout << "real front is: " << realvec.front() << std::endl;
  std::cout << "real back is: " << realvec.back() << std::endl;
  std::cout << std::endl;
  
  
  printstr("[my vector info]");
  ft::vector<int> myvec;
  for(int i = 1; i <= 10; i++)
  myvec.push_back(i);
   printmyvec(myvec);
   std::cout << "my at(0) is: " << myvec.at(0) << std::endl;
   std::cout << "my operator[9] is: " << myvec[9] << std::endl;
   std::cout << "my operator[10] is: " << myvec[10] << std::endl;
  std::cout << "my front is: " << myvec.front() << std::endl;
  std::cout << "my back is: " << myvec.back() << std::endl;
  std::cout << std::endl;
}
/*
** assign test
*/
void assign_test()
{
  printstr("---------Test  assign-----------\n");
  printstr("[real vector info]");
  std::vector<int> first;
  std::vector<int> second;
  std::vector<int> third;
  first.assign (7,100);             // 7 ints with a value of 100
  printrealvec(first);
  std::vector<int>::iterator it;
  it=first.begin() + 1;
  second.assign (it, first.end() - 1); // the 5 central values of first
  printrealvec(second);
  int ints[] = {1776,7,4};
  third.assign (ints,ints+3);   // assigning from array.
  printrealvec(third);
  std::cout << "Size of first: " << int (first.size()) << '\n';
  std::cout << "Size of second: " << int (second.size()) << '\n';
  std::cout << "Size of third: " << int (third.size()) << '\n';
 std::cout << std::endl;
  
  printstr("[my vector info]");
  ft::vector<int> myfirst;
  ft::vector<int> mysecond;
  ft::vector<int> mythird;
  myfirst.assign (7,100);       // 7 ints with a value of 100
  printmyvec(myfirst);
  ft::vector<int>::iterator ite;
  ite=myfirst.begin()+1;
  mysecond.assign (ite, (myfirst.end() - 1)); // the 5 central values of first
  printmyvec(mysecond);
  int myints[] = {1776,7,4};
  mythird.assign (myints,myints+3);   // assigning from array.
  printmyvec(mythird);
  std::cout << "Size of myfirst: " << int (myfirst.size()) << '\n';
  std::cout << "Size of mysecond: " << int (mysecond.size()) << '\n';
  std::cout << "Size of mythird: " << int (mythird.size()) << '\n';
  std::cout << std::endl;
}
/*
** insert test
*/
void insert_test()
{
  printstr("---------Test  insert-----------\n");
  printstr("[real vector info]");
  std::vector<int> realvector (3,100); //100 100 100
  printrealvec(realvector);
  
  std::vector<int>::iterator it;
  it = realvector.begin();
  it = realvector.insert (it , 200 ); // 200 100 100 100
  printrealvec(realvector);
  // second insert
  realvector.insert (it,2,300); //300 300 200 100 100 100 
  printrealvec(realvector);
  // third insert with another vector
  it = realvector.begin(); //it在第一位
  std::vector<int> anothervector (2,400);
  realvector.insert (it+2,anothervector.begin(),anothervector.end()); //300 300 400 400 200 100 100 100 第三位插入两个400
  printrealvec(realvector);
  // fourth insert with a tab
  int realarray [] = { 501,502,503 };
  realvector.insert (realvector.begin(), realarray, realarray+3);  // 501 502 503 300 300 400 400 200 100 100 100begin位插入一个数组
  printrealvec(realvector);
  std::cout << std::endl;
  
  printstr("[my vector info]");
  // create
  ft::vector<int> myvector (3,100); //100 100 100
  printmyvec(myvector);
  // first insert
  ft::vector<int>::iterator ite;
  ite = myvector.begin();
  ite = myvector.insert(ite , 200); // 200 100 100 100
  printmyvec(myvector);
  // secont insert
  myvector.insert (ite, 2, 300); //300 300 200 100 100 100 
  printmyvec(myvector);
  // third insert with another vector
  ite = myvector.begin(); //ite在第一位
  ft::vector<int> myanothervector (2,400);
  myvector.insert (ite+2, myanothervector.begin(), myanothervector.end()); //300 300 400 400 200 100 100 100 第三位插入两个400
  printmyvec(myvector);
  // fourth insert with a tab
  int myarray [] = { 501,502,503 };
  myvector.insert (myvector.begin(), myarray, myarray+3);  // 501 502 503 300 300 400 400 200 100 100 100begin位插入一个数组
  printmyvec(myvector);
  
}
/*
** test push_back pop_back 
*/
void push_pop_test()
{
  printstr("---------Test  push_back / pop_back -----------\n");
  printstr("[real vector info]");
  std::vector<std::string> realvec;
  realvec.push_back("hello");
  realvec.push_back("42");
  printrealvec(realvec);
  realvec.pop_back();
  printrealvec(realvec);
  std::cout << std::endl;

  printstr("[my vector info]");
  ft::vector<std::string> myvec;
  myvec.push_back("hello");
  myvec.push_back("42");
  printmyvec(myvec);
  myvec.pop_back();
  printmyvec(myvec);
  std::cout << std::endl;
}
/*
** erase test
*/
void erase_test()
{
  printstr("---------Test erase-----------\n");
  printstr("[real vector info]");
  std::vector<int> realvector;
  for (int i=1; i<=10; i++) realvector.push_back(i);
  printrealvec(realvector);
  // erase the 6th element
  realvector.erase (realvector.begin()+5);
  printrealvec(realvector);
  // erase the first 3 elements:
  realvector.erase (realvector.begin(),realvector.begin()+3);
  printrealvec(realvector);
  std::cout << std::endl;

  printstr("[my vector info]");
  ft::vector<int> myvector;
  for (int i=1; i<=10; i++) myvector.push_back(i);
  printmyvec(myvector);
  // erase the 6th element
  myvector.erase (myvector.begin()+5);
  printmyvec(myvector);
  // erase the first 3 elements:
  myvector.erase (myvector.begin(),myvector.begin()+3);
  printmyvec(myvector);
  std::cout << std::endl;
}
/*
** swap clear test
*/
void swap_clear_test()
{
  printstr("---------Test swap / clear-----------\n");
  printstr("[real vector info]");
  std::vector<int> foo (3,100);   // three ints with a value of 100
  std::vector<int> bar (5,200);   // five ints with a value of 200
  foo.swap(bar);
  std::cout << "foo contains:";
  printrealvec(foo);
  std::cout << "bar contains:";
  printrealvec(bar);
  foo.clear();
  print_realsize(foo);
  std::cout << std::endl;
  

  printstr("[my vector info]");
  ft::vector<int> myfoo (3,100);   // three ints with a value of 100
  ft::vector<int> mybar (5,200);   // five ints with a value of 200
  myfoo.swap(mybar);
  std::cout << "foo contains:";
  printmyvec(myfoo);
  std::cout << "bar contains:";
  printmyvec(mybar);
  myfoo.clear();
  print_mysize(myfoo);
  std::cout << std::endl;
}
/*
**function overloads test
*/
void overloads_test()
{
  printstr("---------Test overloads-----------\n");
  printstr("[real vector info]");
  std::vector<int> realfoo (3,100);
  std::cout << "realfoo vec is: ";
  printrealvec(realfoo);
  std::vector<int> realbar (5,200);
  std::cout << "realbar vec is: ";
  printrealvec(realbar);
  
  /* operator != */
  if (realfoo != realbar) std::cout << "realfoo and realbar is not same" << std::endl;
   /* operator < */
  if (realfoo < realbar) std::cout << "realfoo is smaller then realbar" << std::endl;
  /* operator > */
  if (realfoo > realbar) std::cout << "realfoo is biger then realbar" << std::endl;
 
  /*operator == , <= ,>= */
  realfoo = realbar;
  std::cout << "realfoo vec is: ";
  printrealvec(realfoo);
  
  if (realfoo == realbar) std::cout << "realfoo and realbar is same" << std::endl;
  if (realfoo >= realbar) std::cout << "realfoo is biger or same then realbar" << std::endl;
  if (realfoo <= realbar) std::cout << "realfoo is smaller or same then realbar" << std::endl << std::endl;
  
 
  printstr("[my vector info]");
  ft::vector<int> myfoo (3,100);
  std::cout << "myfoo vec is: ";
  printmyvec(myfoo);
  ft::vector<int> mybar (5,200);
  std::cout << "mybar vec is: ";
  printmyvec(mybar);
  
  /* operator != */
  if (myfoo != mybar) std::cout << "myfoo and mybar is not same" << std::endl;
   /* operator < */
  if (myfoo < mybar) std::cout << "myfoo is smaller then mybar" << std::endl;
  /* operator > */
  if (myfoo > mybar) std::cout << "myfoo is biger then mybar" << std::endl;
 
  
  /*operator ==  <= >= */
  myfoo = mybar;
  std::cout << "myfoo vec is: ";
  printmyvec(myfoo);
  
  if (myfoo == mybar) std::cout << "myfoo and mybar is same" << std::endl;
  if (myfoo >= mybar) std::cout << "myfoo is biger or same then mybar" << std::endl;
  if (myfoo <= mybar) std::cout << "myfoo is smaller or same then mybar" << std::endl ;
  
}

int main()
{
  constructor_test();
  iterator_test();
  size_test();
  resize_test();
  element_test();
  assign_test();
  insert_test();
  push_pop_test();
  erase_test();
  swap_clear_test();
  overloads_test();
  return 0;
}
  
