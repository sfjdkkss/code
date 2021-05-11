#include <string>
#include <vector>
#include <iostream>
using namespace std;


int main() {
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b(a.begin(), a.begin()+2);

    for(int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < b.size(); i++) {
        cout << b[i] << " ";
    }
    cout << endl;

    return 0;
}