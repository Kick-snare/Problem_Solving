#include <bits/stdc++.h>
using namespace std;

vector<int> XOR(vector<int> &seta, vector<int> &setb) {
    vector<int> setc(seta);
    set<int> rmv;
    for(auto b : setb) setc.push_back(b);

    for(auto &b : setb) {
        auto pos = find(seta.begin(), seta.end(), b);
        if(pos!=seta.end()) rmv.insert(*pos);
    }
    sort(setc.begin(), setc.end());

    for(auto r : rmv)
        while(true) {
            auto pos = find(setc.begin(), setc.end(), r);
            if(pos==setc.end()) break;
            setc.erase(pos);
        } 
    return setc;
}

int main() {
    int tmp;
    vector<int> seta, setb, setc;
    while(cin>>tmp && tmp) seta.push_back(tmp);
    while(cin>>tmp && tmp) setb.push_back(tmp);
    setc = XOR(seta, setb);
    for(auto c : setc) cout << c << ' ';
}