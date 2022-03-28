
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
    int i= 3;
    string item;

    while (getline (ss, item, delim)) {
        result.insert(pair<int , std::string>(i--,item));
    }
    return result;
}

int main()
{
    std::string s = "scott tiger + mushroom";

    std::map<int,string> str = split(s, ' ');
    std::map<int,string>::iterator ff = str.begin();
    std::map<int,string>::iterator ff1 = str.end();
    int i = 0;

    ff->second = "dewdd";
    /*while (i <= 3)
    {
        cout << ff->first << "  " << ff->second << endl;
        ff++;
        i++;
    }*/

    cout << str[3] << endl;
    
}