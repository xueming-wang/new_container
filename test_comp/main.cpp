/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:38:46 by xuwang            #+#    #+#             */
/*   Updated: 2022/03/29 17:05:02 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vector.hpp"
#include "../map.hpp"
#include "../stack.hpp"
#include <iostream>
#include <memory>

void printstr(std::string string) {
  std::cout << string << std::endl;
}

template<class T>
void print_mysize(ft::vector<T> myvec)
{
  std::cout << "size: " << myvec.size() << std::endl;
  std::cout << "max_size: " << myvec.max_size() << std::endl;
  std::cout << "capacity: " << myvec.capacity() << std::endl;
}

template<class T>
void  printmyvec(ft::vector<T> myvec)
{
  for (typename ft::vector<T>::iterator it = myvec.begin(); it != myvec.end(); ++it)
    std::cout << *it << ' ';
  std::cout <<  "\n";
}

template < class Key, class T>
void  printmymap(std::string string, ft::map<Key, T> mymap)
{
  std::cout << string << std::endl;
  for (typename ft::map<Key, T>::iterator it = mymap.begin(); it != mymap.end(); ++it)
      std::cout << it->first << " => " << it->second << std::endl;
}
template < class Key, class T>
void  printmymap_val(std::string string, ft::map<Key, T> mymap)
{
  
      std::cout << string;
  for (typename ft::map<Key, T>::iterator it = mymap.begin(); it != mymap.end(); ++it)
      std::cout << it->second << ' ';
  std::cout << "\n";
}

template < class Key, class T>
void  printmymap_key(std::string string, ft::map<Key, T> mymap)
{
  
      std::cout << string;
  for (typename ft::map<Key, T>::iterator it = mymap.begin(); it != mymap.end(); ++it)
      std::cout << it->first << ' ';
  std::cout << "\n";
}

void vec_constructor_test(void){
 
  printstr("---------Test constructor-----------\n");
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
  std::cout << "myfirst vector: ";
  printmyvec(myfirst);
  std::cout << std::endl;
}

/*
** iterator test
*/
void vec_iterator_test(void)
{
  printstr("---------Test iterator-----------\n");
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
void vec_size_test()
{
  printstr("---------Test size/max_size/empty/capatity-----------\n");
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
void vec_resize_test()
{
  printstr("---------Test resize / reserve-----------\n");
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
void vec_element_test()
{
  printstr("---------Test Element acces(at , [], front. back-----------\n");
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
void vec_assign_test()
{
  printstr("---------Test  assign-----------\n");
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
void vec_insert_test()
{
  printstr("---------Test  insert-----------\n");
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
void vec_push_pop_test()
{
  printstr("---------Test  push_back / pop_back -----------\n");
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
void vec_erase_test()
{
  printstr("---------Test erase-----------\n");
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
void vec_swap_clear_test()
{
  printstr("---------Test swap / clear-----------\n");
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
void vec_overloads_test()
{
  printstr("---------Test overloads-----------\n");
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
  if (myfoo <= mybar) std::cout << "myfoo is smaller or same then mybar" << std::endl << std::endl;
  
}

void my_vector()
{
  vec_constructor_test();
  vec_iterator_test();
  vec_size_test();
  vec_resize_test();
  vec_element_test();
  vec_assign_test();
  vec_insert_test();
  vec_push_pop_test();
  vec_erase_test();
  vec_swap_clear_test();
  vec_overloads_test();
  
}
void map_constructor_test(void){

  printstr("---------Test constructor, destructor, operaror= ----------");
  printstr("[my map info]");
  ft::map<char,int> myfirst;
  printmymap_val("map myfirst val is: ", myfirst);
  printmymap_key("map myfirst key is: ", myfirst);
  myfirst['a']=42;
  myfirst['b']=-42;
  printmymap_val("map myfirst val is: ", myfirst);
  printmymap_key("map myfirst key is: ", myfirst);
  /*test  with as many elements as the range [myfirst,last)*/
  ft::map<char,int> mysecond (myfirst.begin(),myfirst.end());
  printmymap_val("map mysecond val is: ", mysecond);
  printmymap_key("map mysecond key is: ", mysecond);
  /*test copy*/
  ft::map<char,int> mythird (mysecond);
  printmymap_val("map mythird val is: ", mythird);
  printmymap_key("map mythird key is: ", mythird);
  /*test operator = */
  mythird['c'] = 0;
  myfirst = mythird;
  printmymap_val("map first val is: ", myfirst);
  printmymap_key("map first key is: ", myfirst);
  std::cout << std::endl;
}

/*
** iterator test
*/
void map_iterator_test(){
  printstr("---------Test  iterator ----------");
  printstr("[my map info]");
  ft::map<int,int> myfirst;
  myfirst[1] = 0;
  myfirst[2] = 42;
  myfirst[3] = -42;
  ft::map<int, int>::iterator myit = myfirst.begin();
  ft::map<int, int>::iterator myite = myfirst.end();
  for(; myit != myite; ++myit)
      std::cout << myit->first << " => " << myit->second << std::endl;
      
  ft::map<int, int>::const_iterator mycit = myfirst.begin();
  ft::map<int, int>::const_iterator mycite = myfirst.end();
  for(; mycit != mycite; ++mycit)
      std::cout << mycit->first << " => " << mycit->second << std::endl;
  std::cout << std::endl;
  
  // /*test reverse iterator*/
  ft::map<int, int>::reverse_iterator myrit = myfirst.rbegin();
  ft::map<int, int>::reverse_iterator myrite = myfirst.rend();
  for (;myrit != myrite; ++myrit)
    std::cout << myrit->first << " => " << myrit->second << '\n';
  
  ft::map<int, int>::const_reverse_iterator mycrit = myfirst.rbegin();
  ft::map<int, int>::const_reverse_iterator mycrite = myfirst.rend();
  for(; mycrit != mycrite; ++mycrit)
      std::cout << mycrit->first << " => " << mycrit->second << std::endl;
  std::cout << std::endl;

}


void map_size_test(){
  
  printstr("---------Test size /empty-----------");
  printstr("[my map info]");
  ft::map<int,int> myfirst;
  std::cout << (myfirst.empty() == 1? "first is empty": "first is not empty") << std::endl;
  std::cout << "first size is: " << myfirst.size() << std::endl;
  
  myfirst[1] = 2;
  std::cout << (myfirst.empty() == 1? "first is empty": "first is not empty") << std::endl;
  std::cout << "first size is: " << myfirst.size() << std::endl;
 
  
  ft::map<char,std::string> mysecond;
  std::cout << (mysecond.empty() == 1? "second is empty": "second is not empty") << std::endl;
  std::cout <<  "second size is: " << mysecond.size() << std::endl;
  
  mysecond[1] = 2;
  std::cout << (mysecond.empty() == 1? "second is empty": "second is not empty") << std::endl;
  std::cout <<  "second size is: " << mysecond.size() << std::endl << std::endl;
  
} 
/*
** Element access test
*/
void map_element_test() {
  printstr("---------Test element-----------");
  printstr("[my map info]");
  ft::map<char, std::string> myfirst;
  myfirst['a'] = "hello";
  myfirst['b'] = "world";
  std::cout << "myfirst['a'] is : " << myfirst['a'] << std::endl;
  std::cout << "myfirst['b'] is : " << myfirst['b'] << std::endl;
  std::cout << std::endl;
}
/*
** insert test
*/
void map_insert_test(){
  printstr("---------Test insert-----------");
  printstr("[my map info]");
  ft::map<char,int> myfirst;
  printstr("(1)insert value_type& val: ");
  myfirst.insert(ft::pair<char, int>('a', 100));
  myfirst.insert(ft::pair<char, int>('b', 200));
  myfirst.insert(ft::pair<char, int>('c', 300));
  printmymap_val("map first val is: ", myfirst);
  printmymap_key("map first key is: ", myfirst);
  ft::map<char,int>::iterator myit = myfirst.begin();
  ft::map<char,int>::iterator myite = myfirst.end();
  for(; myit != myite; ++myit)
      std::cout << myit->first << " => " << myit->second << std::endl;
  
  printstr("(2)insert one iterator to anothermp: ");
  ft::map<char,int> myanothermap;
  myanothermap.insert(myfirst.begin(), myfirst.find('c'));
  for (myit=myanothermap.begin(); myit!=myanothermap.end(); ++myit) {
      std::cout << myit->first << " => " << myit->second << '\n';}
      
  printstr("(3)insert same key: ");
  ft::pair<ft::map<char,int>::iterator,bool> myret;
  myret = myfirst.insert (ft::pair<char, int>('a', 300));//添加重复的key 有问题
  if (myret.second == false) {  //说明没有添加
    std::cout << "element 'a' already existed";
    std::cout << " with a value of " << myret.first->second << '\n';
  }
  
  ft::map<char,int>::iterator myiit = myfirst.begin();
  ft::map<char, int>::iterator myiite = myfirst.end();
  for(; myiit != myiite; ++myiit)
      std::cout << myiit->first << " => " << myiit->second << std::endl;
  std::cout << std::endl;
  
}

/*
** erase test
 */
void map_erase_test(){
  
  printstr("---------Test erase-----------");
  printstr("[my map info]");
  ft::map<char,int> myfirst;
  myfirst.insert(ft::pair<char, int>('a', 100));
  myfirst.insert(ft::pair<char, int>('b', 200));
  myfirst.insert(ft::pair<char, int>('c', 300));
  myfirst.insert(ft::pair<char, int>('d', 400));
  /*erase for (iterator position)*/
  ft::map<char,int>::iterator myit = myfirst.begin();
  ft::map<char,int>::iterator myite = myfirst.end();
  printmymap_val("map myfirst val is: ", myfirst);
  printmymap_key("map myfirst key is: ", myfirst);
  myfirst.erase(myit);
  printmymap_val("map myfirst val is: ", myfirst);
  printmymap_key("map myfirst key is: ", myfirst);
  /*erase for key_type& key */
  myfirst.erase('b');
  printmymap_val("map myfirst val is: ", myfirst);
  printmymap_key("map myfirst key is: ", myfirst);
  /*erase for range (iterator first to  iterator last)*/
  myit = myfirst.begin();
  myite = myfirst.end();
  myfirst.erase(myit, myite);
  printmymap_val("map myfirst val is: ", myfirst);
  printmymap_key("map myfirst key is: ", myfirst);
  std::cout << std::endl;
}
/*
** swap, clear test
*/
void map_swap_clear_test(){
  printstr("---------Test  swap, clear-----------");
  printstr("[my map info]");
  ft::map<char,int> myfirst;
  myfirst['a'] = 42;
  myfirst['b'] = 0;
  printmymap("myfirst is:", myfirst);
  ft::map<char,int> mysecond;
  mysecond['1'] = 100;
  mysecond['2'] = 200;
  printmymap("mysecond is:", mysecond);
  myfirst.swap(mysecond);
  printstr("---aftre swap: ");
  printmymap("myfirst is:", myfirst);
  printmymap("mysecond is:", mysecond); 
  printstr("---aftre clear: ");
  myfirst.clear();
  printmymap("myfirst is:", myfirst);
  mysecond.clear();
  printmymap("mysecond is:", mysecond); 
  std::cout << std::endl;
}
/**
 * keyComp valComp test
*/
void map_keyComp_valComp_test(){
  /*test key_comp*/
  printstr("---------Test  keyComp valComp-----------");
  printstr("[my map info]");
  ft::map<char,int> myfirst;
  ft::map<char,int>::key_compare myfirstcomp = myfirst.key_comp();
  myfirst['a']=100;
  myfirst['b']=200;
  myfirst['c']=300;
  std::cout << "myfirst contains:\n";
  char myhighest = myfirst.rbegin()->first;     // key value of last element
  ft::map<char,int>::iterator myit = myfirst.begin();
  do {
    std::cout << myit->first << " => " << myit->second << '\n';
  } while (myfirstcomp ((*myit++).first, myhighest) );
  std::cout << std::endl;

  ft::map<char,int> mysecond;
  mysecond['x']=1001;
  mysecond['y']=2002;
  mysecond['z']=3003;
  std::cout << "mysecond contains:\n";
  ft::pair<char,int> mysechighest = *mysecond.rbegin();          // last element
  ft::map<char,int>::iterator mysecit = mysecond.begin();
  do {
    std::cout << mysecit->first << " => " << mysecit->second << '\n';
  } while (mysecond.value_comp()(*mysecit++, mysechighest) );
  std::cout << std::endl;
  
}
/**
 * find test
*/
void	map_find_test() {
  printstr("---------Test find-----------");
  printstr("[my map info]");
  ft::map<char, int> myfirst;
  myfirst['a'] = 100;
  myfirst['b'] = 200;
  myfirst['c'] = 300;
  printmymap("myfirst is:", myfirst);
  ft::map<char, int>::iterator myit;
  printstr("find 'a': ");
  myit = myfirst.find('a');
  std::cout << myit->first << " => " << myit->second << std::endl;
  printstr("find 'b': ");
  myit = myfirst.find('b');
  std::cout << myit->first << " => " << myit->second << std::endl;
  ft::map<char, int>::const_iterator mycit;
  printstr("find const 'c': ");
  mycit = myfirst.find('c');
  std::cout << mycit->first << " => " << mycit->second << std::endl;
  std::cout << std::endl;
}
/*
**  count test
*/
void map_count_test() {
  printstr("---------Test count-----------");
  printstr("[my map info]");
  ft::map<char, int> myfirst;
  myfirst['a'] = 100;
  myfirst['b'] = 200;
  myfirst['c'] = 300;
  std::cout << (myfirst.count('b') == 1? "'b' is exist": "'b' is not exist")<< std::endl;
  std::cout << (myfirst.count('e') == 1? "'e' is exist": "'e' is not exist")<< std::endl;
  std::cout << std::endl;
}
/**
 *  bound test
*/
void map_bound_test() {
  printstr("---------Test bound-----------");
  printstr("[my map info]");
  ft::map<int, char> myfirst;
  myfirst[1] = 'a';
  myfirst[2] = 'b';
  myfirst[3] = 'c';
  ft::map<int, char>::iterator myit;
  printstr("to find node >= 1");
  myit = myfirst.lower_bound(1);
  std::cout << myit->first << " => " << myit->second << std::endl;
  printstr("to find node > 1");
  myit = myfirst.upper_bound(1);
  std::cout << myit->first << " => " << myit->second << std::endl;
  printstr("to find node > 2");
  myit = myfirst.upper_bound(2);
  std::cout << myit->first << " => " << myit->second << std::endl << std::endl;
}
/**
 * equal_Range test
*/
void map_equal_test() {
  printstr("---------Test equal_Range-----------");
  printstr("[my map info]");
  ft::map<int, char> myfirst;
  myfirst[1] = 'a';
  myfirst[2] = 'b';
  myfirst[3] = 'c';
  ft::pair<ft::map<int, char>::iterator, ft::map<int, char>::iterator> myret;
  myret = myfirst.equal_range(1); //ret = <lower_bound , upp_bound>
  std::cout << myret.first->first << " => " << myret.first->second << std::endl;
  std::cout << myret.second->first << " => " << myret.second->second << std::endl << std::endl;
  
  myret = myfirst.equal_range(2); //ret = <lower_bound , upp_bound>
  std::cout << myret.first->first << " => " << myret.first->second << std::endl;
  std::cout << myret.second->first << " => " << myret.second->second << std::endl << std::endl;
}

void my_map()
{
  map_constructor_test();
  map_iterator_test();
  map_size_test();
  map_element_test();
  map_insert_test();
  map_erase_test(); 
  map_swap_clear_test();
  map_keyComp_valComp_test();
  map_find_test();
  map_count_test();
  map_bound_test();
  map_equal_test();
}

void stack_constructor_test(void){

    printstr("---------Test constructor-----------\n");
    printstr("[my stack info]");
    ft::vector<int> myvec (2,200); 
    ft::stack<int, ft::vector<int> > mystack (myvec);
    std::cout << mystack.size() << std::endl;

    ft::vector<char> myvecchar (3, 'a');
    ft::stack<char, ft::vector<char> > mystackchar (myvecchar);
    std::cout << mystackchar.size() << std::endl;

    ft::vector<std::string> myvecstr (4, "42");
    ft::stack<std::string, ft::vector<std::string> > mystackstr (myvecstr);
    std::cout << mystackstr.size() << std::endl;
}
/*
** empty push top pop test
*/
void stack_modifier_test() {

    printstr("---------Test empty push top pop-----------\n");
    printstr("[my stack info]");
    ft::stack<int> mystack;
    std::cout << "int: " << (mystack.empty() == true ? "mystack is empty" : "mystack is not empt" )<< std::endl;

    mystack.push(1);
    std::cout << "int: " << (mystack.empty() == true ? "mystack is empty" : "mystack is not empt" )<< std::endl;
    std::cout << "size is: " << mystack.size() << std::endl;
    std::cout << "top element is: " << mystack.top() << std::endl;
    
    mystack.push(2);
    std::cout << "size is: " << mystack.size() << std::endl;
    std::cout << "top element is: " << mystack.top() << std::endl;

    mystack.pop();
    mystack.pop();
    std::cout << "int: " << (mystack.empty() == true ? "mystack is empty" : "mystack is not empt" )<< std::endl;
}
/*
** test relational operators
*/
void stack_operators_test()
{
    printstr("---------Test relational operators-----------\n");
    printstr("[my stack info]");
    ft::stack<int> mystack1;
    std::cout << "mystack1 size is: " << mystack1.size() << std::endl;
    ft::stack<int> mystack2;
    std::cout << "mystack2 size is: " << mystack2.size() << std::endl;
    if (mystack1 == mystack2) std::cout << "mystdack1 and mystack2 is same" << std::endl;
    
    ft::vector<int> myvec (2,200);
    ft::stack<int> mystack3(myvec);
    std::cout << "mystack1 size is: " << mystack1.size() << std::endl;
    std::cout << "mystack3 size is: " << mystack3.size() << std::endl;
    if (mystack1 != mystack3) std::cout << "mystdack1 and mystack3 is not same" << std::endl;
    if (mystack1 < mystack3) std::cout << "mystdack1 is smaller then mystack3" << std::endl;
    if (mystack1 > mystack3 == false) std::cout << "mystdack1 is smaller then mystack3" << std::endl;
    if (mystack1 <= mystack3) std::cout << "mystdack1 is smaller or same then mystack3" << std::endl;
    if (mystack1 >= mystack3) std::cout << "mystdack1 is bigger or same then mystack3" << std::endl; //not show
}

void my_stack()
{
    stack_constructor_test();
    stack_modifier_test();
    stack_operators_test();
}

int main()
{
    my_vector();
    my_map();
    my_stack();
    return 0;
}