/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackmain.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:14:16 by xuwang            #+#    #+#             */
/*   Updated: 2022/03/23 17:53:15 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.hpp"
#include <vector>

void printstr(std::string string) {
  std::cout << string << std::endl;
}
/*
** constructor test
*/
void constructor_test(void){

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
void modifier_test() {

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
void operators_test()
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

int main()
{
    constructor_test();
    modifier_test();
    operators_test();
    return 0;
}