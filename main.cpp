#include <iostream>
#include <memory>
#include <stack>
#include <vector>
//#include "Vector.hpp"
#include "stack.hpp"
#include <stack>
#include <iterator>
#include <string>
#include <map>
#include "pair.hpp"
#include "map.hpp"


template <class T>
typename ft::enable_if<ft::is_integral<T>::value,bool>::type
  is_odd (T i) {return bool(i%2);}

// 2. the second template argument is only valid if T is an integral type:
template < class T, class = typename ft::enable_if<ft::is_integral<T>::value >::type >
bool is_even (T i) {return !bool(i%2);}

int main()
{
   int i = 1;
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
    alloc.construct(p, "1", "dee");
    ft::pair<string, string> p2("3", "cw");
    ft::pair<string, string> p3("7", "cw");
    // map<string, string> m;
    // m.insert(*p);
    // m.insert(p2);
    // m.insert(p3);
    // cout << m["199"] << endl;
    // map<string , string>::iterator it = m.end();
    // mm.erase(i);
    // while (it != m.begin())
    // {
    //     it--;
    //     cout << it->first << " " << it->second << endl;
    // }
    // map<string, string>::iterator it = m.begin();
    // it++;
    // m.insert(it, *p);
    // // alloc.deallocate(p, 1);
    // //  cout << m.end()->first << " " << m.end()->second << endl;

    // while (it != m.end())
    // {
    //     cout << it->first << " " << it->second << endl;
    //     it++;
    // }
    // ft::BST<string , string> tmp1(p3);
    //tmp1.insert(&tmp1, "4", "cdcdc");
    // tmp1.insert(&tmp1, p2);
    // tmp1.insert(&tmp1, p2);
    ft::map<string, string> mm;
    ft::map<string, string> mm1;
    // cout << "wefwef"<<endl;
    mm.insert(p2);
    cout << "          **************"<<endl;
    mm.insert(p3);
    cout << "          **************"<<endl;
    mm.insert(*p);
    cout << "          **************"<<endl;
    mm.insert(ft::make_pair<string, string>("8", "ferf"));
    // ft::BST<string , string> tmp;
    // tmp = tmp1;
    cout << "          **************"<<endl;
    mm["199"]  = "feff";
    cout << "          **************"<<endl;
    cout << mm["6"] << " " << mm["7"] << endl; 
    // tmp.deleteNode(&tmp, "4");
    //mm.clear();
    cout << mm.equal_range("199").first->first << " -> " << mm.count("7") << endl;
    ft::map<string , string>::iterator it = mm.begin();
    ft::map<string , string>::const_iterator cit = mm.begin();
    if (it == cit)
    cout << mm.size() << "size hobalobadobdob" << endl;
    ft::pair<ft::map<std::string, string>::iterator, bool> m_pair(mm.insert(p2));
    //m_pair =  mm.insert(p2);
    it++; 
    it++;
    it++;
    it++;
    //mm.erase(mm.begin(), it);
    cout << it->first << endl;
    it = mm.begin();
    while (it != mm.end())
    {
        cout << (*it).first << " -> " << it->second << endl;
        it++;
    }

    std::cout << std::boolalpha;
    std::cout << "i is odd: " << is_odd(i) << std::endl;
    std::cout << "i is even: " << is_even(i) << std::endl;

    std::cout << "is_integral<int> == " << std::boolalpha
        << ft::is_integral<int>::value << std::endl;
    std::cout << "is_integral<float> == " << std::boolalpha
        << ft::is_integral<float>::value << std::endl;

    // ft::vector<std::string> s(7, "wesh");
    // ft::vector<std::string> f(5, "asat");
    
    // s.insert(s.begin(), s.begin() + 2, s.begin() + 5);
    // for (ft::vector<std::string>::iterator ss = s.begin(); ss < s.end() ; ss++)
    //     std::cout << *ss << std::endl;
    // for (ft::vector<std::string>::iterator ss = f.begin(); ss < f.end() ; ss++)
    //     std::cout << *ss << std::endl;
    return 0;
}
