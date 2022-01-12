#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> A{1, 2, 3 };
    vector<int> B{4, 5, 6};

    for(auto &a : A) cout << a << ' ';
    cout << endl;
    for(auto &b : B) cout << b << ' ';
    cout << endl;

    if(A > B) cout << "A > B" << endl;
    else cout << "A < B" << endl;
}