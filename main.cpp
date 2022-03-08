#include <iostream>
#include <memory>
#include <stack>
#include <vector>
#include "vector.hpp"

int main()
{
  
    // allocator for integer values
    std::allocator<int> myAllocator;

    std::allocator<int>::pointer dd;
    // allocate space for five ints
    int* arr = myAllocator.allocate(5);

    dd = &arr[1];
    // construct arr[0] and arr[3]
    myAllocator.construct(arr, 100);
    arr[3] = 10;
    std::ptrdiff_t p = arr[3];
    std::cout << dd << std::endl;
    std::cout << arr[1] << std::endl;
    std::cout << arr[3] << std::endl;



    vector<int> ss;
    vector<int> s(4);

    s = ss;
    // deallocate space for five ints
    std::cout << s.size() << std::endl;
    myAllocator.deallocate(arr, 5);
  
    return 0;
}