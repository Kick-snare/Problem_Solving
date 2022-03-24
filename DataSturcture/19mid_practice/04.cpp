#include <bits/stdc++.h>
using namespace std;

struct P {
    int no;
    string name;
    char type;

    P(int no, string name, char type) : no(no), name(name), type(type) {};
};

int main() {
    vector<P> p1, p2;

    string name;
    char type;
    int no=0;
    while(cin >> name && name != "---") {
        cin >> type;
        P *tmp = new P(++no, name, type);
        p1.push_back(*tmp);
    }
    no=0;
    while(cin >> name) {
        cin >> type;
        P *tmp = new P(++no, name, type);
        p2.push_back(*tmp);
    }

    stable_sort(p1.begin(), p1.end(), [](auto &a, auto &b){
        if(a.type != b.type) return a.type < b.type;
        return a.type > b.type;
    });
    stable_sort(p2.begin(), p2.end(), [](auto &a, auto &b){
        if(a.type != b.type) return a.type < b.type;
        return a.type > b.type;
    });

    int i=0, j=0;
    while(i != p1.size() || j == p2.size()) {
        if(i == p1.size() || j == p2.size()){
            if(i == p1.size()) cout << p2[j++].name << endl;
            else cout << p1[i++].name << endl;
            continue;
        }

        else if(p1[i].type != p2[j].type) {
            if(p1[i].type < p2[j].type) cout << p1[i++].name << endl;
            else cout << p2[j++].name << endl;
            continue;
        }

        else if(p1[i].no != p2[j].no){
            if(p1[i].no < p2[j].no) cout << p1[i++].name << endl;
            else cout << p2[j++].name << endl;
            continue;
        }

        else cout << p1[i++].name << endl;
    }
}