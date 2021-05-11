#include <string>
#include <iostream>
#include <sstream>
#include <map>
using namespace std;

int main() {
    map<char, int> m;
    m['a'] ++;

    cout << m['a'] << endl;
    cout << m['b'] << endl;

    return 0;
}