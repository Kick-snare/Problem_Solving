#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "I have a dream that my";
    list<char> str;
    for(auto c : s) str.push_back(c);
    // for(auto &c : str) cout << c << ' ';

    auto it = str.begin();
    char command;
    
    while(cin >> command && command != '&') {
        int cmd;
        if(command == '>') cmd = 0;
        else if(command == '<') cmd = 1;
        else if(command == '-') cmd = 2;
        else cmd = 3;

        for(auto c : str) cout << c; cout << endl; 
        cout <<"cmd : "<< command <<  "\t it : " <<*it << endl;

        switch (cmd) {
            
        case 0:{
            it++;
            if(it==str.end()) it--;
            break;
        }
        case 1:{
            if(it!=str.begin()) it--;
            break;
        }
        case 2: {
            it = str.erase(it);
            break;
        }
        case 3: {
            str.insert(it, command);
            it--;
            break;
        }
        default:
            break;
        }
    }
    for(auto c : str) cout << c;
}