#include <iostream>
#include <memory>
#include <stack>
#include <vector>
#include "vector.hpp"
#include "stack.hpp"
#include <stack>
#include <iterator>
#include <string>
#include <map>
#include "pair.hpp"
#include "map.hpp"
int main()
{
  
    // allocator for integer values
    // std::allocator<int> myAllocator;
    // // allocate space for five ints
    // int* arr = myAllocator.allocate(5);
    // std::vector<std::string> ss(5, "Dwed");
    // // construct arr[0] and arr[3]
    // myAllocator.construct(arr, 100);
    // arr[3] = 10;
    // std::ptrdiff_t p = arr[3];
    // std::cout << arr[1] << std::endl;
    // std::cout << arr[3] << std::endl;

    
    // ft::stack<std::string> d;
    //ft::vector<std::string> ss;
    // ft::vector<std::string> s(4, "d");
    // std::vector<std::string> ss();
    // std::cout << ss.front() << std::endl;
    //ss.reserve(5);
    //ss.resize(6);
    // s.reserve(2);
    // s.resize(6);

    // // deallocate space for five ints
    // std::cout << s.size()<< " " << s.capacity() << " " << *s.begin() << std::endl;
    // std::cout << ss.size()<< " " << ss.capacity() << " " << ss[2] << std::endl;
    // myAllocator.deallocate(arr, 5);


//     ft::vector<std::string> tmp(4, "d");
//     ft::vector<std::string> s(tmp.begin(), tmp.end());
//     //s = tmp;
//     std::vector<string> s1(9, "de");
//     cout << " we;frfe" << endl;
//     ft::vector<std::string>::iterator ss = s.begin();
//     std::vector<std::string>::iterator s2 = s1.begin();

//     cout << " we;frfe" << endl;
//     //s.insert(ss, "de");
//     tmp.push_back("omar");
//     tmp.push_back("noobnoob");
//     tmp.erase(tmp.begin() + 2, tmp.begin() + 5);
//     std::cout << tmp.size()<< " " << tmp.capacity() << " " << *ss << std::endl;
//     std::cout << tmp.size()<< " " << tmp.capacity() << " " << *(1 + s2) << std::endl;
//     ft::reverse_iterator<std::vector<string>::iterator> ll(s1.end());
//     ft::reverse_iterator<std::vector<string>::iterator> ll2(s1.begin());
//    for (ft::vector<std::string>::iterator ff = tmp.begin(); ff < tmp.end() ; ff++)
//         std::cout << *(ff) << std::endl;
//     std::cout <<"-------------------" << std::endl;

//     for (; ll < ll2 ; ll++)
//         std::cout << *(ll) << std::endl;
    allocator<ft::pair<string ,string> > alloc;
    ft::pair<string, string> *p = alloc.allocate(1);
    alloc.construct(p, "1","ded");
    ft::pair<string, string> p2("1", "cw");
    ft::pair<string, string> p3("4", "cw");
    // map<int, string> m;
    // m.insert(*p);
    // alloc.deallocate(p, 1);
    // cout << m.begin()->first << " " << m.end()->second << endl;


    ft::BST<string , string> tmp(p2);
    tmp.insert(&tmp, "1", "cdcdc");
    cout << tmp.left->m_pair->first << " " << tmp.left->m_pair->second << endl;
    // ft::vector<std::string> s(7, "wesh");
    // ft::vector<std::string> f(5, "asat");
    
    // s.insert(s.begin(), s.begin() + 2, s.begin() + 5);
    // for (ft::vector<std::string>::iterator ss = s.begin(); ss < s.end() ; ss++)
    //     std::cout << *ss << std::endl;
    // for (ft::vector<std::string>::iterator ss = f.begin(); ss < f.end() ; ss++)
    //     std::cout << *ss << std::endl;
    return 0;
}
