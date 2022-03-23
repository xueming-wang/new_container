/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapmain.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:37:56 by xuwang            #+#    #+#             */
/*   Updated: 2022/03/23 19:42:39 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"

#include <map>
#include <iostream>
#include <iterator>
#include <memory>

void printstr(std::string string) {
  std::cout << string << std::endl;
}
template < class Key, class T>
void  printrealmap(std::string string, std::map<Key, T> realmap) {
   std::cout << string << std::endl;
   for (typename std::map<Key, T>::iterator it = realmap.begin(); it != realmap.end(); ++it)
      std::cout << it->first << " => " << it->second << std::endl;
}

template < class Key, class T>
void  printrealmap_val(std::string string, std::map<Key, T> realmap)
{
      std::cout << string;
  for (typename std::map<Key, T>::iterator it = realmap.begin(); it != realmap.end(); ++it)
      std::cout << it->second << ' ';
  std::cout << "\n";
}

template < class Key, class T>
void  printrealmap_key(std::string string, std::map<Key, T> realmap)
{
  
  std::cout << string;
  for (typename std::map<Key, T>::iterator it = realmap.begin(); it != realmap.end(); ++it)
      std::cout << it->first << ' ';
  std::cout << "\n";
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


void constructor_test(void){

  printstr("---------Test constructor, destructor, operaror= ----------");
  printstr("[real real info]");
  std::map<char,int> first;
  printrealmap_val("map first val is: ", first);
  printrealmap_key("map first key is: ", first);
  first['a']=42;
  first['b']=-42;
  printrealmap_val("map first val is: ", first);
  printrealmap_key("map first key is: ", first);
   /*test  with as many elements as the range [first,last)*/
  std::map<char,int> second (first.begin(),first.end());
  printrealmap_val("map second val is: ", second);
  printrealmap_key("map second key is: ", second);
  /*test copy*/
  std::map<char,int> third (second);
  printrealmap_val("map third val is: ", third);
  printrealmap_key("map third key is: ", third);
  /*test operator = */
  third['c'] = 0;
  first = third;
  printrealmap_val("map first val is: ", first);
  printrealmap_key("map first key is: ", first);
  std::cout << std::endl;
  
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
void iterator_test(){
  printstr("---------Test  iterator ----------");
  printstr("[real map info]");
  std::map<int,int> first;
  first[1] = 0;
  first[2] = 42;
  first[3] = -42;
  std::map<int, int>::iterator it = first.begin();
  std::map<int, int>::iterator ite = first.end();
  for(; it != ite; ++it)
      std::cout << it->first << " => " << it->second << std::endl;
  std::map<int, int>::const_iterator cit = first.begin();
  std::map<int, int>::const_iterator cite = first.end();
  for(; cit != cite; ++cit)
      std::cout << cit->first << " => " << cit->second << std::endl;
  std::cout << std::endl;
  /*test reverse iterator*/
  std::map<int, int>::reverse_iterator rit = first.rbegin();
  std::map<int, int>::reverse_iterator rite = first.rend();
  for(; rit != rite; ++rit)
      std::cout << rit->first << " => " << rit->second << std::endl;
  std::map<int, int>::const_reverse_iterator crit = first.rbegin();
  std::map<int, int>::const_reverse_iterator crite = first.rend();
  for(; crit != crite; ++crit)
      std::cout << crit->first << " => " << crit->second << std::endl;
  std::cout << std::endl;
  
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


void size_test(){
  
  printstr("---------Test size /empty-----------");
  printstr("[real map info]");
  std::map<int,int> first;
  std::cout << (first.empty() == 1? "first is empty": "first is not empty") << std::endl;
  std::cout << "first size is: " << first.size() << std::endl;
  
  first[1] = 2;
  std::cout << (first.empty() == 1? "first is empty": "first is not empty") << std::endl;
  std::cout << "first size is: " << first.size() << std::endl;
  
  
  std::map<char,std::string> second;
  std::cout << (second.empty() == 1? "second is empty": "second is not empty") << std::endl;
  std::cout <<  "second size is: " << second.size() << std::endl;
 
  second[1] = 2;
  std::cout << (second.empty() == 1? "second is empty": "second is not empty") << std::endl;
  std::cout <<  "second size is: " << second.size() << std::endl << std::endl;
 
  
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
void element_test() {
  printstr("---------Test element-----------");
  printstr("[real map info]");
  std::map<char, std::string> first;
  first['a']= "hello";
  first['b']= "world";
  std::cout << "first['a'] is : " << first['a'] << std::endl;
  std::cout << "first['b'] is : " << first['b'] << std::endl << std::endl;
  

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
void insert_test(){
  printstr("---------Test insert-----------");
  printstr("[real map info]");
  printstr("(1)insert value_type& val: ");
  std::map<char,int> first;
  first.insert(std::pair<char, int>('a', 100));
  first.insert(std::pair<char, int>('b', 200));
  first.insert(std::pair<char, int>('c', 300));
  printrealmap_val("map first val is: ", first);
  printrealmap_key("map first key is: ", first);
  std::map<char,int>::iterator it = first.begin();
  std::map<char, int>::iterator ite = first.end();
  for(; it != ite; ++it)
      std::cout << it->first << " => " << it->second << std::endl;
  printstr("(2)insert one iterator");
  std::map<char,int> anothermap;
  anothermap.insert(first.begin(),first.find('c'));
  for (it=anothermap.begin(); it!=anothermap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
  printstr("(3)insert same key: ");
  std::pair<std::map<char,int>::iterator, bool> ret;
  ret = first.insert ( std::pair<char, int>('a' ,400));
  if (ret.second==false) {
    std::cout << "element 'a' already existed";
    std::cout << " with a value of " << ret.first->second << '\n';
  }
  std::map<char,int>::iterator iit = first.begin();
  std::map<char, int>::iterator iite = first.end();
  for(; iit != iite; ++iit)
      std::cout << iit->first << " => " << iit->second << std::endl;
  std::cout << std::endl;

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
// */
void erase_test(){
  
  printstr("---------Test erase-----------");
  printstr("[real map info]");
  std::map<char,int> first;
  first.insert(std::pair<char, int>('a', 100));
  first.insert(std::pair<char, int>('b', 200));
  first.insert(std::pair<char, int>('c', 300));
  first.insert(std::pair<char, int>('d', 400));
  std::map<char,int>::iterator it = first.begin();
  std::map<char,int>::iterator ite = first.end();
  printrealmap_val("map first val is: ", first);
  printrealmap_key("map first key is: ", first);
  first.erase(it);
  printrealmap_val("map first val is: ", first);
  printrealmap_key("map first key is: ", first);
  first.erase('b');
  printrealmap_val("map first val is: ", first);
  printrealmap_key("map first key is: ", first);
  it = first.begin();
  ite = first.end();
  first.erase(it, ite);
  printrealmap_val("map first val is: ", first);
  printrealmap_key("map first key is: ", first);
  std::cout << std::endl;
  
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
void swap_clear_test(){
  printstr("---------Test  swap, clear-----------");
  printstr("[real map info]");
  std::map<char,int> first;
  first['a'] = 42;
  first['b'] = 0;
  printrealmap("first is:", first);
  std::map<char,int> second;
  second['1'] = 100;
  second['2'] = 200;
  printrealmap("second is:", second);
  first.swap(second);
  printstr("---aftre swap: ");
  printrealmap("first is:", first);
  printrealmap("second is:", second); 
  printstr("---aftre clear: ");
  first.clear();
  printrealmap("first is:", first);
  second.clear();
  printrealmap("second is:", second); 
  std::cout << std::endl;
  
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
void keyComp_valComp_test(){
  /*test key_comp*/
  printstr("---------Test  keyComp valComp-----------");
  printstr("[real map info]");
  std::map<char,int> first;
  std::map<char,int>::key_compare firstcomp = first.key_comp();
  first['a']=100;
  first['b']=200;
  first['c']=300;
  std::cout << "first contains:\n";
  char highest = first.rbegin()->first;     // key value of last element
  std::map<char,int>::iterator it = first.begin();
  do {
    std::cout << it->first << " => " << it->second << '\n';
  } while ( firstcomp((*it++).first, highest) );
  /*test value_comp*/
  std::map<char,int> second;
  second['x']=1001;
  second['y']=2002;
  second['z']=3003;
  std::cout << "second contains:\n";
  std::pair<char,int> sechighest = *second.rbegin();          // last element
  std::map<char,int>::iterator secit = second.begin();
  do {
    std::cout << secit->first << " => " << secit->second << '\n';
  } while (second.value_comp()(*secit++, sechighest) );
  std::cout << std::endl;
  
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
void	find_test() {
  printstr("---------Test find-----------");
  printstr("[real map info]");
  std::map<char, int> first;
  first['a'] = 100;
  first['b'] = 200;
  first['c'] = 300;
  printrealmap("myfirst is:", first);
  std::map<char, int>::iterator it;
  printstr("find 'a': ");
  it = first.find('a');
  std::cout << it->first << " => " << it->second << std::endl;
  printstr("find 'b': ");
  it = first.find('b');
  std::cout << it->first << " => " << it->second << std::endl;
  std::map<char, int>::const_iterator cit;
  printstr("find const 'c': ");
  cit = first.find('c');
  std::cout << cit->first << " => " << cit->second << std::endl << std::endl;
  

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
void count_test() {
  printstr("---------Test count-----------");
  printstr("[real map info]");
  std::map<char, int> first;
  first['a'] = 100;
  first['b'] = 200;
  first['c'] = 300;
  std::cout << (first.count('b') == 1? "'b' is exist": "'b' is not exist")<< std::endl;
  std::cout << (first.count('e') == 1? "'a' is exist": "'e' is not exist")<< std::endl;
  std::cout << std::endl;
  
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
void bound_test() {
  printstr("---------Test bound-----------");
  printstr("[real map info]");
  std::map<int, char> first;
  first[1] = 'a';
  first[2] = 'b';
  first[3] = 'c';
  std::map<int, char>::iterator it;
  printstr("to find node >= 1");
  it = first.lower_bound(1);
  std::cout << it->first << " => " << it->second << std::endl;
  printstr("to find node > 1");
  it = first.upper_bound(1);
  std::cout << it->first << " => " << it->second << std::endl;
  printstr("to find node > 2");
  it = first.upper_bound(2);
  std::cout << it->first << " => " << it->second << std::endl << std::endl;
  
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
void equal_test() {
  printstr("---------Test equal_Range-----------");
  printstr("[real map info]");
  std::map<int, char> first;
  first[1] = 'a';
  first[2] = 'b';
  first[3] = 'c';
  std::pair<std::map<int, char>::iterator, std::map<int, char>::iterator> ret;
  ret = first.equal_range(1); //ret = <lower_bound , upp_bound>
  std::cout << ret.first->first << " => " << ret.first->second << std::endl;
  std::cout << ret.second->first << " => " << ret.second->second << std::endl << std::endl;
  
  ret = first.equal_range(2); //ret = <lower_bound , upp_bound>
  std::cout << ret.first->first << " => " << ret.first->second << std::endl;
  std::cout << ret.second->first << " => " << ret.second->second << std::endl << std::endl;

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

int main() {
  constructor_test();
  iterator_test();
  size_test();
  element_test();
  insert_test();
  erase_test(); 
  swap_clear_test();
  keyComp_valComp_test();
  find_test();
  count_test();
  bound_test();
  equal_test();
}