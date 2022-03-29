/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realmain.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:04:22 by xuwang            #+#    #+#             */
/*   Updated: 2022/03/29 16:37:44 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <iterator>
#include <memory>
#include <map>
#include <stack>

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
void  printrealvec(std::vector<T> realvec)
{
  for (typename std::vector<T>::iterator it = realvec.begin(); it != realvec.end(); ++it)
     std::cout << *it << ' ';
  std::cout << "\n";
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

void vec_constructor_test(void){
 
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
}

/*
** iterator test
*/
void vec_iterator_test(void)
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
  
}
/*
** test size , max_size, capatity, empty
*/
void vec_size_test()
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
  
}
/*
** test resize reserve
*/
void vec_resize_test()
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
  
}
/*
** Element access test
*/
void vec_element_test()
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
  
}
/*
** assign test
*/
void vec_assign_test()
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
  
}
/*
** insert test
*/
void vec_insert_test()
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
  
}
/*
** test push_back pop_back 
*/
void vec_push_pop_test()
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

}
/*
** erase test
*/
void vec_erase_test()
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

}
/*
** swap clear test
*/
void vec_swap_clear_test()
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
  
}
/*
**function overloads test
*/
void vec_overloads_test()
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
  
}


void real_vector()
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
}

void map_iterator_test(){
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
}

void map_size_test(){
  
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
}

void map_element_test() {
  printstr("---------Test element-----------");
  printstr("[real map info]");
  std::map<char, std::string> first;
  first['a']= "hello";
  first['b']= "world";
  std::cout << "first['a'] is : " << first['a'] << std::endl;
  std::cout << "first['b'] is : " << first['b'] << std::endl << std::endl;
}

void map_insert_test(){
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
}


void map_erase_test(){
  
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
}

void map_swap_clear_test(){
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
}

void map_keyComp_valComp_test(){
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
}

void	map_find_test() {
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
}

void map_count_test() {
  printstr("---------Test count-----------");
  printstr("[real map info]");
  std::map<char, int> first;
  first['a'] = 100;
  first['b'] = 200;
  first['c'] = 300;
  std::cout << (first.count('b') == 1? "'b' is exist": "'b' is not exist")<< std::endl;
  std::cout << (first.count('e') == 1? "'a' is exist": "'e' is not exist")<< std::endl;
  std::cout << std::endl;
}

void map_bound_test() {
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
}

void map_equal_test() {
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
}

void real_map()
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
    printstr("[real stack info]");
    std::vector<int> realvec (2,200); 
    std::stack<int, std::vector<int> > realstack (realvec);
    std::cout << realstack.size() << std::endl;

    std::vector<char> realvecchar (3, 'a');
    std::stack<char, std::vector<char> > realstackchar (realvecchar);
    std::cout << realstackchar.size() << std::endl;

    std::vector<std::string> realvecstr (4, "42");
    std::stack<std::string, std::vector<std::string> > realstackstr (realvecstr);
    std::cout << realstackstr.size() << std::endl << std::endl;
}

void stack_modifier_test() {

    printstr("---------Test empty push top pop-----------\n");
    printstr("[real stack info]");
    std::stack<int> realstack;
    std::cout << "int: " << (realstack.empty() == true ? "realstack is empty" : "realstack is not empt" )<< std::endl;

    realstack.push(1);
    std::cout << "int: " << (realstack.empty() == true ? "realstack is empty" : "realstack is not empt" )<< std::endl;
    std::cout << "size is: " << realstack.size() << std::endl;
    std::cout << "top element is: " << realstack.top() << std::endl;
    
    realstack.push(2);
    std::cout << "size is: " << realstack.size() << std::endl;
    std::cout << "top element is: " << realstack.top() << std::endl;

    realstack.pop();
    realstack.pop();
    std::cout << "int: " << (realstack.empty() == true ? "mystack is empty" : "mystack is not empt" )<< std::endl;
    std::cout << std::endl;
}

void stack_operators_test()
{
    printstr("---------Test relational operators-----------\n");
    printstr("[real stack info]");
    std::stack<int, std::vector<int> > realstack1;
    std::cout << "realstack1 size is: " << realstack1.size() << std::endl;
    std::stack<int, std::vector<int> > realstack2;
    std::cout << "realstack2 size is: " << realstack2.size() << std::endl;
    if (realstack1 == realstack2) std::cout << "realstdack1 and realstack2 is same" << std::endl;
    
    std::vector<int> realvec (2,200);
    std::stack<int, std::vector<int> >realstack3(realvec);
    std::cout << "realstack1 size is: " << realstack1.size() << std::endl;
    std::cout << "realstack3 size is: " << realstack3.size() << std::endl;
    if (realstack1 != realstack3) std::cout << "realstdack1 and realstack3 is not same" << std::endl;
    if (realstack1 < realstack3) std::cout << "realstdack1 is smaller then realstack3" << std::endl;
    if (realstack1 > realstack3 == false) std::cout << "realstdack1 is smaller then realstack3" << std::endl;
    if (realstack1 <= realstack3) std::cout << "realstdack1 is smaller or same then realstack3" << std::endl<< std::endl;
    if (realstack1 >= realstack3) std::cout << "realstdack1 is bigger or same then realstack3" << std::endl; //not show
}


void real_stack()
{
    stack_constructor_test();
    stack_modifier_test();
    stack_operators_test();
}

int main()
{
  real_vector();
  real_map();
  real_stack();
  return (0);
}
