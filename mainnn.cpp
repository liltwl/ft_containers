
#include <iostream>
#include <memory>
#include <stack>
#include <vector>
#include "vector.hpp"
#include "stack.hpp"
#include <stack>
#include <iterator>
using namespace std;
#include <sstream>
#include <vector>
#include <map>



map<int,string> split (const string &s, char delim) {
    map<int,string> result;
    stringstream ss (s);
    int i= 0;
    string item;

    while (getline (ss, item, delim)) {
        result.insert(pair<int , std::string>(i++,item));
    }
    return result;
}

int main()
{
    std::string s = "scott tiger + mushroom";

    std::map<int,string> str = split(s, ' ');
    for (auto i: str)
    {
        cout <<i.second << endl;
    }

    //cout << str.find(3) << endl;
    
}