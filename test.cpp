#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

 vector<string> split (const string &s, char delim) {
    vector<string> result;
    stringstream ss (s);
    string item;

    while (getline (ss, item, delim)) {
        result.push_back(item);
    }

    return result;
}

int main()
{
    int n;
    cin >> n; cin.ignore();
        string pair[9999];
    for (int i = 0; i < n; i++) {
        getline(cin, pair[i]);
    }
    string _template;
    getline(cin, _template);
    std::vector<string> str = split(_template, ' ');
    for (int i = 0; i< str.size(); i++)
    {
        std::vector<string> str1 = split(str[i], ' ');
        if (str[i].compare(str1[0].substr(1, str1.size() - 2)))
            cout << str1[1];
        else
            cout << str[i];
        cout << " " << str1[0].substr(1, str1.size() - 2);
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout <<  endl;
}